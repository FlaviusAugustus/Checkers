#pragma once
typedef unsigned long long Bitboard;

struct Lookups {

	Bitboard Pieces[64];
	Bitboard Mask1, Mask2, Mask3, Mask6, Mask7, Mask8;
	Bitboard MaskA, MaskH;

	Lookups();

};