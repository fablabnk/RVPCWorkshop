#pragma once

#include <array>
#include <cstdint>
#include <bitset>
#include <ch32v00x.h>
#include "Delay.hpp"

class App {
private:
	enum class State: uint8_t {Pause, Run};
	static inline State state {State::Run};
	static inline std::array<uint8_t, 40*30> framebuf {"Hello world!"};	// frame buffer for 320*240 resolution
public:

	App() = delete;

	/// @brief Prepares scanline to be displayed
	static void update_scanline();

	/// @brief Prepares next frame. Contains main application logic
	static void update_frame();
	
	/// @brief Infinite main loop
	static inline void run() {
		while (1)  {
			if (state == State::Run) {
				update_frame();
			}
		}
	}

	static inline void toggle_pause() {
		if (state == State::Run)
			state = State::Pause;
		else
			state = State::Run;
	}
};