#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define MAXIMUM 0x7FFFFFFF
#define MAXN 1001
int main(){
    int num[MAXN];
    int n;
    cin>>n;
    int min_num = MAXIMUM;
    for(int i=0; i<n; ++i){
        cin>>num[i];
        for(int j=0; j<i; ++j){
            int tmp = abs(num[i]-num[j]);
            if(tmp < min_num){
                min_num = tmp;
            }
        }
    }
    cout<<min_num<<endl;
    return 0;
}