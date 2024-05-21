# MSP430x2xx-C-Based-State-Machine-for-LED-Control-Lab-1
Welcome to my GitHub repository showcasing an embedded system programmed in C, centered around a finite state machine (FSM). This project is designed specifically for MSP430x2xx microcontrollers and focuses on controlling LEDs through state-driven logic to demonstrate efficient and modular code architecture.

# Features
Modular Design: Organized into layers - Application (APP), Board Support Package (BSP), Hardware Abstraction Layer (HAL), and Application Programming Interface (API).

Finite State Machine (FSM): Manages system states and transitions to handle various operational modes effectively.

LED Control: Uses GPIOs to manipulate LEDs based on system state, demonstrating direct hardware control in a low-level embedded environment.

Low Power Management: Implements various system modes for power optimization, essential for embedded applications.

# FSM States and Operations
This project employs an FSM with several states, each designed for specific roles:

state0 (Idle State): The default state after reset where the system awaits user input or an event to transition.

state1 to state4: Represent operational modes such as reading inputs, adjusting settings, managing outputs, and handling system alerts or errors.

Transitions between states are triggered by events or conditions, ensuring predictable and responsive system behavior.

# Interrupt Handling
Interrupts are managed efficiently to ensure that urgent hardware events are addressed promptly without significant delay, enhancing the system's real-time capabilities.

# Project Structure
api.h & api.c: Define interface functions for hardware interaction.

app.h: Declares FSM states and system modes.

bsp.h & bsp.c: Hardware-specific configurations for the MSP430x2xx.

halGPIO.h & halGPIO.c: Interface functions for direct GPIO manipulation.

main.c: The main executable with initial system setup and operational loop.

# Getting Started
To run and modify this project:

1. Set up your MSP430 development environment.
2. Clone this repository.
3. Navigate to the project directory.
4. Compile the code using an MSP430 compiler like MSPGCC.
5. Flash the compiled binary to your MSP430 device.
