#ifndef __FINGERPRINT_H__
#define __FINGERPRINT_H__

#include "serial.h"



//void FINGERPRINT_Recevice_Data(unsigned char ucLength);

void FINGERPRINT_Cmd_Get_Img(void);
void FINGERPRINT_Cmd_Img_To_Buffer1(void);
void FINGERPRINT_Cmd_Img_To_Buffer2(void);
void FINGERPRINT_Cmd_Reg_Model(void);
void FINGERPRINT_Cmd_Delete_All_Model(void);
//void FINGERPRINT_Cmd_Delete_Model(uint uiID_temp);
void FINGERPRINT_Cmd_Get_Templete_Num(void);
//void FINGERPRINT_Cmd_Search_Finger(void);
void FINGERPRINT_Cmd_Search_Finger_Admin(void);
void FINGERPRINT_Cmd_Save_Finger( unsigned char ucH_Char,unsigned char ucL_Char );


#endif