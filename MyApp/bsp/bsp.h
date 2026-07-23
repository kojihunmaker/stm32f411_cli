#ifndef BSP_H_
#define BSP_H_

#include "main.h"  // HAL_Delay 등을 쓰기 위한 HAL 헤더가 포함된 main.h
#include "def.h"

void bspInit(void);
void delay(uint32_t ms);
uint32_t millis(void);

#endif /* BSP_H_ */