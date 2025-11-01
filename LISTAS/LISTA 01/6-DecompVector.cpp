#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pi;


void printVetor(int V[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", V[i]);
    cout << endl;   
}

pi decomposVetor(int V[],int n,  int i, int f, int pivo){
    int q1 = i-1;
    int q2 = f+1;
    int j = 0; 
    while(j<q2){
        if(V[j]<pivo){
            q1++;
            swap(V[j], V[q1]);
            j++;
        }
        else if(V[j]>pivo){
            q2--;
            swap(V[j], V[q2]);
        }
        else j++;
    }
    return {q1, q2};
} // Complexidade: O(n)


int main(){
    int V[] = {4,4,2, 1, 2, 4, 6, 10};
    pi p = decomposVetor(V, 8, 0, 7, 4);
    printVetor(V, 8);
    cout << p.first << " " << p.second << endl;
}




