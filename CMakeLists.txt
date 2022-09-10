# Minimum Version
cmake_minimum_required(VERSION 3.20)

# Settings
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
set(CMAKE_C_FLAGS_MINSIZEREL "${CMAKE_C_FLAGS_MINSIZEREL} -s")

# Setting Default Build Type ( Release )
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

# IP Option
option(IP "Shell Destination IP")
if(NOT IP)
    message(SEND_ERROR "No IP Provided! ( -DIP=x.x.x.x )")
endif()

# Port Option
option(PORT "Shell Destination PORT")
if(NOT PORT)
    message(SEND_ERROR "No PORT Provided! ( -DPORT=XXXXX )")
endif()

# Project Info
project(revshell VERSION 1.0.0 LANGUAGES C)

# Configure "Config.h" with IP and PORT using "Config.h.in"
configure_file(Config.h.in Config.h)

# Compile executable
add_executable(${PROJECT_NAME} main.c)

# Add Compile Definitions for Build Types
string(TOLOWER ${CMAKE_BUILD_TYPE} BTL)
if(${BTL} STREQUAL "debug")
  add_compile_definitions(DEBUG=1)
elseif(${BTL} STREQUAL "relwithdebinfo")
  add_compile_definitions(DEBUG=1)
endif()

# Passing Config.h to Compile Definitions
target_compile_definitions(${PROJECT_NAME} PRIVATE CONFIG="Config.h")

# Include Binary Directory ( Config.h will be there )
target_include_directories(${PROJECT_NAME} PUBLIC 
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  ${PROJECT_BINARY_DIR}
  )
