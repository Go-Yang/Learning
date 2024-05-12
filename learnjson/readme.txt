- learnjson/
  - CMakeLists.txt
  - src/
    - main.cpp
  - include/
    -json
        -json.hpp
    - opencv455/
        -include/
            - core.hpp
            - imgproc.hpp
            - highgui.hpp
        - opencv_world455.lib
        - opencv_world455d.lib


# 设置包含目录
target_include_directories(learnjson  PRIVATE 
    ${CMAKE_SOURCE_DIR}/../include/json
    ${CMAKE_SOURCE_DIR}/../include/opencv455/include
)