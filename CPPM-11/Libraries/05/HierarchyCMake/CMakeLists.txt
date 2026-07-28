# CMakeList.txt: проект CMake для HierarchyCMake; включите исходный код и определения,
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

project ("HierarchyCMake")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set (SOURCES
equilateral_triangle.cpp
figure.cpp
isosceles_triangle.cpp
parallelogram.cpp
quadrangle.cpp
rectangle.cpp
rhombus.cpp
right_triangle.cpp
square.cpp
triangle.cpp
)

set (HEADERS
equilateral_triangle.h
figure.h
isosceles_triangle.h
parallelogram.h
quadrangle.h
rectangle.h
rhombus.h
right_triangle.h
square.h
triangle.h
)

# Библиотеки
add_library(FigureLibDynamic SHARED ${SOURCES} ${HEADERS})

# Добавьте источник в исполняемый файл этого проекта.
add_executable (HierarchyCMake "HierarchyCMake.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HierarchyCMake PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
target_link_libraries(HierarchyCMake FigureLibDynamic)