all: libclassrec.so libclassloops.so libclassrec.a libclassloops.a  mains maindloop maindrec

loops: libclassloops.a
recursives: libclassrec.a  
recursived: libclassrec.so
loopd: libclassloops.so 

mains:  main.o libclassrec.a 
	gcc -Wall -o mains main.o libclassrec.a -lm

maindloop: main.o libclassloops.so 
	gcc -Wall -o maindloop main.o ./libclassloops.so -lm	

maindrec: main.o libclassrec.so 
	gcc -Wall -o maindrec main.o ./libclassrec.so -lm

libclassloops.so: basicClassification.o advancedClassificationLoop.o 
	gcc -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o     

libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	gcc -shared -o libclassrec.so  basicClassification.o advancedClassificationRecursion.o   

libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	ar -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o	

libclassloops.a: basicClassification.o advancedClassificationLoop.o
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o

main.o: main.c NumClass.h
	gcc -Wall -c main.c

basicClassification.o: basicClassification.c NumClass.h
	gcc -Wall -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	gcc -Wall -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	gcc -Wall -c advancedClassificationRecursion.c

.PHONY: clean all
	
clean:
	rm -f *.o *.a *.so mains maindloop maindrec