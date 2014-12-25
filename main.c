/*
 * main.c
 *
 *  Created on: Dec 25, 2014
 *      Author: joao
 */


#include <mpsse.h>
#include <stdio.h>

#define WCMD	"\xA0\x00\x00"	// Write start address command
#define RCMD	"\xA1"		// Read command

int main(int argc, char **argv) {

	struct mpsse_context *scan = NULL;
	//scan = MPSSE(I2C, ONE_HUNDRED_KHZ, MSB);

	if((scan = MPSSE(I2C, FOUR_HUNDRED_KHZ, MSB)) != NULL && scan->open)
	{
		int addr;
		for (addr = 0; addr < 0x7F; ++addr)
		{
			char addr_wr = addr << 1;
			Start(scan);
			Write(scan, &addr_wr, 1);

			if(GetAck(scan) == ACK)
			{
				printf("found at %x\n" , addr<<1);
			}
			else
			{
				printf("not found at %x\n" , addr<<1);
			}
			Stop(scan);
		}
	}
	Close(scan);

	return 0;
}
