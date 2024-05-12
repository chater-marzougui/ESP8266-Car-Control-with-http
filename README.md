<a name="readme-top"></a>
<div align="center">

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]](https://www.linkedin.com/in/chater-marzougui-342125299/)
</div>


<!-- PROJECT LOGO --> 
<br />
<div align="center">
  <a href="https://github.com/chater-marzougui/ESP8266-Car-Control-with-http">
    <img src="https://github.com/chater-marzougui/Flutter-Car-Control_Http/blob/main/android/app/src/main/res/mipmap-xxxhdpi/ic_launcher.png?raw=true" alt="Logo" width="256" height="256">
  </a>
    <h1 style="font-size:35px">Car Commander
    </h1>
  <p align="center" style="font-size: 20px;">
    App made just for fun
    <br />
    <br />
    <a href="https://github.com/chater-marzougui/Flutter-Car-Control_Http">Flutter App Repo</a>
    ·
    <a href="https://github.com/chater-marzougui/ESP8266-Car-Control-with-http/issues/new?labels=bug&template=bug-report---.md">Report Bug</a>
    ·
    <a href="https://github.com/chater-marzougui/Flutter-Car-Control_Http/issues/new?labels=enhancement&template=feature-request---.md">Request Feature</a>
  </p>
</div>


# RC Car Arduino Code
<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#about-the-project">About The Project</a></li>
    <li><a href="#installation">Installation</a></li>
    <li><a href="#arduino-code-repo">Arduino Code Repo</a></li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

<h3>This repository contains the code for an ESP8266-based system that allows for remote control of an RC car using a Flutter app. Features include an HTTP server for real-time communication, button and gyroscope control logic, seamless Wi-Fi connectivity, and email notifications for easy setup. Control your RC car with precision and convenience using this comprehensive ESP8266 solution.
</h3>
<br/>

## Features:

- **HTTP Server:** Establishes an HTTP server on the ESP8266, allowing the RC car to receive control commands from the Flutter app.
- **Button Control:** Implements logic to interpret button control commands sent by the app and translate them into corresponding actions for the RC car.
- **Gyroscope Control:** Provides functionality to interpret gyroscope control commands received from the app and adjust the RC car's movement accordingly.
- **Wi-Fi Connectivity:** Enables the ESP8266 to connect to a Wi-Fi network, allowing seamless communication with the Flutter app.
- **Email Notification:** Sends an email to the user containing the IP address of the ESP8266 upon successful connection to the Wi-Fi network.
<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Installation:

1. Clone this repository to your local machine.
2. Open the Arduino IDE and load the `RC_Car_Controller.ino` sketch.
3. Configure the Wi-Fi credentials and other settings as necessary.
4. Upload the sketch to your ESP8266 microcontroller.
<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Flutter App Repo:

  ### [Flutter-Car-Control_Http](https://github.com/chater-marzougui/Flutter-Car-Control_Http)
  <p align="right">(<a href="#readme-top">back to top</a>)</p>

## Usage:
1. Make the Car, refer to the end of the readme for the components needed for the car.
2. - **if you use the direct way:**
     - Power on the RC car and wait for the ESP8266 to establish a Wi-Fi connection.

   - **if you use the ESP with AP mode:** 
     - Power on the RC car and wait for the ESP8266 to open the HotSpot.
     - Connect to the Hotspot using the password in the file.
     - Open the phone app, choose : change wifi password.
     - Fill in the credentials of your new wifi (home or phone HotSpot).
     - Click connect and move to step 3.
3. Connect to the same Wi-Fi network as the ESP8266.
4. Launch the Flutter RC Car Controller App on your device.
5. Fill in the IP address sent by the microcontroller
6. Select the desired control mode (button or gyroscope) in the app.
7. Begin controlling the RC car using the app's interface.
<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Email Notification Setup:

To enable email notification functionality, follow these steps:

1. **Configure SMTP Settings:** Modify the `EMAIL_SENDER_ADDRESS`, `EMAIL_SENDER_PASSWORD` and `EMAIL_RECIPIENT_ADDRESS` constants in the Arduino code with your SMTP server details and email addresses.
   -You should make an E-mail address for the esp and get the IOT type password.
   -The recipient E-mail should be your E-mail
2. **Test Email Notification:** Once configured, test the email notification feature by connecting the ESP8266 to Wi-Fi. Upon successful connection, you should receive an email containing the IP address of the ESP8266.
<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Needed Materials for the setup:

1. **MicroController:** ESP8266 or ESP32.
2. **Batteries: 18650-cells** At least two cells depending on the power needed by motors.
3. **Motors** 2 Motors with wheels and a universal wheel, or 4 motors with wheels.
4. **Motor Driver** Necessary to power up the microcontroller (with 5V) and for the motors.
<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request
<p align="right">(<a href="#readme-top">back to top</a>)</p>

## License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.
<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTACT -->

## Contact

Chater Marzougui - [@Chater-marzougui][linkedin-url] - chater.mrezgui2002@gmail.com <br/>
<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/chater-marzougui/ESP8266-Car-Control-with-http.svg?style=for-the-badge
[contributors-url]: https://github.com/chater-marzougui/ESP8266-Car-Control-with-http/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/chater-marzougui/ESP8266-Car-Control-with-http.svg?style=for-the-badge
[forks-url]: https://github.com/chater-marzougui/ESP8266-Car-Control-with-http/network/members
[stars-shield]: https://img.shields.io/github/stars/chater-marzougui/ESP8266-Car-Control-with-http.svg?style=for-the-badge
[stars-url]: https://github.com/chater-marzougui/ESP8266-Car-Control-with-http/stargazers
[issues-shield]: https://img.shields.io/github/issues/chater-marzougui/ESP8266-Car-Control-with-http.svg?style=for-the-badge
[issues-url]: https://github.com/chater-marzougui/ESP8266-Car-Control-with-http/issues
[license-shield]: https://img.shields.io/github/license/chater-marzougui/ESP8266-Car-Control-with-http.svg?style=for-the-badge
[license-url]: https://github.com/chater-marzougui/ESP8266-Car-Control-with-http/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/chater-marzougui-342125299