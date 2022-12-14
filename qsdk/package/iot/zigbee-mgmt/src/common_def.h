#ifndef COMMON_H
#define COMMON_H

#include<stdio.h>

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>


#define ZB_ERROR(fmt,args...) 	printf(fmt,##args)
#define ZB_PRINT(fmt,args...) 	printf(fmt,##args)
#define ZB_DBG(fmt,args...) 	printf(fmt,##args)


typedef unsigned char  zb_uint8;
typedef unsigned short zb_uint16;
typedef unsigned int   zb_uint32;
typedef unsigned long long   zb_uint64;


//serial data length.
#define SBUF_LEN	256


enum SERIAL_THREAD_STATUS
{
	S_THREAD_NOT_START,
	S_THREAD_RUNNING,
	S_THREAD_STOP
};


typedef struct serial_tx_buf
{
	zb_uint8 *dat;
	zb_uint8  dat_len;	
	zb_uint8  need_ack;	//we send out ack frame which not need ack again.
	
}serial_tx_buf_t;


#endif

