#ifndef __RINGQUEUE_H
#define __RINGQUEUE_H	 
/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

/* Private types -------------------------------------------------------------*/
/**
  * @brief  队列大小
  */
#define  MAXSIZE   50
/**
  * @brief  
  */
typedef uint8_t QElemType;
typedef enum 
{
  Q_OK = 0, 
  Q_ERROR = !Q_OK
} QStatus;

/**
  * @brief  循环队列顺序存储结构 
  */
typedef struct
{
	QElemType data[MAXSIZE];
	int front;   /* 头指针 */
	int rear;    /* 尾指针 */
}SqQueue;


typedef struct 
{
  QStatus (*init)(SqQueue* Q);
  int (*getLength)(SqQueue* Q);
  QStatus (*push)(SqQueue* Q,QElemType e); 
  QStatus (*pop)(SqQueue* Q,QElemType* e);  
}ringQueue_ops_t;


extern ringQueue_ops_t ringQueue_ops;



#endif /* __RINGQUEUE_H */

