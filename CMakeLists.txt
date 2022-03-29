cmake_minimum_required(VERSION 3.1)
project(Snake1)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall -Wextra)

if (UNIX)
    set ( CMAKE_MODULES_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
endif(UNIX)
if (WIN32)
    set( SFML_STATIC_LIBRARIES TRUE )
    set ( SFML_DIR "C:/Users/Kisiel/Documents/SFML/SFML-2.5.1/lib/cmake/SFML/")
endif(WIN32)

find_package(SFML 2 COMPONENTS graphics audio REQUIRED)
set(SOURCE_FILES main.cpp)
add_executable(Snake1 main.cpp Snake.cpp Snake.h SnakeSFMLController.cpp SnakeSFMLController.h SnakeSFMLView.cpp SnakeSFMLView.h MenuSFMLView.cpp MenuSFMLView.h MenuSFMLControl.cpp MenuSFMLControl.h ScoreboardSFMLView.cpp ScoreboardSFMLView.h ScoreboardSFMLController.cpp ScoreboardSFMLController.h)
target_link_libraries(Snake1 sfml-graphics sfml-audio)