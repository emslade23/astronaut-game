#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include "Game_Object.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"
#include "Astronaut.h"
#include "View.h"
using namespace std;

class Model
{
private:
    int time;
    int count_down;
    Game_Object* object_ptrs[10];
    int num_objects;
    Person* person_ptrs[10];
    int num_persons;
    Oxygen_Depot* depot_ptrs[10];
    int num_depots;
    Space_Station* station_ptrs[10];
    int num_stations;
	//Astronaut* pnt_ast1;
	//Astronaut* pnt_ast2;
	//Oxygen_Depot* pnt_od1;
	//Oxygen_Depot* pnt_od2;
	//Space_Station* pnt_ss1;
    //Space_Station* pnt_ss2;
    Model(const Model&);

public:
    Model();
    ~Model();
    Person* get_Person_ptr(int id);
    Oxygen_Depot* get_Oxygen_Depot_ptr(int id);
    Space_Station* get_Space_Station_ptr(int id);
    bool update();
    void display(View &view);
    void show_status();
    
};
#endif