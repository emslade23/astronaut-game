#include <iostream>
#include <math.h> 
#include "Game_Object.h"
#include "Person.h"
#include "Cart_Point.h"


using namespace std;



Person:: Person()
:Game_Object('P')//allowed??????
{
    speed = 5;
    cout<< "Person default constructed."<< endl;

}

Person:: Person(char in_code)
:Game_Object(in_code)
{
    speed = 5;
    cout<< "Person constructed."<< endl;
    state = 's';

}
Person:: Person(Cart_Point in_loc, int in_id, char in_code)
:Game_Object(in_loc,in_id, in_code)
{
    speed = 5;
    cout<< "Person constructed."<< endl;
  
}

void Person:: start_moving(Cart_Point dest)
{
    if (state != 'l')
    {
        if ((location.x == dest.x) && (location.y == dest.y))
        {
            cout<< display_code<< id_num<< ": I'm already there. see?"<< endl;
        }
        else
        {
             //tells person to start moving
         setup_destination(dest);
         state = 'm';
         cout<< "Moving "<< id_num<< " to "<< dest<< endl;
         cout<< display_code<< id_num<< ": On my way."<< endl;
        }
    }
    else
    {
        cout<< "I'm locked in! I can't move."<< endl;
    }
}

void Person:: stop()
{
    //tells the astronaut to stop moving or collecting oxygen
    state = 's'; //stopped
    cout<< display_code<< id_num<< ": Stopped. "<< endl;

}

void Person:: show_status()
{                                                               //formatting?
    Game_Object::show_status();
    if (state == 'm') 
    {
        cout<< " moving at speed of "<<speed<< " towards "<< destination<< " at each step of "<< delta<<endl;
    }
    else if ((state == 'o') || (state == 'i') || (state == 'd') || (state == 'g')) 
    {
        cout<< " moving at speed of "<<speed<< " towards "<< destination<< " at each step of "<< delta;
    }
    else if (state == 's')
    {
        cout<< " is stopped ";
    }
    else if (state =='l')
    {
        cout<< " is locked ";
    }
}

bool Person::update_location()
{
    //updates the object's location while it is moving 
    Cart_Point location1 = Game_Object:: get_location();
    //if astronaut arrives,
    if ((fabs(destination.x - location1.x) <= fabs(delta.x)) && (fabs(destination.y - location1.y) <= fabs(delta.y)))
    {
        location = destination;
        cout<< display_code<< id_num<< ": I'm there!"<< endl;

        return true;
    }
    else
    {
        location = location + delta;
        cout<< display_code<< id_num<< ": step ..."<< endl;
        return false;
    }
}
void Person:: setup_destination(Cart_Point newdestination)
{
    //sets up the object to start moving to destination
    if ((newdestination.x == location.x) && (newdestination.y == location.y))
    {
        delta = Cart_Vector(0,0);

    }
    else
    {
        destination = newdestination;
        delta = (destination - location) * (speed/cart_distance(destination, location));//what does each variable mean?
    
    }
}
Person:: ~Person()
{
    cout<< "Person destructed."<< endl;
}
void Person::start_supplying(Oxygen_Depot* inputDepot)
{
    cout<< "Sorry, I can't work at a depot. "<< endl;
}
void Person::start_depositing(Space_Station* inputStation)
{
    cout<< "Sorry, I can't work a station. "<< endl;
}
void Person::go_to_station(Space_Station* inputStation)
{
    cout<< "Sorry, I can't lock into a station."<< endl;
}

