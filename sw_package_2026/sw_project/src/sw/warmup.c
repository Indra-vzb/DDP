/******************************************************************
 * This is the warmup file for the Software Session #1
 *
 */

#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include "common.h"

void customprint(uint8_t *in, char *str)
{
    int32_t i;

    xil_printf("%s = ",str);
    for (i = 0; i < 4; i++) {
    	xil_printf("0x%x,", in[i]);
    }
    xil_printf("\n\r");
}

void warmup()
{
	int32_t i;

	/** Useful commands:
	  *
	  *  Dereference: 	the * operator returns the value a pointer is
	  *  				pointing at
	  *  Reference:   	the & operator returns the address of a
	  *  				variable/pointer (location)
	**/

	/**
	  * TASK 1: Compile and execute the following in Pynq board:
	  *  	Project -> Build All
	  *  	Run As -> Launch on Hardware (System Debugger)
	  *
	  *	Make sure screen is opened in another terminal
	  *		screen /dev/ttyUSB1 115200
	  *
	  *
	  * QUESTION: Why do we get such output values for a,b,c?
	**/

    int32_t a;
    uint8_t b;
    int32_t *c;				// This is a pointer

    xil_printf("Value of a = %x\r\n", a);
    xil_printf("Value of b = %x\r\n", b);
    xil_printf("Value of c = %x\r\n", c);

 	/**
 	  * TASK 2
 	  * Uncomment the following code.
 	  * Write code that prints the value and the address of a, b and c.
 	  * For c also write a statement that prints the value c is pointing at.
 	**/

    a = 123;
	b = 0x55;
	c = &a; 				// c points to a

    xil_printf("Value of a = %d with its address: %p \r\n", a, &a);
    xil_printf("Value of b = %x with its address: %p \r\n", b, &b);
    xil_printf("Value of c = %d with its address: %p \r\n", *c, &c);

    /**
      * TASK 3
      * Uncomment the following code and write code that:
      *
 	  * 	1) initializes a_ar with a_ar[i]=i^2 (use a loop)
 	  *
	  * 	2) calculates the sum of the values in b_ar
	  *   	You may want to create a extra variable for the sum
    **/

	  int32_t a_ar[10];
	  int32_t b_ar[] = {1, 2, 3, 4};

	  for (int i = 0; i < 10; i++){
		  a_ar[i] = i*i;
		  xil_printf("element %d is now: %d \r\n",i, a_ar[i]);
	  }



	  uint8_t sizeofB;
	  sizeofB = sizeof(b_ar) / sizeof(b_ar[0]);
	  uint8_t sum = 0;
	  for (int i = 0; i<sizeofB;i++){
		  sum += b_ar[i];
	  }
	  xil_printf("value of the sum %d \r\n", sum);

    //TASK 4
	/**
	  * Arrays are also pointers.
         * 1) Find out the address of a_ar, b_ar, a_ar[0], and b_ar[0]
         *
         * 2) Find out where a_ar[1] and b_ar[1] are located (address).
         * 		What about the delta between a_ar[0] and a_ar[1]
         * 		respectively, b_ar[0] and b_ar[1]?
         * 3) Calculate the sum of the values in b_ar without using the
         * square braces '[' or ']'.
         * 		Use instead the * operator and pointer arithmetic.
	**/

	//1
	  xil_printf("address of a_ar : %d and a_ar[0] : %d \r\n", a_ar, &a_ar[0]);
	  xil_printf("address of b_ar : %d and b_ar[0] : %d \r\n", b_ar, &b_ar[0]);

	//2
	  xil_printf("address of a_ar[1] : %d and b_ar[1] : %d \r\n\n", &a_ar[1], &b_ar[1]);
	  xil_printf("size of one stored integer is : %d, \r\n\n" ,sizeof(a_ar[0]));

	  uint8_t diff1 = &a_ar[1]-&a_ar[0];
	  uint8_t diff2 = &b_ar[1]-&b_ar[0];

	  xil_printf("address of a_ar[0] : %d and a_ar[1]: %d with a delta of %d \r\n" , &a_ar[0], &a_ar[1],diff1);
	  xil_printf("address of b_ar[0] : %d and b_ar[1]: %d with a delta of %d \r\n" , &b_ar[0], &b_ar[1],diff2);

	 //3
	  uint8_t sumb = 0;

	  for (int i = 0; i<sizeofB ;i++){
		  sumb += *(b_ar + i);
	  }
	  xil_printf("the sumb is: %d \r\n\n", sumb);

    //TASK 5
	/**
	  * Uncomment the following lines
      *   Compute d*e (multiplication), such that the lower 32 bits
      *   in f[0] and the higher 32 bits in f[1]
      * Hint: use casting
	**/

    uint32_t d=0xCC8A79EE;
    uint32_t e=0x12234501;
    uint32_t f[2];

    // cast first to 64 bits and then multiply to get the correct output !!!!! (underneth is wrong)

//    uint64_t prod = d*e;
//    f[0] = (uint32_t) prod;
//    uint64_t rightShifted = ((d*e) >> 32);
//    f[1] = (uint32_t) rightShifted;
//
//    xil_printf("we concatenated: %d and %d and it should be: %d \r\n\n", f[1],f[0], d*e);
//
//




    //TASK 6
    /**
      * Uncomment the following lines
      *
      * Write a function sum that calculates the bytewise sum of
      * aa and bb and saves it in cc.
      *
      * You don't have to account for the carry.
      * Print cc with the 'customprint' function.
    **/

    uint8_t aa[] = {0x12, 0x23, 0x45, 0x78};
    uint8_t bb[] = {0x9A, 0xBC, 0xDE, 0xF0};
    uint8_t cc[4];

    int sumt6(uint8_t arr1[], uint8_t size_arr1, uint8_t arr2[], uint8_t size_arr2){

    }


    //TASK 7
    /**
      * Uncomment lines and run the code
      * Explain the values you see in output
      *
      * You can try debugging the code, setting breakpoints at each
      * memory write operation, and observing what happens in the
      * memory layout
      *   Debug As -> Launch on Hardware (System Debugger)
      *   Memory Monitors -> Add address (check the address value of or1 and/or or2)
      *
     **/

    //uint8_t or1[]={0xaa, 0xaa, 0xaa, 0xaa};
    //uint8_t or2[]={0xbb, 0xbb, 0xbb, 0xbb};

    //customprint(or1,"OR1");	

    //for(i=0; i<6; i++)
    //   or2[i] = 0xff;

    //customprint(or1,"OR1");	


}



