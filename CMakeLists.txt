cmake_minimum_required(VERSION 3.10)
project(Snake)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FLAGS -Wall -Werror -Wextra -pedantic)

set(SRC
    drawable.cpp
    food.cpp
    snake.cpp)

add_library(${PROJECT_NAME}-lib ${SRC})
target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})
target_link_libraries(${PROJECT_NAME}-lib PRIVATE sfml-graphics sfml-window sfml-system)
target_link_options(${PROJECT_NAME}-lib PRIVATE -fsanitize=address -fsanitize=undefined)

add_executable(${PROJECT_NAME} main.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}-lib sfml-graphics sfml-window sfml-system)
target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=address -fsanitize=undefined)
