# 🌍 Air Pollution Monitoring System (IoT + ML)

An **IoT and Machine Learning based Air Pollution Monitoring System** designed to measure real-time pollutant concentrations and identify the source of pollutants.  

This project integrates:
- **Arduino/ESP32 (IoT sensors)** for collecting air quality data
- **KNN model (Machine Learning)** for identifying the source of pollutants
- **Client-Server architecture** for data communication

---

## 📁 Project Structure
- **`ardiuno/`** → Contains Arduino/ESP32 code to interface with MQ2 & MQ9 gas sensors, LED, and buzzer. Data is uploaded to the **ThingSpeak cloud platform**.  
- **`KNN/`** → Python scripts implementing the **K-Nearest Neighbors (KNN)** model to classify and identify the source of pollutants.  
- **`Client_server/`** → C-based client-server implementation for transmitting and receiving air quality data across a network.  

---

## ✨ Features
- 📡 **IoT Sensor Integration**: ESP32 with MQ2 & MQ9 sensors to detect CO and NH3 levels.  
- ☁️ **Cloud Dashboard**: Real-time data visualization using ThingSpeak.  
- 🔔 **Alert System**: Buzzer alerts when pollutant levels exceed thresholds.  
- 🤖 **Machine Learning**: KNN model predicts the likely source of pollutants based on sensor data.  
- 🔗 **Client-Server Communication**: Networked architecture for scalable data exchange.  

---

## 🛠️ Tech Stack
- **Hardware**: ESP32, MQ2 Sensor, MQ9 Sensor, Breadboard, Buzzer, LED  
- **Software**: Arduino IDE, ThingSpeak, Python 3, C (Client-Server)  
- **Libraries/Modules**: `WiFi.h`, `WiFiClient.h`, `ThingSpeak.h`, `pandas`, `scikit-learn`, `socket`  

---
