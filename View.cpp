#include <iostream>
#include "View.h"
using namespace std;



View::View()
{
    size = 11;
    scale = 2;
    origin = Cart_Point(0,0);
    

}
bool View:: get_subscripts(int &ix, int &iy, Cart_Point location)
{  
    int possiblex = (location.x - origin.x) / scale;
    int possibley = (location.y - origin.y) / scale;
    if ((possiblex<12) && (possiblex>=0) && (possibley<12) && (possibley>=0)) //checks range of coordinates
    {
        ix = possiblex;
        iy = possibley;
        return true;
    }
    else
    {
        cout << "An object is outside the display" << endl;
        return false;
    }


}
void View:: clear() //clears objects
{
    //sets all of the cells in the grid to the background pattern in example
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j< 11; j++)
        {
            grid[i][j][0] = '.';
            grid[i][j][1] = ' ';
            
        }
    }
}

void View:: plot(Game_Object* ptr) //plots objects
{
    int x = 0;
    int y = 0;
    char * ptr2;

    Cart_Point location = ptr->get_location();

    if (get_subscripts(x, y, location))
    {
        char charArray[10];
        ptr->drawself(charArray);
        
        
        if((grid[x][y][0] == 'S') || (grid[x][y][0] == 'A') || (grid[x][y][0] == 'O') || (grid[x][y][0] == 'o') || (grid[x][y][0] == 's')|| (grid[x][y][0] == '*')) 
        {
            grid[x][y][0] = '*';
            grid[x][y][1] = ' ';
        }
        else
        {
            grid[x][y][0] = charArray[0];
            grid[x][y][1] = charArray[1];
        }
        
        
    
           
        


    }
    //if there is already an object in that location of the grid, the characters are replaced with * and ''
}

void View:: draw() //draws out gameboard
{
    int g = 0;
    int q = 20;
    for (int i = 10; i > -1; i--)
    {
        if (i%2 == 0 && q>8)
        {
            cout<< q;
            g = 4;
            q = q - g;
        }
        else if ((i%2 == 0 && q<=8))
        {
            cout<< q<< " ";
            g = 4;
            q = q - g;
        }
        else
        {
            cout<< "  ";
        }

        for (int j = 0; j < 11; j++)
        {
            if (grid[j][i][0] == '*')
            {
                cout << grid[j][i][0];
                cout<< grid[j][i][1];

            }
            else if (grid[j][i][0] != '.')
            {
                cout<< grid[j][i][0];
                cout<< +grid[j][i][1];
            }
            else
            {
                cout<< grid[j][i][0];
                cout<< grid[j][i][1];
            }
            
                
        }
        cout<< endl;
    }
    cout << "  0   4   8   12  16  20 "<< endl;
}
