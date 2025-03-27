#include "Hashes.h"

#include "Random.h"

#include <stdio.h>
#include <stdlib.h>
//#include <stdint.h>
#include <assert.h>
//#include <emmintrin.h>
//#include <xmmintrin.h>


//best hash in the whole world
void StudentHash(const void * key, int len, uint32_t seed, void * out) {

#define LOG 0 // set to 1 to print logs -- 0 to disable
	uint32_t digest = 0xdeadbeef; // initialization vector (initial value) for hash


	const uint8_t* data = (const uint8_t*) key;

	// u32data is the data bytes but in an array of unsigned 32-bit values,
	// i.e., it allows you to access four bytes at a time instead of one by one
	const uint32_t* u32data = (const uint32_t*) key;

	int CHUNK_SIZE = 4;

	unsigned int idx = 0; // what chunk are we on?

	// for every chunk of four bytes, XOR each chunk on top of the previous digest
	while (idx < (len / CHUNK_SIZE))
	{
		uint8_t *bytes = (uint8_t *)&digest;	

		//Swap Bytes
		uint8_t temp0 = bytes[0];
		bytes[0] = bytes[2];
		bytes[2] = temp0;

		uint8_t temp1 = bytes[1];
		bytes[1] = bytes[3];
		bytes[3] = temp1;

		//Mod with each other
		for (int i = 1; i < 12; i++) {
			bytes[i%4] = (1*bytes[i%4] + 2*bytes[(i+1)%4] + 3*bytes[(i+2)%4] + 4*bytes[(i+3)%4] ) % 256;
		}

		// XOR bytes against each other for diffusion
		bytes[0] ^= (bytes[1] + seed + 1);
		bytes[1] ^= (bytes[2] + seed + 2);
		bytes[2] ^= (bytes[3] + seed + 3);
		bytes[3] ^= (bytes[0] + seed + 4);

		digest = *(uint32_t*)bytes;

		digest = (digest << 13) | (digest >> (32 - 13)); // Left rotate by 13 bits
		digest ^= digest >> 13;
		digest *= 0xabcdefab;
		digest ^= digest >> 2;
		digest *= 0x12345678;
		digest ^= digest >> 16;




		digest = digest ^ u32data[idx];

		idx = idx + 1;
	}

 
	*(uint32_t*)out = digest;

}

//----------------------------------------------------------------------------
// fake / bad hashes

void BadHash ( const void * key, int len, uint32_t seed, void * out )
{
	uint32_t h = seed;

	const uint8_t * data = (const uint8_t*)key;

	for(int i = 0; i < len; i++)
	{
		h ^= h >> 3;
		h ^= h << 5;
		h ^= data[i];
	}

	*(uint32_t*)out = h;
}

void sumhash ( const void * key, int len, uint32_t seed, void * out )
{
	uint32_t h = seed;

	const uint8_t * data = (const uint8_t*)key;

	for(int i = 0; i < len; i++)
	{
		h += data[i];
	}

	*(uint32_t*)out = h;
}

void sumhash32 ( const void * key, int len, uint32_t seed, void * out )
{
	uint32_t h = seed;

	const uint32_t * data = (const uint32_t*)key;

	for(int i = 0; i < len/4; i++)
	{
		h += data[i];
	}

	*(uint32_t*)out = h;
}

void DoNothingHash ( const void *, int, uint32_t, void * )
{
}

//-----------------------------------------------------------------------------
// One-byte-at-a-time hash based on Murmur's mix

uint32_t MurmurOAAT ( const void * key, int len, uint32_t seed )
{
	const uint8_t * data = (const uint8_t*)key;

	uint32_t h = seed;

	for(int i = 0; i < len; i++)
	{
		h ^= data[i];
		h *= 0x5bd1e995;
		h ^= h >> 15;
	}

	return h;
}

void MurmurOAAT_test ( const void * key, int len, uint32_t seed, void * out )
{
	*(uint32_t*)out = MurmurOAAT(key,len,seed);
}

//----------------------------------------------------------------------------

void FNV ( const void * key, int len, uint32_t seed, void * out )
{
	unsigned int h = seed;

	const uint8_t * data = (const uint8_t*)key;

	h ^= BIG_CONSTANT(2166136261);

	for(int i = 0; i < len; i++)
	{
		h ^= data[i];
		h *= 16777619;
	}

	*(uint32_t*)out = h;
}

//-----------------------------------------------------------------------------

uint32_t x17 ( const void * key, int len, uint32_t h ) 
{
	const uint8_t * data = (const uint8_t*)key;

	for(int i = 0; i < len; ++i) 
	{
		h = 17 * h + (data[i] - ' ');
	}

	return h ^ (h >> 16);
}

//-----------------------------------------------------------------------------

void Bernstein ( const void * key, int len, uint32_t seed, void * out ) 
{
	const uint8_t * data = (const uint8_t*)key;

	for(int i = 0; i < len; ++i) 
	{
		seed = 33 * seed + data[i];
	}

	*(uint32_t*)out = seed;
}

//-----------------------------------------------------------------------------
// Crap8 hash from http://www.team5150.com/~andrew/noncryptohashzoo/Crap8.html

uint32_t Crap8( const uint8_t *key, uint32_t len, uint32_t seed ) {
#define c8fold( a, b, y, z ) { p = (uint32_t)(a) * (uint64_t)(b); y ^= (uint32_t)p; z ^= (uint32_t)(p >> 32); }
#define c8mix( in ) { h *= m; c8fold( in, m, k, h ); }

	const uint32_t m = 0x83d2e73b, n = 0x97e1cc59, *key4 = (const uint32_t *)key;
	uint32_t h = len + seed, k = n + len;
	uint64_t p;

	while ( len >= 8 ) { c8mix(key4[0]) c8mix(key4[1]) key4 += 2; len -= 8; }
	if ( len >= 4 ) { c8mix(key4[0]) key4 += 1; len -= 4; }
	if ( len ) { c8mix( key4[0] & ( ( 1 << ( len * 8 ) ) - 1 ) ) }
	c8fold( h ^ k, n, k, k )
		return k;
}

void Crap8_test ( const void * key, int len, uint32_t seed, void * out )
{
	*(uint32_t*)out = Crap8((const uint8_t*)key,len,seed);
}
