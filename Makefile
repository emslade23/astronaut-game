CC=g++

OBJS=main.o Cart_Point.o Cart_Vector.o Game_Object.o Game_Command.o Oxygen_Depot.o Astronaut.o Model.o Person.o Space_Station.o View.o

default: PA3

PA3: $(OBJS)
	$(CC) -o PA3 $(OBJS) 

Cart_Vector.o: Cart_Vector.cpp Cart_Vector.h
	$(CC) -c Cart_Vector.cpp -o Cart_Vector.o 
	
Cart_Point.o: Cart_Point.cpp Cart_Point.h Cart_Vector.h
	$(CC) -c Cart_Point.cpp -o Cart_Point.o 

Game_Object.o: Game_Object.cpp Game_Object.h Cart_Point.h Cart_Vector.h
	$(CC) -c Game_Object.cpp -o Game_Object.o 

Oxygen_Depot.o: Oxygen_Depot.cpp Oxygen_Depot.h Game_Object.h Cart_Point.h
	$(CC) -c Oxygen_Depot.cpp -o Oxygen_Depot.o 

Astronaut.o: Astronaut.cpp Astronaut.h Person.h Game_Object.h Oxygen_Depot.h Space_Station.h Cart_Point.h Cart_Vector.h
	$(CC) -c Astronaut.cpp -o Astronaut.o 

Model.o: Model.cpp Model.h Game_Object.h Person.h Space_Station.h Oxygen_Depot.h Astronaut.h View.h
	$(CC) -c Model.cpp -o Model.o 