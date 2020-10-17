#include <stdio.h>

int solveMaze(char **maze, const int HT, const int WD, int x, int y); // draws a path to the exit on the maze string
void printMaze(char **maze, const int HT, const int WD); // prints the maze

int main(){
    char mazeStr[] =
			"  ##############"
		    "#     #     ####"
		    "# ####* ### ####"
		    "#    ###### ####"
		    "#### # #### ####"
		    "#    # #### ####"
		    "#### # #### ####"
		    "####        ####"
		    "################";
    const int HT = 9;
    const int WD = 16;
    char *maze[HT];

    for (int i=0; i<HT ; i++)	// filling the 2D char array
	    maze[i]=&mazeStr[i*WD];

    solveMaze(maze, HT, WD, 0, 0);
    printMaze(maze, HT, WD);

    return 0;
}

int solveMaze(char **maze, const int HT, const int WD, int x, int y){
    if(x < 0 || x >= WD || y < 0 || y >= HT) 
            return 0; // making sure that we are not ouf of boundaries
	if(*(*(maze + y) + x) == '*') 
            return 1; // checks if the rat arrived at destination
	if(*(*(maze + y) + x) == '#' || *(*(maze + y) + x) == '.') 
            return 0; // checks if the point has ever been visited before

	*(*(maze + y) + x) = '.'; // marks visited point

    if(solveMaze(maze, HT, WD, x, y - 1) == 1) 
            return 1; // north direction
    if(solveMaze(maze, HT, WD, x + 1, y) == 1) 
            return 1; // east direction
    if(solveMaze(maze, HT, WD, x, y + 1) == 1) 
            return 1; // south direction
    if(solveMaze(maze, HT, WD, x - 1, y) == 1) 
            return 1; // west direction
	
    *(*(maze + y) + x) = ' '; // marking wrong path with space
	return 0;
}

void printMaze(char **maze, const int HT, const int WD){
    for (int i=0; i<HT ; i++){
	for(int j=0; j<WD-1; j++)
	  printf("%c",maze[i][j]);
    printf("%c\n",maze[i][WD-1]);
    }
}
