# Connected Security Camera System

## Description
Develop a security camera system with motion detection, real-time video streaming, and alerts sent to a smartphone.

## Components
- Camera module
- Motion sensor
- Microcontroller
- Wi-Fi module
- Cloud storage

## Project Code

### Arduino Code
The Arduino code uses a motion sensor to detect movement and trigger alerts. It also handles capturing images and uploading them to cloud storage.

**File:** `security_camera_system.ino`

### Cloud Storage Setup
Use a cloud storage service to save captured images. Configure the camera module to send images using suitable methods.

### Mobile App
A basic Flutter app to check for security alerts.

**File:** `main.dart`

## How to Use

1. **Arduino:**
   - Connect the camera module and motion sensor to the Arduino as described in the code.
   - Upload the Arduino code to the microcontroller.
   - Configure your Wi-Fi credentials and MQTT broker details in the code.

2. **Cloud Storage:**
   - Set up a cloud storage service to receive and store captured images.
   - Configure the Arduino code to send images to the cloud storage.

3. **Mobile App:**
   - Install Flutter and dependencies.
   - Configure the server URL in `main.dart`.
   - Run the app using `flutter run`.

## Deployment
Deploy the cloud storage service and ensure the Arduino can communicate with it. Host the mobile app or distribute it through app stores.

## License
This project is licensed under the MIT License. See the LICENSE file for more details.

## Contributing
Contributions are welcome! Please fork this repository and submit a pull request with your improvements.

## Notes
Ensure you have the necessary libraries installed for the Arduino and mobile app. Adjust configurations based on your setup.
