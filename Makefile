CPPFLAGS=-Wall -g -std=c++11

test1: test1.cpp matrix.cpp
testDomain: testDomain.cpp domain.cpp curvebase.cpp xline.cpp yline.cpp xquad.cpp

clean:
	rm -f test1
	rm -f testDomain
	rm -f outfile.bin

