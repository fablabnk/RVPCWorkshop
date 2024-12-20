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

#pragma once

#include <array>
#include <cstdint>

/// @brief Sound to be played
struct CSound {
	uint16_t t;     // duration of the sound
	uint32_t f;     // frequency multiplied by 1000
	uint32_t hp;    // half-period of oscilation
};

/// @brief Note lengths human readable
enum class Note {
	// bemol            diese
	Ces=11,     C=0,    Cis=1,  // Do
	Des=1,      D=2,    Dis=3,  // Re
	Es=3,       E=4,    Eis=5,  // Mi
	Fes=4,      F=5,    Fis=6,  // Fa
	Ges=6,      G=7,    Gis=8,  // Sol
	As=8,       A=9,    Ais=10, // La
	Bes=10,     B=11,   Bis=0   // Si
};

/// @brief Note lengths human readable
enum class Len {x2=0, x1, _2, _4, _8, _16, _32};

class Sound {
private:
	// All note frequencies for octaves 0-7, multiplied by 1000 to avoid floats
	// Access: gNoteFrequency1000[Note::C][octave]
	static constexpr const uint32_t frequency1000[12][8] {
		{ 32703/2, 32703*1, 32703*2, 32703*4, 32703*8, 32703*16, 32703*32, 32703*64 },
		{ 34648/2, 34648*1, 34648*2, 34648*4, 34648*8, 34648*16, 34648*32, 34648*64 },
		{ 36708/2, 36708*1, 36708*2, 36708*4, 36708*8, 36708*16, 36708*32, 36708*64 },
		{ 38891/2, 38891*1, 38891*2, 38891*4, 38891*8, 38891*16, 38891*32, 38891*64 },
		{ 41203/2, 41203*1, 41203*2, 41203*4, 41203*8, 41203*16, 41203*32, 41203*64 },
		{ 43654/2, 43654*1, 43654*2, 43654*4, 43654*8, 43654*16, 43654*32, 43654*64 },
		{ 46249/2, 46249*1, 46249*2, 46249*4, 46249*8, 46249*16, 46249*32, 46249*64 },
		{ 48999/2, 48999*1, 48999*2, 48999*4, 48999*8, 48999*16, 48999*32, 48999*64 },
		{ 51913/2, 51913*1, 51913*2, 51913*4, 51913*8, 51913*16, 51913*32, 51913*64 },
		{ 55000/2, 55000*1, 55000*2, 55000*4, 55000*8, 55000*16, 55000*32, 55000*64 },
		{ 58270/2, 58270*1, 58270*2, 58270*4, 58270*8, 58270*16, 58270*32, 58270*64 },
		{ 61735/2, 61735*1, 61735*2, 61735*4, 61735*8, 61735*16, 61735*32, 61735*64 }
	};

	// All note half-periods in microseconds for octaves 0-7
	// use: gNoteHalfPeriodUs[Note::C][octave]
	static constexpr const uint32_t halfPeriodUs[12][8] {
		{ 30580/1, 30580/2, 30580/4, 30580/8, 30580/16, 30580/32, 30580/64, 30580/128 },
		{ 28860/1, 28860/2, 28860/4, 28860/8, 28860/16, 28860/32, 28860/64, 28860/128 },
		{ 27240/1, 27240/2, 27240/4, 27240/8, 27240/16, 27240/32, 27240/64, 27240/128 },
		{ 25710/1, 25710/2, 25710/4, 25710/8, 25710/16, 25710/32, 25710/64, 25710/128 },
		{ 24270/1, 24270/2, 24270/4, 24270/8, 24270/16, 24270/32, 24270/64, 24270/128 },
		{ 22910/1, 22910/2, 22910/4, 22910/8, 22910/16, 22910/32, 22910/64, 22910/128 },
		{ 21620/1, 21620/2, 21620/4, 21620/8, 21620/16, 21620/32, 21620/64, 21620/128 },
		{ 20410/1, 20410/2, 20410/4, 20410/8, 20410/16, 20410/32, 20410/64, 20410/128 },
		{ 19260/1, 19260/2, 19260/4, 19260/8, 19260/16, 19260/32, 19260/64, 19260/128 },
		{ 18180/1, 18180/2, 18180/4, 18180/8, 18180/16, 18180/32, 18180/64, 18180/128 },
		{ 17160/1, 17160/2, 17160/4, 17160/8, 17160/16, 17160/32, 17160/64, 17160/128 },
		{ 16200/1, 16200/2, 16200/4, 16200/8, 16200/16, 16200/32, 16200/64, 16200/128 }
	};

	// Standardized note lengths in milliseconds, use: LengthMs[Len::_4]
	static constexpr const uint16_t LengthMs[7] {
		1 << 11, 1 << 10, 1 << 9, 1 << 8, 1 << 7, 1 << 6, 1 << 5
	};

public:

	static CSound create(Note note, uint8_t octave, Len duration) {
		return {
			LengthMs[uint8_t(duration)],
			frequency1000[uint8_t(note)][octave],
			halfPeriodUs[uint8_t(note)][octave]
		};
	}

	static CSound pause(Len duration) {
		return { LengthMs[uint8_t(duration)], 0, 1'000'000u };
	}
};
