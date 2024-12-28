# This is a demo project for RVPC workshop at 38C3

Checkout [FabLab|NK worksop](https://github.com/fablabnk/RVPCWorkshop) page for more info

Checkout [OLIMEX RVPC](https://github.com/OLIMEX/RVPC) project page

## Flashing

- download the picorvd .uf2 firmware from [fablabnk-rvpc](https://github.com/fablabnk/RVPCWorkshop/blob/main/PROGRAMMER/picorvd.uf2) project.
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
- clone this repo somewhere on your system 
- in VS Code, go to File -> Open Folder and navigate in the codebase to /Demo-Sound
- click PlatformIO icon (alien/ant head) and under Project Tasks -> Demo-Sound -> General, click the Build task (firmware.elf should be found in ./pio/build/Demo-Sound)
- power cycle the RVPC
- power cycle the Pico
- flash from the vscode terminal using the command: `gdb-multiarch -ex 'target extended-remote /dev/ttyACM0' -ex 'load' -ex 'detach' -ex 'quit' "./pio/build/Demo-Sound/firmware.elf"`

## Debugging

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
   - in vscode create a debugging setting (or just copy the [launch.json](./.vscode/launch.json) to .vscode directory of the project) and hit F5
 - do debugging
