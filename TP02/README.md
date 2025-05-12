# TP02 – Algoritmos e Estruturas de Dados II

Este repositório contém o **Trabalho Prático 2 (TP02)** da disciplina Algoritmos e Estruturas de Dados II, onde aplicamos diversos algoritmos de busca e ordenação em um conjunto de personagens do universo Harry Potter.

---

## 🚀 Objetivos

* Implementar buscas sequenciais com registro de estatísticas.
* Desenvolver e comparar algoritmos de ordenação: Selection, Insertion, Heap, Counting, Merge e Quick Parcial.
* Instrumentar o código para medir tempo de execução, número de comparações e movimentações.
* Obs: os códigos em C ainda serão upados.

---

## 📂 Conteúdo

| Questão | Arquivo                             | Algoritmo              | Descrição                                          |
| ------- | ----------------------------------- | ---------------------- | -------------------------------------------------- |
| Q01     | `Q01_SearchById.java`               | Busca Sequencial       | Pesquisa por ID até `FIM`.                         |
| Q03     | `Q03_SearchByName.java`             | Busca Sequencial       | Pesquisa por nome até `FIM` e log de comparações.  |
| Q05     | `Q05_SortByName.java`               | Selection Sort         | Ordenação completa por nome.                       |
| Q07     | `Q07_SortByDateOfBirth.java`        | Insertion Sort         | Ordenação completa por data de nascimento.         |
| Q09     | `Q09_SortByHairColour.java`         | Heap Sort              | Ordenação completa por cor de cabelo.              |
| Q11     | `Q11_SortByYear.java`               | Counting Sort          | Ordenação completa por ano de nascimento.          |
| Q13     | `Q13_SortByActorName.java`          | Merge Sort             | Ordenação completa por nome do ator.               |
| Q15     | `Q15_SortByNameParcial.java`        | Selection Sort Parcial | Ordenação parcial (top 10) por nome.               |
| Q16     | `Q16_SortByDateOfBirthParcial.java` | Insertion Sort Parcial | Ordenação parcial (top 10) por data de nascimento. |
| Q18     | `Q18_SortByHouse.java`              | Quick Sort Parcial     | Ordenação parcial por casa (k = lista.size()).     |

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
