#include "maze.h"
int Maze::start_c;
int Maze::start_r;
int Maze::count_of_all_steps;
int Maze::count_of_main_steps;
int Maze::time;
Maze::Maze()
{
    ifstream file("maze.txt");
    string str;
    int x = 0;
    if (x == 0) {
        file >> this->ROWS;
        x++;
    }
    if (x == 1) {
        file >> this->COLS;
        x++;
    }
    this->MAZE = new int[ROWS * COLS];
    this->visited = new int[ROWS * COLS];
    for (int i = 0; i < this->ROWS; i++)
    {
        file >> str;
        for (int j = 0; j < this->COLS; j++)
        {
            if (str[j] == 48)
                this->MAZE[i * this->ROWS + j] = 0;
            if (str[j] == 49)
                this->MAZE[i * this->ROWS + j] = 1;
            if (str[j] == 50) {
                this->MAZE[i * this->ROWS + j] = 2;
                Maze::start_r = i;
                Maze::start_c = j;
            }
            if (str[j] == 51)
                this->MAZE[i * this->ROWS + j] = 3;

        }
    }
    this->init_visited();
}

Maze::~Maze()
{
    delete[] this->MAZE;
    this->MAZE = nullptr;
    this->ROWS = 0;
    this->COLS = 0;
    Maze::start_r = 0;
    Maze::start_c = 0;
    Maze::count_of_all_steps = 0;
    Maze::count_of_main_steps = 0;
    Maze::time = 0;
}
void Maze::init_visited()
{
    for (int i = 0; i < this->ROWS; ++i) {
        for (int j = 0; j < this->COLS; ++j) {
            if (this->MAZE[i * this->ROWS + j] == 1) {
                visited[i * this->ROWS + j] = wall;
            }
            else if (this->MAZE[i * this->ROWS + j] == 3) {
                this->visited[i * this->ROWS + j] = goal;
            }
            else {
                this->visited[i * this->ROWS + j] = empty;
            }
        }
    }
}
int Maze::create_road() {
    if (this->dfs(this->ROWS, Maze::start_r, Maze::start_c)) {
        this->visited_to_maze();
        return 1;
    }
    return 0;
}
void Maze::visited_to_maze() {
    for (int i = 0; i < this->ROWS; ++i) {
        for (int j = 0; j < this->COLS; ++j) {
            if (visited[i * this->ROWS + j] == wall) {
                this->MAZE[i * this->ROWS + j] = 1;
            }
            else if (visited[i * this->ROWS + j] == crumb) {
                this->MAZE[i * this->ROWS + j] = 4;
                Maze::count_of_main_steps++;
                Maze::count_of_all_steps++;
            }
            else if (visited[i * this->ROWS + j] == other) {
                Maze::count_of_all_steps++;
            }
            else if (visited[i * this->ROWS + j] == goal) {
                this->MAZE[i * this->ROWS + j] = 3;
            }
            else {
                this->visited[i * this->ROWS + j] = empty;
            }
        }
    }
    this->MAZE[this->start_r * this->ROWS + this->start_c] = 2;
    delete[] this->visited;
    this->visited = nullptr;
}
int Maze::dfs(int rows, int row, int col) {

    if (this->visited[rows * row + col] == goal) {
        Maze::time++;
        return 1;
    }
    if (this->visited[rows * row + col] == empty) {
        this->visited[rows * row + col] = other;
        if (this->dfs(rows, row, col - 1)) {
            this->visited[rows * row + col] = crumb;
            Maze::time++;
            return 1;
        }
        if (this->dfs(rows, row + 1, col)) {
            this->visited[rows * row + col] = crumb;
            Maze::time++;
            return 1;
        }
        if (this->dfs(rows, row, col + 1)) {
            this->visited[rows * row + col] = crumb;
            Maze::time++;
            return 1;
        }
        if (this->dfs(rows, row - 1, col)) {
            this->visited[rows * row + col] = crumb;
            Maze::time++;
            return 1;
        }
    }
    return 0;
}
int Maze::get_time() {
    return Maze::time;
}
int Maze::get_start_row()
{
    return Maze::start_r;
}
int Maze::get_start_col()
{
    return Maze::start_c;
}
int Maze::get_rows()
{
    return this->ROWS;
}

int Maze::get_cols()
{
    return this->COLS;
}
int Maze::get_maze(int rows, int row, int col)
{
    return this->MAZE[rows * row + col];
}
int Maze::get_count_of_all_steps()
{
    return Maze::count_of_all_steps;
}
int Maze::get_count_of_main_steps()
{
    return Maze::count_of_main_steps;
}