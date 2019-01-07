cmake_minimum_required(VERSION 3.12)
project(proj2)

set(CMAKE_CXX_STANDARD 14)

add_executable(proj2 main.cpp ServerSide.h ClientHandler.h MySerialServer.cpp MySerialServer.h MyTestClientHandler.cpp MyTestClientHandler.h CacheManager.h FileCacheManager.cpp FileCacheManager.h Solver.h)