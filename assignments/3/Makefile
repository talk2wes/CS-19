EXECTUTABLE=p3
STANDARD=-std=c++11
FILE1=IntSet

$(EXECTUTABLE): main.o $(FILE1).o
	g++ main.o $(FILE1).o -o $(EXECTUTABLE)

main.o:
	g++ -c main.cpp

$(FILE1).o:
	g++ -c $(FILE1).cpp

clean:
	rm *.o $(EXECTUTABLE)