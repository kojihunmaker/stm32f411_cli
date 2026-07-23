#include "bsp.h"

void bspInit(void) {
    // 초기화 코드 (필요 없으면 비워둠)
}

void delay(uint32_t ms) {
    HAL_Delay(ms);
}

uint32_t millis(void) {
    return HAL_GetTick();
}