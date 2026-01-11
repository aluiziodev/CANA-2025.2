#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> mat;

void printVetor(int V[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", V[i]);
    cout << endl;   
}

void mergeK(int V[], int i, int f, int n){
    if(i!=f){
        int meio = (i+f)/2;
        mergeK(V,i,meio, n);
        mergeK(V,meio+1,f, n);
        
        int A[(f-i+1)*n];

        int it = i*n;
        int j = (meio+1)*n;
        int l = 0;

        while(it<=((meio+1)*n)-1 || j<=((f+1)*n)-1){
            if(it>((meio+1)*n)-1){
                A[l] = V[j];
                j++;
            }
            else if(j>((f+1)*n)-1){
                A[l] = V[it];
                it++;
            }
            else if(V[it]>V[j]){
                A[l] = V[j];
                j++;
            }
            else{
                A[l] = V[it];
                it++;
            }
            l++;
        }
        l = 0;
        it = i*n;
        while(it<=((f+1)*n)-1){
            V[it] = A[l];
            it++; l++;
        }
    

    }
}

int main(){
    int V[] = {1,3,4,2,6,7,3,4,5,1,2,3};
    mergeK(V, 0, 3, 3);
    printVetor(V, 12);
}