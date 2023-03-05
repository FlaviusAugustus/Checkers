#include "Lookups.h"
#include "Constants.h"

Lookups::Lookups() {

	Pieces[0] = 1;

	for (int i = 1; i < 64; i++) {

		Pieces[i] = Pieces[i - 1] << 1;

	}

	Mask1 = Pieces[A1] | Pieces[C1] | Pieces[E1] | Pieces[G1];
	Mask2 = Pieces[B2] | Pieces[D2] | Pieces[F2] | Pieces[H2];
	Mask3 = Pieces[A3] | Pieces[C3] | Pieces[E3] | Pieces[G3];
	Mask6 = Pieces[B6] | Pieces[D6] | Pieces[F6] | Pieces[H6];
	Mask7 = Pieces[A7] | Pieces[C7] | Pieces[E7] | Pieces[G7];
	Mask8 = Pieces[B8] | Pieces[D8] | Pieces[F8] | Pieces[H8];

	MaskA = Pieces[A1] | Pieces[A3] | Pieces[A5] | Pieces[A7];
	MaskH = Pieces[H2] | Pieces[H4] | Pieces[H6] | Pieces[H8];

}