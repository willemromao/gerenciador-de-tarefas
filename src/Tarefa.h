// Tarefa.h
#ifndef TAREFA_H
#define TAREFA_H

#include <iostream>
#include <vector>

class Tarefa {
private:
    int id; 
    std::string descricao;
    bool concluida;
    static int totalTarefas;

public:
    Tarefa(const std::string& descricao);
    virtual ~Tarefa();

    int getId() const;
    std::string getDescricao() const;
    bool estaConcluida() const;

    void concluir();
    virtual void exibir() const;

    static int getTotalTarefas();
    static void atualizarTotalTarefas(int novoTotal);

    friend std::ostream& operator<<(std::ostream& os, const Tarefa& tarefa);
};

class TarefaAmanha : public Tarefa {
private:
    static int totalTarefasAmanha;

public:
    TarefaAmanha(const std::string& descricao);
    virtual ~TarefaAmanha();

    virtual void exibir() const override;

    static int getTotalTarefasAmanha();
    static void atualizarTotalTarefasAmanha(int novoTotal);
};

#endif // TAREFA_H
