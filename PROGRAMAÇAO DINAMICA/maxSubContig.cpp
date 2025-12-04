#include <bits/stdc++.h>

using namespace std;


// MAIOR SUBSEQUENCIA CONTÍGUA

int maxSubCont(int V[], int n){
    int maxS = V[0];
    int memo[n];
    memo[0] = V[0];
    for(int i =1;i<n;i++){
        memo[i] = max(V[i], V[i]+memo[i-1]);
        if(memo[i]>maxS) maxS = memo[i];
    }

    return maxS;
}

pair<int, int> maxSubContInt(int V[], int n){
    int maxS = V[0];
    int memo[n];
    int init[n];
    pair<int,int> res = {0,0};
    memo[0] = V[0];
    for(int i =1;i<n;i++){
        if(V[i]> V[i]+memo[i-1]){
            memo[i] = V[i];
            init[i] = i;
        }
        else{
            memo[i] = V[i]+memo[i-1];
            init[i] = init[i-1];
        }
        if(memo[i]>maxS){
            maxS = memo[i];
            res = {init[i], i};
        } 
    }

    return res;
}
int main(){
    int V[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = 9;
    pair<int,int> intervalo = maxSubContInt(V, n);
    cout << "Maior soma de subsequência contígua é " << maxSubCont(V, n) << endl;
    cout << "Intervalo da maior soma de subsequência contígua é [" 
    << intervalo.first << ", " << intervalo.second << "]" << endl;
    return 0;
}