#include<cstdio>
int main(){
    int num;
    int score = 0;
    bool ctfl = false;
    int csco = 0;
    while(true){
        scanf("%d", &num);
        if(num == 0) break;
        if(num == 1){
            score += 1;
            ctfl = false;
            csco = 0;
        }
        else if(num == 2){
            ctfl = true;
            csco += 2;
            score += csco;
        }
    }
    printf("%d\n", score);
    return 0;
}
