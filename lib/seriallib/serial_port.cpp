#include"serial_port.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <iostream>
using namespace std;



namespace serialport{


//int set_opt(int,int,int,char,int);
int serial_OpenPort(const char* uartname)
{
    cout << "trying to open serial port:" << uartname <<endl;
    int fd = open(uartname, O_RDWR|O_NOCTTY|O_NONBLOCK);
    if (-1 == fd)
    {
        cout << "Can't Open Serial Port";
        return(-1);
    }
     /*恢复串口为阻塞状态*/
     if(fcntl(fd, F_SETFL, 0)<0)
     {
            cout << "fcntl failed" << endl;
     }else{
        //printf("fcntl=%d\n",fcntl(fd, F_SETFL,0));
        cout << "fcntl=" << fcntl(fd, F_SETFL,0) << endl;
     }
     /*测试是否为终端设备*/
     if(isatty(STDIN_FILENO)==0)
     {
        cout << "standard input is not a terminal device" << endl;
     }
     else
     {
        cout << "isatty success!" << endl;        
     }
     printf("fd-open=%d\n",fd);
      cout << "ifd-open=" << fd << endl;        
     return fd;
}



int serial_ClosePort(int fd)
{
    if(fd >= 0 ){
        fd=close(fd);
	cout<<"serial port closed!"<<endl;
        return fd;
    }
       
    else{
         cout<< "error no port open!" << endl;
         return -1;
    }    
}

int serial_WriteData(int fd,const char *data, int datalength )
{
    int res = 0;
    cout << "fuck serial_WriteData" << endl;
    
    const char* n = "\r\n"; 
    res = write(fd, data, datalength); 
    res = write(fd, n, sizeof(n)); 
    
    if(res != 0)
    	return 0;

   else 
	return -1;

}


int serial_ReadData(int fd, char *data, int datalength)
{ 
    return read(fd, data, datalength);  
}




int serial_SetParameters(int fd,int nSpeed, int nBits, char nEvent, int nStop)
{
    struct termios newtio,oldtio;
    if  ( tcgetattr( fd,&oldtio)  !=  0) {
        perror("SetupSerial 1");
        return -1;
    }
    bzero( &newtio, sizeof( newtio ) );
    newtio.c_cflag  |=  CLOCAL | CREAD;
    newtio.c_cflag &= ~CSIZE;
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
    case 460800:
        cfsetispeed(&newtio, B460800);
        cfsetospeed(&newtio, B460800);
        break;
    case 921600:
        printf("B921600\n");
        cfsetispeed(&newtio, B921600);
                cfsetospeed(&newtio, B921600);
        break;
    default:
        cfsetispeed(&newtio, B9600);
        cfsetospeed(&newtio, B9600);
        break;
    }
    if( nStop == 1 )
        newtio.c_cflag &=  ~CSTOPB;
    else if ( nStop == 2 )
    newtio.c_cflag |=  CSTOPB;
    newtio.c_cc[VTIME]  = 0;
    newtio.c_cc[VMIN] = 0;
    tcflush(fd,TCIFLUSH);
    if((tcsetattr(fd,TCSANOW,&newtio))!=0)
    {
        perror("com set error");
        return -1;
    }
    cout << "set down" << endl;
    cout << fd<<"\t"<< nSpeed<<"\t" << nBits<<"\t" << nEvent<<"\t" << nStop<<"\t" << endl;
    return 0;
}
}
