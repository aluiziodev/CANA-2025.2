#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

/*
Rod Cutting Problem
Given a rod of length n inches and a table of prices P[i] for i = 1, 2, ..., n,
determine the maximum revenue obtainable by cutting up the rod and selling the pieces.
*/

int hastes(int P[], int n){
    int memo[n+1];
    memo[0] = 0;
    for(int i = 1;i<=n;i++){
        memo[i]  = 0;
        for(int j = 1; j<=i; j++){
            memo[i] = max(memo[i-j]+P[j], memo[i]);
        }
    }
    return memo[n];
}

int main(){
    int n;
    cin >> n;
    int P[n+1];
    P[0] = 0;
    for(int i =1;i<=n;i++) cin >> P[i];
    cout << "Preço Max: " << hastes(P,n) << "\n";
    return 0;
}

