
 #ifndef _IR_H_
 #define _IR_H_
 
 /* 键值定义 ---------------------------------------------- */
 #define KEY_POWER 	0x45
 #define KEY_MENU  	0x47
 #define KEY_TEST  	0x44
 #define KEY_RETURN 0x43
 #define KEY_CANCEL 0x0D
 #define KEY_LAST	0x07
 #define KEY_NEXT	0x09
 #define KEY_OK  	0x15
 
 #define KEY_U	0X40
 #define KEY_D  0x19
 #define KEY_0 	0x16
 #define KEY_1 	0x0C
 #define KEY_2  0x18
 #define KEY_3  0x5E
 #define KEY_4  0x08
 #define KEY_5 	0x1C
 #define KEY_6 	0x5A
 #define KEY_7 	0x42
 #define KEY_8 	0x52
 #define KEY_9 	0x4A
 
 /* 变量定义 ---------------------------------------------- */
 
 sbit IRIN = P3^3;	//红外线输入管脚，同时也是单片机外部中断1

 extern unsigned char IrValue[6];	  //用来存放读取到的红外值
 /* 函数声明 ---------------------------------------------- */
 
 void IR_Init();					   //初始化红外接收
 //unsigned char IR_Get_KeyValue( void ); //获取键值
 //void rm_KeyValue( void );
	 
 #endif /* _IR_H_ */
