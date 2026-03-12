CC = gcc
CFLAGS = -std=c11 -Wall -Wextra --no-warnings  -O2

Q1_BIN = Question1/tests
Q2_BIN = Question2/tests

all: q1 q2

q1: Question1/tests.c Question1/student.c
	$(CC) $(CFLAGS) Question1/tests.c Question1/student.c -o $(Q1_BIN)

q2: Question2/tests.c Question2/student.c
	$(CC) $(CFLAGS) Question2/tests.c Question2/student.c -o $(Q2_BIN)

run1: q1
	./$(Q1_BIN)

run2: q2
	./$(Q2_BIN)

run: run1 run2

clean:
	rm -f $(Q1_BIN) $(Q2_BIN)
