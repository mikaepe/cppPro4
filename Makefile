CPPFLAGS=-Wall -g -std=c++11

main1: main1.cpp domain.cpp curvebase.cpp fxcurve.cpp point.cpp gfctn.cpp matrix.cpp

clean:
	rm -f main1
	rm -f outfile.bin
	rm -f gridOut.bin
	rm -f DxOut.bin
	rm -f DyOut.bin
	rm -f DDxOut.bin
	rm -f DDyOut.bin
	rm -f laplaceOut.bin

