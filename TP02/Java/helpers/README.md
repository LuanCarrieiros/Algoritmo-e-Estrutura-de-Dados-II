# Pasta helpers

Este diretório contém classes auxiliares utilizadas pelas questões do TP02, separando lógica de leitura, modelo de dados, utilitários e algoritmos.

---

## 📖 Carregador.java

* **Pacote:** `helpers`
* **Função:** Lê o arquivo CSV (`tmp/characters.csv`), parseia cada linha e retorna uma `List<Personagem>`.
* **Uso:**

  ```java
  List<Personagem> lista = Carregador.carregar("tmp/characters.csv");
  ```

---

## 🧙‍♂️ Personagem.java

* **Pacote:** `helpers`
* **Função:** Modelo de dados para os personagens:

  * Atributos: `id`, `name`, `alternate_names`, `house`, `ancestry`, etc.
  * Métodos: `ler(String)`, `imprimir()`, getters/setters.
* **Uso:** Cada instância representa um personagem com todos os campos do CSV.

---

## 🛠️ Utils.java

* **Pacote:** `helpers`
* **Função:** Métodos utilitários:

  * `isEnd(String)`: verifica se a entrada é `"FIM"`.
  * Métodos de desempate para ordenação:

    * `desempate(Personagem, Personagem)`: por data e nome.
    * `desempateHouse(...)`: por casa e nome.
    * `desempateHairColour(...)`: por cor de cabelo e nome.
    * `desempateYearOfBirth(...)`: por ano e nome.

---

## ⏱️ Timer.java

* **Pacote:** `helpers`
* **Função:** Instrumenta o código para medir:

  * **Tempo de execução** (resolução em nanossegundos)
  * **Número de comparações** (`comparacao()`)
  * **Número de movimentações** (`movimentacao(int)`)
* **Logs:** Salva arquivos `.txt` na pasta `logs/`, ofertando estatísticas formatadas.

---

## 🔍 SearchUtils.java

* **Pacote:** `helpers`
* **Função:** Centraliza métodos de busca:

  * `searchById(...)`: busca sequencial por ID até `FIM` (Q01).
  * `searchByName(...)`: busca sequencial por nome até `FIM` (Q03), contando comparações e gerando log via `Timer`.

---

## 🔢 SortUtils.java

* **Pacote:** `helpers`
* **Função:** Implementa diversos algoritmos de ordenação, todos usando `Timer`:

  * **Selection Sort:** `selecao` e `selecaoParcial` (top k).
  * **Insertion Sort:** `insercao` e `insercaoParcial` (top k).
  * **Heap Sort:** `heapSort` e seu `buildHeap`.
  * **Merge Sort:** `mergeSort` (recursivo e `intercalar`).
  * **Quick Sort Parcial:** `quickSortPartial` (ordenar apenas os k primeiros).
  * **Counting Sort:** `countingSort` (por ano de nascimento, estável).

**Exemplo de uso:**

```java
List<Personagem> subset = ...;
SortUtils.heapSort(subset);

String[] nomes = ...;
SortUtils.selecao(nomes);
```

---

### Observação

* A separação em helpers torna as classes das questões (`QXX_*.java`) mais enxutas, concentrando a lógica e a instrumentação nos utilitários.
* Para gerar logs, basta executar qualquer `QXX` normalmente; os arquivos serão criados em `TP02/logs/`.
