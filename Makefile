# Define flags padrão e flags para OpenMP
CFLAGS = -g -Wall
CFLAGS_OPENMP = -fopenmp -O3

# Define diretórios e arquivos
CC         = gcc
OBJ_DIR    = ./obj
SRC_DIR    = ./src
INCL_DIR   = ./include
OBJECTS    = $(addprefix $(OBJ_DIR)/, read_csv.o write_csv.o forward_propagation.o back_propagation.o mlp_trainer.o mlp_classifier.o)
INCLUDES   = $(addprefix $(INCL_DIR)/, read_csv.h write_csv.h forward_propagation.h back_propagation.h mlp_trainer.h mlp_classifier.h parameters.h)
EXECUTABLE = MLP

# Regra padrão (compilação normal)
$(EXECUTABLE): $(SRC_DIR)/main.c $(OBJECTS)
	$(CC) $(CFLAGS) $< $(OBJECTS) -o $(EXECUTABLE) -I $(INCL_DIR) -lm

# Regra de compilação com OpenMP e otimização
openmp: $(SRC_DIR)/main.c $(OBJECTS)
	$(CC) $(CFLAGS) $(CFLAGS_OPENMP) $< $(OBJECTS) -o $(EXECUTABLE) -I $(INCL_DIR) -lm

# Compilar arquivos .c em .o (normal)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -I $(INCL_DIR) -c $< -o $@

# Limpeza de arquivos gerados
clean:
	rm -f $(OBJECTS)
	rm -rf $(EXECUTABLE)*
