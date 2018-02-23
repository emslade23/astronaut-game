#include <iostream>
#include "Cart_Point.h"//inherits from game_object
#include "Space_Station.h"
using namespace std;

Space_Station:: Space_Station()
:Game_Object('s')
{
    amount_moonstones = 0;
    number_astronauts = 0;
    state = 'o';
    cout<< "Space_Station constructed."<< endl;
}

Space_Station:: Space_Station(Cart_Point inputLoc, int inputId)
:Game_Object(inputLoc, inputId, 's')
{
    
    amount_moonstones = 0;
    number_astronauts = 0;
    state = 'o';
    cout<< "Space_Station constructed."<< endl;

}
void Space_Station:: deposit_moonstones(double deposit_amount)
{
    amount_moonstones = amount_moonstones + deposit_amount;

}
bool Space_Station:: add_astronaut()
{
    if (state == 'u')
    {
        number_astronauts++;
        return true;//note:only increment if status is upgraded
    }
    else
    {
        return false;
    }
}
int Space_Station:: get_astronauts()
{
    return number_astronauts;
}
bool Space_Station:: update()//only return true at the time the space station is upgraded, return false for later function calls
{
    if ((amount_moonstones >=10) && (state != 'u') && (display_code != 'S'))
    {
        state = 'u';
        display_code = 'S';
        cout<< display_code<< id_num<< " has been upgraded."<< endl;
        return true;
    }
    else
    {
        return false;
    }
}
void Space_Station:: show_status()
{   
    if ((state == 'u') && (display_code == 'S'))
    {
        cout << "Space Station status: ";
        Game_Object::show_status();
        cout << " contains "<< amount_moonstones<< " moon stones and contains "<< number_astronauts<< " astronauts. Upgraded. "<< endl;

    }
    else
    {
        cout << "Space Station status: ";
        Game_Object::show_status();
        cout << " contains "<< amount_moonstones<< " moon stones and contains "<< number_astronauts<< " astronauts. Not yet upgraded. "<< endl;
    }
}

Space_Station:: ~Space_Station()
{
    cout<< "Space_Station destructed."<< endl;
}