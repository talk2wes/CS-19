## Wesley Johanson	Pengo:wjohanso	Talk2wes@gmail.com
## Filename: Makefile
## Assignment 6: Splicer

#Name of executable file that is psplicer
EXECTUTABLE=p6
#Compiler Standard
STANDARD=-std=c++11 
#MAIN is name of .cpp file that has main function in it
MAIN=main
#Additional *.cpp files that are linked to main 
FILE1=splicer

$(EXECTUTABLE): $(MAIN).o  $(FILE1).o
	g++ $(STANDARD) $(MAIN).o $(FILE1).o -o $(EXECTUTABLE)

$(MAIN).o:
	g++ $(STANDARD) -c $(MAIN).cpp

$(FILE1).o:
	g++ $(STANDARD) -c $(FILE1).cpp

clean:
	rm *.o $(EXECTUTABLE)

# MY CUSTOM MAKEFILE COMMANDS

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
