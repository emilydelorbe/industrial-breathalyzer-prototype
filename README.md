# Industrial Wall-Mounted Breathalyzer 

> A safety-focused hardware prototype designed to monitor alcohol levels in industrial environments.

---

### Project Overview

This report presents an innovative automated system for detecting and controlling Blood Alcohol Concentration (BAC) in industrial environments. Designed to mitigate operational risks, the system utilizes Arduino technology and an MQ-3 gas sensor to analyze exhaled breath in real-time. Acting as a preventive access control mechanism, it automatically denies entry or triggers alarms when safety thresholds are exceeded. This solution aligns with ISO 45001 standards, ILO guidelines, and Dominican Ministry of Labor regulations, ensuring a controlled, risk-free workspace while protecting both personnel and infrastructure.

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

  ---

### References & Research Background
The development of this prototype was grounded in extensive research regarding industrial safety standards and occupational risk prevention. The following sources were **instrumental in establishing the critical importance of automated BAC monitoring** to prevent workplace accidents, ensure compliance, and protect human lives in corporate environments.

1.  **O. I. Grigoreva and F. V. Nikolaeva**, "Breathalyzer for enterprise access control system," April. [Online]. Available: [Link](https://panor.ru/en/articles/breathalyzer-for-enterprise-access-control-system/95371.html#)
2.  **B. C. Dessbessel, C. N. Dorneles, D. Amorim, S. M. Rhoden, and L. L. de Oliveira**, "Bafômetro automotivo: modelo funcional e de baixo custo usando Arduino," *Brazilian J. Dev.*, vol. 6, no. 7, pp. 51900–51907, 2020. DOI: 10.34117/bjdv6n7-729.
3.  **A. Slemeyer**, "A NEW BREATHALYSER FOR INDUSTRIAL USE," 1978. [Online]. Available: [Consensus App](https://consensus.app/papers/a-new-breathalyser-for-industrial-use-slemeyer/935d1c543f7f59dfb4cc206ec08c0d76/)
4.  **F. Mustafa, M. Carhart, and S. Andreescu**, "A 3D-Printed Breath Analyzer Incorporating CeO2 Nanoparticles for Colorimetric Enzyme-Based Ethanol Sensing," *ACS Appl. Nano Mater.*, 2021. DOI: 10.1021/acsanm.1c01826.
5.  **E. Yousif, D. Alali, S. Aldakhl, and M. Zohdy**, "Use of Vehicle Breathalyzers in the Reduction of DUI Deaths," *2021 IEEE Int. IOT, Electron. Mechatronics Conf.*, pp. 1–8, 2021. DOI: 10.1109/IEMTRONICS52119.2021.9422629.
6.  **R. Borkenstein and H. Smith**, "The Breathalyzer and its Applications," *Med. Sci. Law*, vol. 2, pp. 13–22, 1961. DOI: 10.1177/002580246200200103.
7.  **J. Terrones**, "Diseño e implementación de un sistema de monitoreo y control operativo de alcoholemia para la empresa Galvanoplastia Yhabal S.A.C.," 2019.
8.  **R. Granelli, Z. M. Kovacs-Vajna, and F. Torricelli**, "No Title," *Wiley Online Library*, 2025. [Online]. Available: [Wiley Library](https://onlinelibrary.wiley.com/doi/full/10.1002/smll.202410499)
9.  **P. Olabisi and B. Taiwo**, "Stemming Alcohol-Based Industrial Fatalities Through Enhanced Breathalyser Sensitivity," *IARJSET*, vol. 8, Apr. 2021. DOI: 10.17148/IARJSET.2021.8439.
10. **K. Chiranjeevi, N. Swapna, P. Sowjanya, M. Akshitha, and M. K. Sri**, "Factory Worker Alcohol Detector with Automatic Machine Shutdown," *Int. J. Adv. Res. Sci. Commun. Technol.*, vol. 4, no. 6, 2024. [Online]. Available: [PDF](https://ijarsct.co.in/Paper17689.pdf)
11. **Y. Cho, W. Lee, H. Sin, S. Oh, K. C. Choi, and J.-H. Jun**, "Non-Invasive Alcohol Concentration Measurement Using a Spectroscopic Module: Outlook for the Development of a Drunk Driving Prevention System," 2024. DOI: 10.3390/s24072252.
12. **A. A. Khamis et al.**, "Development and Performance Evaluation of an IoT-Integrated Breath Analyzer," *Int. J. Environ. Res. Public Health*, vol. 20, no. 2, Jan. 2023. DOI: 10.3390/ijerph20021319.
