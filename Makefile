Compilador = gcc
FLAGS = -Wall -Werror
LIBS = -lm

TARGET = LOTSCH

SRC_DIR = src
INC_DIR = include

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(SRC_DIR)/%.o, $(SRCS))
FLAGS += -I$(INC_DIR)


$(TARGET): $(OBJS)
	$(Compilador) $(FLAGS) $(OBJS) -o $(TARGET) $(LIBS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(Compilador) $(FLAGS) -c $< -o $@ $(LIBS)

clean:
	rm -f $(OBJS) $(TARGET)$(EXECUTABLE_EXTENSION)