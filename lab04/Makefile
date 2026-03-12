CC = gcc
CFLAGS = -std=c11 -Wall -Wextra  -O2

Q1_DIR = Question1
Q2_DIR = Question2
Q3_DIR = Question3

Q1_TARGET = q1
Q2_TARGET = q2
Q3_TARGET = q3

all: $(Q1_TARGET) $(Q2_TARGET) $(Q3_TARGET)

$(Q1_TARGET): $(Q1_DIR)/student.c $(Q1_DIR)/tests.c
	$(CC) $(CFLAGS) -o $(Q1_TARGET) $(Q1_DIR)/student.c $(Q1_DIR)/tests.c

$(Q2_TARGET): $(Q2_DIR)/student.c $(Q2_DIR)/tests.c
	$(CC) $(CFLAGS) -o $(Q2_TARGET) $(Q2_DIR)/student.c $(Q2_DIR)/tests.c

$(Q3_TARGET): $(Q3_DIR)/student.c $(Q3_DIR)/tests.c
	$(CC) $(CFLAGS) -o $(Q3_TARGET) $(Q3_DIR)/student.c $(Q3_DIR)/tests.c

run1: $(Q1_TARGET)
	./$(Q1_TARGET)

run2: $(Q2_TARGET)
	./$(Q2_TARGET)

run3: $(Q3_TARGET)
	./$(Q3_TARGET)

run: run1 run2 run3

clean:
	rm -f $(Q1_TARGET) $(Q2_TARGET) $(Q3_TARGET)

.PHONY: all run run1 run2 run3 clean