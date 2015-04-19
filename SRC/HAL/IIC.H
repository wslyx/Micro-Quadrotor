#ifndef __IIC_H__
#define __IIC_H__

#include "stm32f10x.h"

//-----IO��������-----//
#define SDA_IN()  {GPIOA->CRH&=0XFFF0FFFF;GPIOA->CRH|=8<<16;}	// �����޸�Ϊ����ģʽ,����������
#define SDA_OUT() {GPIOA->CRH&=0XFFF0FFFF;GPIOA->CRH|=3<<16;}	// �����޸�Ϊ50MHZ��������������üĴ����ķ�ʽ�ٶȸ���

//-----IO��������-----// 
#define IIC_SCL_H    GPIO_SetBits(GPIOA, GPIO_Pin_11) 			// SCL_H
#define IIC_SCL_L    GPIO_ResetBits(GPIOA, GPIO_Pin_11) 		// SCL_L
#define IIC_SDA_H    GPIO_SetBits(GPIOA, GPIO_Pin_12) 			// SDA_H
#define IIC_SDA_L    GPIO_ResetBits(GPIOA, GPIO_Pin_12) 		// SDA_L 
#define READ_SDA  	 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12)  // ����SDA


//-----IIC���в�������-----//
void IIC_Init(void);			// ��ʼ��IIC��IO��				 
void IIC_Start(void);			// ����IIC��ʼ�ź�
void IIC_Stop(void);	  		// ����IICֹͣ�ź�
void IIC_Send_Byte(u8 txd);		// IIC����һ���ֽ�
u8 IIC_Read_Byte(u8 ack);		// IIC��ȡһ���ֽ�
u8 IIC_Wait_Ack(void); 			// IIC�ȴ�ACK�ź�
void IIC_Ack(void);				// IIC����ACK�ź�
void IIC_NAck(void);			// IIC������ACK�ź�

#endif