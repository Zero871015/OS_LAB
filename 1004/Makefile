all: lab1 hard_lab1 Hello_Loop

lab1:
	gcc -static lab1.c -o lab1

hard_lab1:
	gcc lab1.c -o hard_lab1
	strip hard_lab1

Hello_Loop:
	gcc Hello_Loop.c -o Hello_Loop
	strip Hello_Loop

clean:
	rm lab1 hard_lab1 Hello_Loop
