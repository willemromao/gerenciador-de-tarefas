#include "Tarefa.h"

int Tarefa::totalTarefas = 0;

Tarefa::Tarefa(const std::string& descricao) : id(++totalTarefas), descricao(descricao), concluida(false) {}

Tarefa::~Tarefa() {}

int Tarefa::getId() const {
    return id;
}

std::string Tarefa::getDescricao() const {
    return descricao;
}

bool Tarefa::estaConcluida() const {
    return concluida;
}

void Tarefa::concluir() {
    concluida = true;
}

void Tarefa::exibir() const {
    std::cout << "ID: " << id << "\t" << descricao << std::endl;
}

int Tarefa::getTotalTarefas() {
    return totalTarefas;
}

void Tarefa::atualizarTotalTarefas(int novoTotal) {
    totalTarefas = novoTotal;
}

std::ostream& operator<<(std::ostream& os, const Tarefa& tarefa) {
    os << "ID: " << tarefa.id << "\tDescrição: " << tarefa.descricao << "\tConcluída: " << (tarefa.concluida ? "Sim" : "Não");
    return os;
}

int TarefaAmanha::totalTarefasAmanha = 0;

TarefaAmanha::TarefaAmanha(const std::string& descricao) : Tarefa(descricao) {
    totalTarefasAmanha++;
}

TarefaAmanha::~TarefaAmanha() {
    totalTarefasAmanha--;
}

void TarefaAmanha::exibir() const {
    std::cout << "ID: " << getId() << "\t" << getDescricao() << "\t(Tarefa para Amanhã)" << std::endl;
}

int TarefaAmanha::getTotalTarefasAmanha() {
    return totalTarefasAmanha;
}

void TarefaAmanha::atualizarTotalTarefasAmanha(int novoTotal) {
    totalTarefasAmanha = novoTotal;
}