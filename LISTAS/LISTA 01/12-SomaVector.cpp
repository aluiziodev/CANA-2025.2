#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;


void mergeSort(vi &V, int i, int f){
    if(i!=f){
        int meio = (i+f)/2;
        mergeSort(V, i, meio);
        mergeSort(V, meio+1, f);

        vi aux(f-i+1);
        int l = 0;
        int it = i;
        int j = meio+1;
        while(it<=meio || j<=f){
            if(it>meio){
                aux[l] = V[j]; j++;
            }
            else if(j>f){
                aux[l] = V[it]; it++;
            }
            else if(V[it]<V[j]){
                aux[l] = V[it]; it++;
            }
            else{
                aux[l] = V[j]; j++;
            }
            l++;
        }

        l = 0;
        it = i;
        while(it<=f){
            V[it] = aux[l];
            it++; l++;
        }
    
    }
}

bool contains(vi &V, int n, int x){
    mergeSort(V, 0, n-1); // O(nlog(n))
    int i = 0;
    int j = n-1;
    while(i<j){
        if(V[i]+V[j]==x) return true;
        else if(V[i]+V[j]<x) i++;
        else j--;
    } // O(n)
    return false;
}
// O(n log(n))

int main(){
    vi V = {3, 2, 4, 7, 9, 6, 1};
    if(contains(V, 7, 10)) cout << "1\n";
    else cout << "0\n";
}