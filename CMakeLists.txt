cmake_minimum_required(VERSION 3.0.0)
project(agora_rtc_sdk_c VERSION 4.2.31)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(AgoraRtcSdk)

# this project
add_library(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC "./include")
aux_source_directory(./src SRCS)
aux_source_directory(./src/bridge BRIDGE_SRCS)
target_sources(${PROJECT_NAME} PRIVATE ${SRCS} ${BRIDGE_SRCS})

# include AgoraRTC SDK
target_include_directories(${PROJECT_NAME} PRIVATE agora_rtc_sdk)
target_link_libraries(${PROJECT_NAME} agora_rtc_sdk)
