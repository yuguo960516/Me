/*
 * exram.c
 *
 *  Created on: 2017-6-18
 *      Author: yuguo
 */
#include "exsram.h"

unsigned int  *ExsramStart = (unsigned  int *)0x4000;
unsigned int  *ExsramEnd = (unsigned  int *)0xc000;

void write_exsram(unsigned int *buf,int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		*(ExsramStart+i)=*(buf+i);
	}
}

unsigned int *read_exsram(int offset,int length)
{
	unsigned int *buf;
	int i;
	for(i=0;i<length;i++)
	{
		*(buf+i)=*(ExsramStart+offset+i);
	}
	return buf;
}

void clear_exsram()
{
	int  i;
	for(i=0;i<32767;i++)
	{
		*(ExsramStart+i)=0x0000;
	}
}

