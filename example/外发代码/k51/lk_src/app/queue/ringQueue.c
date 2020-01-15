/**
  ******************************************************************************
  * @file           : ringqueue.c
  * @author         : zjk
  * @version        : v1.0
  * @date           : 
  * @brief          : 顺序存储循环队列
  */
  
/* Includes ------------------------------------------------------------------*/
#include "queue/ringQueue.h" 



 /**************************************************************************************************
 * @fn    QStatus QueueInit(SqQueue* Q)
 *
 * @brief   缓存初始化
 * input parameters
 *
 * @Q: 缓存结构
 * output parameters
 *
 * None.
 *
 * @return      QStatus 状态
 */
 QStatus QueueInit(SqQueue* Q)
 {
    Q->front = 0;
    Q->rear = 0;
    return Q_OK;
}

  /**************************************************************************************************
 * @fn     int QueueLength(SqQueue *Q)
 *
 * @brief  返回Q的元素的个数，也就是当前队列的长度
 * input parameters
 *
 * @Q: 缓存结构
 * output parameters
 *
 * None.
 *
 * @return int    队列长度
 */
 int QueueLength(SqQueue *Q)
 {
    return (Q->rear - Q->front + MAXSIZE)%MAXSIZE;
 }



 /**
  * @brief  入队列，若队列未满，则插入元素e为新的队尾元素
  * @param  None
  * @retval None
  */
 QStatus Queue_push(SqQueue*Q,QElemType e)
 {
     if((Q->rear + 1)%MAXSIZE == Q->front)             /*队列 满 */
     return Q_ERROR;
     Q->data[Q->rear] = e;                             //将元素e赋值给队尾
     Q->rear =  (Q->rear +1 )%MAXSIZE;                 /*real 指针向后移动，若到最后则转到数组头部*/
     return Q_OK;
 }
  /**
  * @brief  出队列，若队列不空，则删除Q中对头元素，用e返回其值
  * @param  None
  * @retval None
  */
QStatus Queue_pop(SqQueue*Q,QElemType* e)
{
    if(Q->front == Q->rear)   /*队列空判断 */
    return Q_ERROR;
    *e = Q->data[Q->front];   //将队头元素付给e
    Q->front = (Q->front + 1)%MAXSIZE;
    return Q_OK;
 }
 
ringQueue_ops_t ringQueue_ops=
{
    .init = QueueInit,
    .getLength = QueueLength,
    .push = Queue_push,
    .pop = Queue_pop,
};






/************************ (C) COPYRIGHT ZiFiSense *****END OF FILE****/
