# RC Car Arduino Code

This repository contains the Arduino code for the ESP8266 microcontroller installed in the RC car. The code enables communication with the Flutter RC Car Controller App over HTTP protocol, facilitating remote control of the RC car.

## Features:

- **HTTP Server:** Establishes an HTTP server on the ESP8266, allowing the RC car to receive control commands from the Flutter app.
- **Button Control:** Implements logic to interpret button control commands sent by the app and translate them into corresponding actions for the RC car.
- **Gyroscope Control:** Provides functionality to interpret gyroscope control commands received from the app and adjust the RC car's movement accordingly.
- **Wi-Fi Connectivity:** Enables the ESP8266 to connect to a Wi-Fi network, allowing seamless communication with the Flutter app.
- **Email Notification:** Sends an email to the user containing the IP address of the ESP8266 upon successful connection to the Wi-Fi network.

## Installation:

1. Clone this repository to your local machine.
2. Open the Arduino IDE and load the `RC_Car_Controller.ino` sketch.
3. Configure the Wi-Fi credentials and other settings as necessary.
4. Upload the sketch to your ESP8266 microcontroller.

## Flutter App Repo:

  ### [Flutter-Car-Control_Http](https://github.com/chater-marzougui/Flutter-Car-Control_Http)

## Usage:
- Make the Car, refer to the end of the readme for the composents needed for the car.
- Power on the RC car and wait for the ESP8266 to establish a Wi-Fi connection.
- Connect to the same Wi-Fi network as the ESP8266.
- Launch the Flutter RC Car Controller App on your device.
- Fill in the IP address sent by the microcontroller
- Select the desired control mode (button or gyroscope) in the app.
- Begin controlling the RC car using the app's interface.

## Email Notification Setup:

To enable email notification functionality, follow these steps:

1. **Configure SMTP Settings:** Modify the `EMAIL_SENDER_ADDRESS`, `EMAIL_SENDER_PASSWORD` and `EMAIL_RECIPIENT_ADDRESS` constants in the Arduino code with your SMTP server details and email addresses.
   -You should make an E-mail address for the esp and get the IOT type password.
   -The recepient E-mail should be your E-mail
3. **Test Email Notification:** Once configured, test the email notification feature by connecting the ESP8266 to Wi-Fi. Upon successful connection, you should receive an email containing the IP address of the ESP8266.

## Needed Materials for the setup:

1. **MicroController:** ESP8266 or ESP32.
2. **18650 Batteries:** depending on the power needed by motors, at least two cells.
3. **Motors** 2 Motors with wheels and a universal wheel, or 4 motors with wheels.
4. **Motor Driver** Necessary to power up the microcontroller (with 5V) and for the motors.

## Contribution:

Contributions are welcome! Whether you're interested in adding new features, optimizing existing code, or fixing bugs, feel free to fork this repository and submit a pull request. Together, we can enhance the functionality and reliability of the RC car Arduino code for the community.

## License:

This project is licensed under the MIT License - see the file for details.

## Credits:

- **Developer:** Chater Marzougui
- **Contact:** chater.mrezgui2002@gmail.com
