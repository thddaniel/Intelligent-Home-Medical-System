#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

extern volatile unsigned char UART1_FINGERPRINT_RECEVICE_BUFFER[24];

int UART1_Send_Byte(unsigned char wbyte);
//unsigned char UART1_Receive_Byte();
void FINGERPRINT_Recevice_Data(unsigned char ucLength);
int set_opt(int fd,int nSpeed, int nBits, char nEvent, int nStop);
int open_port(int fd,int comport);
#endif
