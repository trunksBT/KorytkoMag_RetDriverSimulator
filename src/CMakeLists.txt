message("KorytkoMagRetDriver ReleaseCMakeLists")

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${UTILS}
    ${PLUGIN_SPECIFICS}

    ${EXTERNAL_LIBRARIES_MESSAGING_PATTERN}
    ${EXTERNAL_LIBRARIES_COMMAND_PATTERN}
    ${EXTERNAL_LIBRARIES_DATABASE}
    ${EXTERNAL_LIBRARIES_HDLC}
    ${EXTERNAL_LIBRARIES_USER_INTERFACE}
    ${EXTERNAL_LIBRARIES_UTILS}
    ${EXTERNAL_LIBRARIES_TESTUTILS}
)

target_link_libraries(${PROJECT_NAME}
    ${Boost_LIBRARIES}
    # /usr/lib/gcc/x86_64-linux-gnu/8/libstdc++fs.a # uncomment on UBUNTU, I know it sucks
    /usr/lib64/libstdc++fs.a # uncomment on Manjaro, I know it sucks
)
