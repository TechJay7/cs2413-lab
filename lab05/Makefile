CC = gcc
CFLAGS = -std=c11 -Wall -Wextra  -O2

all: q1 q2

q1: question1/student.c question1/tests.c
	$(CC) $(CFLAGS) -o question1/q1_test question1/student.c question1/tests.c

q2: question2/student.c question2/tests.c
	$(CC) $(CFLAGS) -o question2/q2_test question2/student.c question2/tests.c

# New commands (what you want)
run1: q1
	./question1/q1_test

run2: q2
	./question2/q2_test

# Keep full test option
test: q1 q2
	./question1/q1_test
	./question2/q2_test

clean:
	rm -f question1/q1_test question2/q2_test