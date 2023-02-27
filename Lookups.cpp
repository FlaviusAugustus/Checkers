#include "Lookups.h"
#include "Constants.h"

Lookups::Lookups() {

	Piecies[0] = 1;

	for (int i = 1; i < 32; i++) {

		Piecies[i] = Piecies[i - 1] << 1;

	}

	Mask1 = Piecies[A1] | Piecies[C1] | Piecies[E1] | Piecies[G1];
	Mask2 = Piecies[B2] | Piecies[D2] | Piecies[F2] | Piecies[H2];
	Mask3 = Piecies[A3] | Piecies[C3] | Piecies[E3] | Piecies[G3];
	Mask6 = Piecies[B4] | Piecies[D4] | Piecies[F4] | Piecies[H4];
	Mask7 = Piecies[A7] | Piecies[C7] | Piecies[E7] | Piecies[G7];
	Mask8 = Piecies[B8] | Piecies[D8] | Piecies[F8] | Piecies[H8];

	MaskA = Piecies[A1] | Piecies[A3] | Piecies[A5] | Piecies[A7];
	MaskH = Piecies[H2] | Piecies[H4] | Piecies[H6] | Piecies[H8];

}