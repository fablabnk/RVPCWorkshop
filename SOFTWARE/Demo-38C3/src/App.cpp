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
	switch (c) {
		case 'Z':
		case 'z':
			Buzzer::play(Sound::create(Note::C5, Len::_32));
			break;
		case 'S':
		case 's':
			Buzzer::play(Sound::create(Note::Cis5, Len::_32));
			break;
		case 'X':
		case 'x':
			Buzzer::play(Sound::create(Note::D5, Len::_32));
			break;
		case 'D':
		case 'd':
			Buzzer::play(Sound::create(Note::Dis5, Len::_32));
			break;
		case 'C':
		case 'c':
			Buzzer::play(Sound::create(Note::E5, Len::_32));
			break;
		case 'V':
		case 'v':
			Buzzer::play(Sound::create(Note::F5, Len::_32));
			break;
		case 'G':
		case 'g':
			Buzzer::play(Sound::create(Note::Fis5, Len::_32));
			break;
		case 'B':
		case 'b':
			Buzzer::play(Sound::create(Note::G5, Len::_32));
			break;
		case 'H':
		case 'h':
			Buzzer::play(Sound::create(Note::Gis5, Len::_32));
			break;
		case 'N':
		case 'n':
			Buzzer::play(Sound::create(Note::A5, Len::_32));
			break;
		case 'J':
		case 'j':
			Buzzer::play(Sound::create(Note::Ais5, Len::_32));
			break;
		case 'K':
		case 'k':
			Buzzer::play(Sound::create(Note::B5, Len::_32));
			break;
		default:
			Buzzer::play(Sound::create(Note::Pause, Len::_32));
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

// non-blocking polyphony mode - uses horisontal synchronization interrupt set
// by VGA to update buzzer pin state at ~32kHz (depending on selected VGA mode)
std::array<Chord, 57> gMarioIntro {
	Chord({Note::D3, Note::Fis3, Note::E5}, Len::_16),
	Chord({}, Len::_16), // pause
	Chord({Note::D3, Note::Fis3, Note::E5}, Len::_16),
	Chord({}, Len::_16), // pause
	Chord({}, Len::_8), // pause
	Chord({Note::D3, Note::Fis3, Note::E5}, Len::_16),
	Chord({}, Len::_16), // pause
	Chord({}, Len::_8), // pause
	Chord({Note::D3, Note::Fis3, Note::C5}, Len::_16),
	Chord({}, Len::_16), // pause
	Chord({Note::D3, Note::Fis3, Note::E5}, Len::_16),
	Chord({}, Len::_16), // pause
	Chord({}, Len::_8), // pause
	// ========
	Chord({Note::G3, Note::B3, Note::G5}, Len::_16),
	Chord({}, Len::_16), // pause
	Chord({}, Len::_8), // pause
	Chord({}, Len::_4), // pause
	Chord({Note::D3, Note::G3, Note::G4}, Len::_16),
	Chord({}, Len::_16), // pause
	Chord({}, Len::_8), // pause
	Chord({}, Len::_4), // pause
	// ========
	Chord({Note::G3, Note::G4, Note::C5}, Len::_16),
	Chord({}, Len::_16), // pause
	Chord({}, Len::_8), // pause
	Chord({}, Len::_8), // pause
	Chord({Note::E3, Note::E4, Note::G4}, Len::_16),
	Chord({}, Len::_16), // pause
	Chord({}, Len::_4), // pause
	Chord({Note::C3, Note::C4, Note::E4}, Len::_16),
	Chord({}, Len::_16), // pause
	Chord({}, Len::_8), // pause
	// ========
	Chord({}, Len::_8), // pause
	Chord({Note::F3, Note::C4, Note::A4}, Len::_4),
	Chord({Note::G3, Note::D4, Note::B4}, Len::_4),
	Chord({Note::Ges3, Note::Des4, Note::Bes4}, Len::_8),
	Chord({Note::F3, Note::C4, Note::A4}, Len::_4),
	// ========
	Chord({Note::E3, Note::E4, Note::G4}, Len::_16),
	Chord({}, Len::_16), // pause
	Chord({}, Len::_8), // pause
	Chord({Note::C4, Note::C5, Note::E5}, Len::_16),
	Chord({}, Len::_16), // pause
	Chord({}, Len::_8), // pause
	Chord({Note::E4, Note::E5, Note::G5}, Len::_16),
	Chord({}, Len::_16), // pause
	Chord({}, Len::_8), // pause
	Chord({Note::F4, Note::F5, Note::A5}, Len::_16),
	Chord({}, Len::_16), // pause
	Chord({}, Len::_8), // pause
	Chord({Note::D4, Note::D5, Note::F5}, Len::_8),
	Chord({Note::E4, Note::E5, Note::G5}, Len::_16),
	Chord({}, Len::_16), // pause
	// ========
	Chord({}, Len::_8), // pause
	Chord({Note::C4, Note::G4, Note::E5}, Len::_4),
	Chord({Note::G3, Note::E4, Note::C5}, Len::_8),
	Chord({Note::B3, Note::F4, Note::D5}, Len::_8),
	Chord({Note::G3, Note::D4, Note::G4}, Len::_4),
	Chord({Note::G3, Note::D4, Note::G4}, Len::_8)
};

// // blocking way of playing sounds: nothing else can be done while a sound is played
// void gFifthSym() {
// 		Buzzer::play(Sound::create(Note::Pause, Len::_8));
// 		Buzzer::play(Sound::create(Note::G4, Len::_8));
// 		Buzzer::play(Sound::create(Note::G4, Len::_8));
// 		Buzzer::play(Sound::create(Note::G4, Len::_8));
// // ----
// 		Buzzer::play(Sound::create(Note::Es4, Len::_2));
// // ----
// 		Buzzer::play(Sound::create(Note::Pause, Len::_8));
// 		Buzzer::play(Sound::create(Note::F4, Len::_8));
// 		Buzzer::play(Sound::create(Note::F4, Len::_8));
// 		Buzzer::play(Sound::create(Note::F4, Len::_8));
// // ----
// 		Buzzer::play(Sound::create(Note::D4, Len::_2));
// // ----
// 		Buzzer::play(Sound::create(Note::Pause, Len::_8));
// 		Buzzer::play(Sound::create(Note::G4, Len::_8));
// 		Buzzer::play(Sound::create(Note::G4, Len::_8));
// 		Buzzer::play(Sound::create(Note::G4, Len::_8));
// // ----
// 		Buzzer::play(Sound::create(Note::Es4, Len::_8));
// 		Buzzer::play(Sound::create(Note::As4, Len::_8));
// 		Buzzer::play(Sound::create(Note::As4, Len::_8));
// 		Buzzer::play(Sound::create(Note::As4, Len::_8));
// // ----
// 		Buzzer::play(Sound::create(Note::G4, Len::_8));
// 		Buzzer::play(Sound::create(Note::Es5, Len::_8));
// 		Buzzer::play(Sound::create(Note::Es5, Len::_8));
// 		Buzzer::play(Sound::create(Note::Es5, Len::_8));
// // ----
// 		Buzzer::play(Sound::create(Note::C5, Len::_2));
// // ----
// 		Buzzer::play(Sound::create(Note::Pause, Len::_8));
// 		Buzzer::play(Sound::create(Note::G4, Len::_8));
// 		Buzzer::play(Sound::create(Note::G4, Len::_8));
// 		Buzzer::play(Sound::create(Note::G4, Len::_8));
// // ----
// 		Buzzer::play(Sound::create(Note::D4, Len::_8));
// 		Buzzer::play(Sound::create(Note::As4, Len::_8));
// 		Buzzer::play(Sound::create(Note::As4, Len::_8));
// 		Buzzer::play(Sound::create(Note::As4, Len::_8));
// // ----
// 		Buzzer::play(Sound::create(Note::G4, Len::_8));
// 		Buzzer::play(Sound::create(Note::F5, Len::_8));
// 		Buzzer::play(Sound::create(Note::F5, Len::_8));
// 		Buzzer::play(Sound::create(Note::F5, Len::_8));
// // ----
// 		Buzzer::play(Sound::create(Note::D5, Len::_2));
// // ----
// 		Buzzer::play(Sound::create(Note::Pause, Len::_8));
// 		Buzzer::play(Sound::create(Note::G5, Len::_8));
// 		Buzzer::play(Sound::create(Note::G5, Len::_8));
// 		Buzzer::play(Sound::create(Note::F5, Len::_8));
// // ----
// 		Buzzer::play(Sound::create(Note::Es5, Len::_2));
// // ----
// 		Buzzer::play(Sound::create(Note::Pause, Len::_8));
// 		Buzzer::play(Sound::create(Note::G5, Len::_8));
// 		Buzzer::play(Sound::create(Note::G5, Len::_8));
// 		Buzzer::play(Sound::create(Note::F5, Len::_8));
// // ----
// 		Buzzer::play(Sound::create(Note::Es5, Len::_2));
// // ----
// 		Buzzer::play(Sound::create(Note::Pause, Len::_8));
// 		Buzzer::play(Sound::create(Note::G5, Len::_8));
// 		Buzzer::play(Sound::create(Note::G5, Len::_8));
// 		Buzzer::play(Sound::create(Note::F5, Len::_8));
// // ----
// 		Buzzer::play(Sound::create(Note::Es5, Len::_8));
// 		Buzzer::play(Sound::create(Note::Pause, Len::_8));
// 		Buzzer::play(Sound::create(Note::Pause, Len::_4));
// // ----
// 		Buzzer::play(Sound::create(Note::C5, Len::_8));
// 		Buzzer::play(Sound::create(Note::Pause, Len::_8));
// 		Buzzer::play(Sound::create(Note::Pause, Len::_4));
// // ----
// 		Buzzer::play(Sound::create(Note::G5, Len::_2));
// };

