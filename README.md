# FabLab|NK workshop for [OLIMEX RVPC](https://github.com/OLIMEX/RVPC) project 

#### This repo contains submodules: 

#### To clone all at once use `git clone --recurse-submodules -j8 repolink`

#### To pull all changes including submodules use `git pull --recurse-submodules repolink`

### Workshop includes
 - soldering the rvpc
 - creating the flasher based on Arduino UNO
 - writing a program for the rvpc
 - flashing the program to the rvpc

## About the RVPC project

The EURO 1.00 Risc-V personal computer with VGA and Keyboard and Woz like monitor. The purpose of this project is to make educational platform which people can use to learn RISCV assembler and experiment like in the old days in 1980s :)

<img src="DOCUMENTS/RVPC-1.jpg" height=200>

### Licensee
* Hardware is released under CERN Open Hardware Licence Version 2 - Strongly Reciprocal
* Software is released under GPL V3 Licensee
* Documentation is released under CC BY-SA 4.0

## Soldering the RVPC
For soldering RVPC follow the [User Manual](https://github.com/fablabnk/RVPCWorkshop/blob/main/DOCUMENTS/RVPC-user-manual.pdf), which includes billof materials, pcb layout and some instructions

## Creating flasher for RVPC
As Arduino boards are easier to find and often times cheaper than olimex propriatary flasher device (based on ESP32), we decided to make an extra step and create our flasher based on them.
Arduino must be flashed with firmware from [BlueSyncLine arduino-ch32v003-swio](https://gitlab.com/BlueSyncLine/arduino-ch32v003-swio) project:
 - clone the project `git clone https://gitlab.com/BlueSyncLine/arduino-ch32v003-swio.git`
 - install required tools:
    - `sudo apt-get install avrdude`
    - `sudo apt-get install avr-gcc`
 - build the project:
    - `cd project/dir`
    - `make`
 - flash firmware to arduino:
    - connect arduino
    - in terminal check the name of arduino: `ls /dev/ | grep AMC` (should give sth like `ttyACM0`)
    - check whether the name of device (`ttyAMCx`) corresponds with the one in the `flash.sh` script located in the `project/dir`
    - then `chmod 755 flash.sh && ./flash.sh`
    - check whether flashin was succseefull by connecting to arduino using Arduino IDE and typing in serial monitor (115200 baudrate) `w` or `p` - it should return `!` or `+`
 - flash one of the prebuilt projects to the RVPC:
    - TBD

## Writing, Compiling and Flashing the program
 - write a program
 - compile the program: TBD
 - flashing the program - see previous paragraph
