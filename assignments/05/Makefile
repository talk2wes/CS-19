## Wesley Johanson	Pengo:wjohanso	Talk2wes@gmail.com
## Filename: Makefile
## Assignment 5: Cinco  

EXECTUTABLE=Cinco
STANDARD=-std=c++11
#FILE1=IntSet
MAIN=Cinco
#MAIN is the *.cpp file has the main function in it

$(EXECTUTABLE): $(MAIN).o 
	g++ $(STANDARD) $(MAIN).o -o $(EXECTUTABLE)

$(MAIN).o:
	g++ $(STANDARD) -c $(MAIN).cpp

#$(FILE1).o:
#	g++ $(STANDARD) -c $(FILE1).cpp

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
