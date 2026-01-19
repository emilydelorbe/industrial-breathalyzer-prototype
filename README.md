# industrial-breathalyzer-prototype
A safety-focused hardware prototype designed to monitor alcohol levels in industrial environments.

Project Overview

This project consists of a wall-mounted device capable of detecting blood alcohol concentration (BAC) through breath analysis. The goal was to create a functional prototype for industrial safety, ensuring a hazard-free work environment by preventing machinery operation under the influence.

Features

Non-Contact Detection: Sanitary design for multiple users.

Visual/Audio Alerts: Traffic light system (Green/Red) and buzzer for pass/fail results.

Wall-Mounted Design: Engineered for fixed installation at entry points.

Tech Stack & Hardware

Microcontroller: [Ej. Arduino Uno / ESP32]

Sensors: [Ej. MQ-3 Alcohol Gas Sensor]

Output: [Ej. LCD Display 16x2, LEDs, Buzzer]

Logic: C++ (Arduino IDE) & Circuit Design.

Gallery


<img width="743" height="395" alt="foto-modelo-3D" src="https://github.com/user-attachments/assets/63d88e57-6319-4a19-8324-87cba2c496c7" />


![foto-resultado-alc](https://github.com/user-attachments/assets/3a63135f-64bd-40ef-9159-8f4db4226395)

How it Works
The sensor warms up for stability.

User blows near the sensor (no contact required).

The algorithm processes the analog signal.

If the value exceeds the safety threshold (set strictly for industrial standards), the alarm triggers.
