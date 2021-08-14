#include <REGX52.H>
#include "IrReceive.h"
#include "stdio.h"
void main(void)
{
	IR_Init();	//红外中断初始化
	P1_2=1;		//继电器常开
	while(1){};
	}
