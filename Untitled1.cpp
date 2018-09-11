#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,i,a[1000];
    int tong=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];   
    }
    for(i=1;i<n-1;i++){
        if(a[i]>a[i+1]&&a[i]>a[i-1]) tong+=a[i];
    }
    cout<<tong;
    return 0;
}
