cmake_minimum_required(VERSION 3.5)

project(equipment_In_UUPPO VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    addman.cpp
    addman.h
    addman.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(equipment_In_UUPPO
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        additem.h additem.cpp additem.ui
        additemkomp.h additemkomp.cpp additemkomp.ui
    )
else()
    if(ANDROID)
        add_library(equipment_In_UUPPO SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(equipment_In_UUPPO
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(equipment_In_UUPPO PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.equipment_In_UUPPO)
endif()
set_target_properties(equipment_In_UUPPO PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS equipment_In_UUPPO
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(equipment_In_UUPPO)
endif()
