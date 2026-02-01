# Squad-Q – Voice Controlled Differential Drive Car

## 1. Project Description
This project demonstrates a **voice-controlled differential drive car** using the **Arduino UNO Q**.  
A lightweight AI keyword spotting model detects simple voice commands, which are mapped to motor control actions on the microcontroller, enabling hands-free control of the robot.

The project focuses on combining **embedded AI inference** with **basic motor control**.

---

## 2. Hardware Lineup
- Arduino UNO Q  
- Logitech Webcam (audio input)  
- Single shaft BO motors  
- Motor driver  
- 1.1V 3s lithium ionBattery pack with BMS  
- USB hub  

---

## 3. User Interface & Feedback
- Voice commands are given through the webcam microphone  
- Detected commands are printed on the serial terminal  
- The robot provides physical feedback by moving in the corresponding direction, while the LED matrix shows an arrow pointing in the direction of turning.  

---

## 4. The AI Model
A **custom-trained keyword spotting model** built using **Edge Impulse** with **MFE (Mel Frequency Energy) preprocessing** is used.

- Runs locally on the Arduino UNO Q  
- Recognizes the following commands:
  - `front`
  - `back`
  - `left`
  - `right`

---

## 5. Software Architecture
The software is split into two main parts:

1. **AI Inference on the microprocessor**
   - Captures audio input
   - Runs the keyword spotting model
   - Outputs the detected command

2. **Motor Control Sketch**
   - Receives the detected command
   - Maps commands to motor actions
   - Controls the stepper motors using differential drive logic

---

## 6. Visuals & Media
- Images of the assembled robot  
- A short demonstration video showing voice-controlled movement  

---

## 7. GitHub Repository
**Repository Link:** _Add your GitHub link here_
