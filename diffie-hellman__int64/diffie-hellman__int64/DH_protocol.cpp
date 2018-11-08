#include "DH_protocol.h"

__int64 DH_protocol::fast_pow(__int64 a, __int64 n) {
	if (n == 0) return 1;
	if (n % 2 == 1) {
		return (fast_pow(a, n-1)*a)%p;
	}
	else {
		(fast_pow(a, n / 2)*a) % p;
	}
}

__int64 DH_protocol::powSomeoneKey(__int64 B, __int64 a)
{
	return fast_pow(B, a);
}

__int64 DH_protocol::getOwnKey(__int64 a)
{
	return fast_pow(g,a);
}

DH_protocol::DH_protocol(__int64 g, __int64 p)
{
	this->g = g;
	this->p = p;
}

DH_protocol::DH_protocol()
{
}


DH_protocol::~DH_protocol()
{
}
