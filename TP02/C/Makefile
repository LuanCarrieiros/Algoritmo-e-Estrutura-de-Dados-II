# Define o compilador
CC = gcc

# ... (restante das suas flags e definições de diretórios) ...

# Alvo para criar o diretório bin
$(BIN_DIR):
	@echo "Criando diretório $(BIN_DIR)/..."
	mkdir -p $(BIN_DIR) # Comando para criar diretório, funciona em ambientes Unix-like e PowerShell/CMD modernos

# Regra genérica para compilar arquivos .c de src/ em .o em bin/
# Certifique-se de que cada regra de compilação de .o dependa de $(BIN_DIR)
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c | $(BIN_DIR) # Adiciona a dependência da pasta bin
	@echo "Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# ... (o restante do seu Makefile) ...

# E também adicione a dependência para os executáveis:
$(BIN_DIR)/Q04_BinarySearch: Q04_BinarySearch.c $(COMMON_OBJS) | $(BIN_DIR) # Adiciona a dependência da pasta bin
	@echo "Linkando $@..."
	$(CC) $(CFLAGS) $< $(COMMON_OBJS) -o $@

# Repita o '| $(BIN_DIR)' para todas as regras de executáveis
# Ex:
$(BIN_DIR)/Q06_SelectionRec: Q06_SelectionRec.c $(COMMON_OBJS) | $(BIN_DIR)
	@echo "Linkando $@..."
	$(CC) $(CFLAGS) $< $(COMMON_OBJS) -o $@

# ... e assim por diante para todos os EXECUTABLES