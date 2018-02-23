#include <iostream>
#include "Game_Command.h"
using namespace std;

void command_handling(Model& model, View& view, char input)
{
	int id1;
	int id2;
	double x;
	double y;

    switch(input) //switch statement 
    {
		case 'm':
			cin >> id1;
			cin >> x;
			cin >> y;
			do_move_command(model, view, id1, x, y);
			break;
        case 'w':
			cin >> id1;
			cin >> id2;
			do_depot_command(model, view, id1, id2);
			break;
        case 'd':
			cin >> id1;
			cin >> id2;
			do_deposit_moonstones_command(model, view, id1, id2);
			break;
        case 's':
			cin >> id1;
			do_stop_command(model, view, id1);
			break;
        case 'l':
			cin >> id1;
			cin >> id2;
			do_lock_in_at_station_command(model, view, id1, id2);
			break;
        case 'g':
			do_go_command(model, view);
			break;
        case 'r':
			do_run_command(model, view);
			break;
        case 'q':
			do_quit_command(model);
			break;
		default:
			cout << "ERROR: Please enter a valid commnd!" << endl;
	
    }
}


void do_move_command(Model& model, View& view, int id1, double x, double y) //declares astronaut pointer and calls start moving function
{
	Person * astronaut_pointer1 = model.get_Person_ptr(id1);
	astronaut_pointer1->start_moving(Cart_Point(x, y));
	model.display(view);
}
void do_depot_command(Model& model, View& view, int id1, int id2) //declares astronaut pointer and calls start supplying function
{
	Person * astronaut_pointer1 = model.get_Person_ptr(id1);
	Oxygen_Depot* oxygen_depot_pointer = model.get_Oxygen_Depot_ptr(id2);

	astronaut_pointer1->start_supplying(oxygen_depot_pointer);
	model.display(view);
}
void do_deposit_moonstones_command(Model& model, View& view, int id1, int id2) // declares astronaut pointer and calls start depositing function
{
	Person * astronaut_pointer1 = model.get_Person_ptr(id1);
	Space_Station* space_station_pointer1 = model.get_Space_Station_ptr(id2);
	astronaut_pointer1->start_depositing(space_station_pointer1);
	model.display(view);
	
}
void  do_stop_command(Model& model, View& view, int id1) //stops astronaut
{
	Person * astronaut_pointer1 = model.get_Person_ptr(id1);
	astronaut_pointer1->stop();
	model.display(view);
}
void do_lock_in_at_station_command(Model& model, View& view, int id1, int id2) //locks astronaut into station
{
	Person * astronaut_pointer1 = model.get_Person_ptr(id1);
	Space_Station* space_station_pointer1 = model.get_Space_Station_ptr(id2);
	astronaut_pointer1->go_to_station(space_station_pointer1);
	model.display(view);
}
void do_go_command(Model& model, View& view) //updates objects once
{
	cout << "Advancing one tick." << endl;
	model.update();
	model.show_status();
	model.display(view);
}
void do_run_command(Model& model, View& view) //updates objects up to 5 times
{
	cout << "Advancing to next event." << endl;
	int time = 0;
	while ((!model.update()) && (time < 4))
	{
		time = time + 1;
	}
	model.show_status();
	model.display(view);
}
void do_quit_command(Model& model) //quits program
{
	cout << "Terminating program. " << endl;

}
