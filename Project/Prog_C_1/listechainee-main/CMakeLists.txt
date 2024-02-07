# Minimum cmake version
cmake_minimum_required(VERSION 3.13.4)

# Project properties: C project
project(ListeChainee
  VERSION 1.0.1
  LANGUAGES C
)

# Add executables of projects
#add_library(list STATIC list/list.c)
add_library(list SHARED list/list.c)
set_target_properties(list
  PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
  PUBLIC_HEADER list/list.h)
configure_file(list.pc.in list.pc @ONLY)
target_include_directories(list PRIVATE "${PROJECT_SOURCE_DIR}")
add_executable(listechainee src/listechainee_main.c)
include_directories(BEFORE "${PROJECT_SOURCE_DIR}")
target_link_libraries(listechainee list)
add_executable(testlistechainee tests/test-main.c tests/list-tests.c tests/cmd-tests.c)
target_link_libraries(testlistechainee list -lcunit)
add_test(testlistechainee testlistechainee)

install(TARGETS list
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_BINARY_DIR}/list.pc
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
