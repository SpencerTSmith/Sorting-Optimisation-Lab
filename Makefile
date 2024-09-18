# This file is responsible for building the program
# Modify the "FILE_TST" to reference the filename
# that you want to test.
#
# To build the code
#


# Uncomment the file you want to test
FILE_TST=./src/test_var000.c # modify
#FILE_TST=./src/test_var001.c # better quick sort

#FILE_TST=./src/test_var100.c # basic quicksort
#FILE_TST=./src/test_var101.c # hoare partition quicksort
#FILE_TST=./src/test_var102.c # change recursion check
#FILE_TST=./src/test_var103.c # threaded

#FILE_TST=./src/test_var200.c
#FILE_TST=./src/test_var201.c
#FILE_TST=./src/test_var202.c

#FILE_TST=./src/test_var300.c
#FILE_TST=./src/test_var301.c
#FILE_TST=./src/test_var302.c
#FILE_TST=./src/test_var303.c


#FILE_TST=./src/master_sort.c

# Uncomment where you want output to be
FILE_OUT=./data/test_out000.csv
#FILE_OUT=./data/test_out001.csv

#FILE_OUT=./data/test_out100.csv
#FILE_OUT=./data/test_out101.csv
#FILE_OUT=./data/test_out102.csv
#FILE_OUT=./data/test_out103.csv
#FILE_OUT=./data/test_out103-1.csv

#FILE_OUT=./data/test_out200.csv
#FILE_OUT=./data/test_out201.csv
#FILE_OUT=./data/test_out202.csv

#FILE_OUT=./data/test_out300.csv
#FILE_OUT=./data/test_out301.csv
#FILE_OUT=./data/test_out302.csv
#FILE_OUT=./data/test_out303.csv


#FILE_OUT=./data/master.csv

FILE_REF=./src/baseline.c # Once you have a correct and faster variant you might want to replace this.

#####

CFLAGS=-std=c99 -O2 # Feel free to modify the optimization flags, but the impact will be marginal at best.
CFLAGS_DEBUG=-std=c99 -g -O0 # If you modify this you really shouldn't muck with the optimization flags.
#####
NAME_REF=compute_ref # leave this alone
NAME_TST=compute_tst # also leave this alone


all: clean build-verifier build-timer run

build-verifier:
	gcc $(CFLAGS_DEBUG) -DCOMPUTE_NAME_REF=$(NAME_REF)  -DCOMPUTE_NAME_TST=$(NAME_TST) -c ./src/verifier.c -o verifier.o -lm -fopenmp
	gcc $(CFLAGS_DEBUG) -DCOMPUTE_NAME=$(NAME_REF) -c $(FILE_REF) -o FILE_REF.o -lm -fopenmp
	gcc $(CFLAGS_DEBUG) -DCOMPUTE_NAME=$(NAME_TST) -c $(FILE_TST) -o FILE_TST.o -lm -fopenmp
	gcc $(CFLAGS_DEBUG) FILE_REF.o FILE_TST.o verifier.o -o  ./run_verifier.x -lm -fopenmp


build-timer:
	gcc $(CFLAGS)  -DCOMPUTE_NAME_TST=$(NAME_TST) -c ./src/timer.c -o timer.o -lm -fopenmp
	gcc  FILE_TST.o timer.o -o ./run_timer.x -lm -fopenmp

dump-asm:
	gcc $(CFLAGS) -DCOMPUTE_NAME=$(NAME_TST) -S $(FILE_TST)

run:
	#./run_timer.x 16 50000 1024 1 $(FILE_OUT)
	./run_timer.x 16 1024 16 1 $(FILE_OUT)
	./run_verifier.x 16 256 16 1

clean:
	rm -f *.o *.x *~ *.s
