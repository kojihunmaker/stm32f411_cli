[Uploading README.md…]()
# stm32f411_cli

STM32F411 보드(Nucleo-F411RE)에서 돌아가는 FreeRTOS 기반 UART CLI 펌웨어임. 시리얼로 붙어서 LED, GPIO, 온도센서 이런 거 명령어로 찔러볼 수 있고, 센서 값 주기적으로 쏴주는 모니터링 모드도 있음.

## 뭐가 되냐면

- 셸(CLI) 직접 구현함 — 명령어 파싱, 방향키(↑/↓) 히스토리, 백스페이스, Ctrl+C까지 됨
- LED on/off/toggle, 주기 줘서 자동 토글도 가능
- GPIO 아무 핀이나 read/write (`a`~`h` 포트, `0`~`15` 핀)
- `md`로 메모리 덤프 — 아무 주소나 찍으면 위험하니까 Flash/RAM/시스템메모리/페리페럴 레지스터 범위만 허용함
- MCU 내부 온도센서 읽기 (ADC + DMA)
- 버튼(B1) 인터럽트 켜고 끄고
- 로그 레벨 컬러로 나옴 (FATAL~VERBOSE), 런타임에 레벨 바꿀 수 있음
- `mon` 명령 켜면 센서 값들을 `$개수,id:type:value,...#` 이런 포맷으로 주기적으로 UART에 쏴줌

## 하드웨어

| 항목 | 내용 |
|---|---|
| MCU | STM32F411xE (Cortex-M4) |
| UART | USART2, 115200bps, PA2(TX)/PA3(RX) |
| LED | PA5 (Nucleo LD2) |
| Button | PC13 (Nucleo B1), 하강엣지 EXTI |
| ADC | ADC1, 내부 온도센서 채널, DMA(DMA2_Stream0) 연속 변환 |
| Timebase | TIM10 씀 (SysTick 말고) |
| 클럭 | HSI → PLL |

## 폴더 구조

```
stm32f411_cli/
├── Core/                       # CubeMX가 알아서 만든 것들 (main, 클럭, ISR)
├── Drivers/                    # ST 표준 라이브러리 (CMSIS, HAL v1.8.5) - 건드릴 거 없음
├── Middlewares/Third_Party/    # FreeRTOS Kernel V10.3.1
├── MyApp/                      # 여기가 진짜 내가 짠 코드
│   ├── ap/                     # CLI 명령어, FreeRTOS 태스크, 모니터링 프로토콜
│   ├── bsp/                    # millis(), delay() 같은 보드 지원 함수
│   ├── common/                 # 공통 헤더, 로그 매크로
│   └── hw/driver/              # uart, led, button, temp, gpio, cli, log 드라이버
├── cmake/                      # 툴체인 + CubeMX cmake 설정
├── CMakeLists.txt
├── CMakePresets.json
├── STM32F411XX_FLASH.ld        # 링커 스크립트
├── startup_stm32f411xe.s       # 시작 코드
└── stm32f411_cli.ioc           # CubeMX 프로젝트 파일
```

## 빌드는 이렇게

`arm-none-eabi-gcc`, `CMake`(3.22+), `Ninja` 깔려있어야 됨.

```bash
# Debug
cmake --preset Debug
cmake --build --preset Debug

# Release
cmake --preset Release
cmake --build --preset Release
```

결과물은 `build/<Debug|Release>/`에 생김. VS Code + CMake Tools 써도 되고, CubeMX(`stm32f411_cli.ioc`)로 다시 만들어도 됨.

## 플래싱

ST-Link로 STM32CubeProgrammer든 OpenOCD든 `.vscode/launch.json` 설정으로 디버거 붙여서 굽으면 됨.

## CLI 명령어

115200 8N1로 USART2에 붙어서 치면 됨.

| 명령어 | 뭐하는 놈인지 |
|---|---|
| `help` | 명령어 목록 쫙 보여줌 |
| `cls` | 화면 지움 |
| `led [on\|off]` / `led toggle [period]` | LED 켜고 끄고 토글, 주기 주면 알아서 깜빡임 |
| `info` / `info uptime` | HW 모델, FW 버전, UID, DevID, 가동시간 |
| `sys reset` | 소프트웨어 리셋 |
| `gpio read [a~h][0~15]` | 핀 상태 읽기 |
| `gpio write [a~h][0~15] [0\|1]` | 핀 출력 |
| `md [addr(hex)] [length]` | 메모리 덤프 (예: `md 08000000 32`) |
| `button [on\|off]` | 버튼 인터럽트 리포트 on/off |
| `temp` / `temp [period]` | 온도 한 번 읽거나 주기적으로 자동으로 읽기 |
| `mon [on\|off] [period]` | 센서 모니터링 모드 켜고 끄기, 전송 주기 설정 |
| `log get` / `log set [0~5]` | 로그 레벨 조회/설정 (0:FATAL ~ 5:VERBOSE) |

## 라이선스

`Drivers/`, `Middlewares/`는 ST랑 FreeRTOS 라이선스 따라감 (각 폴더 `LICENSE.txt` 참고). `MyApp/`, `Core/` 쪽은 따로 라이선스 명시 안 해둠.
