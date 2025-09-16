import os

# .c 파일들이 있는 디렉토리
src_dir = r"C:\Users\dltjr\AndroidStudioProjects\GeunHwang\app\src\main\cpp"
cmake_path = os.path.join(src_dir, "CMakeLists.txt")

# 확장자가 .c인 파일들만 추출
c_files = [f for f in os.listdir(src_dir) if f.endswith('.c')]

# CMakeLists.txt 작성
with open(cmake_path, 'w', encoding='utf-8') as f:
    f.write("cmake_minimum_required(VERSION 3.4.1)\n\n")
    f.write("add_library(\n    native-lib\n    SHARED\n")
    for c_file in c_files:
        f.write(f"    {c_file}\n")
    f.write(")\n\n")
    f.write("find_library(\n    log-lib\n    log\n)\n\n")
    f.write("target_link_libraries(\n    native-lib\n    ${log-lib}\n)\n")

print(f"CMakeLists.txt 생성 완료: {cmake_path}")
