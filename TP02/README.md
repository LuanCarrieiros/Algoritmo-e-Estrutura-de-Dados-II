# TP02 - Algoritmos de Ordenação e Pesquisa

Implementação completa do Trabalho Prático 02 da disciplina **Algoritmos e Estruturas de Dados II** (AEDS II). Este trabalho aborda a implementação e análise de diferentes algoritmos de ordenação e pesquisa utilizando um dataset de personagens do universo Harry Potter.

## 📋 Especificação

O trabalho consiste na implementação de **18 questões** que abordam:
- **Algoritmos de Pesquisa**: Sequencial e Binária
- **Algoritmos de Ordenação Completa**: Selection Sort, Insertion Sort, Merge Sort, Quick Sort, Heap Sort, Counting Sort, Bubble Sort, Shell Sort, Radix Sort
- **Algoritmos de Ordenação Parcial**: Selection Sort (k=10), Insertion Sort (k=10), Heap Sort (k=10), Quick Sort (k=n)

## 🏗️ Estrutura do Projeto

```
TP02/
├── TP02Q01.java    # Pesquisa por ID (Java)
├── TP02Q02.c       # Registro de personagem (C)
├── TP02Q03.java    # Pesquisa sequencial por nome (Java)
├── TP02Q04.c       # Pesquisa binária (C)
├── TP02Q05.java    # Selection Sort por nome (Java)
├── TP02Q06.c       # Selection Sort recursivo por nome (C)
├── TP02Q07.java    # Insertion Sort por data nascimento (Java)
├── TP02Q08.c       # Shell Sort por cor dos olhos (C)
├── TP02Q09.java    # Heap Sort por cor do cabelo (Java)
├── TP02Q10.c       # Quick Sort por casa (C)
├── TP02Q11.java    # Counting Sort por ano nascimento (Java)
├── TP02Q12.c       # Bubble Sort por cor do cabelo (C)
├── TP02Q13.java    # Merge Sort por nome do ator (Java)
├── TP02Q14.c       # Radix Sort por ID (C)
├── TP02Q15.java    # Selection Sort parcial por nome k=10 (Java)
├── TP02Q16.c       # Insertion Sort parcial por data k=10 (C)
├── TP02Q17.c       # Heap Sort parcial por cabelo k=10 (C)
├── TP02Q18.java    # Quick Sort parcial por casa k=n (Java)
└── README.md
```

## 🎯 Questões Implementadas

| Questão | Linguagem | Algoritmo                      | Atributo de Ordenação | Tipo                         |
|---------|-----------|--------------------------------|-------------------------|------------------------------|
| Q01     | Java      | Pesquisa por ID                | -                       | Pesquisa                     |
| Q02     | C         | Registro                       | -                       | Estrutura                    |
| Q03     | Java      | Pesquisa Sequencial            | name                    | Pesquisa                     |
| Q04     | C         | Pesquisa Binária               | name                    | Pesquisa                     |
| Q05     | Java      | Selection Sort                 | name                    | Ordenação Completa           |
| Q06     | C         | Selection Sort (Recursivo)     | name                    | Ordenação Completa           |
| Q07     | Java      | Insertion Sort                 | dateOfBirth             | Ordenação Completa           |
| Q08     | C         | Shell Sort                     | eyeColour               | Ordenação Completa           |
| Q09     | Java      | Heap Sort                      | hairColour              | Ordenação Completa           |
| Q10     | C         | Quick Sort                     | house                   | Ordenação Completa           |
| Q11     | Java      | Counting Sort                  | yearOfBirth             | Ordenação Completa           |
| Q12     | C         | Bubble Sort                    | hairColour              | Ordenação Completa           |
| Q13     | Java      | Merge Sort                     | actorName               | Ordenação Completa           |
| Q14     | C         | Radix Sort                     | id                      | Ordenação Completa           |
| Q15     | Java      | Selection Sort Parcial         | name                    | Ordenação Parcial (k=10)    |
| Q16     | C         | Insertion Sort Parcial         | dateOfBirth             | Ordenação Parcial (k=10)    |
| Q17     | C         | Heap Sort Parcial              | hairColour              | Ordenação Parcial (k=10)    |
| Q18     | Java      | Quick Sort Parcial             | house                   | Ordenação Parcial (k=n)     |

## 🔧 Detalhes de Implementação

### Estrutura de Dados Customizada
Todas as implementações utilizam **estruturas de dados customizadas** sem dependência de bibliotecas externas:
- **Java**: Classe `ListaPersonagem` com array interno
- **C**: Struct `ListaPersonagem` com gerenciamento manual de memória

### Compatibilidade com Sistema de Avaliação
As implementações em C utilizam o padrão de entrada `scanf(" %[^\r\n]%*c", linha)` para compatibilidade com o sistema Verde (Linux).

### Análise de Complexidade
Cada algoritmo gera logs de execução contendo:
- **Matrícula**: 816676
- **Comparações**: Número total de comparações realizadas
- **Movimentações**: Número total de movimentações de elementos
- **Tempo de execução**: Tempo em segundos com precisão de microssegundos

## 🚀 Como Executar

### Compilação e Execução Java
```bash
# Exemplo para Q01 - Pesquisa por ID
javac TP02Q01.java && java TP02Q01 < "entrada e saida/TP02Q01 - Pesquisa ID/pub.in"

# Exemplo para Q03 - Pesquisa Sequencial
javac TP02Q03.java && java TP02Q03 < "entrada e saida/TP02Q03 - Pesquisa Sequencial/pub.in"

# Exemplo para Q05 - Selection Sort
javac TP02Q05.java && java TP02Q05 < "entrada e saida/TP02Q05 - Selection Sort/pub.in"
```

### Compilação e Execução C
```bash
# Exemplo para Q02 - Registro
gcc TP02Q02.c -o TP02Q02 && ./TP02Q02 < "entrada e saida/TP02Q02 - Registro/pub.in"

# Exemplo para Q04 - Pesquisa Binária
gcc TP02Q04.c -o TP02Q04 && ./TP02Q04 < "entrada e saida/TP02Q04 - Pesquisa Binaria/pub.in"

# Exemplo para Q06 - Selection Sort Recursivo
gcc TP02Q06.c -o TP02Q06 && ./TP02Q06 < "entrada e saida/TP02Q06 - Selection Sort Rec/pub.in"
```

### 📁 Como Encontrar o Caminho Correto
Para cada questão, o arquivo de entrada estará localizado em:
```
"entrada e saida/[NOME_DA_QUESTAO]/pub.in"
```

Substitua `[NOME_DA_QUESTAO]` pelo nome específico da pasta da questão desejada. Exemplos:
- TP02Q01 - Pesquisa ID
- TP02Q02 - Registro
- TP02Q03 - Pesquisa Sequencial
- TP02Q04 - Pesquisa Binaria
- TP02Q05 - Selection Sort
- E assim por diante para todas as 18 questões...

## 📊 Dataset

O dataset utilizado é o arquivo `/tmp/characters.csv` contendo 405 personagens do universo Harry Potter com 17 atributos cada:
- id, name, alternate_names, house, ancestry, species, patronus
- hogwartsStaff, hogwartsStudent, actorName, alive
- dateOfBirth, yearOfBirth, eyeColour, gender, hairColour, wizard

## 🎓 Conceitos Abordados

- **Algoritmos de Ordenação**: Análise de complexidade temporal e espacial
- **Algoritmos de Pesquisa**: Pesquisa sequencial vs. binária
- **Estruturas de Dados**: Implementação de listas dinâmicas
- **Análise Experimental**: Instrumentação de código para coleta de métricas
- **Programação Defensiva**: Tratamento de entrada e gerenciamento de memória
- **Compatibilidade Cross-Platform**: Tratamento de entrada para diferentes sistemas

## 🏆 Resultados

Todos os algoritmos foram testados e validados contra casos de teste fornecidos, demonstrando:
- Corretude na implementação
- Eficiência na execução
- Compatibilidade com sistema de avaliação automática
- Análise precisa de complexidade experimental

---
**Disciplina**: Algoritmos e Estruturas de Dados II  
**Trabalho**: TP02 - Algoritmos de Ordenação e Pesquisa  
**Matrícula**: 816676  
**Universidade**: PUC Minas