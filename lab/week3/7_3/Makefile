PROGNAME=counter
FILENAME=$(PROGNAME).cpp
EXE=$(PROGNAME).out

$(FILENAME):
	g++ $(FILENAME) 

clean: 
	rm $(EXE)

run: $(FILENAME) 
	g++ $(FILENAME) -o $(EXE)

#This is a clear run
crun: $(FILENAME)
	@clear
	@g++ $(FILENAME) -o $(EXE)
	./$(EXE)

#Quick git commit and save 
git-master:
	git add *
	git commit -m "Makefile quick commit"
	git push origin master

