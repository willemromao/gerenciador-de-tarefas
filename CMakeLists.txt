cmake_minimum_required(VERSION 3.10)

project(GerenciadorDeTarefas)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES 
    src/GerenciadorTarefas.cpp
    src/Tarefa.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
