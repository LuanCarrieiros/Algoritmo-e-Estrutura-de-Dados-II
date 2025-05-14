# TP02 – Algoritmos e Estruturas de Dados II

Este repositório contém o **Trabalho Prático 2 (TP02)** da disciplina Algoritmos e Estruturas de Dados II, onde aplicamos diversos algoritmos de busca e ordenação em um conjunto de personagens do universo Harry Potter.

---

## 🚀 Objetivos

* Implementar buscas sequenciais com registro de estatísticas.
* Desenvolver e comparar algoritmos de ordenação: Selection, Insertion, Heap, Counting, Merge e Quick Parcial.
* Instrumentar o código para medir tempo de execução, número de comparações e movimentações.

---

## 📂 Conteúdo

| Questão | Linguagem | Arquivo                      | Algoritmo                 | Descrição                                         |
| ------- | --------- | ---------------------------- | ------------------------- | ------------------------------------------------- |
| Q01     | Java      | `Q01_SearchById.java`        | Busca Sequencial          | Pesquisa por ID até `FIM`.                        |
| Q02     | C         | `Q02_Registro.c`             | Registro & struct         | Leitura e impressão de structs.                   |
| Q03     | Java      | `Q03_SearchByName.java`      | Busca Sequencial          | Pesquisa por nome até `FIM` e log de comparações. |
| Q04     | C         | `Q04_BinarySearch.c`         | Busca Binária             | Pesquisa em vetor ordenado.                       |
| Q05     | Java      | `Q05_SortByName.java`        | Selection Sort            | Ordenação completa por nome.                      |
| Q06     | C         | `Q06_SelectionRec.c`         | Selection Sort Recursivo  | Ordenação recursiva por seleção.                  |
| Q07     | Java      | `Q07_SortByDOB.java`         | Insertion Sort            | Ordenação completa por data de nascimento.        |
| Q08     | C         | `Q08_Shellsort.c`            | Shellsort                 | Ordenação por gaps.                               |
| Q09     | Java      | `Q09_SortByHairColour.java`  | Heap Sort                 | Ordenação completa por cor de cabelo.             |
| Q10     | C         | `Q10_Quicksort.c`            | Quicksort                 | Ordenação rápida interna.                         |
| Q11     | Java      | `Q11_SortByYear.java`        | Counting Sort             | Ordenação completa por ano.                       |
| Q12     | C         | `Q12_Bubble.c`               | Bubble Sort               | Ordenação por bolha.                              |
| Q13     | Java      | `Q13_SortByActorName.java`   | Merge Sort                | Ordenação completa por nome do ator.              |
| Q14     | C         | `Q14_RadixSort.c`            | Radix Sort                | Ordenação por dígitos.                            |
| Q15     | Java      | `Q15_SortByNameParcial.java` | Selection Sort Parcial    | Top 10 por nome.                                  |
| Q16     | Java      | `Q16_InsertionParcial.java`  | Insertion Sort Parcial    | Top 10 por data de nascimento.                    |
| Q17     | C         | `Q17_HeapPartial.c`          | Heap Sort Parcial (top k) | Top k por heap.                                   |
| Q18     | Java      | `Q18_SortByHouse.java`       | Quick Sort Parcial        | Ordenação parcial (k = lista.size()).             |

---

## 🛠️ Como Compilar

No terminal, na pasta raiz `TP02/`, execute:

```bash
javac -d . helpers/*.java *.java
```

* O parâmetro `-d .` cria as pastas de pacote para as classes em `helpers/`.

---

## ▶️ Como Executar

Depois de compilado, rode cada exercício com:

```bash
java Q01_SearchById
java Q03_SearchByName
# ...
java Q18_SortByHouse
```

As entradas são lidas até a linha `FIM` e os resultados são impressos no console.

---

## 📊 Logs de Execução

Os algoritmos geram arquivos de log na pasta `logs/` com estatísticas:

* **Tempo de execução** (segundos, 6 casas decimais)
* **Número de comparações**
* **Número de movimentações**

Arquivos de exemplo:

```
logs/816676_selecao.txt
logs/816676_mergeSort.txt
…
```

---

## 🛠️ Ferramentas

* **Java 11+** (JDK)
* **javac** e **java** (linha de comando)
* C (gcc) 

---

Uso acadêmico. Feel free to study and adapt!
