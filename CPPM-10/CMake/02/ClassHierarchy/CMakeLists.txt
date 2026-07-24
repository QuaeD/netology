# CMakeList.txt: проект CMake для ClassHierarchy; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("ClassHierarchy")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (ClassHierarchy 
"ClassHierarchy.cpp"
"Figure/equilateral_triangle.h"
"Figure/equilateral_triangle.cpp"
"Figure/figure.h"
"Figure/figure.cpp"
"Figure/isosceles_triangle.h"
"Figure/isosceles_triangle.cpp"
"Figure/parallelogram.h"
"Figure/parallelogram.cpp"
"Figure/rectangle.h"
"Figure/rectangle.cpp"
"Figure/right_triangle.h"
"Figure/right_triangle.cpp"
"Figure/rhombus.h"
"Figure/rhombus.cpp"
"Figure/square.h"
"Figure/square.cpp"
"Figure/triangle.h"
"Figure/triangle.cpp"
"Figure/quadrangle.h"
"Figure/quadrangle.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ClassHierarchy PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
