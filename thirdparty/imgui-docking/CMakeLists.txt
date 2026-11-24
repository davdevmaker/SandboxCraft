cmake_minimum_required(VERSION 3.5)
project(imgui)

add_library(imgui) #we create  a library
target_sources(imgui PRIVATE
"${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui.cpp" # we add all the c++ files inside imgui
"${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_demo.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_draw.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_tables.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_widgets.cpp"
)


 # we tell it where to look for these files.
target_include_directories(imgui PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/imgui")