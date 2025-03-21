#include<iostream>
#include<climits>
using namespace std;
int maxs=0;
int getscore(int arr[10],int n,int i){
    if (n==1) return arr[0];
    if(i==0) return arr[1];
    if (i==n-1) return arr[n-2];
    else{
        return arr[i-1]* arr[i+1];
    }
    
}
int backtrack(int arr[10],int n,int score){
    if (n==0){
        if (score>maxs){
            maxs=score; 
        }
        return maxs;
    }
    for (int i=0;i<n;i++){
        int temp=arr[i];
        int gain =getscore(arr,n,i);
        for (int j=i;j<n;j++){
            arr[j]=arr[j+1];
        }
        backtrack(arr,n-1,score+gain);
        for (int j = n - 1; j > i; j--) {
            arr[j] = arr[j - 1];
        }
        arr[i] = temp;
    }
    return maxs;
}
int main() {
    int n;
    cin >> n;
    int arr[10];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << backtrack(arr, n, 0) << endl;
    return 0;
}
