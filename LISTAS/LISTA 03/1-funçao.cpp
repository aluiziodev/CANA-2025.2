#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;


int alg1(int n){
    if(n<=4) return 0;
    else return alg1(n/2) + alg1((n/2) + 1) + alg1((n/2) + 2) + n;
}

int alg2(int n){
    int PD[n];
    for(int i = 0; i<5; i++) PD[i] = 0;
    for(int i = 5; i<=n; i++){
        PD[i] = PD[i/2] + PD[(i/2) + 1] + PD[(i/2) + 2] + i;
    }
    return PD[n];
}

int memo[100000];
void init_memo(){
    for(int i = 0; i<100000; i++) memo[i] = -1;
}

int alg3(int n){
    if(memo[n] != -1) return memo[n];
    else if (n<=4) {
        memo[n] = 0;
        return 0;
    }
    memo[n] = alg3(n/2) + alg3((n/2) + 1) + alg3((n/2) + 2) + n;
    return memo[n];
}

