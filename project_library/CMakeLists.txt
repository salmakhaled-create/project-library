cmake_minimum_required(VERSION 3.16)

project(project_library LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(project_library

  mainwindow.h mainwindow.cpp
  login.h login.cpp
  menupage.h menupage.cpp
  displaypage.h displaypage.cpp
  addbooks.h addbooks.cpp

  main.cpp
  mainwindow.h mainwindow.cpp mainwindow.ui
  returnpage.h returnpage.cpp
  checkoutpage.h checkoutpage.cpp

)
target_link_libraries(project_library PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(project_library PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(project_library PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(project_library PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(project_library PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(project_library PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(project_library PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(project_library PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(project_library PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

include(GNUInstallDirs)
install(TARGETS project_library
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
