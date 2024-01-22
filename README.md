# Traffic Light System
The project is a part of **Microprocessor Microcontroller Course (CO3009)**, which requires students to design and implement an embedded 4-way traffic light system with some specific functionalities using an STM32F103C6 microcontroller Board. This simple system introduced us to Finite Machine, Scheduler, and UART communication.

## Description
The **traffic controller** will be supported with the following functionalities:
- _Automatic:_ The system operates automatically with the lights on both sides of the traffic intersection automatically changing colors (green, yellow, red) according to the preset time.
- _Manual:_ The traffic controller can choose the allowed light color of the traffic lights. The lights will only change color when the traffic controller allows it.
- _Adjustment:_ Change the light duration of the Automatic mode with the increase/decrease mechanism by pressing the button (supports continuous automatic increase/decrease when pressed).

**Pedestrians** will be supported with the following functionality:
- _Request to cross:_ Alert for ordinary pedestrians, visually or hearing impaired individuals. When requesting to cross, the system will display the appropriate light color based on the traffic lights of the vehicles. At the same time, a sound alert will be issued to indicate that it is safe to cross or that the time to cross is almost up.

---
The detailed report (in Vietnamese) can be accessed: [here](https://github.com/amyranotamirror/CO3009_MiniProject/blob/main/doc/Report.pdf)
