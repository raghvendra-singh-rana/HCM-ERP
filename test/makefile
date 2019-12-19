CC=gcc
CFLAGS = -c -std=c99
MCMODEL = -mcmodel=large

#CREATE BIN AND BUILD FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME
 $(shell mkdir -p bin)
 $(shell mkdir -p build)

#TARGET TO COMPILE ALL THE TESTS TOGETHER
all:HCM
	
HCM:	main.o	test_run_console.o	test_run_login.o	test_run_new_pass.o	test_run_validate.o	validate.o	test_run_delete.o
	$(CC) -g -o bin/MAIN build/main.o  build/test_run_login.o  build/test_run_new_pass.o  build/test_run_validate.o build/validate.o build/test_run_delete.o

main.o: src/main.c
	$(CC) -g -c $(MCMODEL)  src/main.c -o build/main.o

test_run_console.o: src/console.c
	$(CC) -g -c $(MCMODEL) src/console.c -o build/console.o
	
test_run_login.o: src/test_run_login.c
	$(CC) -g -c $(MCMODEL) src/test_run_login.c -o build/test_run_login.o

test_run_new_pass.o: src/test_run_new_pass.c
	$(CC) -g -c $(MCMODEL) src/test_run_new_pass.c -o build/test_run_new_pass.o

test_run_validate.o: src/validate.c
	$(CC) -g -c $(MCMODEL) src/test_run_validate.c -o build/test_run_validate.o

validate.o: src/validate.c
	$(CC) -g -c $(MCMODEL) src/validate.c -o build/validate.o

test_run_delete.o: src/test_run_delete.c
	$(CC) -g -c $(MCMODEL) src/test_run_delete.c -o build/test_run_delete.o


#CLEAN COMMANDS
clean:	
	rm -r build
	rm -r bin
