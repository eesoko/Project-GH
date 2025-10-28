% =========================================================================
% [ SCRIPT ] : feature_extractor_codegen_execution.m
% [ PURPOSE ] : Generate portable ANSI-C code (no SSE, no NEON)
% =========================================================================

% 1. 입력 타입 정의
INPUT_ARGS = {coder.typeof(0, [Inf, 6], [1, 0]), coder.typeof(0)};

% 2. 설정 객체 생성
cfg = coder.config('lib');             % 정적/동적 라이브러리 생성용 설정
cfg.GenerateReport = true;             % 코드 생성 리포트 생성
cfg.EnableOpenMP = false;              % OpenMP 비활성화
cfg.SupportNonFinite = true;           % NaN/Inf 지원
cfg.IntegrityChecks = false;           % 런타임 검증 비활성화
cfg.HardwareImplementation.ProdHWDeviceType = 'Generic->MATLAB Host Computer';  % 범용 CPU

% 3. 코드 생성 실행
codegen feature_extractor_codegen -args INPUT_ARGS -config cfg -lang:c -report
