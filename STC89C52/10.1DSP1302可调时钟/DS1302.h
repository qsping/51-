#ifndef __DS1302_H__
#define __DS1302_H_

void DS1302_Init();
unsigned char DS1302_Time[];
void DS1302_WriteByte(unsigned char Command,Data);
unsigned char DS1302_ReadByte(unsigned char Command);

void DS1302_SetTime(void);//��ʱ��д��
void DS1302_ReadTime(void);//��ʱ�����
#endif