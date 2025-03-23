#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    int n;
    int gate[3];
    int people[3];
    cin>>n;
    for (int i = 0; i < 3; i++) {
        cin >> gate[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> people[i];
    
    }
    int arr[20];
    for (int i=0;i<n;i++){
        arr[i]=i+1;    
    }
    int min=100000000;
    do{
        int dist=0,p=0;
        for (int i=0;i<people[0];i++){
            dist+=abs(arr[p]-gate[0]);
            p++;
        }
        for (int i=0;i<people[1];i++){
            dist+=abs(arr[p]-gate[1]);
            p++;
        }
        for (int i=0;i<people[2];i++){
            dist+=abs(arr[p]-gate[2]);
            p++;
        }
        dist += p; 
        if (dist < min) min = dist;

    }while (next_permutation(arr, arr + n));
    cout<<min<<endl;
    return 0;
}
