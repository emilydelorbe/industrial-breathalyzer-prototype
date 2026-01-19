# Industrial Wall-Mounted Breathalyzer 

> A safety-focused hardware prototype designed to monitor alcohol levels in industrial environments.

---

### Project Overview

This project consists of a wall-mounted device capable of detecting blood alcohol concentration (BAC) through breath analysis. The goal was to create a functional prototype for **Industrial Safety**, ensuring a hazard-free work environment by preventing machinery operation under the influence.

### Key Features

* **Non-Contact Detection:** Sanitary design allowing multiple users without physical contact.
* **Visual/Audio Alerts:** Intuitive traffic light system (Green/Yellow/Red/Blue) and buzzer for immediate pass/fail results.
* **Wall-Mounted Design:** Engineered for fixed installation at factory entry points.

---

### Tech Stack & Hardware

* **Microcontroller:** Arduino (Uno/Nano compatible)
* **Sensors:** MQ-3 Alcohol Gas Sensor
* **Output:** OLED Display (SH1106), 4 Status LEDs, Active Buzzer
* **Logic:** C++ (Arduino IDE) & Electronic Circuit Design

### Circuit Connections (Pinout)

Based on the `alcoholimetro.ino` source code, the components are mapped as follows:

| Component | Microcontroller Pin | Function |
|-----------|---------------------|----------|
| **MQ-3 Sensor (Analog)** | Pin A0 | Reads raw alcohol concentration data. |
| **Red LED** | Digital Pin 8 | **NO APTO:** Critical Alert (BAC ≥ 0.05). |
| **Yellow LED** | Digital Pin 9 | **PRECAUCION:** High Warning (BAC ≥ 0.03). |
| **Green LED** | Digital Pin 10 | **MODERADO:** Low Warning (BAC ≥ 0.01). |
| **Blue LED** | Digital Pin 11 | **LIBRE:** No alcohol detected (BAC < 0.01). |
| **Buzzer** | Digital Pin 12 | **ALARM:** Triggers for 15s when result is "NO APTO". |
| **OLED Display (SH1106)** | I2C Pins (SDA/SCL) | Displays BAC value, Status text, and Alarm timer. |

---

### Gallery


**3D Model / Concept**
<br>
<img width="743" alt="foto-modelo-3D" src="https://github.com/user-attachments/assets/63d88e57-6319-4a19-8324-87cba2c496c7" />

**Functional Prototype**
<br>
![foto-resultado-alc](https://github.com/user-attachments/assets/3a63135f-64bd-40ef-9159-8f4db4226395)

---

### How it Works

1.  **Initialization:** The sensor warms up for stability (auto-calibration).
2.  **Detection:** User blows near the sensor (no mouth contact required).
3.  **Processing:** The algorithm processes the analog signal and filters noise.
4.  **Result:**
    * If the value is safe, the **Blue LED** lights up.
    * If it exceeds safety thresholds (set strictly for industrial standards), the **Red LED** and **Alarm** trigger.

---

### Future Roadmap & Scalability

To transition this prototype into a market-ready industrial product, the following upgrades are planned:

1.  **Custom PCB Design:**
    * Migrate from breadboard wiring to a custom **Printed Circuit Board (PCB)**.
    * **Goal:** Reduce signal noise, ensure vibration resistance in industrial settings, and fit into a compact, wall-mounted enclosure.

2.  **IoT & Database Integration:**
    * Implement a serial communication system (using Python/SQL) to send sensor data to a central computer.
    * **Goal:** Create a **digital log** that registers the Employee ID, Time, and BAC Level automatically. This allows HR and Safety Managers to audit compliance and generate safety reports.
