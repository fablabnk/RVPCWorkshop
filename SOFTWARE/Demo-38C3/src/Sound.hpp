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
#include <utility>

#include "Delay.hpp"


/// @brief Note lengths human readable
enum class Len {x2=0, x1, _2, _4, _8, _16, _32, _64};

/// @brief Sound to be played
struct CSound {
	uint16_t t;		// duration of the sound
	uint32_t f;		// frequency multiplied by 1000
	uint32_t hps;	// half-period of oscilation in microseconds
};

/// @brief Note lengths human readable
enum class Note : uint8_t {
	Pause=0, // pause required for chords, 0-value is convenient in array init
	// bemol						diese
	Ces0=0u,		C0=1u,  		Cis0=2u,		//	Do 0
	Des0=2u,		D0=3u,  		Dis0=4u,		//	Re 0
	Es0=4u,			E0=5u,  		Eis0=6u,		//	Mi 0
	Fes0=5u,		F0=6u,  		Fis0=7u,		//	Fa 0
	Ges0=7u,		G0=8u,  		Gis0=9u,		//	Sol 0
	As0=9u,			A0=10u,  		Ais0=11u,		//	La 0
	Bes0=11u,		B0=12u,  		Bis0=13u,		//	Si 0
	Ces1=12u,		C1=13u,  		Cis1=14u,		//	Do 1
	Des1=14u,		D1=15u,  		Dis1=16u,		//	Re 1
	Es1=16u,		E1=17u,  		Eis1=18u,		//	Mi 1
	Fes1=17u,		F1=18u,  		Fis1=19u,		//	Fa 1
	Ges1=19u,		G1=20u,  		Gis1=21u,		//	Sol 1
	As1=21u,		A1=22u,  		Ais1=23u,		//	La 1
	Bes1=23u,		B1=24u,  		Bis1=25u,		//	Si 1
	Ces2=24u,		C2=25u,  		Cis2=26u,		//	Do 2
	Des2=26u,		D2=27u,  		Dis2=28u,		//	Re 2
	Es2=28u,		E2=29u,  		Eis2=30u,		//	Mi 2
	Fes2=29u,		F2=30u,  		Fis2=31u,		//	Fa 2
	Ges2=31u,		G2=32u,  		Gis2=33u,		//	Sol 2
	As2=33u,		A2=34u,  		Ais2=35u,		//	La 2
	Bes2=35u,		B2=36u,  		Bis2=37u,		//	Si 2
	Ces3=36u,		C3=37u,  		Cis3=38u,		//	Do 3
	Des3=38u,		D3=39u,  		Dis3=40u,		//	Re 3
	Es3=40u,		E3=41u,  		Eis3=42u,		//	Mi 3
	Fes3=41u,		F3=42u,  		Fis3=43u,		//	Fa 3
	Ges3=43u,		G3=44u,  		Gis3=45u,		//	Sol 3
	As3=45u,		A3=46u,  		Ais3=47u,		//	La 3
	Bes3=47u,		B3=48u,  		Bis3=49u,		//	Si 3
	Ces4=48u,		C4=49u,  		Cis4=50u,		//	Do 4
	Des4=50u,		D4=51u,  		Dis4=52u,		//	Re 4
	Es4=52u,		E4=53u,  		Eis4=54u,		//	Mi 4
	Fes4=53u,		F4=54u,  		Fis4=55u,		//	Fa 4
	Ges4=55u,		G4=56u,  		Gis4=57u,		//	Sol 4
	As4=57u,		A4=58u,  		Ais4=59u,		//	La 4
	Bes4=59u,		B4=60u,  		Bis4=61u,		//	Si 4
	Ces5=60u,		C5=61u,  		Cis5=62u,		//	Do 5
	Des5=62u,		D5=63u,  		Dis5=64u,		//	Re 5
	Es5=64u,		E5=65u,  		Eis5=66u,		//	Mi 5
	Fes5=65u,		F5=66u,  		Fis5=67u,		//	Fa 5
	Ges5=67u,		G5=68u,  		Gis5=69u,		//	Sol 5
	As5=69u,		A5=70u,  		Ais5=71u,		//	La 5
	Bes5=71u,		B5=72u,  		Bis5=73u,		//	Si 5
	Ces6=72u,		C6=73u,  		Cis6=74u,		//	Do 6
	Des6=74u,		D6=75u,  		Dis6=76u,		//	Re 6
	Es6=76u,		E6=77u,  		Eis6=78u,		//	Mi 6
	Fes6=77u,		F6=78u,  		Fis6=79u,		//	Fa 6
	Ges6=79u,		G6=80u,  		Gis6=81u,		//	Sol 6
	As6=81u,		A6=82u,  		Ais6=83u,		//	La 6
	Bes6=83u,		B6=84u,  		Bis6=85u,		//	Si 6
	Ces7=84u,		C7=85u,  		Cis7=86u,		//	Do 7
	Des7=86u,		D7=87u,  		Dis7=88u,		//	Re 7
	Es7=88u,		E7=89u,  		Eis7=90u,		//	Mi 7
	Fes7=89u,		F7=90u,  		Fis7=91u,		//	Fa 7
	Ges7=91u,		G7=92u,  		Gis7=93u,		//	Sol 7
	As7=93u,		A7=94u,  		Ais7=95u,		//	La 7
	Bes7=95u,		B7=96u,  		Bis7=97u,		//	Si 7
	Ces8=96u,		C8=97u,  		Cis8=98u,		//	Do 8
	Des8=98u,		D8=99u,  		Dis8=100u,		//	Re 8
	Es8=100u,		E8=101u,  		Eis8=102u,		//	Mi 8
	Fes8=101u,		F8=102u,  		Fis8=103u,		//	Fa 8
	Ges8=103u,		G8=104u,  		Gis8=105u,		//	Sol 8
	As8=105u,		A8=106u,  		Ais8=107u,		//	La 8
	Bes8=107u,		B8=108u,  		Bis8=109u,		//	Si 8
};

class Sound {
private:
	// All note frequencies for octaves 0-7, multiplied by 1000 to avoid floats
	// Access: frequency1000[Note::C]
	static constexpr const uint32_t frequency1000[109] {
		100, // pause frequency
		32703u >> 1, 34648u >> 1, 36708u >> 1, 38891u >> 1, 41203u >> 1, 43654u >> 1, 46249u >> 1, 48999u >> 1, 51913u >> 1, 55000u >> 1, 58270u >> 1, 61735u >> 1, 	 // octave 0
		32703u << 0, 34648u << 0, 36708u << 0, 38891u << 0, 41203u << 0, 43654u << 0, 46249u << 0, 48999u << 0, 51913u << 0, 55000u << 0, 58270u << 0, 61735u << 0, 	 // octave 1
		32703u << 1, 34648u << 1, 36708u << 1, 38891u << 1, 41203u << 1, 43654u << 1, 46249u << 1, 48999u << 1, 51913u << 1, 55000u << 1, 58270u << 1, 61735u << 1, 	 // octave 2
		32703u << 2, 34648u << 2, 36708u << 2, 38891u << 2, 41203u << 2, 43654u << 2, 46249u << 2, 48999u << 2, 51913u << 2, 55000u << 2, 58270u << 2, 61735u << 2, 	 // octave 3
		32703u << 3, 34648u << 3, 36708u << 3, 38891u << 3, 41203u << 3, 43654u << 3, 46249u << 3, 48999u << 3, 51913u << 3, 55000u << 3, 58270u << 3, 61735u << 3, 	 // octave 4
		32703u << 4, 34648u << 4, 36708u << 4, 38891u << 4, 41203u << 4, 43654u << 4, 46249u << 4, 48999u << 4, 51913u << 4, 55000u << 4, 58270u << 4, 61735u << 4, 	 // octave 5
		32703u << 5, 34648u << 5, 36708u << 5, 38891u << 5, 41203u << 5, 43654u << 5, 46249u << 5, 48999u << 5, 51913u << 5, 55000u << 5, 58270u << 5, 61735u << 5, 	 // octave 6
		32703u << 6, 34648u << 6, 36708u << 6, 38891u << 6, 41203u << 6, 43654u << 6, 46249u << 6, 48999u << 6, 51913u << 6, 55000u << 6, 58270u << 6, 61735u << 6, 	 // octave 7
		32703u << 7, 34648u << 7, 36708u << 7, 38891u << 7, 41203u << 7, 43654u << 7, 46249u << 7, 48999u << 7, 51913u << 7, 55000u << 7, 58270u << 7, 61735u << 7, 	 // octave 8
	};

	// All note half-periods in microseconds for octaves 0-8
	// use: halfPeriodUs[Note::C]
	static constexpr const uint32_t halfPeriodUs[109] {
		5000000, // pause half-period in microseconds
		30580u >> 0, 28860u >> 0, 27240u >> 0, 25710u >> 0, 24270u >> 0, 22910u >> 0, 21620u >> 0, 20410u >> 0, 19260u >> 0, 18180u >> 0, 17160u >> 0, 16200u >> 0, 	 // octave 0
		30580u >> 1, 28860u >> 1, 27240u >> 1, 25710u >> 1, 24270u >> 1, 22910u >> 1, 21620u >> 1, 20410u >> 1, 19260u >> 1, 18180u >> 1, 17160u >> 1, 16200u >> 1, 	 // octave 1
		30580u >> 2, 28860u >> 2, 27240u >> 2, 25710u >> 2, 24270u >> 2, 22910u >> 2, 21620u >> 2, 20410u >> 2, 19260u >> 2, 18180u >> 2, 17160u >> 2, 16200u >> 2, 	 // octave 2
		30580u >> 3, 28860u >> 3, 27240u >> 3, 25710u >> 3, 24270u >> 3, 22910u >> 3, 21620u >> 3, 20410u >> 3, 19260u >> 3, 18180u >> 3, 17160u >> 3, 16200u >> 3, 	 // octave 3
		30580u >> 4, 28860u >> 4, 27240u >> 4, 25710u >> 4, 24270u >> 4, 22910u >> 4, 21620u >> 4, 20410u >> 4, 19260u >> 4, 18180u >> 4, 17160u >> 4, 16200u >> 4, 	 // octave 4
		30580u >> 5, 28860u >> 5, 27240u >> 5, 25710u >> 5, 24270u >> 5, 22910u >> 5, 21620u >> 5, 20410u >> 5, 19260u >> 5, 18180u >> 5, 17160u >> 5, 16200u >> 5, 	 // octave 5
		30580u >> 6, 28860u >> 6, 27240u >> 6, 25710u >> 6, 24270u >> 6, 22910u >> 6, 21620u >> 6, 20410u >> 6, 19260u >> 6, 18180u >> 6, 17160u >> 6, 16200u >> 6, 	 // octave 6
		30580u >> 7, 28860u >> 7, 27240u >> 7, 25710u >> 7, 24270u >> 7, 22910u >> 7, 21620u >> 7, 20410u >> 7, 19260u >> 7, 18180u >> 7, 17160u >> 7, 16200u >> 7, 	 // octave 7
		30580u >> 8, 28860u >> 8, 27240u >> 8, 25710u >> 8, 24270u >> 8, 22910u >> 8, 21620u >> 8, 20410u >> 8, 19260u >> 8, 18180u >> 8, 17160u >> 8, 16200u >> 8, 	 // octave 8
	};


	// Standardized note lengths in milliseconds, use: LengthMs[Len::_4]
	static constexpr const uint16_t LengthMs[8] {
		1 << 11, 1 << 10, 1 << 9, 1 << 8, 1 << 7, 1 << 6, 1 << 5, 1 << 4
	};

public:

	static CSound create(Note note, Len duration) {
		return {
			LengthMs[uint8_t(duration)],
			frequency1000[uint8_t(note)],
			halfPeriodUs[uint8_t(note)]
		};
	}

	static uint32_t get_halfperiod_us(Note n) {
		return halfPeriodUs[(uint8_t)n];
	};

	static uint32_t get_halfperiod_tick(Note n) {
		return halfPeriodUs[(uint8_t)n] * Tick::ticks_per_us;
	};

	static uint32_t get_length_ms(Len len) {
		return LengthMs[(uint8_t)len];
	}
};


/// @brief Play several notes at the time, all notes of a chord have same length
/// TODO: 1 in Chord switch from array<_, 4> to sth more flexible
/// TODO: 2 move expiration tick into Buzzer class and make Chord class constexpr-able
/// TODO: 3 implement staccato, augmentation dot and reprise to save space
class Chord {
private:
	std::array <uint32_t, 4u>	halfperiods;		// systicks, 4-note polyphony
	Len							dur;				// chord duration
	uint32_t					expiration_tick;	// tick number after which chord should no longer be played
public:
	/// @brief Initialize chord with up to 4 notes
	/// 		with Chord({{note0, octave0}, ...}, len_ms). Pass an empty
	///			array for pause.
	/// @param notes array of notes from Sound::get_halfperiod_us(Note, octave)
	/// @param len_ms length of the cord, one of the standard predefined lengths
	Chord(const std::array<Note, 4u>& notes, Len duration):
		halfperiods({
			Sound::get_halfperiod_tick(notes[0]),
			Sound::get_halfperiod_tick(notes[1]),
			Sound::get_halfperiod_tick(notes[2]),
			Sound::get_halfperiod_tick(notes[3]),
			}),
		dur(duration)
	{
		halfperiods[0] += (halfperiods[0] == 0); // avoid zero divisions
		halfperiods[1] += (halfperiods[1] == 0);
		halfperiods[2] += (halfperiods[2] == 0);
		halfperiods[3] += (halfperiods[3] == 0);
		renew();
	}

	/// @brief Check whether buzzer pin should be set high or low
	/// @return true or false
	bool pwm() const {
		return (SysTick->CNT / halfperiods[(SysTick->CNT/(Tick::ticks_per_ms<<1))&0b11])&1; // switch between notes every 2 milliseconds
	}

	/// @brief Update expiration tick, so the same chord can be played again
	void renew() {
		expiration_tick = SysTick->CNT + Sound::get_length_ms(dur) * Tick::ticks_per_ms;
	}

	/// @brief Check whether chord is still to be played
	/// @return true if chord duration has expired
	bool is_expired() const {
		return SysTick->CNT >= expiration_tick;
	}
};
