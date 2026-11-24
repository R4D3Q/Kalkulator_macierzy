CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Wykrywanie systemu operacyjnego
ifeq ($(OS),Windows_NT)
	TARGET = Kalkulator_macierzy.exe
	RM = del /Q /F
	# Zamiana ukośników na wypadek podfolderów w przyszłości
	CLEAN_FILES = $(subst /,\,$(OBJS)) $(TARGET)
else
	TARGET = Kalkulator_macierzy
	RM = rm -f
	CLEAN_FILES = $(OBJS) $(TARGET)
endif

SRCS = main.c common.c matrix.c matrix_io.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c common.h matrix.h matrix_io.h
common.o: common.c common.h
matrix.o: matrix.c matrix.h common.h
matrix_io.o: matrix_io.c matrix_io.h matrix.h common.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(CLEAN_FILES)