#include <iostream>
#include <climits>
using namespace std;

const int OPEN = 0;
const int PATH = 3;
const int WALL = 1;
const int JEWEL = 2;
const int MAX = 10;

int maxJewels = 0;
int minDepth = INT_MAX;

// Movement directions: right, down, left, up
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

// Recursive DFS function
void dfs(int i, int j, int N, int maze[MAX][MAX], int path[MAX][MAX], int bestPath[MAX][MAX],
         int jewels, int depth) {

    // Base case: reached destination
    if (i == N - 1 && j == N - 1) {
        if (jewels > maxJewels || (jewels == maxJewels && depth < minDepth)) {
            maxJewels = jewels;
            minDepth = depth;

            // Save the best path
            for (int r = 0; r < N; r++) {
                for (int c = 0; c < N; c++) {
                    bestPath[r][c] = path[r][c];
                }
            }
        }
        return;
    }

    // Explore 4 directions
    for (int d = 0; d < 4; d++) {
        int r = i + dx[d];
        int c = j + dy[d];

        // Check if move is valid
        if (r >= 0 && r < N && c >= 0 && c < N && maze[r][c] != WALL && path[r][c] == OPEN) {
            path[r][c] = PATH;

            int collect = 0;
            if (maze[r][c] == JEWEL) {
                collect = 1; // If this cell has a jewel, collect it
            }

            dfs(r, c, N, maze, path, bestPath, jewels + collect, depth + 1);

            path[r][c] = OPEN; // Backtrack
        }
    }
}

int main() {
    int N;
    cin >> N;

    int maze[MAX][MAX];
    int path[MAX][MAX] = {0};
    int bestPath[MAX][MAX] = {0};

    // Input maze
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
        }
    }

    // Start at (0,0)
    path[0][0] = PATH;
    int startJewels = 0;
    if (maze[0][0] == JEWEL) {
        startJewels = 1;
    }

    // Run DFS
    dfs(0, 0, N, maze, path, bestPath, startJewels, 0);

    // Print best path
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << bestPath[i][j] << " ";
        }
        cout << endl;
    }

    // Print total jewels collected
    cout << maxJewels << endl;

    return 0;
}

/*
#include<iostream>
using namespace std;
const int PATH=3;
int jewel=2;
int wall=1;
int open=0;
int maxjewels=0;
int mindepth=100000;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void bfs(int i,int j,int n,int jewels,int maze[50][50],int path[50][50],int bestpath[50][50],int depth){
    if(i==n-1 && j==n-1){
        if(jewels>maxjewels ||( jewels==maxjewels && depth<mindepth)){
            maxjewels=jewels;
            mindepth=depth;
        for(int r=0;r<n;r++){
            for (int c=0;c<n;c++){
                bestpath[r][c]=path[r][c];
            }
        }
        return;
    }
}
    for(int d=0;d<4;d++){
        int ni=i+dx[d];
        int nj=j+dy[d];
        if(ni>=0 && nj>=0 && ni<n && nj<n && maze[ni][nj]!=wall && path[ni][nj]==open){
            path[ni][nj]=PATH;
            int collect=0;
            if (maze[ni][nj]==jewel){
                    collect=1;
            }
            bfs(ni,nj,n,jewels+collect,maze,path,bestpath,depth+1);
            path[ni][nj]=open;
            }
        }
    }
int main (){
    int n;
    cin>>n;
    int i;
    int j;
    int maze[50][50];
    int path[50][50];
    int bestpath[50][50];
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            cin >>maze[i][j];
        }
    }
    path[0][0]=PATH;
    int startjewel=0;
    if(maze[0][0]==jewel){
        startjewel=1;
    }
    bfs(0, 0, n, startjewel, maze, path, bestpath, 0);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<bestpath[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<maxjewels<<endl;
}*/
