# ☀️ Solar-What

An intelligent, servo-driven solar panel system designed to **track the sun**, **optimize energy collection**, and **manage power flow** between a battery and the grid. Based off of this project: https://www.instructables.com/Operating-a-Serial-Servo-Waveshare-Using-Arduino/

---

## 📌 Project Overview

**Solar-What** is a solar energy project that uses a servo motor to rotate a solar panel throughout the day, aligning it with optimal solar irradiation based on real-time or scheduled sun position data. The collected energy charges a battery and powers the system itself. If there is excess energy, it's sent to the grid through a micro-converter, with power flow monitored by an AC plug-in power sensor.

---

## 🧠 How It Works

1. **Sun Position Tracking**
   - A yet-to-be-determined API provides solar position data (azimuth/altitude).
   - The system calculates the desired orientation based on the current time and sun location.
   - A servo motor adjusts the panel’s angle accordingly.

2. **Energy Flow Management**
   - Solar energy charges a connected battery during daylight hours.
   - If the battery is full and excess energy is available, the system:
     - Activates the grid-tie output via a **micro inverter**.
     - Monitors power output using an **AC plug-in power meter**.
   - If there is not enough energy, power is retained to charge the battery and power the servo.

3. **Night Reset**
   - At sunset, the servo resets the panel to the morning position, preparing for the next day.

---

## 🔧 Hardware (WIP)

| Component              | Description                                      |
|------------------------|--------------------------------------------------|
| Solar Panel            | Primary energy source                           |
| Servo Motor            | Rotates the panel toward the sun                |
| Battery Pack           | Stores generated energy                         |
| Micro Inverter         | Sends excess energy to the grid                 |
| AC Power Monitor       | Monitors outgoing energy                        |
| Microcontroller (TBD)  | Manages logic, communication, and control flow |
| Sun Tracking API       | Provides sun angle data                         |

---

## 📊 Data Flow

```plaintext
[Sun API] ──> [Microcontroller] ──> [Servo Motor]
                              │
                              ├──> [Battery Charging]
                              ├──> [Battery Level Check]
                              ├──> [Excess Power?]
                              │       ├──> YES → [Grid Tie + Monitor]
                              │       └──> NO  → [Retain for System Power]
                              └──> [Nighttime Reset Trigger]
