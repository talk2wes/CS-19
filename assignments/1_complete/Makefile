PROGNAME=words
FILENAME=$(PROGNAME).cpp
EXE=$(PROGNAME).out

$(FILENAME):
	g++ $(FILENAME) 

clean: 
	rm *.out

run: $(FILENAME)
	@g++ $(FILENAME) -o $(EXE)
	@./$(EXE)

crun: $(FILENAME)
	@clear
	@g++ $(FILENAME) -o $(EXE)
	@./$(EXE)


git-master:
	git add *
	git commit -m "Makefile quick commit"
	git push origin master

