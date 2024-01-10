# Gerenciador de Tarefas

### Descrição do Projeto

O projeto consiste em um gerenciador de tarefas implementado em C++, dividido em três arquivos principais: `Tarefa.h`, `Tarefa.cpp` e `GerenciadorTarefas.cpp`. O código é estruturado de forma a demonstrar conceitos importantes de programação, como alocação de memória dinâmica, manipulação de arquivos, construtores, destrutores, uso de memória estática, sobrecarga de função e herança.

### Tarefa.h
Este arquivo contém a definição da classe `Tarefa` e a classe derivada `TarefaAmanha`. A classe `Tarefa` possui membros privados, como o identificador (`id`), descrição (`descricao`) e estado de conclusão (`concluida`). Há também um membro estático (`totalTarefas`) que mantém o total de tarefas criadas.

A classe `Tarefa` possui métodos para obter o ID, a descrição, verificar se a tarefa está concluída, concluir a tarefa, exibir informações e métodos estáticos para obter o total de tarefas e atualizar esse total. A sobrecarga do operador de saída (`<<`) é utilizada para facilitar a exibição das informações da tarefa.

A classe derivada `TarefaAmanha` herda da classe `Tarefa` e adiciona seu próprio membro estático (`totalTarefasAmanha`). Além disso, ela sobrescreve o método `exibir` para incluir informações específicas sobre tarefas programadas para o dia seguinte.

### Tarefa.cpp

Neste arquivo, são implementados os métodos declarados na classe `Tarefa` e `TarefaAmanha`. A alocação dinâmica de memória é utilizada para criar novas instâncias de tarefas. O destrutor é responsável por liberar a memória alocada para cada tarefa.

Os métodos de manipulação de tarefas, como adicionar, concluir e exibir, são implementados para facilitar a interação com o gerenciador. O arquivo também contém a implementação de funções estáticas para atualizar o total de tarefas.

### GerenciadorTarefas.cpp
O arquivo principal do programa implementa as funções de interação com o usuário, utilizando um menu simples. As funções incluem adição de tarefas, listagem, conclusão de tarefas, adição de tarefas para o dia seguinte, listagem de tarefas para o dia seguinte, salvamento das tarefas em um arquivo e desalocação de memória.

É importante observar que a desalocação de memória é realizada no final do programa para evitar vazamento de memória. Além disso, as funções de salvar tarefas em um arquivo e listar tarefas para o dia seguinte demonstram o uso de manipulação de arquivos.

### Compilação

Um método mais prático seria fazendo uso do CMake e na pasta raíz do projeto executar os comandos abaixo:

```
mkdir build
cd build
cmake ..
```
Uma vez compilado:
```
make
./GerenciadorTarefas
```

### Menu

![Menu do Programa](/img/menu.png)
