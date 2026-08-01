# CMakeList.txt: проект CMake для RacingSimulator; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) 

project ("RacingSimulator")

set (SOURCES
check_utils.cpp
naming_utils.cpp
print_utils.cpp
race_engine.cpp
read_utils.cpp
vehicle.cpp
)

set (HEADERS
check_utils.h
naming_utils.h
print_utils.h
race_engine.h
read_utils.h
vehicle.h
)

#Библиотеки
add_library(RacingSimulatorLib STATIC ${SOURCES} ${HEADERS})

# Добавьте источник в исполняемый файл этого проекта.
add_executable (RacingSimulator "main.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET RacingSimulator PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
target_link_libraries(RacingSimulator RacingSimulatorLib)