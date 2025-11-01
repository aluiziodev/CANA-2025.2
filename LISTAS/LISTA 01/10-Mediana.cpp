#include <bits/stdc++.h>

using namespace std;


double mediana(int X[], int Y[], int n){
    int i, j;
    int inicio = 0;
    int fim = n-1;
    i =  n/2;
    j = n - i;

    while(inicio<=fim && (Y[j-1]>X[i] || X[i-1]>Y[j])){
        if(Y[j-1]>X[i]){
            inicio = i+1;
        }   
        else if(X[i-1]>Y[j]){
            fim = i-1;
        }
        i = (fim+inicio)/2;
        j = n-i;
    }
    double r = (min(X[i],Y[j]) + max(X[i-1],Y[j-1]))/2.0;
    return r;
}


int main(){
    int X[] = {1,3,5,7,9};
    int Y[]= {2,4,6,8,10};

    cout << mediana(X, Y, 5) << endl;


}