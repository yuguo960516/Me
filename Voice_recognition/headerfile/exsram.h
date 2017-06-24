/*
 * exsram.h
 *
 *  Created on: 2017-6-18
 *      Author: yuguo
 */

#ifndef EXSRAM_H_
#define EXSRAM_H_

void write_exsram(unsigned int *start,int length);
unsigned int *read_exsram(int offset,int length);
void clear_exsram();

#endif /* EXSRAM_H_ */
