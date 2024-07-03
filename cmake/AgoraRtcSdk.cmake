# AgoraRTC SDK
include(ExternalProject)
ExternalProject_Add(agora_rtc_sdk_download
  URL               https://download.agora.io/rtsasdk/release/Agora-RTC-x86_64-linux-gnu-v4.2.31-20240327_111832-296989.tgz
  URL_HASH          MD5=03406501f35e66f3b407a60e3b51b68e
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  UPDATE_COMMAND    ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)
ExternalProject_Get_Property(agora_rtc_sdk_download SOURCE_DIR)
set(AGORA_RTC_SDK_LIB_DIR ${SOURCE_DIR}/agora_sdk)
set(AGORA_RTC_SDK_INCLUDE_DIR ${SOURCE_DIR}/agora_sdk/include)
unset(SOURCE_DIR)

add_library(agora_rtc_sdk SHARED IMPORTED)
add_dependencies(agora_rtc_sdk agora_rtc_sdk_download)
file(MAKE_DIRECTORY ${AGORA_RTC_SDK_INCLUDE_DIR})
set_property(TARGET agora_rtc_sdk PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${AGORA_RTC_SDK_INCLUDE_DIR})
set_property(TARGET agora_rtc_sdk PROPERTY IMPORTED_LOCATION ${AGORA_RTC_SDK_LIB_DIR}/libagora_rtc_sdk.so)
