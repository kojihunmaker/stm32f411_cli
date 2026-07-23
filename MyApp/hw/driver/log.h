#ifndef _HW_DRIBER_LOG_H_
#define _HW_DRIBER_LOG_H_
#include "def.h"
#include "hw_def.h"
#include "log_def.h"
#include "uart.h"
#include "cli.h"
bool logInit();
void logSetLevel(uint8_t Level);
uint8_t logGetRuntimeLevel();
void cliLog(uint8_t argc, char** argv);

#endif