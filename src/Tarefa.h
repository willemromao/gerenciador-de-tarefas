/**
 * @file Tarefa.h
 * @brief Declaração das classes Tarefa e TarefaAmanha.
 * @author Francisco Willem Romão Moreira
 * @date 2023-12-18
 */

#ifndef TAREFA_H
#define TAREFA_H

#include <iostream>
#include <vector>

/**
 * @brief Classe que representa uma tarefa.
 */
class Tarefa {
private:
    int id; /**< Identificador único da tarefa. */
    std::string descricao; /**< Descrição da tarefa. */
    bool concluida; /**< Indica se a tarefa está concluída. */
    static int totalTarefas; /**< Total de tarefas criadas. */

public:
    /**
     * @brief Construtor da classe Tarefa.
     * @param descricao Descrição da tarefa.
     */
    Tarefa(const std::string& descricao);

    /**
     * @brief Destrutor da classe Tarefa.
     */
    virtual ~Tarefa();

    /**
     * @brief Obtém o ID da tarefa.
     * @return ID da tarefa.
     */
    int getId() const;

    /**
     * @brief Obtém a descrição da tarefa.
     * @return Descrição da tarefa.
     */
    std::string getDescricao() const;

    /**
     * @brief Verifica se a tarefa está concluída.
     * @return true se a tarefa estiver concluída, false caso contrário.
     */
    bool estaConcluida() const;

    /**
     * @brief Marca a tarefa como concluída.
     */
    void concluir();

    /**
     * @brief Exibe informações sobre a tarefa.
     */
    virtual void exibir() const;

    /**
     * @brief Obtém o total de tarefas criadas.
     * @return Total de tarefas.
     */
    static int getTotalTarefas();

    /**
     * @brief Atualiza o total de tarefas criadas.
     * @param novoTotal Novo total de tarefas.
     */
    static void atualizarTotalTarefas(int novoTotal);

    /**
     * @brief Sobrecarga do operador de saída para facilitar a exibição de uma tarefa.
     * @param os Stream de saída.
     * @param tarefa Tarefa a ser exibida.
     * @return Stream de saída atualizada.
     */
    friend std::ostream& operator<<(std::ostream& os, const Tarefa& tarefa);
};

/**
 * @brief Classe que representa uma tarefa agendada para amanhã.
 */
class TarefaAmanha : public Tarefa {
private:
    static int totalTarefasAmanha; /**< Total de tarefas agendadas para amanhã. */

public:
    /**
     * @brief Construtor da classe TarefaAmanha.
     * @param descricao Descrição da tarefa agendada para amanhã.
     */
    TarefaAmanha(const std::string& descricao);

    /**
     * @brief Destrutor da classe TarefaAmanha.
     */
    virtual ~TarefaAmanha();

    /**
     * @brief Sobrescreve a função exibir para exibir informações específicas de tarefas agendadas para amanhã.
     */
    virtual void exibir() const override;

    /**
     * @brief Obtém o total de tarefas agendadas para amanhã.
     * @return Total de tarefas agendadas para amanhã.
     */
    static int getTotalTarefasAmanha();

    /**
     * @brief Atualiza o total de tarefas agendadas para amanhã.
     * @param novoTotal Novo total de tarefas agendadas para amanhã.
     */
    static void atualizarTotalTarefasAmanha(int novoTotal);
};

#endif // TAREFA_H