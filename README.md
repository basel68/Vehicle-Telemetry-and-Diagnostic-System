# Vehicle Telemetry and Diagnostic System

## Overview
The Vehicle Telemetry and Diagnostic System is a comprehensive simulation framework designed to model a modern vehicle's telemetry and diagnostics capabilities. This project features an integrated suite of sensors including speed, temperature, and radar, alongside an adaptive cruise control system, using advanced C++ design patterns and principles.

## Features
- **Sensor Integration**: Includes multiple types of sensors like speed sensors, temperature sensors, and radar sensors.
- **Adaptive Cruise Control**: Simulates an adaptive cruise control system that dynamically adjusts vehicle speed based on radar sensor input.
- **Diagnostics**: Monitors and reports the status of various vehicle subsystems, aiding in rapid diagnosis and maintenance.
- **Event-Driven Architecture**: Utilizes the Observer design pattern to manage events and state changes across different system components.

## Getting Started

### Prerequisites
- C++17 compliant compiler (e.g., GCC, Clang)
- CMake 3.10 or higher
- Git for version control

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/basel68/Vehicle-Telemetry-and-Diagnostic-System.git
2. Navigate into the project directory:
   ```bash
   cd Vehicle-Telemetry-and-Diagnostic-System
3. Build the project using CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   make

4. Run
   ```bash
   ./vehicle


