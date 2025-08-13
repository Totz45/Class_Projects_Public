myprog.exe : main.o threeintsfcts.o
    g++ main.o threeintsfcts.o -o myprog.exe

main.o : main.cpp threeintsfcts.h
    g++ -Wall -c main.cpp 

threeintsfcts.o : threeintsfcts.cpp threeintsfcts.h
    g++ -Wall -c threeintsfcts.cpp 

clean :
    rm *.o myprog.exe