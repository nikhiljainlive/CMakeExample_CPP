cmake_minimum_required(VERSION 3.18.3)

project(Printer)

option(USE_LIB "Using Addition Library" ON)

configure_file(PrinterConfig.h.in PrinterConfig.h)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES_Main Main.cpp Printer/source/Printer.cpp Reader.cpp)

set(SOURCES_Runner Runner.cpp Printer/source/Printer.cpp Reader.cpp)

if(USE_LIB)
	add_subdirectory(addition)
	list(APPEND EXTRA_LIBS addition)
	list(APPEND EXTRA_INCLUDES addition)
endif()

set(INCLUDE_DIRS Printer/include Reader/include ${PROJECT_BINARY_BIN} ${EXTRA_INCLUDES})

include_directories(${INCLUDE_DIRS})

add_executable(printer_exec ${SOURCES_Main})

target_link_libraries(printer_exec PUBLIC ${EXTRA_LIBS})

add_executable(runner_exec ${SOURCES_Runner})

install(TARGETS printer_exec DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/PrinterConfig.h"
  DESTINATION include
  )