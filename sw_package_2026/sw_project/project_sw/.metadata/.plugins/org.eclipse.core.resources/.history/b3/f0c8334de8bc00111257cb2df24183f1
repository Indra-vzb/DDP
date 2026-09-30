/******************************************************************
 * This is the main file for the Software Sessions
 *
 */

#include <stdint.h>
#include <inttypes.h>
#include "mp_arith.h"

#include "common.h"

// Uncomment for Session SW1
extern void warmup();

// Uncomment for Session SW2 onwards
//#include "mp_arith.h"
//#include "montgomery.h"
//#include "asm_func.h"


int main()
{
    init_platform();
    init_performance_counters(1);

    // Hello World template
    //----------------------
    xil_printf("Begin\n\r");

START_TIMING

    xil_printf("Hello World!\n\r");
	uint32_t a[32]   = { 0xba05733c, 0x12c73d39, 0x527ffea6, 0x7e564b45, 0x0f8b4cc3, 0x43e14e6a, 0xb256e6f5, 0xbe584b90, 0xbde591df, 0x991785b1, 0x806759ec, 0x043c7b70, 0x2fe03526, 0xea605a09, 0x72c9797e, 0x94c1ffbf, 0xee754dec, 0xfee99d64, 0x9f0ae430, 0x475bf74f, 0xb257a194, 0x3861bab4, 0x70fa22d1, 0x95a12def, 0xc5f6d4e9, 0xe45a8fcb, 0xfa163f0a, 0xe61b39fa, 0xb8954aa3, 0x3c2b670f, 0x2d1fc3c8, 0xc25ddd00 };
	uint32_t b[32]   = { 0xd659064b, 0x72d587b4, 0x167aaa94, 0x14464102, 0xdf5ead97, 0x924f3b77, 0x4a419d3d, 0x424dfc43, 0x69dcf522, 0x9b684f8a, 0x2da2a6d7, 0x7e44e123, 0xdab4b334, 0xc7ab27aa, 0x2f2aebc9, 0x95e47169, 0xa4ac6e62, 0x72f38c0e, 0xf68c189f, 0xc47aa374, 0x9856817f, 0xf9cf7378, 0xbcd598a0, 0x5ac40fec, 0xbeb6702d, 0xd415d561, 0x4e51b58f, 0x118e6b2d, 0x626b4a55, 0x943366ee, 0x67fe878e, 0xe3a22c41 };
	uint32_t res[33];
	uint32_t c[33]   = { 0x905e7987, 0x859cc4ee, 0x68faa93a, 0x929c8c47, 0xeee9fa5a, 0xd63089e1, 0xfc988432, 0x00a647d3, 0x27c28702, 0x347fd53c, 0xae0a00c4, 0x82815c93, 0x0a94e85a, 0xb20b81b4, 0xa1f46548, 0x2aa67128, 0x9321bc4f, 0x71dd2973, 0x9596fcd0, 0x0bd69ac4, 0x4aae2314, 0x32312e2d, 0x2dcfbb72, 0xf0653ddc, 0x84ad4516, 0xb870652d, 0x4867f49a, 0xf7a9a528, 0x1b0094f8, 0xd05ecdfe, 0x951e4b56, 0xa6000941, 0x00000001 };

	uint32_t size = 32;
	mp_add(a,b,res,size);
	xil_printf("\n\nOur result : ");
	// print the result we got
	  for (int i = 0; i < 33; i++){
		  xil_printf("%x,",res[i]);
	  }
	  xil_printf("\r\n\n");





	for (int i = 0; i < 33; i++){
		if (c[i] != res[i]){
			xil_printf("failed on %d \n\r", i);
			return -1;
		}
	}




STOP_TIMING

	xil_printf("End\n\r");

    // SW1: warmup exercise
    //----------------------

    cleanup_platform();

    return 0;
}
