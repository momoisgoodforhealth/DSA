#include <bits/stdc++.h>
using namespace std;

void bubblesort(vector<int>& v) {
    int n = v.size();

    for (int i = 0 ; i < n; i++) {
        for (int j  = 0; j<n-i-1; j++) {
            if (v[j] > v[j+1]) swap(v[j],v[j+1]);
        }
    }
}

int main() {
vector<int> v = {5,9,1,3,2};
bubblesort(v);
for (auto i: v) 
cout << i << " ";
return 0;
}