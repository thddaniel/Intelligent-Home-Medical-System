/*  说明：指纹模块底层调用函数
 *  功能：具体参照芯片手册
 *
 */

#include "fingerprint.h"



unsigned char FP_Pack_Head[6] = {0xEF,0x01,0xFF,0xFF,0xFF,0xFF};   
unsigned char FP_Get_Img[6] = {0x01,0x00,0x03,0x01,0x0,0x05};    
unsigned char FP_Templete_Num[6] ={0x01,0x00,0x03,0x1D,0x00,0x21 };  
//uchar FP_Search[11]={0x01,0x0,0x08,0x04,0x01,0x0,0x0,0x03,0xA1,0x0,0xB2};  
unsigned char FP_Search_0_9[11]={0x01,0x0,0x08,0x04,0x01,0x0,0x0,0x0,0x13,0x0,0x21};  
unsigned char FP_Img_To_Buffer1[7]={0x01,0x0,0x04,0x02,0x01,0x0,0x08};  
unsigned char FP_Img_To_Buffer2[7]={0x01,0x0,0x04,0x02,0x02,0x0,0x09};  
unsigned char FP_Reg_Model[6]={0x01,0x0,0x03,0x05,0x0,0x09};  
unsigned char FP_Delet_All_Model[6]={0x01,0x0,0x03,0x0d,0x00,0x11};
volatile unsigned char  FP_Save_Finger[9]={0x01,0x00,0x06,0x06,0x01,0x00,0x0B,0x00,0x19};  
//volatile uchar FP_Delete_Model[10]={0x01,0x00,0x07,0x0C,0x0,0x0,0x0,0x1,0x0,0x0};  


/*
void FINGERPRINT_Recevice_Data(unsigned char ucLength)
{
  unsigned char i;

  for (i=0;i<ucLength;i++)
        UART1_FINGERPRINT_RECEVICE_BUFFER[i] = UART1_Receive_Byte();
}*/


 
void FINGERPRINT_Cmd_Get_Img(void)
{
    unsigned char i;

    for(i=0;i<6;i++) 
        UART1_Send_Byte(FP_Pack_Head[i]);
    
    for(i=0;i<6;i++)  
        UART1_Send_Byte(FP_Get_Img[i]);
}


 
void FINGERPRINT_Cmd_Img_To_Buffer1(void)
{
 	    unsigned char i;
    
            for(i=0;i<6;i++)
            {
                  UART1_Send_Byte(FP_Pack_Head[i]);
            }
           
            for(i=0;i<7;i++)
            {
      		   UART1_Send_Byte(FP_Img_To_Buffer1[i]);
            }
}


void FINGERPRINT_Cmd_Img_To_Buffer2(void)
{
     unsigned char i;
     for(i=0;i<6;i++)
     {
            UART1_Send_Byte(FP_Pack_Head[i]);
     }
           
      for(i=0;i<7;i++)
      {
            UART1_Send_Byte(FP_Img_To_Buffer2[i]);
      }
}
 
 
void FINGERPRINT_Cmd_Reg_Model(void)
{
    unsigned char i;    

    for(i=0;i<6;i++)  
    {
        UART1_Send_Byte(FP_Pack_Head[i]);
    }

    for(i=0;i<6;i++)  
    {
        UART1_Send_Byte(FP_Reg_Model[i]);
    }

}

 

void FINGERPRINT_Cmd_Delete_All_Model(void)
{
     unsigned char i;    

    for(i=0;i<6;i++)  
        UART1_Send_Byte(FP_Pack_Head[i]);

    for(i=0;i<6;i++)  
        UART1_Send_Byte(FP_Delet_All_Model[i]);
}

/*
void FINGERPRINT_Cmd_Delete_Model(uint uiID_temp)
{
        volatile uint uiSum_temp = 0;
	uchar i;    
	 
	FP_Delete_Model[4]=(uiID_temp&0xFF00)>>8;
	FP_Delete_Model[5]=(uiID_temp&0x00FF);
	
	for(i=0;i<8;i++)
	    uiSum_temp = uiSum_temp + FP_Delete_Model[i];
		
			
	FP_Delete_Model[8]=(uiSum_temp&0xFF00)>>8;
	FP_Delete_Model[9]=uiSum_temp&0x00FF;
	 

    for(i=0;i<6;i++)  
        UART1_Send_Byte(FP_Pack_Head[i]);

    for(i=0;i<10;i++)  
        UART1_Send_Byte(FP_Delete_Model[i]);
}


*/
void FINGERPRINT_Cmd_Get_Templete_Num(void)
{ 
   unsigned int i;

   for(i=0;i<6;i++) 
        UART1_Send_Byte(FP_Pack_Head[i]);

   for(i=0;i<6;i++)
        UART1_Send_Byte(FP_Templete_Num[i]);
   
}


/*
void FINGERPRINT_Cmd_Search_Finger(void)
{
       uchar i;	   
       for(i=0;i<6;i++)
       {
    	      UART1_Send_Byte(FP_Pack_Head[i]);   
       }

       for(i=0;i<11;i++)
       {
    	      UART1_Send_Byte(FP_Search[i]);   
       }
} 
*/


void FINGERPRINT_Cmd_Search_Finger_Admin(void)
{
       unsigned char i;
       for(i=0;i<6;i++)
       {
             UART1_Send_Byte(FP_Pack_Head[i]);
       }

       for(i=0;i<11;i++)
       {
    	      UART1_Send_Byte(FP_Search_0_9[i]);   
       }
}	 


void FINGERPRINT_Cmd_Save_Finger( unsigned char ucH_Char,unsigned char ucL_Char )
{
           unsigned int temp = 0;
           unsigned char i;

           FP_Save_Finger[5] = ucH_Char;
           FP_Save_Finger[6] = ucL_Char;
           
           for(i=0;i<7;i++)
                 temp = temp + FP_Save_Finger[i];
			    
           FP_Save_Finger[7]=(temp & 0x00FF00) >> 8;
           FP_Save_Finger[8]= temp & 0x0000FF;
		   
           for(i=0;i<6;i++)    
                  UART1_Send_Byte(FP_Pack_Head[i]);

           for(i=0;i<9;i++)  
      		   UART1_Send_Byte(FP_Save_Finger[i]);       
}

