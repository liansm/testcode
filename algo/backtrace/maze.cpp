#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

/*
int n, m;
bool maze[100][100];
bool maze_mask[100][100];

void create_maze()
{
    memset(maze_mask, 0, sizeof(100*100));
    
    cin >> n >> m;
    char val;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> val;
            if(val == '.'){
                maze[i][j] = 0;
            }
            else if(val == '#'){
                maze[i][j] = 1;
            }
        }
    }
}

void travel_maze(int x, int y)
{
    //越界
    if(x < 0 || x >= n || y < 0 || y >= m){
        return;
    }

    //遇到障碍物
    if(maze[x][y] == 1){
        return;
    }
    
    //已经走过了
    if(maze_mask[x][y] == 1){
        return;
    }

    
    maze_mask[x][y] = 1;
    
    
    if(x == n-1 && y == m-1){
        cout << "YES" << endl;
        exit(-1);
    }

    travel_maze(x, y+1);
    travel_maze(x+1, y);
    travel_maze(x, y-1);
    travel_maze(x-1, y);
    
    maze_mask[x][y] = 0;
}


int main()
{
    create_maze();

    travel_maze(0,0);

    cout << "NO" << endl;
    return 0;
}
*/
