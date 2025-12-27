\# 🏠 Home Light Automation using ESP8266 \& Blynk



An IoT-based home automation system that controls home lighting using an ESP8266 (NodeMCU).  

The system supports \*\*dual-mode automation\*\* using real-time \*\*Google Sunrise/Sunset API\*\* data and \*\*ambient light sensing (LDR)\*\*, along with manual control via the Blynk IoT platform.



---



\## ✨ Features



\- 📱 Remote light control using Blynk app

\- 🌅 Automatic control using Google Sunrise/Sunset API

\- 🌗 Sensor-based control using LDR (ambient light)

\- 🔁 Dual-mode operation: API mode or Sensor mode

\- 🕹️ Manual override from mobile app

\- 🌐 Real-time monitoring

\- ⚡ Low-cost and easy to implement



---



\## 🧰 Components Used



\- ESP8266 NodeMCU

\- LED / AC Bulb (Load)

\- LDR with LM393 module

\- Jumper wires

\- Breadboard

\- Micro USB cable

\- Wi-Fi connection



---



\## 🖥️ Software \& Tools



\- Arduino IDE

\- Blynk IoT Platform (Web \& Mobile)

\- ESP8266 Board Package

\- Git \& GitHub

\- VS Code (optional)



---



\## ⚙️ Working Principle



The system operates in two automatic modes along with manual control:



\### 🌅 API-Based Mode

\- ESP8266 fetches sunrise and sunset time using Google API.

\- Lights turn ON after sunset and OFF after sunrise automatically.

\- Provides accurate daily scheduling based on location.



\### 🌗 Sensor-Based Mode

\- LDR senses surrounding light intensity.

\- If ambient light is low → lights turn ON.

\- If ambient light is high → lights turn OFF.

\- Useful during cloudy or sudden lighting changes.



\### 🔁 Dual-Mode Toggle

\- User can switch between API mode and Sensor mode using a toggle button in Blynk.

\- Manual control can override automation when required.



This ensures reliable and adaptive lighting under all conditions.



---



\## 📱 Blynk Dashboard \& Console



Below is the Blynk console/dashboard used to monitor and control the system:



!\[Blynk Console](blynk\_console.png)



\### 🛠️ How to Create the Dashboard



1\. Go to \*\*Blynk Console\*\* and create a new template.

2\. Name it \*\*HOME LIGHT AUTOMATION\*\* and select hardware as \*\*ESP8266\*\*.

3\. Create a new device from this template and copy the \*\*Auth Token\*\*.

4\. In the Web/Mobile dashboard, add widgets:



&nbsp;  - 🔢 \*\*Display Widget\*\* → Virtual Pin \*\*V1\*\* → LDR Light Sensor value  

&nbsp;  - 💡 \*\*Button Widget\*\* → Virtual Pin \*\*V2\*\* → Light/Relay control (Switch mode)  

&nbsp;  - 🔁 \*\*Button Widget\*\* → Virtual Pin \*\*V3\*\* → Toggle between:

&nbsp;    - Google API mode 🌅

&nbsp;    - LDR Sensor mode 🌗  



5\. Save the dashboard.



Once the ESP8266 is online, you can control and monitor the lights in real time.



---



\## 🚀 Getting Started



\### 1️⃣ Clone the Repository

```bash

git clone https://github.com/Urvi2727/Home-Light-Automation.git



