PROGNAME=scramble
FILENAME=$(PROGNAME).cpp
EXE=$(PROGNAME).out
STANDARD=-std=c++11

$(FILENAME):
	g++ $(FILENAME) 

clean: 
	rm *.out

run: $(FILENAME)
	@g++ $(FILENAME) $(STANDARD)  -o $(EXE)
	@./$(EXE)

crun: $(FILENAME)
	@clear
	@g++ $(FILENAME) -o $(EXE)
	@./$(EXE)


git-master:
	git add *
	git commit -m "Makefile quick commit"
	git push origin master

