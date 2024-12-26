# Generate asm file from source

remove `-fverbose-asm` to remove comments
play with `-Ox` in range 0-3 to see intructions count difference, also try to replace it with `-gX` with x in range 0-3


riscv64-unknown-elf-g++ -I/Users/user/.platformio/packages/framework-wch-noneos-sdk/Peripheral/ch32v00x/inc -I/Users/user/.platformio/packages/framework-wch-noneos-sdk/Core/ch32v00x/ -I/Users/user/.platformio/packages/framework-wch-noneos-sdk/System/ch32v00x/ -march=rv32ec -mabi=ilp32e -S -fverbose-asm -O3 src/tmp.cpp -o tmp.s
