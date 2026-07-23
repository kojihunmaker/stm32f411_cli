[portfolio.html](https://github.com/user-attachments/files/30305538/portfolio.html)
<!DOCTYPE html>
<html lang="ko">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>고지훈 · 임베디드 개발자</title>
<style>
  :root{
    --bg:#0d1117;
    --panel:#161b22;
    --line:#2b3240;
    --ink:#dfe3ea;
    --ink-dim:#8892a0;
    --ink-faint:#565f6d;
    --accent:#57c7a8;
    --red:#e0645f;
    --yellow:#e0b354;
    --green:#57c7a8;
  }
  *{box-sizing:border-box;}
  html,body{margin:0;padding:0;}
  body{
    background:var(--bg);color:var(--ink);
    font-family:ui-monospace,'JetBrains Mono','Fira Code',Menlo,Consolas,monospace;
    font-size:14px;line-height:1.75;
  }
  a{color:var(--accent);}

  .topbar{display:flex;justify-content:space-between;align-items:baseline;padding:26px 5vw 18px;border-bottom:1px solid var(--line);}
  .topbar .name{font-weight:600;color:var(--ink);font-size:19px;}
  .topbar .role{color:var(--ink-faint);font-size:12.5px;margin-left:10px;}
  .topbar .links a{color:var(--ink-dim);margin-left:18px;font-size:12.5px;text-decoration:none;}
  .topbar .links a:hover{color:var(--accent);}

  .lead{padding:30px 5vw 10px;display:flex;align-items:center;justify-content:space-between;gap:24px;}
  .lead-text{max-width:640px;}
  .lead .who{color:var(--accent);}
  .lead p{color:var(--ink-dim);margin:10px 0 0;font-size:13.5px;}
  .lead-svg{flex:0 0 auto;opacity:.55;}
  @media (max-width:820px){.lead-svg{display:none;}}
  .stack{display:flex;flex-wrap:wrap;gap:8px;margin:18px 0 0;padding:0 5vw;list-style:none;}
  .stack li{border:1px solid var(--line);color:var(--ink-dim);padding:3px 10px;font-size:12px;border-radius:3px;}

  .section-hint{color:var(--ink-faint);font-size:11.5px;padding:36px 5vw 14px;border-top:1px solid var(--line);margin-top:26px;}

  .cards{display:grid;grid-template-columns:1fr 1fr;gap:16px;padding:0 5vw 60px;}
  @media (max-width:760px){.cards{grid-template-columns:1fr;}}

  .card{
    text-align:left;background:var(--panel);border:1px solid var(--line);border-radius:8px;
    padding:0 0 18px;cursor:pointer;font-family:inherit;color:var(--ink);overflow:hidden;
  }
  .card:hover{border-color:var(--accent);}
  .card .thumb{display:flex;align-items:center;justify-content:center;width:100%;height:130px;overflow:hidden;background:var(--bg);border-bottom:1px solid var(--line);}
  .card .thumb svg{opacity:.8;transition:opacity .15s,transform .2s;}
  .card:hover .thumb svg{opacity:1;transform:scale(1.05);}
  .card .body-pad{padding:16px 20px 0;display:block;}
  .card .n{color:var(--ink-faint);font-size:11.5px;display:block;margin-bottom:8px;}
  .card .t{color:var(--ink);font-size:15px;font-weight:600;display:block;margin-bottom:8px;}
  .card .d{color:var(--ink-dim);font-size:12.5px;margin-bottom:12px;}
  .card .tg{display:flex;flex-wrap:wrap;gap:6px;margin-bottom:10px;}
  .card .tg span{color:var(--accent);border:1px solid var(--accent);font-size:11px;padding:2px 8px;border-radius:3px;}
  .card .go{color:var(--ink-faint);font-size:12px;}
  .card:hover .go{color:var(--accent);}

  footer{border-top:1px solid var(--line);padding:20px 5vw;color:var(--ink-faint);font-size:11.5px;}

  /* window */
  .backdrop{
    position:fixed;inset:0;background:rgba(3,5,9,0.72);
    display:none;align-items:center;justify-content:center;z-index:100;padding:20px;
  }
  .backdrop.open{display:flex;}
  .win{
    width:100%;max-width:700px;max-height:88vh;background:var(--panel);
    border:1px solid var(--line);border-radius:8px;overflow:hidden;
    display:flex;flex-direction:column;
  }
  .win-bar{
    display:flex;align-items:center;gap:10px;
    padding:11px 16px;background:var(--bg);border-bottom:1px solid var(--line);
  }
  .win-bar .dots{display:flex;gap:6px;}
  .win-bar .dots span{width:10px;height:10px;border-radius:50%;display:inline-block;}
  .dot-r{background:var(--red);}.dot-y{background:var(--yellow);}.dot-g{background:var(--green);}
  .win-bar .file{color:var(--ink-faint);font-size:12px;flex:1;}
  .win-bar .close{background:none;border:none;color:var(--ink-faint);cursor:pointer;font-family:inherit;font-size:13px;}
  .win-bar .close:hover{color:var(--red);}

  .win-body{padding:22px 24px 26px;overflow-y:auto;}
  .d-head{padding-bottom:16px;margin-bottom:18px;border-bottom:1px solid var(--line);}
  .d-head h2{margin:0 0 8px;font-size:18px;color:var(--ink);font-weight:600;}
  .d-head .meta{color:var(--ink-faint);font-size:12px;display:flex;gap:18px;flex-wrap:wrap;margin-bottom:12px;}
  .d-head .meta b{color:var(--ink-dim);font-weight:500;}
  .d-head .stacktags{display:flex;flex-wrap:wrap;gap:6px;margin-bottom:14px;}
  .d-head .stacktags span{color:var(--accent);border:1px solid var(--accent);font-size:11px;padding:2px 8px;border-radius:3px;}
  .d-head .src a{font-size:12.5px;text-decoration:none;}
  .d-head .src a:hover{text-decoration:underline;}

  details{border:1px solid var(--line);border-radius:6px;margin-bottom:10px;background:var(--bg);}
  details summary{
    padding:12px 16px;cursor:pointer;color:var(--ink);font-size:13.5px;font-weight:500;
    list-style:none;display:flex;align-items:center;gap:10px;
  }
  details summary::-webkit-details-marker{display:none;}
  details summary::before{content:'▸';color:var(--ink-faint);transition:transform .12s;}
  details[open] summary::before{transform:rotate(90deg);color:var(--accent);}
  details .body{padding:0 16px 16px 38px;color:var(--ink-dim);font-size:13px;}
  details .body ul{margin:6px 0;padding-left:18px;}
  details .body li{margin-bottom:8px;}
  details .body li b{color:var(--ink);font-weight:500;}
  details .body p{margin:0 0 10px;}
  details .body p:last-child{margin-bottom:0;}
  details .body code{background:var(--panel);border:1px solid var(--line);padding:1px 5px;border-radius:3px;font-size:12px;}

  .shots{display:flex;gap:10px;flex-wrap:wrap;margin:12px 0 4px;}
  .shots figure{margin:0;flex:1;min-width:140px;}
  .shots img{width:100%;display:block;border:1px solid var(--line);border-radius:6px;object-fit:contain;max-height:220px;background:var(--bg);}
  .shots figcaption{color:var(--ink-faint);font-size:11px;margin-top:6px;text-align:center;}
</style>
</head>
<body>

<div class="topbar">
  <div><span class="name">고지훈</span><span class="role">embedded / iot developer</span></div>
  <div class="links">
    <a href="mailto:kojh1210@gmail.com">mail</a>
    <a href="https://github.com/kojihunmaker" target="_blank" rel="noopener">github</a>
  </div>
</div>

<div class="lead">
  <div class="lead-text">
    <p><span class="who">$</span> 하드웨어의 물리적 제약과 노이즈 속에서도 안정적으로 동작하는 시스템을 만드는 데 관심이 많습니다.<br>프로젝트를 선택하면 개요부터 트러블슈팅까지 볼 수 있습니다.</p>
  </div>
  <svg class="lead-svg" width="150" height="110" viewBox="0 0 150 110" xmlns="http://www.w3.org/2000/svg">
    <g fill="none" stroke="#2b3240" stroke-width="1.5">
      <path d="M10 90 H50 V60 H90"/>
      <path d="M10 20 H40 V50 H70 V90 H140"/>
      <path d="M110 20 H140 V70"/>
      <path d="M70 20 V10"/>
    </g>
    <g fill="none" stroke="#57c7a8" stroke-width="1.5">
      <path d="M50 60 V30 H110"/>
    </g>
    <g fill="#57c7a8">
      <circle cx="50" cy="60" r="3"/>
      <circle cx="110" cy="30" r="3"/>
      <circle cx="10" cy="90" r="3"/>
      <circle cx="140" cy="70" r="3"/>
    </g>
    <g fill="#2b3240">
      <circle cx="10" cy="20" r="3"/>
      <circle cx="90" cy="60" r="3"/>
      <circle cx="70" cy="10" r="3"/>
      <circle cx="140" cy="20" r="3"/>
    </g>
    <rect x="40" y="80" width="20" height="20" rx="2" fill="none" stroke="#2b3240" stroke-width="1.5"/>
    <rect x="100" y="45" width="16" height="16" rx="2" fill="none" stroke="#57c7a8" stroke-width="1.5"/>
  </svg>
</div>
<ul class="stack">
  <li>단국대학교 신소재공학과</li><li>C / C++</li><li>STM32</li><li>Arduino</li><li>FreeRTOS</li><li>TCP/IP Socket</li><li>Linux</li>
</ul>

<div class="section-hint">PROJECTS — 클릭하면 창으로 열립니다</div>
<div class="cards">
  <button class="card" onclick="openProject('vending')">
    <span class="thumb">
      <svg width="72" height="90" viewBox="0 0 72 90" xmlns="http://www.w3.org/2000/svg">
        <rect x="4" y="4" width="64" height="82" rx="4" fill="none" stroke="#57c7a8" stroke-width="2"/>
        <rect x="11" y="12" width="50" height="34" rx="2" fill="none" stroke="#57c7a8" stroke-width="1.5"/>
        <line x1="36" y1="12" x2="36" y2="46" stroke="#57c7a8" stroke-width="1.5"/>
        <line x1="11" y1="29" x2="61" y2="29" stroke="#57c7a8" stroke-width="1.5"/>
        <circle cx="20" cy="56" r="2.5" fill="#57c7a8"/>
        <circle cx="36" cy="56" r="2.5" fill="#57c7a8"/>
        <circle cx="52" cy="56" r="2.5" fill="#57c7a8"/>
        <rect x="11" y="64" width="50" height="16" rx="2" fill="none" stroke="#2b3240" stroke-width="1.5"/>
      </svg>
    </span>
    <span class="body-pad">
      <span class="n">2026.05 — 2026.06</span>
      <span class="t">IoT 자판기 시스템</span>
      <span class="d">아두이노·라즈베리파이·STM32 간 Wi-Fi/Bluetooth 통신으로 무인 자판기 재고와 센서 데이터를 실시간으로 관리하는 IoT 생태계</span>
      <span class="tg"><span>Arduino</span><span>TCP/IP</span><span>MariaDB</span></span>
      <span class="go">기술서 열기 →</span>
    </span>
  </button>
  <button class="card" onclick="openProject('sorting')">
    <span class="thumb">
      <svg width="100" height="80" viewBox="0 0 100 80" xmlns="http://www.w3.org/2000/svg">
        <rect x="6" y="60" width="88" height="10" rx="2" fill="none" stroke="#2b3240" stroke-width="1.5"/>
        <circle cx="16" cy="70" r="4" fill="none" stroke="#2b3240" stroke-width="1.5"/>
        <circle cx="84" cy="70" r="4" fill="none" stroke="#2b3240" stroke-width="1.5"/>
        <rect x="30" y="52" width="16" height="8" fill="none" stroke="#57c7a8" stroke-width="1.5"/>
        <path d="M20 60 V38 L45 30 L60 42 L52 60" fill="none" stroke="#57c7a8" stroke-width="2" stroke-linejoin="round"/>
        <circle cx="20" cy="38" r="3" fill="#57c7a8"/>
        <circle cx="45" cy="30" r="3" fill="#57c7a8"/>
        <circle cx="60" cy="42" r="3" fill="#57c7a8"/>
        <path d="M60 42 L68 30" stroke="#57c7a8" stroke-width="2" stroke-linecap="round"/>
        <path d="M64 26 L72 34 M72 26 L64 34" stroke="#57c7a8" stroke-width="1.5"/>
      </svg>
    </span>
    <span class="body-pad">
      <span class="n">2026.04 — 2026.05</span>
      <span class="t">무게 기반 자동 분류 시스템</span>
      <span class="d">로드셀 무게값으로 Heavy/Light를 판별해 로봇팔과 컨베이어가 자동으로 분류하는 FreeRTOS 기반 임베디드 시스템</span>
      <span class="tg"><span>STM32</span><span>FreeRTOS</span><span>HX711</span></span>
      <span class="go">기술서 열기 →</span>
    </span>
  </button>
  <button class="card" onclick="openProject('cli')">
    <span class="thumb">
      <svg width="100" height="72" viewBox="0 0 100 72" xmlns="http://www.w3.org/2000/svg">
        <rect x="4" y="4" width="92" height="64" rx="4" fill="none" stroke="#57c7a8" stroke-width="2"/>
        <line x1="4" y1="18" x2="96" y2="18" stroke="#57c7a8" stroke-width="1.5"/>
        <circle cx="12" cy="11" r="2" fill="#57c7a8"/>
        <circle cx="20" cy="11" r="2" fill="#2b3240"/>
        <circle cx="28" cy="11" r="2" fill="#2b3240"/>
        <path d="M14 30 L24 38 L14 46" fill="none" stroke="#57c7a8" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"/>
        <line x1="28" y1="46" x2="50" y2="46" stroke="#57c7a8" stroke-width="2" stroke-linecap="round"/>
        <line x1="14" y1="56" x2="70" y2="56" stroke="#2b3240" stroke-width="1.5"/>
        <line x1="62" y1="32" x2="86" y2="32" stroke="#2b3240" stroke-width="1.5"/>
      </svg>
    </span>
    <span class="body-pad">
      <span class="n">2026.03.09 — 2026.03.20</span>
      <span class="t">STM32 UART CLI 펌웨어</span>
      <span class="d">FreeRTOS 기반으로 UART 시리얼 셸을 직접 구현해 LED·GPIO·메모리 덤프·센서를 명령어로 제어/모니터링하는 개인 실습 프로젝트</span>
      <span class="tg"><span>STM32F411</span><span>FreeRTOS</span><span>UART</span></span>
      <span class="go">기술서 열기 →</span>
    </span>
  </button>
</div>

<footer>고지훈 — 임베디드·IoT 개발자 포트폴리오</footer>

<div class="backdrop" id="backdrop" onclick="if(event.target===this)closeProject()">
  <div class="win">
    <div class="win-bar">
      <div class="file" id="winFile"></div>
      <button class="close" onclick="closeProject()">✕ 닫기</button>
    </div>
    <div class="win-body" id="winBody"></div>
  </div>
</div>

<script>
const projects = {
  vending: {
    title: "IoT 자판기 시스템",
    date: "2026.05.27 – 2026.06.03",
    role: "TCP 서버 구축 · 통신 프로토콜 설계 · 아두이노 펌웨어",
    github: "https://github.com/kojihunmaker/vending_machine",
    tags: ["Arduino Uno","ESP-01","C/C++","MariaDB","EEPROM","DHT11/CDS"],
    overview: `
      <ul>
        <li>자판기(Edge) · 중앙서버(Cloud) · 재고창고(Management)를 Wi-Fi/Bluetooth로 연결한 IoT 생태계 구축</li>
        <li>아두이노·센서 기반 판매 및 환경 데이터 자동 수집(무인화·자동화)</li>
        <li>TCP 소켓 통신을 통한 자판기-서버 간 실시간 데이터 송수신 및 MariaDB 적재</li>
        <li>STM32 스텝모터 기반 창고 재고 보충 제어 및 재고 데이터 동기화</li>
      </ul>
      <div class="shots">
        <figure><img src="vending-outside.jpg" alt="자판기 외부"><figcaption>자판기 외부</figcaption></figure>
        <figure><img src="vending-inside.jpg" alt="자판기 내부"><figcaption>자판기 내부</figcaption></figure>
      </div>`,
    build: `
      <p><b>서버(iot_server, C)</b> — 클라이언트(자판기) 연결마다 스레드를 생성해 다중 기기를 동시 처리. MySQL C API로 MariaDB(iotdb)와 연동해 VEND 수신 시 sales_log 기록·재고 차감, SENSOR 수신 시 sensor_log 기록.</p>
      <p><b>통신 프로토콜</b> — <code>[machine_id:PASSWD]</code> 인증 → 서버가 machine_id 조회 후 SETSTOCK 자동 응답 → 이후 VEND(판매)·SENSOR(센서값)·RESET(재고초기화) 메시지 송수신. <code>strtok(buf,"[@]")</code> 기반으로 prefix/명령/파라미터 파싱.</p>
      <p><b>EEPROM 설정 관리</b> — 자판기 ID·비밀번호·위치 정보를 EEPROM에 저장해 기기별 구분. 부팅 시 Magic byte(0xAB)로 초기 설정 여부 판별, 5초 이내 특정 입력 시 재설정 모드 진입.</p>`,
    trouble: `
      <p><b>다중 기기 데이터 식별 불가</b> — 아두이노를 두 대 연결해도 DB의 machine_id가 1로 하드코딩되어 있어, 어느 장치든 데이터가 machine_id=1로 저장됐습니다. 로그인한 사용자 ID(client_info → ID)를 기준으로 machines 테이블에서 해당 기기의 machine_id를 동적으로 조회하도록 수정해 기기별로 데이터가 올바르게 구분되도록 했습니다.</p>
      <p><b>재고 동기화 메시지 누락</b> — 서버가 연결 직후 SETSTOCK으로 재고 정보를 보내는데 자판기가 이를 정상 수신하지 못했습니다. 원인은 <code>socketEvent()</code> 내 <code>client.flush()</code> 호출이 수신 버퍼까지 비워버리는 것이었고, 이 호출을 제거해 해결했습니다.</p>`,
    learned: `
      <ul>
        <li>인증·동기화 실패는 별도 에러 없이 조용히 실패할 수 있다는 것을 실제로 겪으며, 증상만으로 판단하지 않고 프로토콜 레벨에서 직접 확인하는 습관을 갖게 되었습니다.</li>
        <li>PuTTY를 Raw 모드로 서버에 직접 연결해 인증 문자열을 손으로 테스트하는 등, 클라이언트 재빌드 없이 프로토콜 자체를 검증하는 디버깅 방법을 체득했습니다.</li>
      </ul>`
  },
  sorting: {
    title: "무게 기반 자동 분류 시스템",
    date: "2026.04.22 – 2026.05.10",
    role: "로봇팔 구동부 개선 · 로드셀 하드웨어 및 판정 파라미터 설정",
    github: "https://github.com/kojihunmaker/Weight-based-automatic-classification-system",
    tags: ["STM32 F411RE","C","FreeRTOS","HX711","PCA9685","MG996R"],
    overview: `
      <ul>
        <li>로드셀 기반 무게 측정으로 물체를 실시간 분류하는 자동화 시스템 구현</li>
        <li>로봇팔을 이용한 물체 이송 및 적재 자동화</li>
        <li>하드웨어 물리적 오차를 소프트웨어적으로 보정해 측정 신뢰성 확보</li>
      </ul>`,
    build: `
      <p><b>로봇팔 구동부 개선</b> — 기존 AD002 마이크로 서보모터의 토크 부족 문제 해결을 위해 부하가 집중되는 4번(Shoulder)·5번(Base) 관절을 고토크 MG996R로 교체. 모터 외형 치수 증가에 따른 마운트 홀 재설계, 무게중심 재배치, 베이스 지지대 강성 보강으로 진동·쏠림 방지.</p>
      <p><b>로드셀 하드웨어 및 파라미터</b> — 로드셀을 바닥에 직접 두면 측정이 불안정해지는 문제를 받침 구조 제작으로 해결. 영점 캘리브레이션과 중앙값·EMA 필터 튜닝으로 측정 정밀도 확보, 물체 감지(25g)/해제(12g) 임계값 및 안정화(stable) 판정 기준값 설정.</p>
      <div class="shots">
        <figure><img src="robot-arm.jpg" alt="로봇팔 구동부"><figcaption>로봇팔 구동부</figcaption></figure>
        <figure><img src="loadcell.jpg" alt="로드셀 설치 구조"><figcaption>로드셀 설치 구조</figcaption></figure>
      </div>`,
    trouble: `
      <p><b>로드셀 잔류값 문제</b> — 물체 제거 후에도 5~15g의 잔류값이 남는 현상 발견. 로드셀 내 금속 탄성체가 완전히 복귀하지 못하는 물리적 한계로 소프트웨어 보정만으로는 완전 해결이 불가능하다고 판단, Zero Tracking을 적용해 물체 해제 후 일정 조건 충족 시 tare offset을 잔류값 방향으로 서서히 보정하도록 구현했습니다.</p>
      <p><b>하드웨어 고정 구조 시도 및 폐기</b> — 물체가 불안정하게 올려질 때 흔들림을 줄이려 고정 틀을 설계·제작했으나, 오히려 내부 금속 탄성체 변형이 커지며 값이 더 불안정해지는 것을 확인해 채택하지 않았습니다. 대신 변화량이 연속 5회 이상 ±2g 이내로 유지될 때만 값을 확정하는 stable 판정 로직을 소프트웨어로 구현해 해결했습니다.</p>`,
    learned: `
      <ul>
        <li>모든 문제에 하드웨어적 보완이 답은 아니라는 것과, 시도한 접근이 실제로 효과가 있는지 검증하고 다음 방향을 판단하는 것이 엔지니어에게 중요한 역량임을 깨달았습니다.</li>
        <li>하나의 버그를 고치는 데서 멈추지 않고 관련된 문제를 연달아 파고들어 근본 원인까지 확인하는 태도를 갖게 되었고, 이는 이후 어떤 임베디드 시스템을 다루더라도 흔들리지 않는 판단 기준이 되었습니다.</li>
      </ul>`
  },
  cli: {
    title: "STM32 UART CLI 펌웨어",
    date: "2026.03.09 – 2026.03.20",
    role: "개인 실습 · FreeRTOS 기반 CLI 셸 직접 구현",
    github: "https://github.com/kojihunmaker/stm32f411_cli",
    tags: ["STM32F411","FreeRTOS","UART","CMake"],
    overview: `
      <ul>
        <li>STM32F411(Nucleo) 보드에서 동작하는 FreeRTOS 기반 UART CLI 펌웨어를 수업 실습으로 개인 진행</li>
        <li>명령어 파싱, 방향키(↑/↓) 히스토리, 백스페이스, Ctrl+C까지 지원하는 셸(CLI)을 직접 구현</li>
        <li>LED, GPIO, 메모리 덤프, MCU 내부 온도센서, 버튼 인터럽트를 명령어로 제어·조회</li>
        <li><code>mon</code> 명령으로 센서 값을 주기적으로 스트리밍하는 모니터링 프로토콜 설계</li>
      </ul>`,
    build: `
      <p><b>FreeRTOS 태스크 분리</b> — default/led/temp/monitor 4개 태스크로 구성해 CLI 입력 처리와 백그라운드 LED 토글·온도 측정·센서 스트리밍을 서로 간섭 없이 병행 수행.</p>
      <p><b>메모리 덤프 명령 안전장치</b> — <code>md [addr] [length]</code>로 임의 주소를 찍으면 위험하므로, Flash/RAM/시스템메모리/페리퍼럴 레지스터 범위만 접근을 허용하도록 화이트리스트 제한.</p>
      <p><b>모니터링 프로토콜 설계</b> — <code>mon</code> 명령으로 <code>$개수,id:type:value,...#</code> 포맷을 직접 설계해 여러 센서 값을 한 번에 UART로 스트리밍.</p>`,
    trouble: `
      <p><b>CMake 빌드 시 소스 파일을 못 찾는 문제</b> — CubeMX가 생성한 CMakeLists.txt가 소스 파일을 <code>*.C</code>(대문자 확장자)로 glob하고 있었는데, 대소문자를 구분하는 리눅스 환경에서는 실제 파일(<code>.c</code>)과 매칭이 안 돼 빌드가 되지 않는 문제를 발견. 확장자 패턴을 소문자로 맞춰 해결.</p>`,
    learned: `
      <ul>
        <li>로우레벨 CLI를 직접 구현하면서 UART 인터럽트 기반 입력 처리, 커맨드 파싱, 히스토리 버퍼 관리 등 임베디드 셸의 기본 구조를 체득했습니다.</li>
        <li>메모리 덤프처럼 위험할 수 있는 명령은 반드시 접근 가능한 주소 범위를 화이트리스트로 제한해야 한다는 것을 직접 구현하며 체감했습니다.</li>
      </ul>`
  }
};

function openProject(key){
  const p = projects[key];
  document.getElementById('winFile').textContent = `~/projects/${key}`;
  document.getElementById('winBody').innerHTML = `
    <div class="d-head">
      <h2>${p.title}</h2>
      <div class="meta"><span><b>기간</b> ${p.date}</span><span><b>담당</b> ${p.role}</span></div>
      <div class="stacktags">${p.tags.map(t=>`<span>${t}</span>`).join('')}</div>
      <div class="src"><a href="${p.github}" target="_blank" rel="noopener">→ ${p.github.replace('https://github.com/','github.com/')}</a></div>
    </div>
    <details open>
      <summary>개요</summary>
      <div class="body">${p.overview}</div>
    </details>
    <details open>
      <summary>구현 내용</summary>
      <div class="body">${p.build}</div>
    </details>
    <details open>
      <summary>겪은 문제와 해결</summary>
      <div class="body">${p.trouble}</div>
    </details>
    <details open>
      <summary>배운 점</summary>
      <div class="body">${p.learned}</div>
    </details>
  `;
  document.getElementById('backdrop').classList.add('open');
}

function closeProject(){
  document.getElementById('backdrop').classList.remove('open');
}

document.addEventListener('keydown', (e)=>{ if(e.key==='Escape') closeProject(); });
</script>

</body>
</html>
