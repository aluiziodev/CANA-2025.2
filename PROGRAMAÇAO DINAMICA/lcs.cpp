#include <bits/stdc++.h>
#define INTMAX 1000
using namespace std;

string memo[INTMAX][INTMAX];

void init(){
    for(int i =0;i<INTMAX;i++){
        for(int j =0;j<INTMAX;j++){
            memo[i][j] = "";
        }
    }
}

string lcs(string X, string Y, int m, int n){
    if(m ==0 || n==0) return "";
    if(X[m-1] == Y[n-1]){
        memo[m][n] = lcs(X, Y, m-1, n-1) + X[m-1];
        return memo[m][n];
    }
    else{
        string s1 = lcs(X, Y, m-1, n);
        string s2 = lcs(X, Y, m, n-1);
        if(s1.length() > s2.length()){
            memo[m][n] = s1;
            return s1;
        }
        else{
            memo[m][n] = s2;
            return s2;
        }
    }
}

int main(){
    init();
    string X = "ABCBDAB";
    string Y = "BDCABC";
    int m = X.length();
    int n = Y.length();
    string lcsStr = lcs(X, Y, m, n);
    cout << "LCS: " << lcsStr << "\n";
    return 0;
}