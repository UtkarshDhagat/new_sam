#include<iostream>
#include<climits>
using namespace std;
int min_cost=100000;
int tsp(int m[12][12],int cost,int n,int pos,bool visited[],int count){
    if(count==n){
        min_cost=min(min_cost,cost+m[pos][0]);
    }
    for(int city=0;city<n;city++){
        if (!visited[city]){
            visited[city]=true;
            tsp(m,cost+m[pos][city],n,city,visited,count+1);
            visited[city]=false;
        }
    }
    return min_cost;
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int m[12][12];
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cin>>m[i][j];
            }
        }
        min_cost=1000000;
        bool visited[12]={false};
        cout<<tsp(m,0,n,1,visited,0)<<endl;;
    }
}

