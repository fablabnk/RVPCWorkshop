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

#include <cstdint>

// Synchronization signals differ for different vga modes, choose Lo or Hi
enum class Sync : bool {Lo, Hi};

struct Timing {
	uint8_t fporch; // front porch, in pixels (lines) for horisontal (vertical) resolution
	uint8_t spulse; // synch pulse, in pixels (lines) for horisontal (vertical) resolution
	uint8_t bporch; // back  porch, in pixels (lines) for horisontal (vertical) resolution
};

struct VGAMode {
	uint8_t		frequency;	// display refresh rate, Hz
	uint32_t	linefreq;	// line refresh rate, Hz
	Timing		htim;		// horisontal timings
	uint16_t	hres;		// number of visible pixels in a line
	Timing		vtim;		// vertical   timings
	uint16_t	vres;		// number of visible pixels (lines) in a column
	Sync		hsync;		// horisontal synching signal: Lo or Hi
	Sync		vsync;		// vertical synching signal: Lo or Hi

	// returns total vertical pixels (lines)
	inline uint16_t vtotal() const {
		return vres + vtim.bporch + vtim.fporch + vtim.spulse;
	}
	// returns total horisontal pixels (columns)
	inline uint16_t htotal() const {
		return hres + htim.bporch + htim.fporch + htim.spulse;
	}
};

/// @brief 320x240 @60Hz // doesn't work (1524 183 262 2)
/// 320	240	60 Hz	31.5 kHz	ModeLine "320x240" 12.60 320 328 376 400 240 245 246 262 -HSync -VSync DoubleScan
constexpr const VGAMode m320x240_60Hz = {
	.frequency=60u,
	.linefreq=31500u,
	.htim={
		.fporch=8u,
		.spulse=48u,
		.bporch=24u
	},
	.hres=320u,
	.vtim={
		.fporch=5u,
		.spulse=2u,
		.bporch=15u
	},
	.vres=240u,
	.hsync=Sync::Hi,
	.vsync=Sync::Hi
};

/// @brief 512x384 @60Hz // doesn't work
/// 512 384 60 Hz 48.3631 kHz ModeLine "512x384" 32.50 512 524 592 672 384 385 388 403 -HSync -VSync DoubleScan
constexpr const VGAMode m512x384_60Hz = {
	.frequency=60u,
	.linefreq=48363u,
	.htim={
		.fporch=12u,
		.spulse=68u,
		.bporch=24u
	},
	.hres=512u,
	.vtim={
		.fporch=1u,
		.spulse=3u,
		.bporch=15u
	},
	.vres=384u,
	.hsync=Sync::Lo,
	.vsync=Sync::Lo
};

/// @brief 640x480 @60Hz // works, effective 240x480 // if (VGA_VSYNC_TIM->CNT > 37 && VGA_VSYNC_TIM->CNT < 480 + 33) { while(VGA_HSYNC_TIM->CNT < (144) * 1.87) ; GPIOC->OUTDR |= (GPIO_Pin_2); GPIOC->OUTDR &= (~GPIO_Pin_2); }
/// 640	480	60 Hz	31.5 kHz	ModeLine "640x480" 25.20 640 656 752 800 480 490 492 525 -HSync -VSync
constexpr const VGAMode m640x480_60Hz = {
	.frequency=60u,
	.linefreq=31500u,
	.htim={
		.fporch=16u,
		.spulse=96u,
		.bporch=48u
	},
	.hres=640u,
	.vtim={
		.fporch=10u,
		.spulse=2u,
		.bporch=33u
	},
	.vres=480u,
	.hsync=Sync::Lo,
	.vsync=Sync::Lo
};

/// @brief PAL 720x576 @50
/// 720 576 50 Hz 31.2 kHz ModeLine "720x576@50" 27 720 732 795 864 576 581 586 625 -hsync -vsync
constexpr const VGAMode mPAL720x576_50Hz = {
	.frequency=50u,
	.linefreq=31200u,
	.htim={
		.fporch=12u,
		.spulse=63u,
		.bporch=69u
	},
	.hres=720u,
	.vtim={
		.fporch=5u,
		.spulse=5u,
		.bporch=39u
	},
	.vres=576u,
	.hsync=Sync::Lo,
	.vsync=Sync::Lo
};

/// @brief 800x600 @56Hz
/// 800	600	56 Hz	35.1562 kHz	ModeLine "800x600" 36.00 800 824 896 1024 600 601 603 625 +HSync +VSync
constexpr const VGAMode m800x600_56Hz = {
	.frequency=56u,
	.linefreq=35156u,
	.htim={
		.fporch=24u,
		.spulse=72u,
		.bporch=128u
	},
	.hres=800u,
	.vtim={
		.fporch=1u,
		.spulse=2u,
		.bporch=22u
	},
	.vres=600u,
	.hsync=Sync::Hi,
	.vsync=Sync::Hi
};

/// @brief 1024x768 @60Hz // effective res 150x768
/// 1024	768	60 Hz	48.3631 kHz	ModeLine "1024x768" 65.00 1024 1048 1184 1344 768 771 777 806 -HSync -VSync
constexpr const VGAMode m1024x768_60Hz = {
	.frequency=60u,
	.linefreq=48363u,
	.htim={
		.fporch=24u,
		.spulse=136u,
		.bporch=160u
	},
	.hres=1024u,
	.vtim={
		.fporch=3u,
		.spulse=6u,
		.bporch=29u
	},
	.vres=768u,
	.hsync=Sync::Lo,
	.vsync=Sync::Lo
};

/* 1024 
Parameter	Horizontal	Vertical
Resolution	800 pixels	600 lines
Front Porch	16 pixels	1 line
Sync Width	80 pixels	3 lines
Back Porch	160 pixels	21 lines
Total	1056 pixels	625 lines
Frequency	46.875 kHz	75 Hz
Polarity	Positive	Positive
*/

/* 1268, 1.524 * 64 = 97.5, 445 3
Parameter	Horizontal	Vertical
Resolution	640 pixels	350 lines
Front Porch	32 pixels	32 lines
Sync Width	64 pixels	3 lines
Back Porch	96 pixels	60 lines
Total	832 pixels	445 lines
Frequency	37.8606 kHz	85 Hz
Polarity	Positive	Negative
*/

/// @brief 640x350 @85Hz // 1268, 1.524 * 64 = 97.5, 445 3
constexpr const VGAMode m640x350_85Hz = {
	.frequency=85u,
	.linefreq=37861u,
	.htim={
		.fporch=32u,
		.spulse=64u,
		.bporch=96u
	},
	.hres=640u,
	.vtim={
		.fporch=32u,
		.spulse=3u,
		.bporch=60u
	},
	.vres=350u,
	.hsync=Sync::Hi,
	.vsync=Sync::Lo
};