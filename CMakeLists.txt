cmake_minimum_required(VERSION 3.10)

project(GerenciadorDeTarefas)

set(CMAKE_CXX_STANDARD 11)

# Adiciona os arquivos fonte
set(SOURCES 
    src/GerenciadorTarefas.cpp
    src/Tarefa.cpp
)

# Gera o executável
add_executable(${PROJECT_NAME} ${SOURCES})
