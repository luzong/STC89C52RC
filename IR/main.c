#include <REGX52.H>
#include "IrReceive.h"
#include "stdio.h"

void UartInit(void)   //初始化波特率为9600
{
    SCON=0x50;  
    TMOD=0x20;
    TCON=0x40;
    TH1=0xfd;
    TI=1;
    TR1=1;
}
/*
 void delay(unsigned int k)	
{						
	unsigned int i,j;				
	for(i=0;i<k;i++)
	{			
		for(j=0;j<121;j++);
	}						
}
*/
void main(void)
{
//	unsigned char buf[6]
	IR_Init();
	UartInit();
	P1_2=1;
	while(1)
	{
		
	/*	
		
		//if(17664==IR_Get_KeyValue()){
			printf("%c",IrValue[2]);
		if('E'==IrValue[2] || 'F'==IrValue[2] || 'G'==IrValue[2]){
			printf("1234");
			delay(500);
			IrValue[2]='0';
		}
		else if('D'==IrValue[2] || '@'==IrValue[2] || 'C'==IrValue[2]){
			printf("5678");
			delay(500);
			IrValue[2]='0';
		}
			
		*/
		}
		//rm_KeyValue();
	}
