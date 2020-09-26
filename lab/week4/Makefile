PROGNAME=bubbleSort
FILENAME=$(PROGNAME).cpp
EXE=$(PROGNAME).out
COMPILER=g++ -std=c++11

$(FILENAME):
	$(COMPILER) $(FILENAME) 

clean: 
	rm *.out

run: 
	$(COMPILER) $(FILENAME) -o $(EXE)
	./$(EXE)

crun: 
	clear
	$(COMPILER) $(FILENAME) -o $(EXE)
	./$(EXE)


git-master:
	git add *
	git commit -m "Makefile quick commit"
	git push origin master

