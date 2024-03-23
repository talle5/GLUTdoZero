cmake_minimum_required(VERSION 3.22)

project(GLUTdoZero)

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_GENERATOR Ninja)

add_executable(glutdozero main.cpp
                    lib/utility/Camera.cpp
                    lib/utility/CameraDistante.cpp
                    lib/utility/CameraJogo.cpp
                    lib/utility/Desenha.cpp
                    lib/utility/model3ds.cpp
                    lib/utility/Vetor3D.cpp
                    lib/gui_glut/extra.cpp
                    lib/gui_glut/gui.cpp
                    lib/gui_glut/OpenTextures.cpp)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
find_package(OpenGL REQUIRED)
find_library( GLUT_glut_LIBRARY NAMES glut glut32 freeglut
              PATHS
              ${OPENGL_LIBRARY_DIR}
              ${GLUT_ROOT_PATH}/Release)
find_package(Lib3ds REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} lib)
target_link_libraries(glutdozero GL GLU glut 3ds SDL2_image IL)

if(UNIX)
  set_target_properties(glutdozero PROPERTIES SUFFIX ".bin")
endif()