/*
 * mp_arith.c
 *
 */

#include <stdint.h>


// calculate the sum first by casting first both numbers to 64 bit then the sum will have its carry
// bit on
void mp_add(uint32_t *a, uint32_t *b, uint32_t *res, uint32_t size)
{
	uint64_t sum;
	uint32_t carry = 0;

	for(uint32_t i = 0; i<size ; i++)
	{
		sum = (uint64_t)a[i] + b[i] + carry;    // 64 bit so that it can't overflow if carry
		res[i] = (uint32_t)sum; 				// low 32 bits = (a+b+c)mod W
		carry = (uint32_t)(sum >> 32); 			// high bits = carry (1 or 0)
	}
	res[size] = carry;							// t_n = c

}



void mp_sub(uint32_t *a, uint32_t *b, uint32_t *res, uint32_t size)
{
	uint64_t diff;
	uint32_t borrow = 0;

	for(uint32_t i = 0 ; i<size ; i++)
	{
		diff = (uint64_t)a[i] - b[i] - borrow;
		res[i] = (uint32_t)diff;
		borrow = (uint32_t)(diff >> 32) & 1; // upper half is either all 0s(no borrow) or all 1s (borrow)
	}
	res[size] = borrow;
}



void mod_add(uint32_t *a, uint32_t *b, uint32_t *N, uint32_t *res, uint32_t size)
{
	uint32_t sum[size + 1];
	mp_add(a, b, sum, size);

	mp_sub(sum, N, res, size);

	uint32_t borrow = res[size];

	// sum < N only if the top word is 0 and the subtraction borrowed
	if (sum[size] == 0 && borrow)
	{
		for (uint32_t i = 0; i < size; i++)
		{
			res[i] = sum[i];
		}
	}
}



void mod_sub(uint32_t *a, uint32_t *b, uint32_t *N, uint32_t *res, uint32_t size)
{
	uint32_t borrow = mp_sub(a, b, res, size);
	if (borrow)
	{
		uint_32_t tmp[size=1];
		mp_add(res, N, tmp, size)
		for (uint32_t i = 0; i < size; i++)
			res[i] = tmp[i]
	}
}


