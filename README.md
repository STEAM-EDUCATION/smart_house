# Smart House

## Overview

This project integrates various sensors to monitor environmental conditions such as motion, temperature, and light intensity. It uses an **IR sensor** to detect motion, a **DHT11 sensor** to measure temperature, and a **LDR** (Light Dependent Resistor) to measure light levels. The system provides visual feedback through **LEDs** (Red, Blue, and Green) based on sensor readings. The project can be used to create a basic environmental monitoring system that responds to changes in temperature, light, and motion.

---

## Components Used

- **Arduino Uno (or compatible Arduino board)**
- **IR Motion Sensor** (detects motion)
- **DHT11 Temperature and Humidity Sensor** (measures temperature)
- **LDR (Light Dependent Resistor)** (detects light intensity)
- **3 LEDs** (Red, Blue, Green for visual feedback)
- **Resistors** (for LED current limiting)
- **Breadboard and Jumper wires** (for connecting components)

---

## Pin Configuration

- **Red LED Pin (Pin 13)**: Turns on when motion is detected.
- **Blue LED Pin (Pin 12)**: Turns on when the temperature exceeds the threshold (30°C).
- **Green LED Pin (Pin 11)**: Turns on when it is dark (based on LDR reading).
- **IR Sensor Pin (Pin 3)**: Reads motion detection signals (LOW for motion detected).
- **DHT11 Pin (Pin 2)**: Reads temperature data from the DHT11 sensor.
- **LDR Pin (Analog Pin A0)**: Reads the ambient light intensity.

---

## Key Logic Breakdown

1. **Motion Detection**:
   - The system reads the **IR sensor** to detect motion. If the sensor reads LOW (motion detected), the **Red LED** is turned on.

2. **Temperature Monitoring**:
   - The **DHT11 sensor** measures the temperature, and the system compares it against a predefined threshold of 30°C.
   - If the temperature exceeds or equals the threshold, the **Blue LED** turns on, indicating high temperature.
   
3. **Light Intensity Detection**:
   - The **LDR** measures the ambient light. If the light intensity is low (dark), the **Green LED** is turned on.

4. **LED Indicators**:
   - **Red LED**: Turns on when motion is detected by the **IR sensor**.
   - **Blue LED**: Turns on if the temperature is above or equal to 30°C (threshold).
   - **Green LED**: Turns on when the light intensity is low (it’s dark).

---

## Circuit Diagram

1. **IR Motion Sensor**:
   - Connect the **OUT** pin of the IR sensor to **Pin 3** of the Arduino.
   - Connect the **VCC** and **GND** of the sensor to the **5V** and **GND** of the Arduino.

2. **DHT11 Temperature Sensor**:
   - Connect the **Data** pin of the DHT11 to **Pin 2** of the Arduino.
   - Connect the **VCC** and **GND** to the **5V** and **GND** pins of the Arduino.

3. **LDR**:
   - Connect the **LDR** to **Analog Pin A0** for light intensity readings.
   - Use a voltage divider circuit with a resistor to read analog values from the LDR.

4. **LEDs**:
   - Connect **Red LED** to **Pin 13**, **Blue LED** to **Pin 12**, and **Green LED** to **Pin 11** of the Arduino.
   - Use appropriate resistors (typically 220Ω) to limit the current for the LEDs.

---

## Code Overview

- **setup()**:
  - Initializes the serial communication for debugging.
  - Sets the pin modes for the LEDs, sensors, and other components.
  - Initializes the **DHT11 sensor**.

- **loop()**:
  - Continuously checks the **IR sensor** for motion:
    - If motion is detected, the **Red LED** is turned on.
    - If no motion is detected, the **Red LED** is turned off.
  - Reads the **temperature** from the **DHT11 sensor**:
    - If the temperature is above the threshold of 30°C, the **Blue LED** is turned on.
    - If the temperature is below the threshold, the **Blue LED** is turned off.
  - Reads the **LDR** value to check if it's dark:
    - If the light intensity is low (dark), the **Green LED** is turned on.
    - If there is sufficient light, the **Green LED** is turned off.
  - Displays the sensor readings on the **Serial Monitor** for debugging purposes.

---

## Operation Summary

1. **Motion Detection**:
   - The system detects motion using the **IR sensor**. When motion is detected, the **Red LED** turns on. If no motion is detected, the LED is off.

2. **Temperature Monitoring**:
   - The system reads the temperature from the **DHT11 sensor** and compares it to a predefined threshold (30°C). If the temperature exceeds or is equal to the threshold, the **Blue LED** turns on.

3. **Light Intensity**:
   - The **LDR** sensor is used to measure the ambient light. If the light intensity is low (indicating it's dark), the **Green LED** turns on.

---

## Troubleshooting

1. **No Motion Detection**:
   - Check the **IR sensor** connections. Ensure the sensor is powered correctly and the output is connected to **Pin 3**.
   - Verify that the sensor is not blocked by any obstacles.

2. **Incorrect Temperature Readings**:
   - Ensure the **DHT11** sensor is connected to the correct pin (Pin 2) and is properly powered.
   - The **DHT11** sensor can sometimes give errors if the connection is loose, so ensure solid connections.

3. **LEDs Not Lighting Up**:
   - Verify the **LED wiring** and ensure that the appropriate resistors are used for current limiting.
   - Check the **pin assignments** in the code to make sure the LEDs are connected to the correct pins on the Arduino.

4. **LDR Not Responding to Light**:
   - Check if the **LDR** is properly connected to **A0** and ensure the voltage divider circuit is set up correctly.
   - Ensure the light source is strong enough to affect the sensor.

---
