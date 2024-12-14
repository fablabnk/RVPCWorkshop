## Building and flashing projects on macose might require a couple of packages to be installed

 - Install xcode from appstore or xcode command line tools with from terminal:`xcode-select --install`
 - Install homebrew:
    ```
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    ```
 - Add homebrew to the path by adding to `~/.zschrc` and `~/.basch_profile` the following:
    ```
    export PATH="$PATH:/opt/homebrew/bin"
    ```
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

### After installing Platformio extension for VSCode you may add it to `~/.zschrc` and `~/.basch_profile` as well:
    ```
    export PATH="$PATH:$HOME/.platformio/penv/bin"
    ```
