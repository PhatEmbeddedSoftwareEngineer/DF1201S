/*
 * df1201s.cpp
 *
 *  Created on: Aug 5, 2024
 *      Author: NCPC
 */

#include "df1201s.hpp"
struct SenCommand _send;
DF1201S::DF1201S()
{

}

DF1201S::~DF1201S()
{


}
static void baseSend()
{
	_send.leng = sizeof(_send.data)/sizeof(_send.data[0]);
	HAL_UART_Transmit(&huart1, _send.data, _send.leng, HAL_MAX_DELAY);
	memset(_send.data,0x00,sizeof( _send.data));
	HAL_Delay(2000);
}
void DF1201S::sendAT()
{

	strcpy((char*)_send.data,"AT\r\n");
	baseSend();
}

void DF1201S::queryVOL()
{
	strcpy((char*)_send.data,"AT+VOL=?\r\n");
	baseSend();
}

void DF1201S::enableAmplifier()
{
	strcpy((char*)_send.data,"AT+AMP=ON\r\n");
	baseSend();
}

void DF1201S::setMinVol()
{
	strcpy((char*)_send.data,"AT+VOL=+5\r\n");
	baseSend();
}

void DF1201S::setMiddleVol()
{
	strcpy((char*)_send.data,"AT+VOL=+10\r\n");
	baseSend();
}
void DF1201S::setHighVol()
{
	strcpy((char*)_send.data,"AT+VOL=+20\r\n");
	baseSend();
}
void DF1201S::setMaxVol()
{
	strcpy((char*)_send.data,"AT+VOL=+30\r\n");
	baseSend();
}
void DF1201S::setPlayMode()
{
	/*
	 * phat xong 1 bai roi dung*/
	strcpy((char*)_send.data,"AT+PLAYMODE=3\r\n");
	baseSend();
}
void DF1201S::queryplayMode()
{
	strcpy((char*)_send.data,"AT+PLAYMODE=?\r\n");
	baseSend();
}
void DF1201S::playNumberOneMusic()
{
	strcpy((char*)_send.data,"AT+PLAYNUM=1\r\n");
	baseSend();
}
void DF1201S::playNumberTwoMusic()
{
	strcpy((char*)_send.data,"AT+PLAYNUM=2\r\n");
	baseSend();
}

void DF1201S::controlPlayMode(uint8_t n)
{
	/*
	 * 1. lặp 1 bài mãi mãi
	 * 2. lặp tất cả các bài
	 * 3. phát 1 bài sau đó dừng lại
	 * 4. phát random nhiều bài
	 * 5. lặp lại tất cả bài trong folder
	 * ?. truy vấn chế độ playmode hiện tại
	 * */

	//uint8_t data[20];
	sprintf((char*)_send.data,"AT+PLAYMODE=%d\r\n",n);
	baseSend();

}

void DF1201S::controlVol(uint8_t vol)
{
	sprintf((char*)_send.data,"AT+VOL=%d\r\n",vol);
	baseSend();
}

void DF1201S::controlPlaying(CtrlPlay type)
{
	if(type == PLAY_AND_PAUSE)
	{
		strcpy((char*)_send.data,"AT+PLAY=PP\r\n");
		baseSend();
	}
	if(type == NEXT)
	{
		strcpy((char*)_send.data,"AT+PLAY=NEXT\r\n");
		baseSend();
	}
	if(type==LAST)
	{
		strcpy((char*)_send.data,"AT+PLAY=LAST\r\n");
		baseSend();
	}
}

void DF1201S::controlFastRewind(uint8_t second)
{
	/*
	 * ex: second = -5 or second = 5
	 * */
	sprintf((char*)_send.data,"AT+TIME=%d\r\n",second);
	baseSend();

}

void DF1201S::controlQueryFile(uint8_t query)
{
	sprintf((char*)_send.data,"AT+QUERY=%d\r\n",query);
	baseSend();
}

void DF1201S::controlPlayNumFile(uint8_t fileNum)
{
	sprintf((char*)_send.data,"AT+PLAYNUM=%d\r\n",fileNum);
	baseSend();
}

void DF1201S::controlPlayFileSpecific(char *SpecificFile)
{
	sprintf((char*)_send.data,"AT+PLAYFILE=%s\r\n",SpecificFile);
	baseSend();
}
void DF1201S::DeleteFile(void)
{
	strcpy((char*)_send.data,"AT+DEL\r\n");
	baseSend();
}
void DF1201S::setAmplifier(EnableAmplifier state)
{
	if(state == ON)
	{
		strcpy((char*)_send.data,"AT+AMP=ON\r\n");
	}
	else
	{
		strcpy((char*)_send.data,"AT+AMP=OFF\r\n");
	}
	baseSend();
}

void DF1201S::controlRecording(Recording type)
{
	if(type == RECORD_AND_PAUSE)
	{
		strcpy((char*)_send.data,"AT+REC=RP\r\n");
	}
	else
	{
		strcpy((char*)_send.data,"AT+REC=SAVE\r\n");
	}
	baseSend();
}

void DF1201S::controlBaurate(uint16_t baudrate)
{
	/*
	 * @Param
	 * 9600,19200,38300,57600,115200
	 * */
	sprintf((char*)_send.data,"AT+BAUDRATE=%d\r\n",baudrate);
	baseSend();
}



