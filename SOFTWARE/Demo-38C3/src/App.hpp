#pragma once

#include <array>
#include <cstdint>
#include <bitset>
#include <ch32v00x.h>
#include "Delay.hpp"
#include "VGA.hpp"

class App {
private:
	enum class State: uint8_t {Pause, Run};
	static inline State state {State::Run};
	static inline std::array<std::array<uint8_t, VGA::SL.size()>, 23u> framebuf {
		std::array<uint8_t, VGA::SL.size()>{},
		{},
		{"      DIY 1$ PC WORKSHOP   "},
		{},
		{},
		{"        SUNDAY 16:30       "},
		{},
		{"   HARDAWARE HACKING AREA  "},
		{},
		{},
		{"          42 BERLIN        "},
		{},
		{"          FABLAB|NK        "},
		{},
		{},
		{},
		{"    GiTHUB.COM/FABLABNK    "},
		};
public:

	App() = delete;

	/// @brief Prepares scanline to be displayed
	/// @param line_idx index of the line
	static void update_scanline(uint16_t line_idx);

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