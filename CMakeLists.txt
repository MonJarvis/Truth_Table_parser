cmake_minimum_required(VERSION 3.19)
project(Truth_Table LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(Truth_Table
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    tokenizer.cpp tokenizer.h
    truthtable.cpp truthtable.h
    parcer.cpp parser.h
    node.h
)

target_link_libraries(Truth_Table
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS Truth_Table
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Truth_Table
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
