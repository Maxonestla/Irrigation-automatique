# Irrigation-automatique
This project is an automatic irrigation for green wall using arduino.
It uses two moisture sensors, one on top of the wall to know when to open the solenoid valve and one on bottom to close the solenoid valve when the dirt is wet enough.

## Electrical circuit
I used Kicad to make the following electrical circuit.

![Alt text](schematic.png)
YL-69 are moisture sensors and the left part represent the 5V relay to activate solenoid valve.
YL-69 are resistive sensors, we measure the voltage at their terminals. The voltage is affected by the soil moisture.

The 5V relay used has a PNP transistor controlled by D2 pin. PNP resistors allow current to pass when the base is at a lower potential than the emitter. Therefore, we need to set D2 pin to a low level to activate the solenoid valve.