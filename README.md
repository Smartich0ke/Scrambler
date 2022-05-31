# Arduino-powered cube scrambler

I go to a school where speed-cubing is popular and a no-phones policy is enforced during lunch break. This device consists of a cutom-designed PCB with a 128x64 OLED display and an ATMega328P chip and generates a random scramble algorithm speedcubing solves can be fair, consistent and retain a level of officiality without the need for a phone app to generate the scrambles.

## The PCB
The PCB is made up of 3 core components:

 * **The user interface** - A 128x64 SSD1306 display to display the scrambles and 3 pushbuttons to navigate the screen's interface
 * **The microcontroller** - An ATmega328P chip to control everything
 * **The LiPo charge circuit** - A Microchip MCP73831 chip to charge a small lithium battery that powers the rest of the board. It is charged via a micro USB port.

The PCB was designed in KiCad. You can find the KiCad files in `pcb/kicad`. You can also find pre-made Gerber files in `pcb/gerbers` for production.

## The code

The code is written using the Arduino framework and the Adafruit SSD1306 library. A `platformio.ini` file is provided for use in PlatformIO and is the reccomended way ot compile and upload the code to this device.

## How to make a scrambler

### A. Make/assemble the board

#### Bill Of Materials (BOM):
 * X1 ATmega328P
 * X1 128x64 OLED display
 * X1 MCP73831
 * X2 10uF electrolytic capacitors
 * X2 4.7uF electrolytic cpacitors
 * X3 6mm pushbutton switches
 * X1 Digikey Micro USB type B connector

 1. Download the necesarry files: `git clone https://github.com/Smartich0ke/Scrambler.git`
 2. Open up the KiCad project in `pcb/kicad/scrambler.kicad_pro`. Open the PCB layout editor and export the necesarry gerbers and adjust the settings in the export window depending on your PCB manufacturer.
 3. Send the files to your PCB manufacturer and get it made.
 4.  4. Solder in the components into their corresponding places according to the BOM above.

### B. Compile and upload the code
 1. Open the root directory of the git repo in PlatformIO VScode extention
 2. In the PlatformIO Tasks menu, double-click "build" under upload_USBTINY
### C. 3D-print the case
*coming soon*

