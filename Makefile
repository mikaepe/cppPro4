CPPFLAGS=-Wall -g -std=c++11

test1: test1.cpp matrix.cpp
testDomain: testDomain.cpp domain.cpp curvebase.cpp xline.cpp yline.cpp fxcurve.cpp xquad.cpp point.cpp gfctn.cpp matrix.cpp
pointMain: pointMain.cpp point.cpp
testMatrix: testMatrix.cpp matrix.cpp

clean:
	rm -f test1
	rm -f testDomain
	rm -f outfile.bin
	rm -f pointMain
	rm -f testMatrix
	rm -f smack

