# Code guide

This part will focus on code of Demo-Tetris. It has most of the features in one place - VGA output, sound (buzzer) output, keyboard input.

The tetris demo is a complete application ready to be built and flashed on the pc.

## Demo directory structure

The demo directory contains a couple of direcotries, line include, lib test, src. Our focus is on src folder as all code stays there. 

### SRC

Short description of the file contents:

 - `chardefs.h` contains definitions for all ascii characters A-Z, 0-9, punctuation, special ones - in the form that is ready to be displayed on monitor. One can modify how characters look in this file. A single character is 8x8 pixels and for 'A' looks like:
  ```
  0b01111100
  0b11000110
  0b11000110
  0b11111110
  0b11000110
  0b11000110
  0b11000110
  0b00000000
  ```
It's basically represented by 8 `uint8_t` (or basically `byte`) values and is shown in binary form for better visibility. One can replace `0b11111110` with 254 with the dame effect.

 - 'keyboard.h' and 'keyboard.c' contain keyboard logic - handling keypresses, converting keycodes to characters. Function `kbd_read()` gets **keykode** value from the last keystroke. `kbd_wait()` is basically a loop which keeps running until a key on keyboard is either pressed or released. `kbd_wait_press()` and `kbd_wait_release()` have the same puyrpose but only wait for one of the two events. `kbd_to_ascii()` converts keykode provided by `kbd_read()` into the actual character. The keyboard  files also contain two **functions for the buzzer** manipulation: `buzz_ok()` - for a predefined 'ok' sound and `buzz()`, which can produce a sound of user choice.

 - `main.c` contains the main application loop:

   ```
   while(1) { // infinite
    // 1. handle keyboard events
    // 2. update screen
   }
   ```

 - `misc.h` and `misc.c` contain helper function to set up hardware itself - GPIO pins, timers, interrupts, PWM.

 - `vga.h` and `vga.c` contain  among others functions that put information onto the display (`vga_write_at()` and `vga_print_at()`) and to check which information is currently in the display buffer (`vga_char_at()`).

 - `wait.h` and `wait.c` contain functions that help to schedule/delay certain events. `Wait_Us()` and `Wait_Ms()` delay execution by `n` micro- or milliseconds. Combination of `setTimeout_Ms()` and `isTimeout_Ms()` allows to execute a portion of code for a defined period of time, as follows:
```
setTimeout_Ms(100);
while (isTimeout_Ms() == false) {
// code
}
```

### tetris.c - main application logic

`run_keyboard_state_machine()` calls corresponding functions depending on the key pressed. One may add or remove different keys bindings for existing functions, add new functions to the existing keys or both. One can find keykodes in the `kbd_to_ascii()` function of `keyboard.c` file.

`run_app_state_machine()` among other is responsible for speed of updates ie difficulty level, with delays. It creates a temporary copy of the current figure and moves it one block down and checks it for collision against frame borders and previous figures.
