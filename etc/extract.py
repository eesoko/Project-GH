# parse_sensors.py
import re
import pandas as pd
from datetime import datetime

log_path = "log_250828_1849.txt"   # 네 logcat 텍스트 파일 경로

# 예: "2025-08-28 18:46:04.848 ... Gyro X: -0.3, Y: -0.88, Z: 1.16"
pat = re.compile(
    r'^(\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d{3}).*?\b(Gyro|Accel)\b.*?'
    r'X:\s*([-\d.]+),\s*Y:\s*([-\d.]+),\s*Z:\s*([-\d.]+)'
)

gyro, accel = [], []
with open(log_path, 'r', encoding='utf-8') as f:
    for line in f:
        m = pat.search(line)
        if not m: 
            continue
        ts_str, kind, x, y, z = m.groups()
        ts = pd.to_datetime(ts_str)  # 로컬 시간으로 파싱
        row = {'time': ts, 'X': float(x), 'Y': float(y), 'Z': float(z)}
        (gyro if kind == 'Gyro' else accel).append(row)

gyro_df  = pd.DataFrame(gyro).sort_values('time')
accel_df = pd.DataFrame(accel).sort_values('time')

# 상대 시간(s) 칼럼(분석 편의용)
for df in (gyro_df, accel_df):
    if not df.empty:
        t0 = df['time'].iloc[0]
        df['t_sec'] = (df['time'] - t0).dt.total_seconds()

stamp = datetime.now().strftime("%y%m%d_%H%M")
gyro_csv  = f"gyro_{stamp}.csv"
accel_csv = f"accel_{stamp}.csv"

gyro_df[['time','X','Y','Z']].to_csv(gyro_csv, index=False)
accel_df[['time','X','Y','Z']].to_csv(accel_csv, index=False)

# 시간 기준 근접 매칭 병합(최대 20ms 차이는 같은 시점으로 간주)
merged = pd.merge_asof(
    gyro_df.sort_values('time'),
    accel_df.sort_values('time'),
    on='time',
    direction='nearest',
    tolerance=pd.Timedelta('20ms'),
    suffixes=('_gyro', '_accel')
)
merged_csv = f"squat_{stamp}.csv"
merged.to_csv(merged_csv, index=False)

print(f"Wrote {gyro_csv}, {accel_csv}, {merged_csv}")
