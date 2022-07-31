	  ORG 0000H			 ;程序开始
	  AJMP MAIN			 ;
	  ORG 0003H			 ;外部中断0入口
	  AJMP INT0X		 ;
	  ORG 0100H		     ;主程序入口
 MAIN:MOV SP,#30H
      MOV IE,#81H		 ;SETB EA;SETB EX0
	  MOV TCON,#01H		 ;(SETB IT0)  //CLR IT0
 HERE:SJMP $
INT0X:CPL P1.1
	  ;JNB P3.2,$  //电平触发方式，防止误操作
	  RETI
	  END