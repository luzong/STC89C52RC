#include <REGX52.H>
#include "IrReceive.h"

unsigned char Time;
unsigned char IrValue[6];
 
 /* 函数声明 ----------------------------------------------- */
 void Delay140us(unsigned int );	
									 
/*******************************************************************************
* 函数           : Delay140us()
* 函数功能		 : 延时
* 输入           : x
* 输出         	 : 无
*******************************************************************************/

void Delay140us(unsigned int x)   //0.14ms误差 0us
{
	unsigned char i;
	while(x--)
	{
		for (i = 0; i<12; i++)
		{}
	}
}
/**********************************************************
 * 函数名称 : IR_Init()
 * 功    能 : 初始化红外线接收
 * 备    注 : 初始化外部中断1
 **********************************************************/
void IR_Init()
{
	IT1=1;   //下降沿触发
	EX1=1;   //打开中断0允许
	EA=1;	 //打开总中断
	IRIN=1;  //初始化端口
}

/**********************************************************
 * 函数名称 : ReadIr()
 * 功    能 : 接受红外线信号并进行解码
 * 备    注 : 外部中断1中断函数
 ***********************************************************/
void ReadIr() interrupt 2
{
	unsigned char j,k;
	unsigned int err;
	Time=0;					 
	Delay140us(60);

	if(IRIN==0)		//确认是否真的接收到正确的信号
	{	 
		err=1000;				//1000*10us=10ms,超过说明接收到错误的信号
		/*当两个条件都为真是循环，如果有一个条件为假的时候跳出循环，免得程序出错的时
		侯，程序死在这里*/	
		while((IRIN==0)&&(err>0))	//等待前面9ms的低电平过去  		
		{			
			Delay140us(1);
			err--;
		} 
		if(IRIN==1)			//如果正确等到9ms低电平
		{
			err=500;
			while((IRIN==1)&&(err>0))		 //等待4.5ms的起始高电平过去
			{
				Delay140us(1);
				err--;
			}
			for(k=0;k<4;k++)		//共有4组数据
			{				
				for(j=0;j<8;j++)	//接收一组数据
				{

					err=60;		
					while((IRIN==0)&&(err>0))//等待信号前面的560us低电平过去
					{
						Delay140us(1);
						err--;
					}
					err=500;
					while((IRIN==1)&&(err>0))	 //计算高电平的时间长度。
					{
						Delay140us(1);//0.14ms
						Time++;
						err--;
						if(Time>30)
						{
							EX1=1;
							return;
						}
					}
					IrValue[k]>>=1;	 //k表示第几组数据
					if(Time>=8)			//如果高电平出现大于565us，那么是1
					{
						IrValue[k]|=0x80;
					}
					Time=0;		//用完时间要重新赋值							
				}
			}
		}
		if(IrValue[2]!=~IrValue[3])
		{
			return;
		}
		else if('E'==IrValue[2] || 'F'==IrValue[2] || 'G'==IrValue[2]){
			P1_2=1;
			IrValue[2]='0';
		}
		else if('D'==IrValue[2] || '@'==IrValue[2] || 'C'==IrValue[2]){
			P1_2=0;
			IrValue[2]='0';
		}
		
	}	
}

/**********************************************************
 * 函数名称 : IR_Get_KeyValue
 * 功    能 : 取得红外线信号中命令码
 * 输    出 : 命令码（键值）
********************************************************
unsigned char IR_Get_KeyValue( void )
{
	return IrValue[2];
}

void rm_KeyValue( void )
{
	IrValue[6]=0;
}
***/