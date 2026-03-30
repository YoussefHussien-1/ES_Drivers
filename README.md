# STM32F103x Bare-Metal Peripheral Drivers & Navigation HAL

## 📌 Project Overview

This repository contains a modular, register-level **MCAL (Microcontroller Abstraction Layer)** and **HAL (Hardware Abstraction Layer)** for the STM32F103x (ARM Cortex-M3) microcontroller. The drivers are developed from scratch without using HAL/LL libraries to ensure deep understanding of hardware-software interfacing and optimal memory footprint.

## 🏗️ Architecture

The project follows a **Layered Software Architecture**:

1.  **MCAL Layer:** Direct register access (GPIO, UART, SysTick, RCC).
2.  **HAL Layer:** Hardware-independent logic (GPS NMEA Parser).
3.  **App Layer:** Main application logic (Avionics & Navigation).

-----

## 🛠️ Implemented Drivers

### 1\. MCAL Layer

  * **RCC (Reset and Clock Control):** Manages system clock and peripheral clock gating.
  * **GPIO (General Purpose Input/Output):** Configures pins for Input, Output (Push-pull/Open-drain), and Alternate Functions.
  * **UART (Universal Asynchronous Receiver/Transmitter):** \* Full-duplex asynchronous communication.
      * Polling-based transmission and reception.
      * Configurable Baud Rate (BRR calculation).
  * **SysTick Timer:** Precise delay generation and time-base management.

### 2\. HAL Layer

  * **GPS NMEA Parser:** \* Interfaced via UART.
      * Extracts **Altitude, Latitude, and Longitude** from `$GPGGA` sentences.
      * High-precision string-to-float conversion (using `atof` logic).

-----

## 🚀 Key Features

  * **Bare-Metal Development:** No reliance on ST's Standard Peripheral Libraries or HAL.
  * **Modular Design:** Each driver has a separate `interface.h`, `private.h`, `config.h`, and `program.c`.
  * **Memory Optimized:** Low RAM and Flash consumption.
  * **Documentation:** Fully commented code following clear naming conventions.

-----

## 💻 Simulation & Testing

The firmware was validated using:

  * **Wokwi:** For real-time UART and peripheral simulation.
  * **Proteus:** For logic verification and timing analysis.
  * **ANSI Escape Codes:** Implemented a custom Serial Dashboard to visualize GPS data in the terminal.

-----

## 📂 File Structure

```text
├── MCAL
│   ├── GPIO
│   ├── UART
│   ├── SysTick
│   └── RCC
├── HAL
│   └── GPS_Parser
├── LIB
│   ├── BIT_MATH.h
│   └── STD_TYPES.h
└── APP
    └── main.c
```

-----

## 👨‍💻 Author

**Youssef**

  * Computer Science Student at Nile University.
  * Interested in Avionics, Embedded Systems, and Flight Control.
  * [LinkedIn Profile] | https://www.linkedin.com/in/youssef-hussein-bb4730350/

-----

