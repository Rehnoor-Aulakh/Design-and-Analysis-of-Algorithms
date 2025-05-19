#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool place(int k, int i, vector<int> &x) {
    for(int j=0; j<k; j++) {
        if(x[j]==i || abs(x[j]-i)==abs(j-k))
            return false;
    }
    return true;
}

void nqueen(int k, vector<int> &x, int n) {
    for(int i=0; i<n; i++) {
        if(place(k, i, x)) {
            x[k] = i;
            if(k == n-1) {
                for(int j=0; j<n; j++)
                    cout << x[j]+1 << " ";
                cout << endl;
            } else {
                nqueen(k+1, x, n);
            }
        }
    }
}

int main() {
    int n = 4;
    vector<int> x(n);
    nqueen(0, x, n);
    return 0;
}