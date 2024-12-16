Fire Detection and Control System Using CNN and Arduino
Overview
This project presents an AI-powered fire detection and control system that integrates a Convolutional Neural Network (CNN) with an Arduino microcontroller to detect and suppress fires in real time. The system is designed to identify fire using image processing techniques and activate appropriate safety mechanisms to control the fire autonomously, ensuring faster response and enhanced safety in critical environments.

Key Features
Real-Time Fire Detection: Utilizes a trained CNN model to process video or image data to detect the presence of fire.
Automated Control Mechanism: Upon detecting fire, the Arduino triggers connected devices such as water pumps, alarms, or extinguishers to suppress the fire.
Efficient Integration: Combines advanced AI capabilities with hardware control for a cost-effective and scalable solution.
Customizable: Easily adaptable to different environments such as homes, factories, or public spaces by training the CNN model for specific fire scenarios.
How It Works
Fire Detection:

A camera captures real-time video or image streams.
The CNN model analyzes the input to identify signs of fire (e.g., flames, smoke).
Signal Processing:

If fire is detected, the system sends a signal to the Arduino microcontroller.
Fire Control Activation:

The Arduino activates connected devices such as water sprinklers, alarms, or fire extinguishers to mitigate the fire.
Project Setup
Hardware Requirements
Arduino Uno (or equivalent)
Relay module
Water pump, fan, or alarm (for fire suppression)
Camera for real-time video/image capture
Software Requirements
Python (for the CNN model)
TensorFlow/Keras (for building and training the CNN)
Arduino IDE (for microcontroller programming)
Installation Steps
Clone the repository:
bash
Copy code
git clone https://github.com/your-username/fire-detection-control.git
cd fire-detection-control
Install required Python libraries:
bash
Copy code
pip install -r requirements.txt
Upload the Arduino code to the Arduino microcontroller using the Arduino IDE.
Run the CNN fire detection script:
bash
Copy code
python fire_detection.py
Connect the hardware setup and test the system.
Future Enhancements
Integration of IoT for remote monitoring and control.
Improved CNN model with higher accuracy for detecting fire and smoke in various conditions.
Support for multiple safety mechanisms, such as gas suppression systems.
Contributors
Your Name - Developer
Contributions are welcome! Feel free to open an issue or submit a pull request.
------------------------------------------------------------------------------------------------
ardino code is availabe in ardino code

main code is availabe in yolov5

 detect.py
run the file in that directry
========================================================================

