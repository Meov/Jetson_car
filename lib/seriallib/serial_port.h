#ifndef __SERIAL_H__
#define __SERIAL_H__

#ifdef __cplusplus
    extern "C"{
#endif
namespace serialport{


//open the serial port uartname
int serial_OpenPort(const char* uartname);
//close opend serial port
int serial_ClosePort(int fd);
int serial_WriteData(int fd,const char *data, int datalength);
int serial_ReadData(int fd, char *data, int datalength);
int serial_SetParameters(int fd,int nSpeed, int nBits, char nEvent, int nStop);

}
 
#ifdef __cplusplus
    }
#endif
#endif
