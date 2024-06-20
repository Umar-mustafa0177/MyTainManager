cmake_minimum_required(VERSION 3.5)

project(MytrainManger VERSION 0.1 LANGUAGES CXX)

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
        nextpage.cpp
        nextpage.h
        nextpage.ui
        user.h
        user.cpp
        user.ui
        admin.cpp
        admin.h
        admin.ui
        manageadmin.cpp
        manageadmin.h
        manageadmin.ui
        addtrain.cpp
        addtrain.h
        addtrain.ui
        modifytrain.cpp
        modifytrain.h
        modifytrain.ui
        deletetrain.cpp
        deletetrain.h
        deletetrain.ui
        searchticket.cpp
        searchticket.h
        searchticket.ui
        buyticket.cpp
        buyticket.h
        buyticket.ui
        findtrain.cpp
        findtrain.h
        findtrain.ui
        seatavailability.cpp
        seatavailability.h
        seatavailability.ui

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MytrainManger
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        nextpage.h nextpage.cpp nextpage.ui
        user.h user.cpp user.ui
        admin.h admin.cpp admin.ui
        manageadmin.h manageadmin.cpp manageadmin.ui
        addtrain.h addtrain.cpp addtrain.ui
        modifytrain.h modifytrain.cpp modifytrain.ui
        deletetrain.h deletetrain.cpp deletetrain.ui
        searchticket.h searchticket.cpp searchticket.ui
        buyticket.h buyticket.cpp buyticket.ui
        findtrain.h findtrain.cpp findtrain.ui
        seatavailability.h seatavailability.cpp seatavailability.ui

        dbheader.h
        imgs.qrc


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET MytrainManger APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(MytrainManger SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(MytrainManger
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(MytrainManger PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.MytrainManger)
endif()
set_target_properties(MytrainManger PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS MytrainManger
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MytrainManger)
endif()
