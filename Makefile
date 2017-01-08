CPPFLAGS=-Wall -g -std=c++11

testDomain: testDomain.cpp domain.cpp curvebase.cpp fxcurve.cpp point.cpp gfctn.cpp matrix.cpp

clean:
	rm -f testDomain
	rm -f outfile.bin
	rm -f gridOut.bin
	rm -f DxOut.bin
	rm -f DyOut.bin
	rm -f DDxOut.bin
	rm -f DDyOut.bin
	rm -f laplaceOut.bin

