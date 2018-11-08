#pragma once
class DH_protocol
{

private:
	__int64 p;
	__int64 g;

	__int64 fast_pow(__int64 a, __int64 n);
public:
	__int64 powSomeoneKey(__int64 B, __int64 a);
	__int64 getOwnKey(__int64 a);
	DH_protocol(__int64 g ,__int64 p);
	DH_protocol();
	~DH_protocol();
};

