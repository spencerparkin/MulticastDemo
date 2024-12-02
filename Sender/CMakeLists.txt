# CMakeLists.txt for Sender.

set(SENDER_APP_SOURCES
    Source/SenderApp.cpp
    Source/SenderApp.h
    Source/Frame.cpp
    Source/Frame.h
)

source_group("Sources" TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SENDER_APP_SOURCES})

add_executable(SenderApp WIN32 ${SENDER_APP_SOURCES})
target_compile_definitions(SenderApp PUBLIC __WXMSW__ _UNICODE)

#target_link_libraries(SenderApp PRIVATE
#    
#)

target_compile_definitions(SenderApp PRIVATE
    WIN32_LEAN_AND_MEAN
    NOMINMAX
    _USE_MATH_DEFINES
)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    target_link_directories(SenderApp PRIVATE
        "${WX_WIDGETS_ROOT}/lib/vc_x64_lib"
    )
else()
    target_link_directories(SenderApp PRIVATE
        "${WX_WIDGETS_ROOT}/lib/vc_lib"
    )
endif()

target_include_directories(SenderApp PRIVATE
    "${WX_WIDGETS_ROOT}/include"
    "${WX_WIDGETS_ROOT}/include/msvc"
)