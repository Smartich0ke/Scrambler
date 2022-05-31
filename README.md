# Arduino-powered cube scrambler

I go to a school where speed-cubing is popular and a no-phones policy is enforced during lunch break. This device consists of a cutom-designed PCB with a 128x64 OLED display and an ATMega328P chip and generates a random scramble algorithm speedcubing solves can be fair, consistent and retain a level of officiality without the need for a phone app to generate the scrambles.

## The PCB
The PCB is made up of 3 core components:

 * **The User Interface** - A 128x64 SSD1306 display to display the scrambles and 3 pushbuttons to navigate the screen's interface
 * **The microcontroller** - An ATmega328P chip to control everything
 * **The LiPo charge circuit** - A Microchip MCP73831 chip to charge a small lithium battery that powers the rest of the board. It is charged via a micro USB port.
