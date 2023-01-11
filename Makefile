#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o, student.o, and stu_sort.o to executable main
main: main.o student.o domestic.o international.o toeflscore.o InternationalList.o StudentList.o DomesticList.o
	g++ -g -o main main.o student.o  domestic.o international.o toeflscore.o InternationalList.o StudentList.o DomesticList.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp

#compile the student.cpp to student.o
student.o: student.cpp
	g++ -g -c student.cpp


#compile the Domestic.cpp to Domestic.o
domestic.o: domestic.cpp
	g++ -g -c domestic.cpp

#compile the international.cpp to international.o
international.o: international.cpp
	g++ -g -c international.cpp

#compile the international.cpp to international.o
toeflscore.o: toeflscore.cpp
	g++ -g -c toeflscore.cpp

InternationalList.o: InternationalList.cpp
	g++ -g -c InternationalList.cpp

StudentList.o: StudentList.cpp
	g++ -g -c StudentList.cpp

DomesticList.o: DomesticList.cpp
	g++ -g -c DomesticList.cpp

#remove built files
clean:
	rm -rf main main.o student.o  international.o domestic.o toeflscore.o InternationalList.o StudentList.o DomesticList.o *~
