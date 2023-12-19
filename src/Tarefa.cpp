/**
 * @file Tarefa.cpp
 * @brief Implementação das funções relacionadas às classes Tarefa e TarefaAmanha.
 * 
 * Este arquivo contém a implementação das funções membros das classes Tarefa e TarefaAmanha,
 * incluindo construtores, destrutores e outras funcionalidades relacionadas.
 * 
 * @author Francisco Willem Romão Moreira
 * @date 2023-12-18
 */
#include "Tarefa.h"

// Inicializa o contador de tarefas
int Tarefa::totalTarefas = 0;

/**
 * @brief Construtor da classe Tarefa.
 * @param descricao Descrição da tarefa.
 */
Tarefa::Tarefa(const std::string& descricao) : id(++totalTarefas), descricao(descricao), concluida(false) {}

/**
 * @brief Destrutor da classe Tarefa.
 */
Tarefa::~Tarefa() {}

/**
 * @brief Obtém o ID da tarefa.
 * @return ID da tarefa.
 */
int Tarefa::getId() const {
    return id;
}

/**
 * @brief Obtém a descrição da tarefa.
 * @return Descrição da tarefa.
 */
std::string Tarefa::getDescricao() const {
    return descricao;
}

/**
 * @brief Verifica se a tarefa está concluída.
 * @return true se a tarefa estiver concluída, false caso contrário.
 */
bool Tarefa::estaConcluida() const {
    return concluida;
}

/**
 * @brief Marca a tarefa como concluída.
 */
void Tarefa::concluir() {
    concluida = true;
}

/**
 * @brief Exibe informações sobre a tarefa.
 */
void Tarefa::exibir() const {
    std::cout << "ID: " << id << "\t" << descricao << std::endl;
}

/**
 * @brief Obtém o total de tarefas criadas.
 * @return Total de tarefas.
 */
int Tarefa::getTotalTarefas() {
    return totalTarefas;
}

/**
 * @brief Atualiza o total de tarefas criadas.
 * @param novoTotal Novo total de tarefas.
 */
void Tarefa::atualizarTotalTarefas(int novoTotal) {
    totalTarefas = novoTotal;
}

/**
 * @brief Sobrecarga do operador de saída para facilitar a exibição de uma tarefa.
 * @param os Stream de saída.
 * @param tarefa Tarefa a ser exibida.
 * @return Stream de saída atualizada.
 */
std::ostream& operator<<(std::ostream& os, const Tarefa& tarefa) {
    os << "ID: " << tarefa.id << "\tDescrição: " << tarefa.descricao << "\tConcluída: " << (tarefa.concluida ? "Sim" : "Não");
    return os;
}

// Inicializa o contador de tarefas agendadas para amanhã
int TarefaAmanha::totalTarefasAmanha = 0;

/**
 * @brief Construtor da classe TarefaAmanha.
 * @param descricao Descrição da tarefa agendada para amanhã.
 */
TarefaAmanha::TarefaAmanha(const std::string& descricao) : Tarefa(descricao) {
    totalTarefasAmanha++;
}

/**
 * @brief Destrutor da classe TarefaAmanha.
 */
TarefaAmanha::~TarefaAmanha() {
    totalTarefasAmanha--;
}

/**
 * @brief Sobrescreve a função exibir para exibir informações específicas de tarefas agendadas para amanhã.
 */
void TarefaAmanha::exibir() const {
    std::cout << "ID: " << getId() << "\t" << getDescricao() << "\t(Tarefa para Amanhã)" << std::endl;
}

/**
 * @brief Obtém o total de tarefas agendadas para amanhã.
 * @return Total de tarefas agendadas para amanhã.
 */
int TarefaAmanha::getTotalTarefasAmanha() {
    return totalTarefasAmanha;
}

/**
 * @brief Atualiza o total de tarefas agendadas para amanhã.
 * @param novoTotal Novo total de tarefas agendadas para amanhã.
 */
void TarefaAmanha::atualizarTotalTarefasAmanha(int novoTotal) {
    totalTarefasAmanha = novoTotal;
}
