## Wesley Johanson	Pengo:wjohanso	Talk2wes@gmail.com
## Filename: Makefile
## Assignment 7: Six degrees of bacon 

#Name of executable file that is psplicer
EXECTUTABLE=p7
STANDARD=-std=c++11 
#Name of the file with main in it [MAIN].cpp
MAIN=main
#Additional [FILE1].cpp file, linked to [MAIN].cpp
##FILE1=splicer

#Compile all object files into executable
$(EXECTUTABLE): $(MAIN).o  #$(FILE1).o
	g++ $(STANDARD) $(MAIN).o -o $(EXECTUTABLE)
	#g++ $(STANDARD) $(MAIN).o $(FILE1).o -o $(EXECTUTABLE)

#Object files
$(MAIN).o:
	g++ $(STANDARD) -c $(MAIN).cpp

#$(FILE1).o:
#	g++ $(STANDARD) -c $(FILE1).cpp

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
