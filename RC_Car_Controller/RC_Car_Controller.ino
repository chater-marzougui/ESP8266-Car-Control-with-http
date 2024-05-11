#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP_Mail_Client.h>

///////////////Variables to Modify
///you have to modify these :
#define AUTHOR_EMAIL "PUT_THE_EMAIL_YOU_MADE_FOR_THE_ESP_HERE"
#define AUTHOR_PASSWORD "PUT_THE_PASSWORD_HERE" // App Password in Gmail
#define RECIPIENT_EMAIL "PUT_YOUR_EMAIL_HERE"
const char* ssid = "infinix7";
const char* password = "12345678";
///// the rest is optional
const int forL = D3;
const int backL = D4;

const int forR = D5 ;
const int backR = D6;

const int led1 = D7;
const int led2 = D8;
///////////////variables to modify END

#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 465
SMTPSession smtp;
int speed = 0;
int yaxis = 0;
int xaxis = 0;

bool ledbool = false;
int k = 0;
ESP8266WebServer server(80);

void setup() {
  pinMode(forL,OUTPUT);
  pinMode(backL,OUTPUT);
  pinMode(forR,OUTPUT);
  pinMode(backR,OUTPUT);

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  

  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);


  ////////////////////////////////////
  MailClient.networkReconnect(true);
  smtp.debug(1);
  Session_Config config;
  config.server.host_name = SMTP_HOST;
  config.server.port = SMTP_PORT;
  config.login.email = AUTHOR_EMAIL;
  config.login.password = AUTHOR_PASSWORD;

  config.login.user_domain = F("127.0.0.1");
  config.time.ntp_server = F("pool.ntp.org,time.nist.gov");
  config.time.gmt_offset = 1;
  config.time.day_light_offset = 0;
  SMTP_Message message;
  message.sender.name = F("Esp 8266");
  message.sender.email = AUTHOR_EMAIL;

  message.subject = "My IP Address";

  message.addRecipient(F("Chater"), RECIPIENT_EMAIL);
  //////////////////////////////////////
  String textMsg = WiFi.localIP().toString();
  //////////////////////////////////////
  message.text.content = textMsg;
  message.text.transfer_encoding = "base64";
  message.text.charSet = F("utf-8");
  message.priority = esp_mail_smtp_priority::esp_mail_smtp_priority_high;
  message.addHeader(F("Message-ID: <abcde.fghij@gmail.com>"));

  smtp.connect(&config);
  smtp.isLoggedIn();
  smtp.isAuthenticated();
  MailClient.sendMail(&smtp, &message);
  /////////////////////////////////////////////////

  for (int i = 0 ; i < 16;i++ ){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    delay(50);
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    delay(50);
  }

  // Define web server routes
  server.on("/MOVE", HTTP_GET, move);
  server.on("/stop" ,HTTP_GET,stop);
  server.on("/led",HTTP_GET,led);
  server.begin();
}






void loop() {
  server.handleClient();
  if (xaxis == 0 && yaxis == 0){
    stop();
  }
  else if (xaxis == 0 && yaxis == 1){
    forward();
  }
  else if (xaxis == 0 && yaxis == -1){
    backward();
  }
  else if (xaxis == 1 && yaxis == 0){
    right();
  }
  else if (xaxis == 1 && yaxis == 1){
    rightup();
  }
  else if (xaxis == 1 && yaxis == -1){
    rightback();
  }
  else if (xaxis == -1 && yaxis == 0){
    left();
  }
  else if (xaxis == -1 && yaxis == 1){
    leftup();
  }
  else if (xaxis == -1 && yaxis == -1){
    leftback();
  }

  if(ledbool){
    if (k < 2){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    delay(50);
    k++;
    }
    else if ( 2 <= k < 4){
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    delay(50);
    k++;
    }
    k = k%4;
  }
  else{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
  }
}



void move(){
  speed = server.arg("speed").toInt();
  xaxis = server.arg("xaxis").toInt();
  yaxis = server.arg("yaxis").toInt();
}

void stop(){
  Serial.println("STOP");

  analogWrite(forL, 0);
  analogWrite(backL, 0);
  analogWrite(forR, 0);
  analogWrite(backR, 0);
}

void forward(){
  Serial.println("forward");

  
  analogWrite(forL, speed);
  analogWrite(backL, 0);
  analogWrite(forR, speed);
  analogWrite(backR, 0);
}

void backward(){
  Serial.println("backward");

  analogWrite(forL, 0);
  analogWrite(backL, speed);
  analogWrite(forR, 0);
  analogWrite(backR, speed);
}

void right(){
  Serial.println("right");
  
  analogWrite(forL, speed);
  analogWrite(backL, 0);
  analogWrite(forR, 0);
  analogWrite(backR, 0);
}

void rightup(){
  Serial.println("rightup");

  analogWrite(forL, speed);
  analogWrite(backL, 0);
  analogWrite(forR, speed/3);
  analogWrite(backR, 0);
}

void rightback(){
  Serial.println("rightback");

  analogWrite(forL, 0);
  analogWrite(backL, speed/3);
  analogWrite(forR, 0);
  analogWrite(backR, speed);

}

void left(){
  Serial.println("left");

  
  analogWrite(forL, 0);
  analogWrite(backL, 0);
  analogWrite(forR, speed);
  analogWrite(backR, 0);
}

void leftup(){
  Serial.println("leftup");
  
  analogWrite(forL, speed);
  analogWrite(backL, 0);
  analogWrite(forR, speed/3);
  analogWrite(backR, 0);
}

void leftback(){
  Serial.println("leftback");
  
  analogWrite(forL, 0);
  analogWrite(backL, speed/3);
  analogWrite(forR, 0);
  analogWrite(backR, speed);
}

void led(){
  ledbool = (server.arg("turnon").toInt() == 1);
}
    