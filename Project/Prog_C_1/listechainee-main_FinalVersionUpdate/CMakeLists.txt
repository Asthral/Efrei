cmake_minimum_required(VERSION 3.14)
project(montest
  VERSION 1.1.0
  LANGUAGES C)
add_executable(exec src/list.c test/test.c)
include_directories(BEFORE "${PROJECT_SOURCE_DIR}")

