#include <bits/stdc++.h>

using namespace std;


int binarySearch(int V[], int i, int f){
    if(i<=f){
        int meio = (i+f)/2;
        if(V[meio]==meio+1) return meio+1;
        else if(V[meio]>meio+1) return binarySearch(V, i, meio-1);
        else return binarySearch(V, meio+1, f);
    }
    return -1;
}


int main(){

    int V[] = {1,2,4,5,6,8,9};
    cout << binarySearch(V, 0, 6) << endl;
}