# Algoritmo e Estrutura de Dados II

Repositório contendo as implementações completas dos trabalhos práticos da disciplina **Algoritmos e Estruturas de Dados II** (AEDS II). O projeto abrange desde conceitos fundamentais de programação até estruturas de dados avançadas, com análise de complexidade e implementações otimizadas.

## 📚 Visão Geral

Este repositório é organizado em trabalhos práticos progressivos que exploram diferentes aspectos da ciência da computação:

- **Fundamentos**: Lógica de programação e recursão
- **Algoritmos**: Ordenação e pesquisa com análise de complexidade  
- **Estruturas Lineares**: Pilhas, filas e listas ligadas
- **Estruturas Avançadas**: Árvores, grafos e tabelas hash

## 🗂️ Estrutura do Repositório

```
Algoritmo-e-Estrutura-de-Dados-II/
├── Aquecimento/              # Exercícios introdutórios
│   ├── ColecaoPokemon.java   # Manipulação de listas
│   ├── Combinador.java       # Algoritmos de combinação
│   ├── Lab01.java/.c         # Laboratório inicial
│   └── Noções de complexidade/
├── TP01/                     # Lógica e Recursão (15 questões)
│   ├── Q01-Q09_*.java/.c     # Versões iterativas
│   ├── Q10-Q15_*Rec.java/.c  # Versões recursivas
│   └── MyIO.java             # Biblioteca de entrada/saída
├── TP02/                     # Algoritmos de Ordenação (18 questões)
│   ├── TP02Q01-Q18.*         # Implementações completas
│   ├── Java/ & C/            # Separação por linguagem
│   └── logs/                 # Arquivos de análise de performance
├── TP03/                     # Estruturas de Dados Lineares
│   ├── Pilhas e Filas/       # Implementações básicas
│   ├── Listas Ligadas/       # Simples e duplas
│   └── Aplicações/           # Casos de uso práticos
└── TP04/                     # Estruturas Avançadas
    ├── Árvores/              # BST, AVL, Red-Black
    ├── Hash/                 # Tabelas hash e tratamento de colisões
    └── Grafos/               # Representações e algoritmos
```

## 🎯 Trabalhos Práticos

### [TP01 - Fundamentos e Recursão](TP01/)
**15 questões** cobrindo conceitos fundamentais:
- **Algoritmos Básicos**: Palíndromos, Cifra de César, Álgebra Booleana
- **Manipulação de Strings**: Validação, transformações, parsing HTML
- **Recursão**: Implementações recursivas de todos os algoritmos iterativos
- **E/S de Arquivos**: Leitura e escrita de dados estruturados

**Linguagens**: Java (9 questões) + C (6 questões)

### [TP02 - Algoritmos de Ordenação e Pesquisa](TP02/)
**18 questões** com análise experimental completa:
- **Algoritmos de Pesquisa**: Sequencial e Binária
- **Ordenação Clássica**: Selection, Insertion, Merge, Quick, Heap, Counting, Bubble, Shell, Radix
- **Ordenação Parcial**: Top-k elementos com k=10
- **Análise de Complexidade**: Instrumentação para contagem de comparações e movimentações

**Linguagens**: Java (9 questões) + C (9 questões)  
**Dataset**: 405 personagens do universo Harry Potter (17 atributos cada)

### [TP03 - Estruturas de Dados Lineares](TP03/)
Implementação de estruturas fundamentais:
- **Pilhas (Stack)**: LIFO com aplicações em expressões matemáticas
- **Filas (Queue)**: FIFO e filas circulares otimizadas
- **Listas Ligadas**: Simples, duplas e circulares
- **Aplicações Práticas**: Simulações e resolução de problemas

### [TP04 - Estruturas Avançadas](TP04/)
Estruturas de dados complexas:
- **Árvores de Busca**: BST, AVL (auto-balanceamento), Red-Black
- **Tabelas Hash**: Tratamento de colisões (encadeamento e endereçamento aberto)
- **Árvores Especiais**: TRIE para busca em strings
- **Grafos**: Representações e algoritmos de busca

## 🛠️ Tecnologias e Ferramentas

- **Java 11+**: Linguagem principal com orientação a objetos
- **C (C99)**: Para conceitos de baixo nível e gerenciamento de memória
- **GCC**: Compilador C com flags de otimização
- **JDK**: Kit de desenvolvimento Java
- **Sistema Verde**: Compatibilidade com plataforma de avaliação Linux

## 🚀 Como Executar

### Pré-requisitos
```bash
# Java
sudo apt install openjdk-11-jdk

# C
sudo apt install gcc build-essential
```

### Execução Geral
1. **Clone o repositório**:
   ```bash
   git clone https://github.com/usuario/Algoritmo-e-Estrutura-de-Dados-II.git
   cd Algoritmo-e-Estrutura-de-Dados-II
   ```

2. **Navegue até o trabalho desejado**:
   ```bash
   cd TP01  # ou TP02, TP03, TP04
   ```

3. **Consulte o README específico** para instruções detalhadas de cada trabalho.

### Compilação Rápida
```bash
# Java
javac *.java && java ClassePrincipal

# C  
gcc programa.c -o programa && ./programa
```

## 📊 Estatísticas do Projeto

- **Total de Questões**: 50+ implementações
- **Linguagens**: Java (70%) + C (30%)
- **Algoritmos Implementados**: 20+ algoritmos clássicos
- **Estruturas de Dados**: 15+ estruturas diferentes
- **Linhas de Código**: 10,000+ LOC
- **Tempo de Desenvolvimento**: 1 semestre acadêmico

## 🎓 Conceitos Abordados

### Fundamentais
- **Análise de Algoritmos**: Complexidade temporal e espacial (Big O)
- **Técnicas de Programação**: Iteração, recursão, divisão e conquista
- **Estruturas de Controle**: Loops, condicionais, manipulação de dados

### Intermediários  
- **Algoritmos de Ordenação**: Comparação experimental de performance
- **Algoritmos de Pesquisa**: Estratégias lineares e logarítmicas
- **Recursão Avançada**: Backtracking e programação dinâmica

### Avançados
- **Estruturas Auto-organizáveis**: Árvores balanceadas automaticamente
- **Hashing**: Funções hash e resolução de conflitos
- **Otimização**: Técnicas para melhorar performance e uso de memória

## 🏆 Resultados e Validação

- **Testes Automatizados**: Validação contra casos de teste fornecidos
- **Análise de Performance**: Logs detalhados de execução e métricas
- **Compatibilidade**: Funcionamento garantido em ambiente Linux (Verde)
- **Qualidade de Código**: Seguimento de boas práticas e padrões acadêmicos

## 📖 Referências Acadêmicas

- **Livro Texto**: "Algoritmos e Estruturas de Dados" - Cormen, Leiserson, Rivest, Stein
- **Material Complementar**: Slides de aula e exercícios práticos
- **Plataforma de Teste**: Sistema Verde para validação automática

---

**Disciplina**: Algoritmos e Estruturas de Dados II  
**Instituição**: [Nome da Universidade]  
**Período**: [2024.1]  
**Matrícula**: 816676

> ⚠️ **Nota Acadêmica**: Este repositório contém trabalhos acadêmicos desenvolvidos para fins educacionais. O uso do código deve respeitar as políticas de integridade acadêmica da instituição.