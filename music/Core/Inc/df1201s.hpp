/*
 * df1201s.hpp
 *
 *  Created on: Aug 5, 2024
 *      Author: NCPC
 */

#ifndef INC_DF1201S_HPP_
#define INC_DF1201S_HPP_

#include "main.h"
#include <cstring>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cstdio>
extern UART_HandleTypeDef huart1;
struct SenCommand
{
	uint8_t data[52];
	uint16_t leng;
};

enum PLAYBACK_MODE
{
	REPEAT_ONE_SONG=1,
	REPEAT_ALL,
	PLAY_ONE_SONE,
	PLAY_RANDOM,
	REPEAT_ALL_FOLDER
};

enum VOLUME
{
	VOLUME_SMALL=0,
	VOLUME_QUITE_SMALL = 5,
	VOLUME_MIDDLE =10,
	VOLUME_HIGH=20,
	VOLUME_MAX=30
};

typedef enum
{
	PLAY_AND_PAUSE,
	NEXT,
	LAST
}CtrlPlay;

enum CtrlQuery
{
	QueryFileNumberOfCurrentFile=1,
	QueryToTalNumberOfTheFiles,
	QueryThoiLuongBaiHatDangPhat,
	QueryTotalTimeOfCurrentFilePlaying,
	QueryFileName
};
enum PLAYNUM
{
	fileOne=1,
	fileTwo,
	fileThree,
	fileFour,
	fileFive
};
typedef enum
{
	ON,
	OFF
}EnableAmplifier;

typedef enum
{
	RECORD_AND_PAUSE,
	SAVE
}Recording;
class DF1201S
{
public:
	DF1201S();
	~DF1201S();
	void sendAT();
	void queryVOL();
	void enableAmplifier();
	void setMinVol();
	void setMiddleVol();
	void setHighVol();
	void setMaxVol();
	void setPlayMode();
	void queryplayMode();
	void playNumberOneMusic();
	void playNumberTwoMusic();

	void controlPlayMode(uint8_t n);
	void controlVol(uint8_t vol);
	void controlPlaying(CtrlPlay type);
	void controlFastRewind(uint8_t second);
	void controlQueryFile(uint8_t query);
	void controlPlayNumFile(uint8_t fileNum);
	void controlPlayFileSpecific(char *SpecificFile);
	void DeleteFile(void);
	void setAmplifier(EnableAmplifier state);

	void controlRecording(Recording type);
	void controlBaurate(uint16_t baudrate);

};



#endif /* INC_DF1201S_HPP_ */
