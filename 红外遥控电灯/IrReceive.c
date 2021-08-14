#include <REGX52.H>
#include "IrReceive.h"

 void delay(unsigned int k)	
{						
	unsigned int i,j;				
	for(i=0;i<k;i++)
	{			
		for(j=0;j<121;j++);
	}						
}
//函数名称 : IR_Init() 初始化外部中断1
void IR_Init()
{
	IT1=0;   //上升沿触发
	EX1=1;   //打开中断0允许
	EA=1;	 //打开总中断
	IRIN=1;  //初始化端口
}

//函数名称 : ReadIr()  外部中断1中断函数
void ReadIr() interrupt 2
{
	P1_2=!P1_2;		//继电器电灯开关取反
	delay(200);		//延时滤波去抖
}
