# TP01 - Fundamentos de Programação e Recursão

Implementação do Trabalho Prático 01 da disciplina **Algoritmos e Estruturas de Dados II** (AEDS II). Este trabalho explora conceitos fundamentais de programação, comparando abordagens iterativas e recursivas em algoritmos básicos, manipulação de strings e operações com arquivos.

## 📋 Especificação

O trabalho consiste na implementação de **15 questões** organizadas em pares iterativo/recursivo:
- **Algoritmos Fundamentais**: Verificação de palíndromos, cifra de César, álgebra booleana
- **Manipulação de Strings**: Transformações, validações e parsing
- **Operações com Arquivos**: Leitura e escrita de dados
- **Análise Comparativa**: Implementações iterativas vs. recursivas

## 🏗️ Estrutura do Projeto

```
TP01/
├── Q01_Palindromo.java          # Verificação de palíndromo (iterativo)
├── Q02_palindromo.c             # Verificação de palíndromo (iterativo)
├── Q03_CifraCesar.java          # Cifra de César (iterativo)
├── Q04_AlteracaoAleatoria.java  # Alteração aleatória de chars (iterativo)
├── Q05_Algebra.java             # Álgebra booleana (iterativo)
├── Q06_Is.java                  # Validação de strings (iterativo)
├── Q07_html.java                # Parsing HTML com contadores (iterativo)
├── Q08_Arquivo.java             # Leitura/escrita de arquivo (iterativo)
├── Q09_Arquivo.c                # Leitura/escrita de arquivo (iterativo)
├── Q10_PalindromoRec.java       # Verificação de palíndromo (recursivo)
├── Q11_palindromoRec.c          # Verificação de palíndromo (recursivo)
├── Q12_CifraCesarRec.java       # Cifra de César (recursivo)
├── Q13_AlteracaoAleatoriaRec.c  # Alteração aleatória (recursivo)
├── Q14_AlgebraRec.java          # Álgebra booleana (recursivo)
├── Q15_IsRec.java               # Validação de strings (recursivo)
├── MyIO.java                    # Biblioteca de entrada/saída
└── README.md
```

## 🎯 Questões Implementadas

| Questão | Linguagem | Abordagem  | Algoritmo           | Descrição                           |
|---------|-----------|------------|---------------------|-------------------------------------|
| Q01     | Java      | Iterativa  | Palíndromo          | Verificação usando loops            |
| Q02     | C         | Iterativa  | Palíndromo          | Implementação com arrays            |
| Q03     | Java      | Iterativa  | Cifra de César      | Deslocamento de caracteres          |
| Q04     | Java      | Iterativa  | Alteração Aleatória | Substituição de caracteres          |
| Q05     | Java      | Iterativa  | Álgebra Booleana    | Avaliação de expressões             |
| Q06     | Java      | Iterativa  | Validação de Strings| Verificação de tipos de caracteres |
| Q07     | Java      | Iterativa  | Parser HTML         | Contagem de tags e caracteres       |
| Q08     | Java      | Iterativa  | Arquivo             | Operações de E/S                    |
| Q09     | C         | Iterativa  | Arquivo             | Leitura/escrita binária             |
| Q10     | Java      | Recursiva  | Palíndromo          | Verificação recursiva               |
| Q11     | C         | Recursiva  | Palíndromo          | Implementação recursiva             |
| Q12     | Java      | Recursiva  | Cifra de César      | Deslocamento recursivo              |
| Q13     | C         | Recursiva  | Alteração Aleatória | Substituição recursiva              |
| Q14     | Java      | Recursiva  | Álgebra Booleana    | Avaliação recursiva                 |
| Q15     | Java      | Recursiva  | Validação de Strings| Verificação recursiva               |

Q7 tinha um bug até então. 
## 🔧 Detalhes de Implementação

### Biblioteca MyIO
Classe utilitária que padroniza operações de entrada e saída:
- **Entrada**: Leitura de strings, inteiros, caracteres
- **Saída**: Formatação e impressão padronizada
- **Compatibilidade**: Funciona em diferentes ambientes Java

### Algoritmos Implementados

#### 1. Verificação de Palíndromo
- **Iterativo**: Comparação de ponteiros das extremidades
- **Recursivo**: Divisão do problema pela metade
- **Complexidade**: O(n) para ambas as abordagens

#### 2. Cifra de César
- **Iterativo**: Loop através de cada caractere
- **Recursivo**: Processamento caractere por caractere
- **Funcionalidade**: Deslocamento de 3 posições no alfabeto

#### 3. Álgebra Booleana
- **Iterativo**: Avaliação sequencial com stack
- **Recursivo**: Parsing recursivo de expressões
- **Operadores**: and, or, not com precedência

#### 4. Validação de Strings
- **Iterativo**: Verificação sequencial de condições
- **Recursivo**: Divisão do problema por caractere
- **Validações**: Vogais, consoantes, inteiros, reais

### Comparação Iterativo vs. Recursivo

| Aspecto         | Iterativo                  | Recursivo                   |
|-----------------|----------------------------|-----------------------------|
| **Memória**     | O(1) adicional             | O(n) stack                  |
| **Performance** | Geralmente mais rápida     | Overhead de chamadas        |
| **Legibilidade**| Mais verbosa               | Mais elegante               |
| **Depuração**   | Mais fácil                 | Stack trace complexo        |

## 🚀 Como Executar

### Compilação e Execução Java
```bash
# Exemplo para Q01 - Palíndromo
javac Q01_Palindromo.java && java Q01_Palindromo < "entrada e saida/tp01/TP01Q01 - Palindromo/pub.in"
javac Q01_Palindromo.java; Get-Content "entrada e saida\TP01Q01 - Palíndromo em Java\pub.in" | java Q01_Palindromo > results.txt 

# Exemplo para Q03 - Cifra César  
javac Q03_CifraCesar.java && java Q03_CifraCesar < "entrada e saida/tp01/TP01Q03 - Cifra Cesar/pub.in"

# Exemplo para Q10 - Palíndromo Recursivo
javac Q10_PalindromoRec.java && java Q10_PalindromoRec < "entrada e saida/tp01/TP01Q10 - Palindromo Rec/pub.in"
```

### Compilação e Execução C
```bash
# Exemplo para Q02 - Palíndromo
gcc Q02_palindromo.c -o Q02_palindromo && ./Q02_palindromo < "entrada e saida/tp01/TP01Q02 - Palindromo/pub.in"

# Exemplo para Q09 - Arquivo
gcc Q09_Arquivo.c -o Q09_Arquivo && ./Q09_Arquivo < "entrada e saida/tp01/TP01Q09 - Arquivo/pub.in"
```

### 📁 Como Encontrar o Caminho Correto
Para cada questão, o arquivo de entrada estará localizado em:
```
"entrada e saida/tp01/[NOME_DA_QUESTAO]/pub.in"
```

Substitua `[NOME_DA_QUESTAO]` pelo nome específico da pasta da questão desejada. Exemplos:
- TP01Q01 - Palindromo
- TP01Q02 - Palindromo  
- TP01Q03 - Cifra Cesar
- TP01Q04 - Alteracao Aleatoria
- E assim por diante...

### Formato de Entrada
A maioria das questões segue o padrão:
```
string1
string2
string3
FIM
```

## 📊 Casos de Teste

### Exemplos de Entrada e Saída

#### Palíndromo (Q01/Q10)
```
Entrada:
arara
casa
FIM

Saída:
SIM
NAO
```

#### Cifra de César (Q03/Q12)
```
Entrada:
abc
xyz
FIM

Saída:
def
abc
```

#### Álgebra Booleana (Q05/Q14)
```
Entrada:
2 A B and(A,B)
1 C or(C,C)
FIM

Saída:
1 1 1
1 1
```

## 🎓 Conceitos Abordados

### Fundamentais
- **Algoritmos Básicos**: Implementação de soluções clássicas
- **Complexidade**: Análise temporal e espacial
- **Estruturas de Controle**: Loops, condicionais, recursão

### Técnicas de Programação
- **Iteração**: Uso eficiente de loops
- **Recursão**: Divisão de problemas, casos base
- **Manipulação de Strings**: Processamento de texto

### Linguagens
- **Java**: Orientação a objetos, gerenciamento automático de memória
- **C**: Programação procedural, controle manual de memória
- **Comparação**: Diferenças sintáticas e semânticas

## 🏆 Validação e Testes

- **Casos de Teste**: Validação contra entradas e saídas esperadas
- **Correção**: Verificação de algoritmos com casos limite
- **Performance**: Comparação entre versões iterativas e recursivas
- **Compatibilidade**: Funcionamento em ambiente Verde (Linux)

---

**Disciplina**: Algoritmos e Estruturas de Dados II  
**Trabalho**: TP01 - Fundamentos de Programação e Recursão  
**Matrícula**: 816676  
**Total de Questões**: 15 implementações (9 Java + 6 C)