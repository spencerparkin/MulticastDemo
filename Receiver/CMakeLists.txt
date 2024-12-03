# CMakeLists.txt for Sender.

set(RECEIVER_APP_SOURCES
    Source/ReceiverApp.cpp
    Source/ReceiverApp.h
    Source/Frame.cpp
    Source/Frame.h
)

source_group("Sources" TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${RECEIVER_APP_SOURCES})

add_executable(ReceiverApp WIN32 ${RECEIVER_APP_SOURCES})
target_compile_definitions(ReceiverApp PUBLIC __WXMSW__ _UNICODE)

target_link_libraries(ReceiverApp PRIVATE
    SocketHelperLib
)

target_compile_definitions(ReceiverApp PRIVATE
    WIN32_LEAN_AND_MEAN
    NOMINMAX
    _USE_MATH_DEFINES
)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    target_link_directories(ReceiverApp PRIVATE
        "${WX_WIDGETS_ROOT}/lib/vc_x64_lib"
    )
else()
    target_link_directories(ReceiverApp PRIVATE
        "${WX_WIDGETS_ROOT}/lib/vc_lib"
    )
endif()

target_include_directories(ReceiverApp PRIVATE
    "${WX_WIDGETS_ROOT}/include"
    "${WX_WIDGETS_ROOT}/include/msvc"
)