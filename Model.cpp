#include <iostream>
#include <stdlib.h>
#include "Model.h"
using namespace std;

Model::Model()
{
    time = -1;
    count_down = 10;
    
  //creating objects on the heap
    person_ptrs[0] = new Astronaut(1,Cart_Point(5,1));
    person_ptrs[1] = new Astronaut(2,Cart_Point(10,1));
    depot_ptrs[0] = new Oxygen_Depot(Cart_Point(1,20),1);
    depot_ptrs[1] = new Oxygen_Depot(Cart_Point(10,20),2);
    station_ptrs[0]= new Space_Station();
    station_ptrs[1] = new Space_Station(Cart_Point(5,5), 2);

	object_ptrs[0] = person_ptrs[0];
	object_ptrs[1] = person_ptrs[1];

	object_ptrs[2] = depot_ptrs[0];
	object_ptrs[3] = depot_ptrs[1];
	
 	object_ptrs[4] = station_ptrs[0];
    object_ptrs[5] = station_ptrs[1];
     
    num_objects = 5;
    num_persons = 2;
    num_depots = 2;
    num_stations = 2;
    cout<< "Model default constructed."<< endl;



}

Model:: ~Model()
{
   for (int i = 0; i<=5; i++)
    {
        delete object_ptrs[i];
    }
    
    
    cout<< "Model destructed."<< endl;
}


Person* Model::get_Person_ptr(int id) //checking id of astronaut
{
    if ((id > 0) && (id<= num_persons))
    {
        int realid = id-1;
        return person_ptrs[realid];
    }
    else
    {
        return 0;
    }
    
}

Oxygen_Depot* Model::get_Oxygen_Depot_ptr(int id) //checking id of oxygen depot
{
    if ((id > 0) && (id<= num_depots))
    {
        int realid = id-1;
        return depot_ptrs[realid];
    }
    else
    {
        return 0;
    }
}
Space_Station* Model::get_Space_Station_ptr(int id) //checking id of space station
{
    if ((id > 0) && (id<= num_stations))
    {
        int realid = id-1;
        return station_ptrs[realid];
    }
    else
    {
        return 0;
    }
}

bool Model:: update()
{
	int count = 0;

    if ((object_ptrs[4]->get_state() == 'u') && (object_ptrs[5]->get_state() =='u'))//if both space stations are updated
    {

        cout << "Ready for takeoff? " << count_down << "..." << endl;
        count_down = count_down - 1;

	    int astronautsStation1 = station_ptrs[0]->get_astronauts();
		int astronautsStation2 = station_ptrs[1]->get_astronauts();

		int totalAstronauts = astronautsStation1 + astronautsStation2;


        if ((astronautsStation1>0)&&(astronautsStation2>0)&&(totalAstronauts == 2))//every astronaut at a station and each station has at least one astronaut
		{
			cout << "Blast off! You Win!" << endl;
            exit(0);
        }
		else if (((astronautsStation1>0) && (astronautsStation2==0)) || ((astronautsStation1==0) && (astronautsStation2 > 0)))
		{
			cout << "Missing 1 astronauts!" << endl;
			for (int j = 0; j<=num_objects; j++)//update every object
			{
				bool val2 = object_ptrs[j]->update();
				if (val2)
				{
					count = count + 1;
				}
			}
		}
        else if ((astronautsStation1==0) && (astronautsStation2 == 0))
        {
			cout << "Missing 2 astronauts!" << endl;
			for (int j = 0; j<=num_objects; j++)//update every object
			{
				bool val2 = object_ptrs[j]->update();
				if (val2)
				{
					count = count + 1;
				}
			}
        }


        if (count_down == 0)
        {
            exit(0);
        }
    }
	else // all cases when the space stations arent upgraded and the astronauts arent locked.
	{
		for (int i = 0; i <= num_objects; i++)
		{
			bool val = object_ptrs[i]->update();
			if (val)
			{
				count = count + 1;
			}
		}
	}


	time = time + 1;

    if (count > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Model::display(View &view) //displays gameboard
{
    
    //generates view display for all objects
    view.clear();
    for (int i = 0; i<=num_objects; i++)
    {
        view.plot(object_ptrs[i]);
    }
    
    view.draw();
    
}

void Model::show_status() //shows status of objects and time
{
    cout<< "Time: "<< time<< endl;
    for (int i = 0; i<=num_objects; i++)
    {
        object_ptrs[i]->show_status();
    }
}
