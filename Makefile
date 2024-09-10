# This file is responsible for building the program
# Modify the "FILE_TST" to reference the filename
# that you want to test.
#
# To build the code
#


# Uncomment the file you want to test
#FILE_TST=./src/test_var000.c # modify
#FILE_TST=./src/test_var001.c # better quick sort
#FILE_TST=./src/test_var100.c # basic quicksort
#FILE_TST=./src/test_var101.c # hoare partition quicksort
FILE_TST=./src/test_var102.c # no copy
#FILE_TST=./src/test_var004.c
# ...
#FILE_TST=test_var999.c


FILE_REF=./src/baseline.c # Once you have a correct and faster variant you might want to replace this.

#####

CFLAGS=-std=c99 -O2 # Feel free to modify the optimization flags, but the impact will be marginal at best.
CFLAGS_DEBUG=-std=c99 -g -O0 # If you modify this you really shouldn't muck with the optimization flags.
#####
NAME_REF=compute_ref # leave this alone
NAME_TST=compute_tst # also leave this alone


all: clean build-verifier build-timer run

build-verifier:
	gcc $(CFLAGS_DEBUG) -DCOMPUTE_NAME_REF=$(NAME_REF)  -DCOMPUTE_NAME_TST=$(NAME_TST) -c ./src/verifier.c -o verifier.o
	gcc $(CFLAGS_DEBUG) -DCOMPUTE_NAME=$(NAME_REF) -c $(FILE_REF) -o FILE_REF.o
	gcc $(CFLAGS_DEBUG) -DCOMPUTE_NAME=$(NAME_TST) -c $(FILE_TST) -o FILE_TST.o
	gcc $(CFLAGS_DEBUG) -lm FILE_REF.o FILE_TST.o verifier.o -o ./run_verifier.x


build-timer:
	gcc $(CFLAGS)  -DCOMPUTE_NAME_TST=$(NAME_TST) -c ./src/timer.c -o timer.o
	gcc $(CFLAGS) -DCOMPUTE_NAME=$(NAME_TST) -c $(FILE_TST) -o FILE_TST.o
	gcc -lm  FILE_TST.o timer.o -o ./run_timer.x

dump-asm:
	gcc $(CFLAGS) -DCOMPUTE_NAME=$(NAME_TST) -S $(FILE_TST)

run:
	./run_timer.x
	./run_verifier.x

clean:
	rm -f *.o *.x *~ *.s
