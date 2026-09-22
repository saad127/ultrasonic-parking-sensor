# Ultrasonic Parking Sensor System

An Arduino-based automotive parking assist system using the HC-SR04 ultrasonic distance sensor, multi-stage status LEDs, and an audible piezo alert.

---

## 📌 Overview & Distance Logic

The system continuously measures the distance to approaching obstacles and triggers three intuitive feedback levels:

- **Safe Zone (> 100 cm):** 
  - Green LED ON
  - Orange & Red LEDs OFF
  - Buzzer OFF
- **Warning Zone (50 cm – 100 cm):** 
  - Orange LED ON
  - Green & Red LEDs OFF
  - Moderate intermittent beep (`delay(100)` ON / `delay(200)` OFF)
- **Danger Zone (≤ 50 cm):** 
  - Red LED ON
  - Green & Orange LEDs OFF
  - Rapid urgent alert (`delay(50)` ON / `delay(50)` OFF)

---

## 🔌 Circuit Pinout

| Component | Pin / Terminal | Arduino Pin | Mode |
| :--- | :---: | :---: | :---: |
| **Green LED** | Anode (+) via 220Ω | Pin 2 | OUTPUT |
| **Orange LED** | Anode (+) via 220Ω | Pin 3 | OUTPUT |
| **Red LED** | Anode (+) via 220Ω | Pin 4 | OUTPUT |
| **Piezo Buzzer** | Positive (+) | Pin 5 | OUTPUT |
| **HC-SR04** | Trig | Pin 6 | OUTPUT |
| **HC-SR04** | Echo | Pin 7 | INPUT |
| **Power Rails** | VCC / GND | 5V / GND | Power |

---

## 📐 Circuit Diagram

![Circuit Layout](docs/circuit.png)

---

## 🛠️ Hardware Requirements (BOM)

| ID | Component | Quantity | Value / Details |
| :---: | :--- | :---: | :--- |
| U1 | Arduino Uno R3 | 1 | Microcontroller |
| DIST1 | Ultrasonic Sensor | 1 | HC-SR04 (4-pin) |
| D1 | Red LED | 1 | 5mm |
| D2 | Orange LED | 1 | 5mm |
| D3 | Green LED | 1 | 5mm |
| R1-R3 | Resistors | 3 | 220 Ω |
| PIEZO1 | Piezo Buzzer | 1 | Audio indicator |

---

## 💻 Working Logic & Calculation

The sensor calculates distance based on the speed of sound in air ($340\text{ m/s} = 0.034\text{ cm/\mu s}$):

$$\text{Distance (cm)} = \frac{\text{Echo Pulse Duration (\mu s)} \times 0.034}{2}$$

Source code is available at [`src/parking_sensor.ino`](./src/parking_sensor.ino).
