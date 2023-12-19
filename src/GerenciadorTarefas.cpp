/**
 * @file GerenciadorTarefas.cpp
 * @brief Implementação das funções do Gerenciador de Tarefas.
 * 
 * Este arquivo contém a implementação das funções responsáveis por gerenciar tarefas,
 * como adicionar, exibir, concluir e agendar tarefas para amanhã.
 * 
 * @author Francisco Willem Romão Moreira
 * @date 2023-12-18
 */
#include "Tarefa.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

// Protótipos das funções
/**
 * @brief Exibe o menu de opções do programa.
 */
void exibirMenu();

/**
 * @brief Exibe a lista de tarefas.
 * @param tarefas Vetor de ponteiros para as tarefas.
 */
void exibirTarefas(const std::vector<Tarefa*>& tarefas);

/**
 * @brief Adiciona uma nova tarefa à lista.
 * @param tarefas Vetor de ponteiros para as tarefas.
 */
void adicionarTarefa(std::vector<Tarefa*>& tarefas);

/**
 * @brief Conclui e remove uma tarefa da lista.
 * @param tarefas Vetor de ponteiros para as tarefas.
 */
void concluirTarefa(std::vector<Tarefa*>& tarefas);

/**
 * @brief Adiciona uma nova tarefa agendada para amanhã à lista.
 * @param tarefas Vetor de ponteiros para as tarefas.
 */
void adicionarTarefaAmanha(std::vector<Tarefa*>& tarefas);

/**
 * @brief Lista as tarefas agendadas para amanhã.
 * @param tarefas Vetor de ponteiros para as tarefas.
 */
void listarTarefasAmanha(const std::vector<Tarefa*>& tarefas);

/**
 * @brief Salva as tarefas no arquivo "tarefas.txt".
 * @param tarefas Vetor de ponteiros para as tarefas.
 */
void salvarTarefas(const std::vector<Tarefa*>& tarefas);

/**
 * @brief Função principal do programa.
 * @return 0 ao finalizar o programa.
 */
int main();

// Implementação das funções

/**
 * @brief Exibe o menu de opções do programa.
 */
void exibirMenu() {
    std::cout << "===== Gerenciador de Tarefas =====\n";
    std::cout << "1. Adicionar\n";
    std::cout << "2. Listar\n";
    std::cout << "3. Concluir e Remover\n";
    std::cout << "4. Adicionar Tarefa para Amanhã\n";
    std::cout << "5. Listar Tarefas para Amanhã\n";
    std::cout << "6. Sair e Salvar\n \n";
}

/**
 * @brief Exibe a lista de tarefas.
 * @param tarefas Vetor de ponteiros para as tarefas.
 */
void exibirTarefas(const std::vector<Tarefa*>& tarefas) {
    std::cout << "===== Lista de Tarefas =====\n";
    for (const Tarefa* tarefa : tarefas) {
        tarefa->exibir();
    }
    std::cout << "Total de tarefas: " << Tarefa::getTotalTarefas() << "\n \n";
}

/**
 * @brief Adiciona uma nova tarefa à lista.
 * @param tarefas Vetor de ponteiros para as tarefas.
 */
void adicionarTarefa(std::vector<Tarefa*>& tarefas) {
    std::string descricao;
    std::cout << "Digite a descrição da tarefa: ";
    std::getline(std::cin, descricao);

    Tarefa* novaTarefa = new Tarefa(descricao);
    tarefas.push_back(novaTarefa);

    std::cout << "Tarefa adicionada com sucesso!\n \n";
}

/**
 * @brief Conclui e remove uma tarefa da lista.
 * @param tarefas Vetor de ponteiros para as tarefas.
 */
void concluirTarefa(std::vector<Tarefa*>& tarefas) {
    if (tarefas.empty()) {
        std::cout << "Não há tarefas para concluir.\n";
        return;
    }

    exibirTarefas(tarefas);

    int id;
    std::cout << "Digite o ID da tarefa a ser concluída: ";
    std::cin >> id;

    auto it = std::remove_if(tarefas.begin(), tarefas.end(), [id](const Tarefa* tarefa) {
        return tarefa->getId() == id;
    });

    if (it != tarefas.end()) {
        // Criar um vetor temporário para armazenar as tarefas concluídas
        std::vector<Tarefa*> concluidas;
        std::copy_if(tarefas.begin(), it, std::back_inserter(concluidas), [id](const Tarefa* tarefa) {
            return tarefa->getId() == id;
        });

        // Remover as tarefas concluídas do vetor principal
        tarefas.erase(it, tarefas.end());

        // Exibir as tarefas concluídas
        for (const Tarefa* tarefa : concluidas) {
            tarefa->exibir();
            delete tarefa; // Liberar a memória
        }

        std::cout << "Tarefa concluída e removida com sucesso!\n \n";
    } else {
        std::cout << "Tarefa não encontrada.\n \n";
    }

    TarefaAmanha::atualizarTotalTarefasAmanha(tarefas.size());

    Tarefa::atualizarTotalTarefas(tarefas.size());
}

/**
 * @brief Adiciona uma nova tarefa agendada para amanhã à lista.
 * @param tarefas Vetor de ponteiros para as tarefas.
 */
void adicionarTarefaAmanha(std::vector<Tarefa*>& tarefas) {
    std::string descricao;
    std::cout << "Digite a descrição da tarefa para amanhã: ";
    std::getline(std::cin, descricao);

    TarefaAmanha* novaTarefaAmanha = new TarefaAmanha(descricao);
    tarefas.push_back(novaTarefaAmanha);

    std::cout << "Tarefa para amanhã adicionada com sucesso!\n \n";

    TarefaAmanha::atualizarTotalTarefasAmanha(tarefas.size());
}

/**
 * @brief Lista as tarefas agendadas para amanhã.
 * @param tarefas Vetor de ponteiros para as tarefas.
 */
void listarTarefasAmanha(const std::vector<Tarefa*>& tarefas) {
    std::cout << "===== Lista de Tarefas para Amanhã =====\n";
    for (const Tarefa* tarefa : tarefas) {
        const TarefaAmanha* tarefaAmanha = dynamic_cast<const TarefaAmanha*>(tarefa);
        if (tarefaAmanha) {
            tarefaAmanha->exibir();
        }
    }
}

/**
 * @brief Salva as tarefas no arquivo "tarefas.txt".
 * @param tarefas Vetor de ponteiros para as tarefas.
 */
void salvarTarefas(const std::vector<Tarefa*>& tarefas) {
    std::ofstream arquivo("tarefas.txt");

    if (arquivo.is_open()) {
        for (const Tarefa* tarefa : tarefas) {
            arquivo << tarefa->getId() << " " << tarefa->getDescricao();

            const TarefaAmanha* tarefaAmanha = dynamic_cast<const TarefaAmanha*>(tarefa);
            if (tarefaAmanha) {
                arquivo << " (Tarefa para Amanhã)";
            }

            arquivo << "\n";
        }

        arquivo.close();
        std::cout << "Tarefas salvas com sucesso!\n";
    } else {
        std::cerr << "Erro ao abrir o arquivo para salvar tarefas.\n";
    }
}

/**
 * @brief Função principal do programa.
 * @return 0 ao finalizar o programa.
 */
int main() {
    std::vector<Tarefa*> tarefas;

    int escolha;
    do {
        exibirMenu();
        std::cout << "Digite sua escolha: ";
        std::cin >> escolha;
        std::cin.ignore();

        switch (escolha) {
            case 1:
                adicionarTarefa(tarefas);
                break;
            case 2:
                exibirTarefas(tarefas);
                break;
            case 3:
                concluirTarefa(tarefas);
                break;
            case 4:
                adicionarTarefaAmanha(tarefas);
                break;
            case 5:
                listarTarefasAmanha(tarefas);
                break;
            case 6:
                std::cout << "Saindo do programa.\n";
                break;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }

    } while (escolha != 6);

    salvarTarefas(tarefas);

    // Desalocação de memória
    for (Tarefa* tarefa : tarefas) {
        delete tarefa;
    }

    tarefas.clear();

    return 0;
}
