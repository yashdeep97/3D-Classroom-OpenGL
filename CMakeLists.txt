cmake_minimum_required(VERSION 3.2)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)

project(3D-Classroom-OpenGL)

add_executable(Classroom classroom.cpp "src/chair.cpp" "src/cupboard.cpp" "src/fan.cpp" "src/shelf.cpp" "src/snowman.cpp" "src/table.cpp" "src/window.cpp" )

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLU REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS})
target_link_libraries(Classroom ${OPENGL_LIBRARIES} glut GLU GL)