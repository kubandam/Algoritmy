#include <iostream>
#include <fstream>
#include "maze.h"
using namespace std;


void print_maze(Maze* maze) {
    for (int i = 0; i < maze->get_rows(); i++)
    {
        for (int j = 0; j < maze->get_cols(); j++)
        {
            cout << maze->get_maze(i, maze->get_rows(), j);
        }
        cout << endl;
    }
    cout << endl;
}


int main()
{
    Maze* maze = new Maze();
    print_maze(maze);
    if (!maze->create_road()) {
        cout << "Nenasla sa cesta do ciela!" << endl;
    }
    else {
        print_maze(maze);
        cout << "Pocet vsetkych krokov: " << maze->get_count_of_all_steps() << endl;
        cout << "Pocet hlavnych krokov: " << maze->get_count_of_main_steps() << endl;
        cout << "Cas hladania: " << maze->get_time() << endl;
    }
}