cmake_minimum_required(VERSION 3.12)
project(proj2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
add_executable(proj2 main.cpp ServerSide.h ClientHandler.h MyParallelServer.cpp
        MyParallelServer.h MyTestClientHandler.cpp MyTestClientHandler.h CacheManager.h
        FileCacheManager.h Solver.h MySerialServer.cpp MySerialServer.h MatrixProblemClientHandler.cpp MatrixProblemClientHandler.h StringSolver.cpp StringSolver.h)