cmake_minimum_required(VERSION 3.10)

project(Printer)

option(USE_LIB "Using Addition Library" ON)

configure_file(PrinterConfig.h.in PrinterConfig.h)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES_Main Main.cpp Printer/source/Printer.cpp Reader.cpp)

set(SOURCES_Runner Runner.cpp Printer/source/Printer.cpp Reader.cpp)

if(USE_LIB)
	add_subdirectory(lib)
	list(APPEND EXTRA_LIBS lib)
	list(APPEND EXTRA_INCLUDES lib)
endif()

set(INCLUDE_DIRS Printer/include Reader/include ${PROJECT_BINARY_BIN} ${EXTRA_INCLUDES})

include_directories(${INCLUDE_DIRS})

add_executable(printer_exec ${SOURCES_Main})

target_link_libraries(printer_exec PUBLIC ${EXTRA_LIBS})

add_executable(runner_exec ${SOURCES_Runner})