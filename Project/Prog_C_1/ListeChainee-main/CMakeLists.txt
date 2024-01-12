# Minimum cmake version
cmake_minimum_required(VERSION 3.13.4)

# Project properties: C project
project(ListeChainee
  VERSION 1.0.0
  LANGUAGES C
)

# Add executables of projects
add_executable(listechainee listchainee_main.c)
add_library(list list.c)
