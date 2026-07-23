# stm32f411_cli

STM32F411 보드(Nucleo-F411RE 기준) 위에서 동작하는 **FreeRTOS 기반 UART CLI 펌웨어**입니다. USB-UART로 보드에 접속해 LED, GPIO, ADC(온도), 시스템 정보 등을 명령어로 제어/조회할 수 있고, 센서 값을 주기적으로 송신하는 모니터링 모드도 지원합니다.

## 주요 기능

- 자체 구현한 셸(CLI): 명령어 파싱, 방향키(↑/↓) 히스토리, 백스페이스, Ctrl+C 처리
- LED 제어 (on/off/toggle, 자동 토글 주기 설정)
- 임의 GPIO 핀 read/write (`a`~`h` 포트, `0`~`15` 핀)
- 메모리 덤프(`md`) — Flash/RAM/시스템 메모리/페리페럴 레지스터 영역만 안전하게 접근
- MCU 내부 온도 센서 읽기 (ADC + DMA)
- 버튼(B1) 인터럽트 on/off 및 로그 출력
- 레벨별 컬러 로그 시스템 (FATAL~VERBOSE, 런타임 레벨 조절)
- `mon` 명령으로 여러 센서 값을 ASCII 패킷(`$개수,id:type:value,...#`)으로 주기적 송신하는 모니터링 모드

## 하드웨어

| 항목 | 내용 |
|---|---|
| MCU | STM32F411xE (Cortex-M4) |
| UART | USART2, 115200bps, PA2(TX)/PA3(RX) |
| LED | PA5 (Nucleo LD2) |
| Button | PC13 (Nucleo B1), 하강엣지 EXTI 인터럽트 |
| ADC | ADC1, 내부 온도센서 채널, DMA(DMA2_Stream0) 연속 변환 |
| Timebase | TIM10 (SysTick 대신 HAL 타임베이스로 사용) |
| 클럭 | HSI → PLL |

## 폴더 구조

```
stm32f411_cli/
├── Core/                       # STM32CubeMX 자동 생성 (main, 클럭, ISR 등)
├── Drivers/                    # ST 표준 라이브러리 (CMSIS, HAL v1.8.5)
├── Middlewares/Third_Party/    # FreeRTOS Kernel V10.3.1
├── MyApp/                      # 애플리케이션 코드 (직접 작성)
│   ├── ap/                     # CLI 명령, FreeRTOS 태스크, 모니터링 프로토콜
│   ├── bsp/                    # millis(), delay() 등 보드 지원 함수
│   ├── common/                 # 공통 헤더, 로그 매크로
│   └── hw/driver/              # uart, led, button, temp, gpio, cli, log 드라이버
├── cmake/                      # 툴체인 및 CubeMX CMake 설정
├── CMakeLists.txt
├── CMakePresets.json
├── STM32F411XX_FLASH.ld        # 링커 스크립트
├── startup_stm32f411xe.s       # 시작 코드
└── stm32f411_cli.ioc           # STM32CubeMX 프로젝트 파일
```

## 빌드 방법

`arm-none-eabi-gcc` 툴체인과 `CMake`(3.22+), `Ninja`가 필요합니다.

```bash
# Debug 빌드
cmake --preset Debug
cmake --build --preset Debug

# Release 빌드
cmake --preset Release
cmake --build --preset Release
```

빌드 결과물은 `build/<Debug|Release>/` 에 생성됩니다. VS Code + CMake Tools, 또는 STM32CubeIDE에서도 CubeMX(`stm32f411_cli.ioc`)로 재생성하여 사용할 수 있습니다.

## 플래싱

ST-Link를 통해 STM32CubeProgrammer, OpenOCD, 또는 VS Code `launch.json`에 설정된 디버거로 플래싱합니다.

## CLI 사용법

시리얼 터미널(115200 8N1)로 USART2에 접속한 뒤 명령어를 입력합니다.

| 명령어 | 설명 |
|---|---|
| `help` | 등록된 전체 명령어 목록 출력 |
| `cls` | 화면 지우기 |
| `led [on\|off]` / `led toggle [period]` | LED 켜기/끄기/토글, 주기(ms) 지정 시 자동 토글 |
| `info` / `info uptime` | HW 모델, FW 버전, UID, DevID, 가동시간 출력 |
| `sys reset` | 소프트웨어 리셋 |
| `gpio read [a~h][0~15]` | 지정 핀 상태 읽기 |
| `gpio write [a~h][0~15] [0\|1]` | 지정 핀 출력 |
| `md [addr(hex)] [length]` | 메모리 덤프 (예: `md 08000000 32`) |
| `button [on\|off]` | 버튼 인터럽트 리포트 on/off |
| `temp` / `temp [period]` | 온도 1회 읽기 / 주기적(ms) 자동 읽기 |
| `mon [on\|off] [period]` | 센서 모니터링 모드 on/off, 전송 주기(ms) 설정 |
| `log get` / `log set [0~5]` | 런타임 로그 레벨 조회/설정 (0:FATAL ~ 5:VERBOSE) |

## 라이선스

`Drivers/`, `Middlewares/`는 STMicroelectronics 및 FreeRTOS의 라이선스를 따릅니다(각 폴더 내 `LICENSE.txt` 참고). `MyApp/`, `Core/` 등 이 프로젝트 고유 코드의 라이선스는 별도로 명시되지 않았습니다.
