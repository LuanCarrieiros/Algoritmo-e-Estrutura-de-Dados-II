# Define o compilador
CC = gcc

# Flags de compilação
# -Wall: Habilita todos os warnings
# -Wextra: Habilita warnings extras
# -pedantic: Força conformidade com o padrão C
# -I$(INCLUDE_DIR): Adiciona o diretório de includes ao caminho de busca
CFLAGS = -Wall -Wextra -I$(INCLUDE_DIR)

# Define diretórios
SRC_DIR = ./src
INCLUDE_DIR = ./include

# Lista de todos os arquivos de objeto comuns (sem o main)
# Eles serão criados na pasta SRC_DIR (ex: src/common.o)
COMMON_OBJS = $(SRC_DIR)/common.o \
              $(SRC_DIR)/list.o \
              $(SRC_DIR)/personagem.o \
              $(SRC_DIR)/linked_list.o \
              $(SRC_DIR)/utils.o \
              $(SRC_DIR)/sorting_algos.o \
              $(SRC_DIR)/search_algos.o

# Lista de todos os executáveis das questões
# Eles serão criados na pasta C/ (onde o Makefile está)
EXECUTABLES = Q04_BinarySearch.exe \
              Q06_SelectionRec.exe \
              Q08_Shellsort.exe \
              Q10_Quicksort.exe \
              Q12_Bubble.exe \
              Q17_HeapPartial.exe

# Regra genérica para compilar arquivos .c de src/ em .o em src/
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Regras para compilar cada arquivo principal de questão em um executável
# Os executáveis serão criados na pasta C/ (onde o Makefile está)
Q04_BinarySearch.exe: Q04_BinarySearch.c $(COMMON_OBJS)
	@echo "Linkando $@..."
	$(CC) $(CFLAGS) $< $(COMMON_OBJS) -o $@

Q06_SelectionRec.exe: Q06_SelectionRec.c $(COMMON_OBJS)
	@echo "Linkando $@..."
	$(CC) $(CFLAGS) $< $(COMMON_OBJS) -o $@

Q08_Shellsort.exe: Q08_Shellsort.c $(COMMON_OBJS)
	@echo "Linkando $@..."
	$(CC) $(CFLAGS) $< $(COMMON_OBJS) -o $@

Q10_Quicksort.exe: Q10_Quicksort.c $(COMMON_OBJS)
	@echo "Linkando $@..."
	$(CC) $(CFLAGS) $< $(COMMON_OBJS) -o $@

Q12_Bubble.exe: Q12_Bubble.c $(COMMON_OBJS)
	@echo "Linkando $@..."
	$(CC) $(CFLAGS) $< $(COMMON_OBJS) -o $@

Q17_HeapPartial.exe: Q17_HeapPartial.c $(COMMON_OBJS)
	@echo "Linkando $@..."
	$(CC) $(CFLAGS) $< $(COMMON_OBJS) -o $@

# Alvo 'all' para compilar todos os executáveis
all: $(EXECUTABLES)
	@echo "Compilação de todos os executáveis C concluída!"

# Alvo 'clean' para remover arquivos de objeto e executáveis
clean:
	@echo "Limpando arquivos compilados..."
	@powershell.exe -Command "Remove-Item -Path '.\src\*.o' -ErrorAction SilentlyContinue -Force"
	@powershell.exe -Command "Remove-Item -Path '.\*.exe' -ErrorAction SilentlyContinue -Force"
	@echo "Limpeza concluída."

.PHONY: all clean