/*  说明：设置串口函数
 *  功能：设置波特率 串口几 以及发送接受函数
 *
 */
#include "serial.h"

volatile unsigned char UART1_FINGERPRINT_RECEVICE_BUFFER[24];	  


 int set_opt(int fd,int nSpeed, int nBits, char nEvent, int nStop)
{

    struct termios newtio,oldtio;
    if ( tcgetattr( fd,&oldtio) != 0) { 
        perror("SetupSerial 1");
        return -1;
    }
    bzero( &newtio, sizeof( newtio ) );
    newtio.c_cflag |= CLOCAL | CREAD; 
    newtio.c_cflag &= ~CSIZE; 
    newtio.c_oflag &= ~(ONLCR | OCRNL);  
    newtio.c_iflag &= ~(IXON | IXOFF | IXANY);   

	
    switch( nBits )
    {
    case 7:
        newtio.c_cflag |= CS7;
    break;
    case 8:
        newtio.c_cflag |= CS8;
    break;
    }
	
	
    switch( nEvent )
    {
    case 'O':
        newtio.c_cflag |= PARENB;
        newtio.c_cflag |= PARODD;
        newtio.c_iflag |= (INPCK | ISTRIP);
        break;
    case 'E': 
        newtio.c_iflag |= (INPCK | ISTRIP);
        newtio.c_cflag |= PARENB;
        newtio.c_cflag &= ~PARODD;
        break;
    case 'N': 
        newtio.c_cflag &= ~PARENB;
        break;
    }
	
	
    switch( nSpeed )
    {
    case 2400:
        cfsetispeed(&newtio, B2400);
        cfsetospeed(&newtio, B2400);
        break;
    case 4800:
        cfsetispeed(&newtio, B4800);
         cfsetospeed(&newtio, B4800);
        break;
    case 9600:
        cfsetispeed(&newtio, B9600);
        cfsetospeed(&newtio, B9600);
        break;
    case 115200:
        cfsetispeed(&newtio, B115200);
        cfsetospeed(&newtio, B115200);
        break;
    default:
        cfsetispeed(&newtio, B9600);
        cfsetospeed(&newtio, B9600);
        break;
    }
    if( nStop == 1 )
        newtio.c_cflag &= ~CSTOPB;
    else if ( nStop == 2 )
    newtio.c_cflag |= CSTOPB;
    newtio.c_cc[VTIME] =5; 
    newtio.c_cc[VMIN] = 0; 
	
    tcflush(fd,TCIFLUSH);
    if((tcsetattr(fd,TCSANOW,&newtio))!=0)
    {
        perror("com set error");
        return -1;
    }
    //printf("set done!\n");
    return 0;
}


 
int open_port(int fd,int comport)
{
    char *dev[]={"/dev/tq2440_serial0","/dev/tq2440_serial1","/dev/tq2440_serial2"};
    long vdisable;
    if (comport==0)
    {    fd = open( "/dev/tq2440_serial0", O_RDWR);
        if (-1 == fd){
            perror("Can't Open Serial Port");
            return(-1);
        }
        else 
            printf("open ttySAC0 .....\n");
    }
    else if(comport==1)
    {    fd = open("/dev/tq2440_serial1", O_RDWR|O_NOCTTY|O_NDELAY);

    if (-1 == fd){
        perror("Can't Open Serial Port");
            return(-1);
        }
        //else 
          //  printf("open ttySAC1 .....\n");
    }
    else if (comport==2)
    {
        fd = open( "/dev/tq2440_serial2", O_RDWR|O_NOCTTY|O_NDELAY);
        if (-1 == fd){
            perror("Can't Open Serial Port");
            return(-1);
        }
        else 
            printf("open ttySAC2 .....\n");
    }
    if(fcntl(fd, F_SETFL, 0)<0)
        printf("fcntl failed!\n");
    //else
      //  printf("fcntl=%d\n",fcntl(fd, F_SETFL,0));
    if(isatty(STDIN_FILENO)==0)
        printf("standard input is not a terminal device\n");
   // else
        // printf("isatty success!\n");
        //printf("fd-open=%d\n",fd);
    return fd;
}


 
int UART1_Send_Byte(unsigned char wbyte)
{
	int fd;
	int i;
	
        if(( fd=open_port(fd,0)) < 0){
   		perror("open_port error");
   		return -1;
	}

 	if(( i=set_opt(fd,9600,8,'N',1) ) < 0){
                //perror("set_opt error");
   		return -1;
	}
	
        write(fd,&wbyte,1);
        //printf("write %X succeed!\n",wbyte);
	close(fd);
    return 0;	
}

 
/*unsigned char UART1_Receive_Byte()
{
	int fd;
	int i;
	int rByte;
	unsigned char buff[1];
	unsigned char rbyte;

	if(( fd=open_port(fd,1)) < 0){
   		perror("open_port error");
   		return -1;
	}

 	if(( i=set_opt(fd,9600,8,'N',1) ) < 0){
   		perror("set_opt error");
   		return -1;
	}
	
	while( (rByte= read(fd, buff, 1)) == 0 )
	{}
	
	rbyte=buff[0];
	printf("Bytes is %X\n",rbyte);
	
	close(fd);

	return rbyte;
}
*/

 
void FINGERPRINT_Recevice_Data(unsigned char ucLength)
{
    int fd;
	int i,j;
	int rByte;
	unsigned char buff[1];
	unsigned char rbyte;

        if(( fd=open_port(fd,0)) < 0)
        {
                //perror("open_port error");
   		return -1;
	}

        if(( i=set_opt(fd,9600,8,'N',1) ) < 0)
        {
                //perror("set_opt error");
   		return -1;
	}
	
	for (j=0;j<ucLength;j++)
        {
		while((rByte= read(fd,buff,1))==0)
		{}
		UART1_FINGERPRINT_RECEVICE_BUFFER[j] = buff[0];
		buff[0]=0;
	}

	for(i=0;i<ucLength;i++)
	{
		printf("%X ",UART1_FINGERPRINT_RECEVICE_BUFFER[i]);
	}    
	printf("\n");

	
	close(fd);
}
