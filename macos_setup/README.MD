## Building and flashing projects on macose might require a couple of packages to be installed

 - Install xcode from appstore or xcode command line tools with from terminal:`xcode-select --install`
 - Check the following packages:
    ```
    Brew update
    brew install cmake
    brew tap riscv/riscv
    brew install riscv-tools
    brew install avrdude
    brew install avr-gcc
    brew install libusb
    brew autoremove
    brew install --cask gcc-arm-embedded
    ```
 - Check whether brewed bins are in the PATH and/or updaate your `~/.zschrc` and `~/.basch_profile` with:
    ```
    export PATH="$PATH:/opt/homebrew/bin"
    ```
