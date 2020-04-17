#pragma once
#include <fstream>
using namespace std;
const int N = 1;
class Maze
{
private:
	int* MAZE;
	int* visited;

	int ROWS = 0;
	int COLS = 0;

	static int start_r;
	static int start_c;
	static int count_of_all_steps;
	static int count_of_main_steps;
	static int time;

	enum terrain {
		start,
		empty,
		wall,
		goal,
		crumb,
		other
	};

public:
	Maze();
	~Maze();

	void visited_to_maze();
	void init_visited();

	int create_road();
	int get_maze(int rows, int row, int col);
	int dfs(int, int, int);

	int get_rows();
	int get_cols();
	int get_start_row();
	int get_start_col();
	int get_count_of_all_steps();
	int get_count_of_main_steps();
	int get_time();
	
};

