#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int man (int x1,int y1,int x2,int y2){
    return abs (x1-x2)+ abs(y1-y2);
}
int dfs(int n,int x,int y,int home_x,int home_y,bool visited[],int custx[],int custy[],int dist,int &minn,int count){
    if (count==n){
        dist+=man (x,y,home_x,home_y);
        if (dist<minn){
            minn=dist;
        }
    return minn;
    }
    for (int i=0;i<n;i++){
        if (!visited[i]){
            visited[i]=true;
            dfs (n,custx[i],custy[i],home_x,home_y,visited,custx,custy,dist +man(x,y,custx[i],custy[i]),minn,count+1);
            visited[i]=false;
        } 
    }
    return minn;
}
int main() {
    for (int test = 1; test <= 10; test++) {
        int N;
        cin >> N; 
        int officeX, officeY, homeX, homeY;
        cin >> officeX >> officeY >> homeX >> homeY;
        int custX[10], custY[10];
        for (int i = 0; i < N; i++) {
            cin >> custX[i] >> custY[i];
        }
        bool visited[10] = {false};
        int minn = 10000000;
        
        cout <<"#"<<" "<<test <<" "<< dfs(N, officeX, officeY, homeX, homeY, visited,custX, custY,0,minn,0)<< endl;
    }
    return 0;
}
