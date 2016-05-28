#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n, t, u, pos = 0;
    scanf("%d", &n);
    short from[n*n+1] = {};
    short to[n*n+1] = {};
    char human[n+1] = {};
    char str[256];
    gets(str);
    while(1) {
        gets(str);
        if(0 == strcmp("BLOOD", str)){
            break;
        }else{
            sscanf(str, "%d %d", &(from[pos]), &(to[pos]));
            pos++;
        }
    }
    while(scanf("%d", &t) != EOF){
        if(t==0) break;
        human[t] = 0b11;
    }
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < pos; j++){
            if(human[from[j]]&0b01) human[to[j]] |= 0b01;
            if(human[to[j]]&0b10) human[from[j]] |= 0b10;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!human[i]){
            printf("%d ", i);
            cnt++;
        }
    }
    if(cnt == 0) printf("0");
    return 0;
}