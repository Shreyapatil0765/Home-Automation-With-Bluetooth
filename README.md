# Home-Automation-With-Bluetooth
Company: CODTECH IT SOLUTIONS

NAME: SHREYA PATIL

INTERN ID: CT04DF2846

DOMAIN: EMBEDDED SYSTEMS

DURATION: 4 WEEKS

MENTOR: NEELA SANTOSH

This project presents a Bluetooth Controlled Home Automation System that enables wireless switching of electrical appliances using a smartphone. The control system is based on an Arduino Uno microcontroller interfaced with a Bluetooth module (HC-05), relay switches, and support components like transistors and flyback diodes. It also includes manual push button control for added reliability. The system is designed to be low-cost, user-friendly, and suitable for short-range domestic automation.

Components Used :
Arduino Uno – Acts as the central controller that processes input and controls outputs.

HC-05 Bluetooth Module – Establishes serial wireless communication with a smartphone.

Relay Module (2 SPDT Relays) – Switches the AC appliances on or off.

NPN Transistors (2N2222) – Amplify the low-current Arduino signals to drive the relays.

Flyback Diodes (e.g., 1N4007) – Protect the circuit from voltage spikes caused by switching.

Resistors (1kΩ) – Limit base current to transistors.

Push Buttons – Allow manual control of the appliances.

Lamps (AC Loads) & DC Motor – Represent the appliances being switched.

Power Supply (5V for Arduino, 12V for relays and dc motor, AC voltage source for lamp) – Provides the required operating voltages.

Circuit Explanation :
The Arduino Uno receives control characters through the HC-05 Bluetooth module. Based on the received command, the Arduino triggers its digital pins to turn a relay on or off. Since relays require more current than the Arduino can supply, transistors (2N2222) are used as switches. When the Arduino sends a HIGH signal to the transistor’s base via a 1kΩ resistor, the transistor conducts, completing the circuit for the relay coil and energizing it.
When energized, the SPDT relay switches its common (COM) terminal from Normally Closed (NC) to Normally Open (NO), allowing current to flow to the appliance (lamp). Once the relay is turned off, it returns to the NC position.
Flyback diodes are placed in reverse bias across each relay coil to suppress the voltage spike generated when the relay is turned off. This protects the Arduino and transistors from potential damage due to back EMF.
The manual push buttons are connected to digital input pins of the Arduino. They provide a local control option — pressing them sends a signal to the Arduino to toggle the corresponding relay. This dual-control approach ensures the system can be used even if the Bluetooth connection fails.

Simulation Software Used :
The system was designed and tested using Proteus 8 Professional. As the default libraries did not include HC-05 or Arduino models, external libraries were imported. Proteus allowed visual confirmation of relay switching, transistor behavior, and communication flow, making it an ideal platform for testing the logic before physical implementation.

Challenges Faced :
1. Relay Triggering Errors: Incorrect base resistor values for the transistors caused unreliable switching initially. This was resolved by proper transistor biasing.
2. Back EMF Issues: Relay coil switching generated voltage spikes that were damaging components. The issue was resolved by introducing flyback diodes across each coil.

Conclusion :
The circuit successfully demonstrates a basic home automation concept using Bluetooth technology and simple electronic components. The inclusion of manual buttons, proper switching using transistors, and protective diodes makes the system safe and reliable. It serves as a scalable prototype for more advanced smart home solutions.

