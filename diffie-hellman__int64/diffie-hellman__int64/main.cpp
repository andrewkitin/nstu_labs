#include "DH_protocol.h" 
#include <cstdlib>
#include <ctime>
#include <iostream>

__int64 generate_degree() {
	srand(time(0));
	__int64 r = rand() % INT_MAX;
	return r;
}

void check_DHalgorithm(DH_protocol& P,__int64 A, __int64 a) {
	__int64 b = generate_degree();
	__int64 B = P.getOwnKey(b);

	__int64 K1 = P.powSomeoneKey(B, a);
	__int64 K2 = P.powSomeoneKey(A, b);

	if (K1 == K2) { std::cout << "Secret keys are equivalent" << std::endl; }
}


void main() {
	__int64 g = 5; __int64 p = 18014398241046527;
	DH_protocol P(g,p);
	__int64 a = generate_degree();
	__int64 A = P.getOwnKey(a);
	check_DHalgorithm(P,A,a);
}