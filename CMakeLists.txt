cmake_minimum_required(VERSION 3.17)
project(PingPong C)

set(CMAKE_C_STANDARD 99)

message("Building ${PROJECT_NAME}...")

message("Building object files...")

include_directories(src)

add_executable(PingPong src/main.c
        src/log.c
        src/ball.c
        src/draw.c
        src/frames.c
        src/init.c
        src/input.c
        src/sound.c
        src/stage.c
        src/util.c
        src/collision.c src/headers/util.h src/headers/ball.h)

message("Linking libraries...")

if (WIN32)
    target_link_libraries(PingPong mingw32 SDL2main SDL2_mixer SDL2_ttf SDL2 m)
endif(WIN32)

if (UNIX)
    target_link_libraries(PingPong SDL2_mixer SDL2_ttf SDL2 m)
endif(UNIX)