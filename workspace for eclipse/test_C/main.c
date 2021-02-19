/*
 * main.c
 *
 *  Created on: Jan 9, 2021
 *      Author: hossam
 */
#include <stdio.h>
#include "../Lib/Std_Types.h"
typedef struct {
	u8 x;
	u32 y;

}Str;
//__attribute__((packed));

int main(void){

	printf("Size of Struct  : %i \n",sizeof(Str));

	return 0;
}

