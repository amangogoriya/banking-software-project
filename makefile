output: main.o close.o open.o interest.o print.o
	g++ main.o close.o open.o interest.o print.o -o output
main.o: main.cpp
	g++ -c main.cpp
close.o:close.cpp connect.h
	g++ -c close.cpp
open.o: open.cpp connect.h
	g++ -c open.cpp
interest.o: interest.cpp connect.h
	g++ -c interest.cpp
print.o: print.cpp connect.h
	g++ -c print.cpp

clean:
	rm *.o output