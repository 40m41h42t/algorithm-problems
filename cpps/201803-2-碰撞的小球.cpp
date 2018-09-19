#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct ball{
    int id;
    int x;
}a[101];
bool cmpid(ball x, ball y){
    return x.id < y.id;
}
bool cmpx(ball x, ball y){
    return x.x < y.x;
}
int main(){
    int n, L, t;
    int i;
    cin>>n>>L>>t;
    for(i=0; i<n; ++i){
        a[i].id = i;
        scanf("%d", &a[i].x);
    }
    sort(a, a+n, cmpx);
    int temp[101];
    for(i=0; i<n; ++i){
        temp[i] = L-abs((a[i].x+t)%(2*L)-L);
    }
    sort(temp, temp+n);
    for(i=0; i<n; ++i){
        a[i].x = temp[i];
    }
    sort(a, a+n, cmpid);
    for(i=0; i<n; ++i){
        printf("%d", a[i].x);
        if(i < n-1){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}