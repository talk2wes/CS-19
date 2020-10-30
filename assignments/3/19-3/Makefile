## Wesley Johanson	Pengo:wjohanso	Talk2wes@gmail.com
## Filename: Makefile
## Assignment 3: Integer Set Class

EXECTUTABLE=p3
STANDARD=-std=c++11
FILE1=IntSet

$(EXECTUTABLE): main.o $(FILE1).o
	g++ $(STANDARD) main.o $(FILE1).o -o $(EXECTUTABLE)

main.o:
	g++ $(STANDARD) -c main.cpp

$(FILE1).o:
	g++ $(STANDARD) -c $(FILE1).cpp

clean:
	rm *.o $(EXECTUTABLE)

clear:
	clear

clean-SWP:
	rm *.*.swp

git-qs:
	git add *
	git commit -m "quicksave"
	git push origin master

run:
	./$(EXECTUTABLE)

rerun: clean $(EXECTUTABLE) run 

crerun: clear rerun
