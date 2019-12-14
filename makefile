CC=gcc
CFLAGS = -c -std=c99
MCMODEL = -mcmodel=large

#CREATE BIN AND BUILD FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME
 $(shell mkdir bin)
 $(shell mkdir build)

#TARGET TO COMPILE ALL THE TESTS TOGETHER (NOT SIMULATOR)

#TARGET TO COMPILE EVERYTHING 
all: tests


tests: main.o login.o list.o console.o user_name.o validate.o modify.o delete.o apply_leave.o  approve_leave.o pay.o info.o new_pass.o menu_admin.o menu_employee.o month_convert.o add.o time1.o
	$(CC) -g -o bin/MAIN build/main.o  build/login.o build/list.o build/console.o build/user_name.o build/validate.o build/modify.o build/delete.o build/apply_leave.o build/approve_leave.o build/pay.o build/info.o build/new_pass.o build/menu_admin.o build/menu_employee.o build/month_convert.o build/add.o build/time1.o

	
main.o: src/main.c
	$(CC) -g -c $(MCMODEL)  src/main.c -o build/main.o
	
login.o: src/login.c
	$(CC) -g -c $(MCMODEL) src/login.c -o build/login.o

add.o: src/add.c
	$(CC) -g -c $(MCMODEL)  src/add.c -o build/add.o
	
list.o: src/list.c
	$(CC) -g -c $(MCMODEL) src/list.c -o build/list.o


time1.o: src/time1.c
	$(CC) -g -c $(MCMODEL) src/time1.c -o build/time1.o

console.o: src/console.c
	$(CC) -g -c $(MCMODEL) src/console.c -o build/console.o

user_name.o: src/user_name.c
	$(CC) -g -c $(MCMODEL) src/user_name.c -o build/user_name.o

validate.o: src/validate.c
	$(CC) -g -c $(MCMODEL) src/validate.c -o build/validate.o

modify.o: src/modify.c
	$(CC) -g -c $(MCMODEL) src/modify.c -o build/modify.o

delete.o: src/delete.c
	$(CC) -g -c $(MCMODEL) src/delete.c -o build/delete.o

apply_leave.o: src/apply_leave.c
	$(CC) -g -c $(MCMODEL) src/apply_leave.c -o build/apply_leave.o

approve_leave.o: src/approve_leave.c
	$(CC) -g -c $(MCMODEL) src/approve_leave.c -o build/approve_leave.o

pay.o: src/pay.c
	$(CC) -g -c $(MCMODEL) src/pay.c -o build/pay.o
info.o: src/info.c
	$(CC) -g -c $(MCMODEL) src/info.c -o build/info.o

new_pass.o: src/new_pass.c
	$(CC) -g -c $(MCMODEL) src/new_pass.c -o build/new_pass.o

menu_admin.o: src/menu_admin.c
	$(CC) -g -c $(MCMODEL) src/menu_admin.c -o build/menu_admin.o

menu_employee.o: src/menu_employee.c
	$(CC) -g -c $(MCMODEL) src/menu_employee.c -o build/menu_employee.o

month_convert.o: src/month_convert.c
	$(CC) -g -c $(MCMODEL) src/month_convert.c -o build/month_convert.o

#CLEAN COMMANDS
clean:
	rm -rf build *.o *~
	rm -rf bin *.o *~