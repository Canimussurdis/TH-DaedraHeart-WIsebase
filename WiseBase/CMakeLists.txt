cmake_minimum_required(VERSION 3.5)

project(WiseBase LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

if(ANDROID)
  add_library(WiseBase SHARED
    main.cpp
    mainWindow.cpp
    include/BaseFileReader.h
    include/PageEdit.h
    include/PageMetrics.h
    include/PageTextEdit.h
    include/Note.h
    mainWindow.h
    mainWindow.ui
  )
else()
  add_executable(WiseBase
    main.cpp
    mainWindow.cpp
    src/BaseFileReader.cpp
    src/Note.cpp
    src/PageEdit.cpp
    src/PageMetrics.cpp
    src/PageTextEdit.cpp
    src/Picture.cpp
    src/TableHeader.cpp
    src/TableView.cpp
    src/User.cpp
    src/UserColumn.cpp
    include/Picture.h
    include/TableHeader.h
    include/TableView.h
    include/User.h
    include/UserColumn.h
    include/BaseFileReader.h
    include/PageEdit.h
    include/PageMetrics.h
    include/PageTextEdit.h
    include/Note.h
    mainWindow.h
    mainWindow.ui
  )
endif()

target_link_libraries(WiseBase PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
