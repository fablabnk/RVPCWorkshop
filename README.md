# FabLab|NK Chaos Communication Congress (38C3) workshop for [OLIMEX RVPC](https://github.com/OLIMEX/RVPC) project

### Workshop includes
 - soldering the RVPC
 - creating a CH32V003 programmer using a Raspberry Pi Pico
 - writing a program for the RVPC
 - flashing the program to the RVPC

## About the RVPC project

The EURO 1.00 Risc-V personal computer with VGA and Keyboard and Woz like monitor. The purpose of this project is to make educational platform which people can use to learn RISCV assembler and experiment like in the old days in 1980s :)

<img src="DOCUMENTS/RVPC-1.jpg" height=200>

### Licensee
* Hardware is released under CERN Open Hardware Licence Version 2 - Strongly Reciprocal
* Software is released under GPL V3 Licensee
* Documentation is released under CC BY-SA 4.0

## Soldering the RVPC
For soldering RVPC follow the [User Manual](https://github.com/fablabnk/RVPCWorkshop/blob/main/DOCUMENTS/RVPC-user-manual.pdf), which includes billof materials, pcb layout and some instructions

# RVPC Build Guide

[Coming soon]

# Programming using Raspberry Pi Pico

You will need a Raspberry Pi with pin headers. We used a (Pico 1)[https://www.raspberrypi.com/documentation/microcontrollers/pico-series.html#pico-1-technical-specification]

## Wiring

- Connect Pico's SWIO pin (pin GP28, physical pin 34 on my Pico 1) to RVPC PGM pin 
- Connect a Pico GND pin to RVPC GND pin
- Power RVPC as normal by providing 5V on barrel jack connector (e.g. USB to barrel jack converter)

<img src="./IMAGES/pico_programmer.jpg" width="30%">

# Flashing

- download the picorvd .uf2 firmware from our repo [here](./PROGRAMMER/picorvd.uf2).
- NOTE: the original firmware can be found in the Actions tab of the original picorvd repo [here](https://github.com/aappleby/picorvd/actions). Click on the first entry in the list (for example) and scroll to the bottom of the page. However, recently when I checked there it was marked as 'expired'
- hold BOOTSEL whilst connecting Pico via USB to your PC
- drag .uf2 firmware onto drive that appears, wait for reboot
- check Pico is appearing on /dev/ttyACM0, if not adjust accordingly in ./flash.sh
- install dependencies:
`sudo apt-get install build-essential libnewlib-dev gcc-riscv64-unknown-elf libusb-1.0-0-dev libudev-dev gdb-multiarch`
- install python-venv module for platformio extension: `sudo apt install python3-venv`
- install Visual Studio Code as described [here](https://code.visualstudio.com/docs/setup/linux)
- install Platform IO extension for VS Code as described [here](https://platformio.org/install/ide?install=vscode)
- install CH32V-Platform as described [here](https://github.com/Community-PIO-CH32V/ch32-pio-projects?tab=readme-ov-file#installing-the-ch32v-platform)
- clone this repo somewhere on your system i.e. `git clone https://github.com/fablabnk/RVPCWorkshop.git`
- in VS Code, go to File -> Open Folder and navigate in the codebase to /RVPC/SOFTWARE/Demo-Tetris (or whichever example you prefer)
- click PlatformIO icon (alien/ant head) and under Project Tasks -> RVPC -> General, click the Build task
- back in the VS Code file explorer, firmware.elf should be found in ./pio/build/RVPC
- right click and choose 'open containing folder', then right click again in blank space and choose 'open in terminal'
- power cycle the RVPC
- power cycle the Pico
- flash from the terminal using the command: `gdb-multiarch -ex 'target extended-remote /dev/ttyACM0' -ex 'load' -ex 'detach' -ex 'quit' "firmware.elf"`

# Debugging the firmware:

 - (optionally) add initial breakpoint programmatically (usually at the start of the main function):
    ```
    #if defined(__riscv)
        __asm__ volatile("ebreak");
    #endif
    ```
 - make sure you have `gdb-multiarch` (see dependencies in **flashing** section)
 - connect Raspberry to RVPC, powercycle rvpc, then powercycle raspberry or connect it to the Laptop/PC
 - in terminal navigate to the project directory
 - connect to the debugger with either:
   - in the terminal: run the command `gdb-multiarch -ex 'target extended-remote /dev/ttyACM0'  ".pio/build/RVPC/firmware.elf"`
   - in vscode create a debugging setting (or just copy the [launch.json](./SOFTWARE/launch.json) to .vscode directory of the project) and hit F5
 - do debugging

# Writing some display code

[coming soon]
