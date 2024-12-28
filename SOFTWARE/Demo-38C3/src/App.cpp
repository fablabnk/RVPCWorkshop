/* ***************************************************************************
MIT License

Copyright (c) 2024 k-off pacovali@student.42berlin.de

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*************************************************************************** */

#include "App.hpp"
#include "Buzzer.hpp"
#include "Charset.hpp"
#include "Delay.hpp"
#include "Keyboard.hpp"
#include "Sound.hpp"
#include "VGA.hpp"

// Add application logic here
void App::update_frame() {
	volatile char c = Keyboard::ascii(Keyboard::wait_any());
	// Buzzer::play(Sound::create(Note::C, 6, Len::_32));
	switch (c) {
		case 'Z':
		case 'z':
			Buzzer::play(Sound::create(Note::C, 5, Len::_32));
			break;
		case 'S':
		case 's':
			Buzzer::play(Sound::create(Note::Cis, 5, Len::_32));
			break;
		case 'X':
		case 'x':
			Buzzer::play(Sound::create(Note::D, 5, Len::_32));
			break;
		case 'D':
		case 'd':
			Buzzer::play(Sound::create(Note::Dis, 5, Len::_32));
			break;
		case 'C':
		case 'c':
			Buzzer::play(Sound::create(Note::E, 5, Len::_32));
			break;
		case 'V':
		case 'v':
			Buzzer::play(Sound::create(Note::F, 5, Len::_32));
			break;
		case 'G':
		case 'g':
			Buzzer::play(Sound::create(Note::Fis, 5, Len::_32));
			break;
		case 'B':
		case 'b':
			Buzzer::play(Sound::create(Note::G, 5, Len::_32));
			break;
		case 'H':
		case 'h':
			Buzzer::play(Sound::create(Note::Gis, 5, Len::_32));
			break;
		case 'N':
		case 'n':
			Buzzer::play(Sound::create(Note::A, 5, Len::_32));
			break;
		case 'J':
		case 'j':
			Buzzer::play(Sound::create(Note::Ais, 5, Len::_32));
			break;
		case 'K':
		case 'k':
			Buzzer::play(Sound::create(Note::B, 5, Len::_32));
			break;
		default:
			Buzzer::play(Sound::pause(Len::_32));
			break;
	}
}

/// @brief Prepares scanline to be displayed
void App::update_scanline(uint16_t line_idx) {
	// framebuf line index
	uint16_t fi = line_idx >> 3;
	// charset line index
	uint16_t ci = line_idx & 0b00000111;
	VGA::SL[0] = gC[framebuf[fi][0]][ci]; VGA::SL[1] = gC[framebuf[fi][1]][ci];
	VGA::SL[2] = gC[framebuf[fi][2]][ci]; VGA::SL[3] = gC[framebuf[fi][3]][ci];
	VGA::SL[4] = gC[framebuf[fi][4]][ci]; VGA::SL[5] = gC[framebuf[fi][5]][ci];
	VGA::SL[6] = gC[framebuf[fi][6]][ci]; VGA::SL[7] = gC[framebuf[fi][7]][ci];
	VGA::SL[8] = gC[framebuf[fi][8]][ci]; VGA::SL[9] = gC[framebuf[fi][9]][ci];
	VGA::SL[10] = gC[framebuf[fi][10]][ci]; VGA::SL[11] = gC[framebuf[fi][11]][ci];
	VGA::SL[12] = gC[framebuf[fi][12]][ci]; VGA::SL[13] = gC[framebuf[fi][13]][ci];
	VGA::SL[14] = gC[framebuf[fi][14]][ci]; VGA::SL[15] = gC[framebuf[fi][15]][ci];
	VGA::SL[16] = gC[framebuf[fi][16]][ci]; VGA::SL[17] = gC[framebuf[fi][17]][ci];
	VGA::SL[18] = gC[framebuf[fi][18]][ci]; VGA::SL[19] = gC[framebuf[fi][19]][ci];
	VGA::SL[20] = gC[framebuf[fi][20]][ci]; VGA::SL[21] = gC[framebuf[fi][21]][ci];
	VGA::SL[22] = gC[framebuf[fi][22]][ci]; VGA::SL[23] = gC[framebuf[fi][23]][ci];
	VGA::SL[24] = gC[framebuf[fi][24]][ci]; VGA::SL[25] = gC[framebuf[fi][25]][ci];
	VGA::SL[26] = gC[framebuf[fi][26]][ci]; VGA::SL[27] = gC[framebuf[fi][27]][ci];
}


void play_5th_symphony() {
			Buzzer::play(Sound::pause(Len::_8));
		Buzzer::play(Sound::create(Note::G, 4, Len::_8));
		Buzzer::play(Sound::create(Note::G, 4, Len::_8));
		Buzzer::play(Sound::create(Note::G, 4, Len::_8));
// ----
		Buzzer::play(Sound::create(Note::Es, 4, Len::_2));
// ----
		Buzzer::play(Sound::pause(Len::_8));
		Buzzer::play(Sound::create(Note::F, 4, Len::_8));
		Buzzer::play(Sound::create(Note::F, 4, Len::_8));
		Buzzer::play(Sound::create(Note::F, 4, Len::_8));
// ----
		Buzzer::play(Sound::create(Note::D, 4, Len::_2));
// ----
		Buzzer::play(Sound::pause(Len::_8));
		Buzzer::play(Sound::create(Note::G, 4, Len::_8));
		Buzzer::play(Sound::create(Note::G, 4, Len::_8));
		Buzzer::play(Sound::create(Note::G, 4, Len::_8));
// ----
		Buzzer::play(Sound::create(Note::Es, 4, Len::_8));
		Buzzer::play(Sound::create(Note::As, 4, Len::_8));
		Buzzer::play(Sound::create(Note::As, 4, Len::_8));
		Buzzer::play(Sound::create(Note::As, 4, Len::_8));
// ----
		Buzzer::play(Sound::create(Note::G, 4, Len::_8));
		Buzzer::play(Sound::create(Note::Es, 5, Len::_8));
		Buzzer::play(Sound::create(Note::Es, 5, Len::_8));
		Buzzer::play(Sound::create(Note::Es, 5, Len::_8));
// ----
		Buzzer::play(Sound::create(Note::C, 5, Len::_2));
// ----
		Buzzer::play(Sound::pause(Len::_8));
		Buzzer::play(Sound::create(Note::G, 4, Len::_8));
		Buzzer::play(Sound::create(Note::G, 4, Len::_8));
		Buzzer::play(Sound::create(Note::G, 4, Len::_8));
// ----
		Buzzer::play(Sound::create(Note::D, 4, Len::_8));
		Buzzer::play(Sound::create(Note::As, 4, Len::_8));
		Buzzer::play(Sound::create(Note::As, 4, Len::_8));
		Buzzer::play(Sound::create(Note::As, 4, Len::_8));
// ----
		Buzzer::play(Sound::create(Note::G, 4, Len::_8));
		Buzzer::play(Sound::create(Note::F, 5, Len::_8));
		Buzzer::play(Sound::create(Note::F, 5, Len::_8));
		Buzzer::play(Sound::create(Note::F, 5, Len::_8));
// ----
		Buzzer::play(Sound::create(Note::D, 5, Len::_2));
// ----
		Buzzer::play(Sound::pause(Len::_8));
		Buzzer::play(Sound::create(Note::G, 5, Len::_8));
		Buzzer::play(Sound::create(Note::G, 5, Len::_8));
		Buzzer::play(Sound::create(Note::F, 5, Len::_8));
// ----
		Buzzer::play(Sound::create(Note::Es, 5, Len::_2));
// ----
		Buzzer::play(Sound::pause(Len::_8));
		Buzzer::play(Sound::create(Note::G, 5, Len::_8));
		Buzzer::play(Sound::create(Note::G, 5, Len::_8));
		Buzzer::play(Sound::create(Note::F, 5, Len::_8));
// ----
		Buzzer::play(Sound::create(Note::Es, 5, Len::_2));
// ----
		Buzzer::play(Sound::pause(Len::_8));
		Buzzer::play(Sound::create(Note::G, 5, Len::_8));
		Buzzer::play(Sound::create(Note::G, 5, Len::_8));
		Buzzer::play(Sound::create(Note::F, 5, Len::_8));
// ----
		Buzzer::play(Sound::create(Note::Es, 5, Len::_8));
		Buzzer::play(Sound::pause(Len::_8));
		Buzzer::play(Sound::pause(Len::_4));
// ----
		Buzzer::play(Sound::create(Note::C, 5, Len::_8));
		Buzzer::play(Sound::pause(Len::_8));
		Buzzer::play(Sound::pause(Len::_4));
// ----
		Buzzer::play(Sound::create(Note::G, 5, Len::_2));
		Delay::ms(100);
};

