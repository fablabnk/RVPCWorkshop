#!/bin/bash
pico=$(ls /dev | grep ACM)

gdb-multiarch -ex "target extended-remote /dev/${pico}"  -ex 'load' -ex 'detach' -ex 'quit' ".pio/build/Demo-38C3/firmware.elf"
