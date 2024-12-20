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

#include "Keyboard.hpp"
#include "Buzzer.hpp"
#include "Delay.hpp"
#include "Sound.hpp"

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

void loop() {
	while (1) {
		char c = Keyboard::read_printable();
		switch (c) {
			case 'Z':
			case 'z':
				Buzzer::play(Sound::create(Note::C, 3, Len::_32));
				break;
			case 'S':
			case 's':
				Buzzer::play(Sound::create(Note::Cis, 3, Len::_32));
				break;
			case 'X':
			case 'x':
				Buzzer::play(Sound::create(Note::D, 3, Len::_32));
				break;
			case 'D':
			case 'd':
				Buzzer::play(Sound::create(Note::Dis, 3, Len::_32));
				break;
			case 'C':
			case 'c':
				Buzzer::play(Sound::create(Note::E, 3, Len::_32));
				break;
			case 'V':
			case 'v':
				Buzzer::play(Sound::create(Note::F, 3, Len::_32));
				break;
			case 'G':
			case 'g':
				Buzzer::play(Sound::create(Note::Fis, 3, Len::_32));
				break;
			case 'B':
			case 'b':
				Buzzer::play(Sound::create(Note::G, 3, Len::_32));
				break;
			case 'H':
			case 'h':
				Buzzer::play(Sound::create(Note::Gis, 3, Len::_32));
				break;
			case 'N':
			case 'n':
				Buzzer::play(Sound::create(Note::A, 3, Len::_32));
				break;
			case 'J':
			case 'j':
				Buzzer::play(Sound::create(Note::Ais, 3, Len::_32));
				break;
			case 'K':
			case 'k':
				Buzzer::play(Sound::create(Note::B, 3, Len::_32));
				break;
			default:
				Buzzer::play(Sound::pause(Len::_32));
				break;
		}
	}
}
