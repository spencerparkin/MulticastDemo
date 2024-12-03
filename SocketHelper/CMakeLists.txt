# CMakeLists.txt for SocketHelper library.

set(SOCKET_HELPER_SOURCES
    Source/SocketHelper.cpp
    Source/SocketHelper.h
    Source/MulticastSender.cpp
    Source/MulticastSender.h
    Source/MulticastReceiver.cpp
    Source/MulticastReceiver.h
    Source/ThreadedMulticastReceiver.cpp
    Source/ThreadedMulticastReceiver.h
    Source/MulticastUser.cpp
    Source/MulticastUser.h
)

add_library(SocketHelperLib SHARED
    ${SOCKET_HELPER_SOURCES}
)

target_link_libraries(SocketHelperLib
    Ws2_32.lib
)

target_compile_definitions(SocketHelperLib PRIVATE
    SOCKET_HELPER_EXPORT
)

target_include_directories(SocketHelperLib PUBLIC
    "Source"
    "${PROJECT_SOURCE_DIR}/SocketHelper/Source"
)