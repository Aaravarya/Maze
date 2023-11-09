#include <bits/stdc++.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void printMaze(const vector<vector<int>>& maze) {
    
    for(auto x: maze)
    {
        for(auto y: x)
        {
            if(y==1)
            cout<<'#';
            else if(y==0)
            cout<<'0';
            else cout<<'*';
        }
        cout<<endl;
    }
}


void generateMaze(vector<vector<int>>& maze, int n) {
    maze = vector<vector<int>>(n, vector<int>(n, 0)); 

    srand(time(0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (rand() % 100 < 30) {
                maze[i][j] = 1;
            }
        }
    }
     
    // Set start and end points
    maze[0][0] = 0;  // Entry point
    maze[n - 1][n - 1] = 0; // Exit point

    cout << "Maze generated successfully:\n";
    for(auto x: maze)
    {
        for(auto y:x)
        cout<<y<<" ";cout<<endl;
    }
}

bool isValidCell(int x, int y, const vector<vector<int>>& maze) {
    return x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] == 0;
}

bool findPathDFS(int x, int y, vector<vector<int>>& maze) {
    if (x == maze.size() - 1 && y == maze[0].size() - 1) {
        maze[x][y] = 2; 
        return true;
    }

    if (!isValidCell(x, y, maze)) {
        return false;
    }
    maze[x][y] = 2; 

    if (findPathDFS(x + 1, y, maze) || findPathDFS(x - 1, y, maze) ||
        findPathDFS(x, y + 1, maze) || findPathDFS(x, y - 1, maze)) {
        return true;
    }

    maze[x][y] = 0;
    return false;
}

void findPath(vector<vector<int>>&maze, int n) {

    if (findPathDFS(0, 0, maze)) {
        cout << "\nPath found:\n";
        printMaze(maze);
    } else {
        cout << "\nPath not possible.\n";
    }
}

int main() {
    int choice, n;
    vector<vector<int>> maze;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Generate Maze\n";
        cout << "2. Find Path\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the size of the maze (n): ";
                cin >> n;
                generateMaze(maze,n);
                break;

            case 2:
                findPath(maze, n);
                break;

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}
