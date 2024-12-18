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
#include <array>


/// #TODO: ensure that this goes to FLASH memory.
/// @brief  Set of displayable ascii characters in a 8x8-bit shape.
///         contains only capital letters that are moved 64 positions
///         to the left compared to ascii table; ' ' to '@' have the same
///         index as in ascii. Use get_printable() for convenience.
constexpr const std::array<std::array<uint8_t, 8u>, 70u> gPrintable = {
	std::array<uint8_t, 8u> { // SOLID idx(0)
	   (uint8_t)0b11111111,
	   (uint8_t)0b11111111,
	   (uint8_t)0b11111111,
	   (uint8_t)0b11111111,
	   (uint8_t)0b11111111,
	   (uint8_t)0b11111111,
	   (uint8_t)0b11111111,
	   (uint8_t)0b11111111
	},
	std::array<uint8_t, 8u> { // A idx(1)
	   (uint8_t)0b01111100,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11111110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b11111100,
	   (uint8_t)0b01100110,
	   (uint8_t)0b01100110,
	   (uint8_t)0b01111100,
	   (uint8_t)0b01100110,
	   (uint8_t)0b01100110,
	   (uint8_t)0b11111100,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b01111100,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000000,
	   (uint8_t)0b11000000,
	   (uint8_t)0b11000000,
	   (uint8_t)0b11000110,
	   (uint8_t)0b01111100,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b11111100,
	   (uint8_t)0b01100110,
	   (uint8_t)0b01100110,
	   (uint8_t)0b01100110,
	   (uint8_t)0b01100110,
	   (uint8_t)0b01100110,
	   (uint8_t)0b11111100,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b11111110,
	   (uint8_t)0b01100010,
	   (uint8_t)0b01101000,
	   (uint8_t)0b01111000,
	   (uint8_t)0b01101000,
	   (uint8_t)0b01100010,
	   (uint8_t)0b11111110,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b11111110,
	   (uint8_t)0b01100010,
	   (uint8_t)0b01101000,
	   (uint8_t)0b01111000,
	   (uint8_t)0b01101000,
	   (uint8_t)0b01100000,
	   (uint8_t)0b11110000,
	   (uint8_t)0b00000000
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b01111100,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000000,
	   (uint8_t)0b11001110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b01111110,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11111110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00111100,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00111100,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00011110,
	   (uint8_t)0b00001100,
	   (uint8_t)0b00001100,
	   (uint8_t)0b00001100,
	   (uint8_t)0b11001100,
	   (uint8_t)0b11001100,
	   (uint8_t)0b01111000,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b11100110,
	   (uint8_t)0b01100110,
	   (uint8_t)0b01101100,
	   (uint8_t)0b01111000,
	   (uint8_t)0b01101100,
	   (uint8_t)0b01100110,
	   (uint8_t)0b11100110,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b11110000,
	   (uint8_t)0b01100000,
	   (uint8_t)0b01100000,
	   (uint8_t)0b01100000,
	   (uint8_t)0b01100010,
	   (uint8_t)0b01100110,
	   (uint8_t)0b11111110,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b10000010,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11101110,
	   (uint8_t)0b11111110,
	   (uint8_t)0b11010110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b11000110,
	   (uint8_t)0b11100110,
	   (uint8_t)0b11110110,
	   (uint8_t)0b11011110,
	   (uint8_t)0b11001110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b01111100,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b01111100,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b11111100,
	   (uint8_t)0b01100110,
	   (uint8_t)0b01100110,
	   (uint8_t)0b01111100,
	   (uint8_t)0b01100000,
	   (uint8_t)0b01100000,
	   (uint8_t)0b11110000,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b01111100,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11010110,
	   (uint8_t)0b11011110,
	   (uint8_t)0b01111100,
	   (uint8_t)0b00000110,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b11111100,
	   (uint8_t)0b01100110,
	   (uint8_t)0b01100110,
	   (uint8_t)0b01111100,
	   (uint8_t)0b01100110,
	   (uint8_t)0b01100110,
	   (uint8_t)0b11100110,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b01111100,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000000,
	   (uint8_t)0b01111100,
	   (uint8_t)0b00000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b01111100,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b01111110,
	   (uint8_t)0b01011010,
	   (uint8_t)0b01011010,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00111100,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b01111100,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b01101100,
	   (uint8_t)0b00111000,
	   (uint8_t)0b00010000,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11010110,
	   (uint8_t)0b11111110,
	   (uint8_t)0b11101110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b10000010,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b11000110,
	   (uint8_t)0b01101100,
	   (uint8_t)0b00111000,
	   (uint8_t)0b00111000,
	   (uint8_t)0b00111000,
	   (uint8_t)0b01101100,
	   (uint8_t)0b11000110,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b01100110,
	   (uint8_t)0b01100110,
	   (uint8_t)0b01100110,
	   (uint8_t)0b00111100,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00111100,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> { // Z idx(26)
	   (uint8_t)0b11111110, 
	   (uint8_t)0b11000110,
	   (uint8_t)0b10001100,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00110010,
	   (uint8_t)0b01100110,
	   (uint8_t)0b11111110,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> { // [ idx(27)
	   (uint8_t)0b01111000,
	   (uint8_t)0b01100000,
	   (uint8_t)0b01100000,
	   (uint8_t)0b01100000,
	   (uint8_t)0b01100000,
	   (uint8_t)0b01100000,
	   (uint8_t)0b01111000,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b11000000,
	   (uint8_t)0b01100000,
	   (uint8_t)0b00110000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00001100,
	   (uint8_t)0b00000110,
	   (uint8_t)0b00000010,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b01111000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b01111000,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00010000,
	   (uint8_t)0b00111000,
	   (uint8_t)0b01101100,
	   (uint8_t)0b11000110,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> { // _ idx(31)
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b11111111,
	},
	std::array<uint8_t, 8u> { // SPACE idx(32)
		(uint8_t)0b00000000,
		(uint8_t)0b00000000,
		(uint8_t)0b00000000,
		(uint8_t)0b00000000,
		(uint8_t)0b00000000,
		(uint8_t)0b00000000,
		(uint8_t)0b00000000,
		(uint8_t)0b00000000
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00011000,
	   (uint8_t)0b00111100,
	   (uint8_t)0b00111100,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00000000
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b01101100,
	   (uint8_t)0b00100100,
	   (uint8_t)0b00100100,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b01101100,
	   (uint8_t)0b01101100,
	   (uint8_t)0b11111110,
	   (uint8_t)0b01101100,
	   (uint8_t)0b11111110,
	   (uint8_t)0b01101100,
	   (uint8_t)0b01101100,
	   (uint8_t)0b00000000
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00010000,
	   (uint8_t)0b01111100,
	   (uint8_t)0b11010000,
	   (uint8_t)0b01111100,
	   (uint8_t)0b00010110,
	   (uint8_t)0b11111100,
	   (uint8_t)0b00010000,
	   (uint8_t)0b00000000
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00000000,
	   (uint8_t)0b01100110,
	   (uint8_t)0b10101100,
	   (uint8_t)0b11011000,
	   (uint8_t)0b00110110,
	   (uint8_t)0b01101010,
	   (uint8_t)0b11001100,
	   (uint8_t)0b00000000
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00111000,
	   (uint8_t)0b01001100,
	   (uint8_t)0b00111000,
	   (uint8_t)0b01111000,
	   (uint8_t)0b11001110,
	   (uint8_t)0b11001100,
	   (uint8_t)0b01111010,
	   (uint8_t)0b00000000
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00110000,
	   (uint8_t)0b00010000,
	   (uint8_t)0b00100000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00011000,
	   (uint8_t)0b00110000,
	   (uint8_t)0b01100000,
	   (uint8_t)0b01100000,
	   (uint8_t)0b01100000,
	   (uint8_t)0b00110000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00000000
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b01100000,
	   (uint8_t)0b00110000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00110000,
	   (uint8_t)0b01100000,
	   (uint8_t)0b00000000
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00000000,
	   (uint8_t)0b01100110,
	   (uint8_t)0b00111100,
	   (uint8_t)0b11111111,
	   (uint8_t)0b00111100,
	   (uint8_t)0b01100110,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00000000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b01111110,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00110000,
	   (uint8_t)0b00010000,
	   (uint8_t)0b00100000
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b11111110,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00110000,
	   (uint8_t)0b00000000
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00000010,
	   (uint8_t)0b00000110,
	   (uint8_t)0b00001100,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00110000,
	   (uint8_t)0b01100000,
	   (uint8_t)0b11000000,
	   (uint8_t)0b00000000
	},
	std::array<uint8_t, 8u> { // 0 idx(48)
	   (uint8_t)0b01111100,
	   (uint8_t)0b11001110,
	   (uint8_t)0b11011110,
	   (uint8_t)0b11110110,
	   (uint8_t)0b11100110,
	   (uint8_t)0b11100110,
	   (uint8_t)0b01111100,
	   (uint8_t)0b00000000
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00011000,
	   (uint8_t)0b00111000,
	   (uint8_t)0b01111000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b01111110,
	   (uint8_t)0b00000000
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b01111100,
	   (uint8_t)0b11000110,
	   (uint8_t)0b00000110,
	   (uint8_t)0b00011100,
	   (uint8_t)0b01110000,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11111110,
	   (uint8_t)0b00000000
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b01111100,
	   (uint8_t)0b11000110,
	   (uint8_t)0b00000110,
	   (uint8_t)0b00111100,
	   (uint8_t)0b00000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b01111100,
	   (uint8_t)0b00000000
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00011100,
	   (uint8_t)0b00111100,
	   (uint8_t)0b01101100,
	   (uint8_t)0b11001100,
	   (uint8_t)0b11111110,
	   (uint8_t)0b00001100,
	   (uint8_t)0b00011110,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b11111110,
	   (uint8_t)0b11000000,
	   (uint8_t)0b11111100,
	   (uint8_t)0b00000110,
	   (uint8_t)0b00000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b01111100,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b01111100,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000000,
	   (uint8_t)0b11111100,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b01111100,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b11111110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b00001100,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00110000,
	   (uint8_t)0b00110000,
	   (uint8_t)0b00110000,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b01111100,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b01111100,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b01111100,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> { // 9 idx(57)
	   (uint8_t)0b01111100,
	   (uint8_t)0b11000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b01111110,
	   (uint8_t)0b00000110,
	   (uint8_t)0b11000110,
	   (uint8_t)0b01111100,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00000000,
	   (uint8_t)0b00110000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00110000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00000000,
	   (uint8_t)0b00110000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00110000,
	   (uint8_t)0b00010000,
	   (uint8_t)0b00100000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00001100,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00110000,
	   (uint8_t)0b01100000,
	   (uint8_t)0b00110000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00001100,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b01111110,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b01111110,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b01100000,
	   (uint8_t)0b00110000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00001100,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00110000,
	   (uint8_t)0b01100000,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b01111000,
	   (uint8_t)0b11001100,
	   (uint8_t)0b00001100,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00110000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00110000,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> { // @ idx(64)
	   (uint8_t)0b01111100,
	   (uint8_t)0b10000010,
	   (uint8_t)0b10011110,
	   (uint8_t)0b10100110,
	   (uint8_t)0b10011110,
	   (uint8_t)0b10000000,
	   (uint8_t)0b01111100,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00110000,
	   (uint8_t)0b00100000,
	   (uint8_t)0b00010000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00001110,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00110000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00001110,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00011000,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b00111000,
	   (uint8_t)0b00001100,
	   (uint8_t)0b00001100,
	   (uint8_t)0b00000110,
	   (uint8_t)0b00001100,
	   (uint8_t)0b00001100,
	   (uint8_t)0b00111000,
	   (uint8_t)0b00000000,
	},
	std::array<uint8_t, 8u> {
	   (uint8_t)0b01110110,
	   (uint8_t)0b11011100,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	   (uint8_t)0b00000000,
	}
};

/// @brief Returns a printable character for display
/// @param c ascii character
/// @return std::array<uint8_t, 8u>&
const std::array<uint8_t, 8u>& get_printable(char c) {
	if (isalpha(c)) {
		return gPrintable[toupper(c) >> 6];
	}
	if (c > 31 && c < 65) {
		return gPrintable[c];
	}
	switch (c) {
		case '[':
			return gPrintable[27];
		case '\\':
			return gPrintable[28];
		case ']':
			return gPrintable[29];
		case '^':
			return gPrintable[30];
		case '_':
			return gPrintable[31];
		case '`':
			return gPrintable[65];
		case '{':
			return gPrintable[66];
		case '|':
			return gPrintable[67];
		case '}':
			return gPrintable[68];
		case '~':
			return gPrintable[69];
		default:
			break;
	}
	return gPrintable[0];
}

// (uint8_t)0b11111110,    // Piece tetris
// (uint8_t)0b10000010,
// (uint8_t)0b10000010,
// (uint8_t)0b10000010,
// (uint8_t)0b10000010,
// (uint8_t)0b10000010,
// (uint8_t)0b11111110,
// (uint8_t)0b00000000

// (uint8_t)0b00000000,    // Border H
// (uint8_t)0b00000000,
// (uint8_t)0b11111111,
// (uint8_t)0b11111111,
// (uint8_t)0b11111111,
// (uint8_t)0b11111111,
// (uint8_t)0b00000000,
// (uint8_t)0b00000000

// (uint8_t)0b00111100,    // Border V
// (uint8_t)0b00111100,
// (uint8_t)0b00111100,
// (uint8_t)0b00111100,
// (uint8_t)0b00111100,
// (uint8_t)0b00111100,
// (uint8_t)0b00111100,
// (uint8_t)0b00111100

// (uint8_t)0b00111100,    // Border BL
// (uint8_t)0b00111100,
// (uint8_t)0b00111111,
// (uint8_t)0b00111111,
// (uint8_t)0b00111111,
// (uint8_t)0b00111111,
// (uint8_t)0b00000000,
// (uint8_t)0b00000000

// (uint8_t)0b00111100,    // Border BR
// (uint8_t)0b00111100,
// (uint8_t)0b11111100,
// (uint8_t)0b11111100,
// (uint8_t)0b11111100,
// (uint8_t)0b11111100,
// (uint8_t)0b00000000,
// (uint8_t)0b00000000

//(uint8_t)0b00000000
//(uint8_t)0b00000000
//(uint8_t)0b01111000
//(uint8_t)0b00001100
//(uint8_t)0b01111100
//(uint8_t)0b11001100
//(uint8_t)0b01110110
//(uint8_t)0b00000000

//(uint8_t)0b11100000
//(uint8_t)0b01100000
//(uint8_t)0b01100000
//(uint8_t)0b01111100
//(uint8_t)0b01100110
//(uint8_t)0b01100110
//(uint8_t)0b01111100
//(uint8_t)0b00000000

//(uint8_t)0b00000000
//(uint8_t)0b00000000
//(uint8_t)0b01111100
//(uint8_t)0b11000110
//(uint8_t)0b11000000
//(uint8_t)0b11000110
//(uint8_t)0b01111100
//(uint8_t)0b00000000

//(uint8_t)0b00011100
//(uint8_t)0b00001100
//(uint8_t)0b00001100
//(uint8_t)0b01111100
//(uint8_t)0b11001100
//(uint8_t)0b11001100
//(uint8_t)0b01110110
//(uint8_t)0b00000000

//(uint8_t)0b00000000
//(uint8_t)0b00000000
//(uint8_t)0b01111100
//(uint8_t)0b11000110
//(uint8_t)0b11111110
//(uint8_t)0b11000000
//(uint8_t)0b01111100
//(uint8_t)0b00000000

//(uint8_t)0b00011100
//(uint8_t)0b00110110
//(uint8_t)0b00110000
//(uint8_t)0b01111000
//(uint8_t)0b00110000
//(uint8_t)0b00110000
//(uint8_t)0b01111000
//(uint8_t)0b00000000

//(uint8_t)0b00000000
//(uint8_t)0b00000000
//(uint8_t)0b01110110
//(uint8_t)0b11001100
//(uint8_t)0b11001100
//(uint8_t)0b01111100
//(uint8_t)0b00001100
//(uint8_t)0b01111000

//(uint8_t)0b11100000
//(uint8_t)0b01100000
//(uint8_t)0b01101100
//(uint8_t)0b01110110
//(uint8_t)0b01100110
//(uint8_t)0b01100110
//(uint8_t)0b11100110
//(uint8_t)0b00000000

//(uint8_t)0b00011000
//(uint8_t)0b00000000
//(uint8_t)0b00111000
//(uint8_t)0b00011000
//(uint8_t)0b00011000
//(uint8_t)0b00011000
//(uint8_t)0b00111100
//(uint8_t)0b00000000

//(uint8_t)0b00001100
//(uint8_t)0b00000000
//(uint8_t)0b00011100
//(uint8_t)0b00001100
//(uint8_t)0b00001100
//(uint8_t)0b00001100
//(uint8_t)0b11001100
//(uint8_t)0b01111000

//(uint8_t)0b11100000
//(uint8_t)0b01100000
//(uint8_t)0b01100110
//(uint8_t)0b01101100
//(uint8_t)0b01111000
//(uint8_t)0b01101100
//(uint8_t)0b11100110
//(uint8_t)0b00000000

//(uint8_t)0b00111000
//(uint8_t)0b00011000
//(uint8_t)0b00011000
//(uint8_t)0b00011000
//(uint8_t)0b00011000
//(uint8_t)0b00011000
//(uint8_t)0b00111100
//(uint8_t)0b00000000

//(uint8_t)0b00000000
//(uint8_t)0b00000000
//(uint8_t)0b11001100
//(uint8_t)0b11111110
//(uint8_t)0b11010110
//(uint8_t)0b11010110
//(uint8_t)0b11000110
//(uint8_t)0b00000000

//(uint8_t)0b00000000
//(uint8_t)0b00000000
//(uint8_t)0b11011100
//(uint8_t)0b01100110
//(uint8_t)0b01100110
//(uint8_t)0b01100110
//(uint8_t)0b01100110
//(uint8_t)0b00000000

//(uint8_t)0b00000000
//(uint8_t)0b00000000
//(uint8_t)0b01111100
//(uint8_t)0b11000110
//(uint8_t)0b11000110
//(uint8_t)0b11000110
//(uint8_t)0b01111100
//(uint8_t)0b00000000

// //--------------------------------

//(uint8_t)0b00000000
//(uint8_t)0b00000000
//(uint8_t)0b11011100
//(uint8_t)0b01100110
//(uint8_t)0b01100110
//(uint8_t)0b01111100
//(uint8_t)0b01100000
//(uint8_t)0b11110000

//(uint8_t)0b00000000
//(uint8_t)0b00000000
//(uint8_t)0b01111100
//(uint8_t)0b11001100
//(uint8_t)0b11001100
//(uint8_t)0b01111100
//(uint8_t)0b00001100
//(uint8_t)0b00011110

//(uint8_t)0b00000000
//(uint8_t)0b00000000
//(uint8_t)0b11011110
//(uint8_t)0b01110110
//(uint8_t)0b01100000
//(uint8_t)0b01100000
//(uint8_t)0b11110000
//(uint8_t)0b00000000

//(uint8_t)0b00000000
//(uint8_t)0b00000000
//(uint8_t)0b01111100
//(uint8_t)0b11000000
//(uint8_t)0b01111100
//(uint8_t)0b00000110
//(uint8_t)0b01111100
//(uint8_t)0b00000000

//(uint8_t)0b00010000
//(uint8_t)0b00110000
//(uint8_t)0b11111100
//(uint8_t)0b00110000
//(uint8_t)0b00110000
//(uint8_t)0b00110100
//(uint8_t)0b00011000
//(uint8_t)0b00000000

//(uint8_t)0b00000000
//(uint8_t)0b00000000
//(uint8_t)0b11001100
//(uint8_t)0b11001100
//(uint8_t)0b11001100
//(uint8_t)0b11001100
//(uint8_t)0b01110110
//(uint8_t)0b00000000

//(uint8_t)0b00000000
//(uint8_t)0b00000000
//(uint8_t)0b11000110
//(uint8_t)0b11000110
//(uint8_t)0b01101100
//(uint8_t)0b00111000
//(uint8_t)0b00010000
//(uint8_t)0b00000000

//(uint8_t)0b00000000
//(uint8_t)0b00000000
//(uint8_t)0b11000110
//(uint8_t)0b11010110
//(uint8_t)0b11010110
//(uint8_t)0b11111110
//(uint8_t)0b01101100
//(uint8_t)0b00000000

//(uint8_t)0b00000000
//(uint8_t)0b00000000
//(uint8_t)0b11000110
//(uint8_t)0b01101100
//(uint8_t)0b00111000
//(uint8_t)0b01101100
//(uint8_t)0b11000110
//(uint8_t)0b00000000

//(uint8_t)0b00000000
//(uint8_t)0b00000000
//(uint8_t)0b11001100
//(uint8_t)0b11001100
//(uint8_t)0b11001100
//(uint8_t)0b01111100
//(uint8_t)0b00001100
//(uint8_t)0b11111000

//(uint8_t)0b00000000
//(uint8_t)0b00000000
//(uint8_t)0b11111100
//(uint8_t)0b10011000
//(uint8_t)0b00110000
//(uint8_t)0b01100100
//(uint8_t)0b11111100
//(uint8_t)0b00000000
