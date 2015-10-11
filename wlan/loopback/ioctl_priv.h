#ifndef _IOCTL_PRIV_H_
#define _IOCTL_PRIV_H_

#include <stdint.h>
#define MT6620_IOC_MAGIC    'm'

typedef struct _ENHANCE_MODE_DATA_STRUCT_T {
	uint32_t	irq;
	uint32_t	u4HISR;

	union {
		struct {
			uint8_t		ucTQ0Cnt;
			uint8_t		ucTQ1Cnt;
			uint8_t		ucTQ2Cnt;
			uint8_t		ucTQ3Cnt;
			uint8_t		ucTQ4Cnt;
			uint8_t		ucTQ5Cnt;
		} u;
		uint32_t	au4WTSR[2];
	} rTxInfo;

	union {
		struct {
			uint16_t	u2NumValidRx0Len;
			uint16_t	u2NumValidRx1Len;
			uint16_t	au2Rx0Len[16];
			uint16_t	au2Rx1Len[16];
		} u;
		uint32_t	au4RxStatusRaw[17];
	} rRxInfo;
		
	uint32_t	u4RcvMailbox0;
	uint32_t	u4RcvMailbox1;
} INTR_DATA_STRUCT_T;
 
struct int_enhance_arg_t {
	unsigned char rxNum;
	unsigned char totalBytes;
};


// list available ioctl here
#define MT6620_IOC_MAGIC	'm'

#define MT6620_IOC_GET_FUNC_FOCUS		_IOR(MT6620_IOC_MAGIC, 0, unsigned char)
#define MT6620_IOC_SET_FUNC_FOCUS		_IOW(MT6620_IOC_MAGIC, 1, unsigned char)
#define MT6620_IOC_GET_SDBUS_WIDTH		_IOR(MT6620_IOC_MAGIC, 2, unsigned char)
#define MT6620_IOC_SET_SDBUS_WIDTH		_IOW(MT6620_IOC_MAGIC, 3, unsigned char)
#define MT6620_IOC_GET_BUS_CLOCK		_IOR(MT6620_IOC_MAGIC, 4, unsigned int)
#define MT6620_IOC_SET_BUS_CLOCK		_IOW(MT6620_IOC_MAGIC, 5, unsigned int)
#define MT6620_IOC_READ_DIRECT			_IOR(MT6620_IOC_MAGIC, 6, unsigned char)
#define MT6620_IOC_WRITE_DIRECT 		_IOW(MT6620_IOC_MAGIC, 7, unsigned char)
#define MT6620_IOC_GET_ADDR				_IOR(MT6620_IOC_MAGIC, 8, unsigned int)
#define MT6620_IOC_SET_ADDR				_IOW(MT6620_IOC_MAGIC, 9, unsigned int)
#define MT6620_IOC_SET_FIFO_MODE		_IO(MT6620_IOC_MAGIC, 10)
#define MT6620_IOC_SET_INCR_MODE		_IO(MT6620_IOC_MAGIC, 11)
#define MT6620_IOC_GET_BLOCK_SIZE		_IOR(MT6620_IOC_MAGIC,12, unsigned int)
#define MT6620_IOC_SET_BLOCK_SIZE		_IOW(MT6620_IOC_MAGIC,13, unsigned int)
#define MT6620_IOC_QUERY_IRQ_LEVEL		_IOR(MT6620_IOC_MAGIC,14, INTR_DATA_STRUCT_T)
#define MT6620_IOC_SET_INT_ENHANCED 	_IOW(MT6620_IOC_MAGIC,15, struct int_enhance_arg_t)
#define MT6620_IOC_ENABLE_INTERRUPT		_IO(MT6620_IOC_MAGIC, 16)
#define MT6620_IOC_DISABLE_INTERRUPT	_IO(MT6620_IOC_MAGIC, 17)

#define MT6620_IOC_MAXNR 18


#endif //_IOCTL_PRIV_H_
