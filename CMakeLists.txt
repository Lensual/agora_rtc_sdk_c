cmake_minimum_required(VERSION 3.0.0)
project(agora_rtc_sdk_c VERSION 0.1.0)

# include AgoraRTC SDK
include(ExternalProject)
ExternalProject_Add(agora_rtc_sdk
  URL               https://download.agora.io/rtsasdk/release/Agora-RTC-x86_64-linux-gnu-v4.2.31-20240327_111832-296989.tgz
  URL_HASH          MD5=03406501f35e66f3b407a60e3b51b68e
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  UPDATE_COMMAND    ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)
set(AGORA_RTC_SDK_LIB_DIR ${CMAKE_BINARY_DIR}/agora_rtc_sdk-prefix/src/agora_rtc_sdk/agora_sdk)
set(AGORA_RTC_SDK_INCLUDE_DIR ${CMAKE_BINARY_DIR}/agora_rtc_sdk-prefix/src/agora_rtc_sdk/agora_sdk/include)
#set(AGORA_RTC_SDK_LIB_DIR ${CMAKE_BINARY_DIR}/../agora_rtc_sdk/libs)
#set(AGORA_RTC_SDK_INCLUDE_DIR ${CMAKE_BINARY_DIR}/../agora_rtc_sdk/libs/include)
include_directories(${AGORA_RTC_SDK_INCLUDE_DIR})
link_directories(${AGORA_RTC_SDK_LIB_DIR})

# this project
include_directories(./include)
aux_source_directory(./src DIR_SRCS)
aux_source_directory(./src/bridge DIR_BRIDGE)
add_library(${PROJECT_NAME} ${DIR_SRCS} ${DIR_BRIDGE})
