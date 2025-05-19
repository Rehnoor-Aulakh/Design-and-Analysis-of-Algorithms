#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findPlatform(vector<int> arr, vector<int> dep) {
    int n = arr.size();
    //since arrival time is already sorted, no need to sort
    // sort(arr.begin(), arr.end());
    // sort(dep.begin(), dep.end());

    int platforms_needed = 0, result = 1;
    int i = 0, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms_needed++;
            i++;
        } else {
            platforms_needed--;
            j++;
        }
        if (platforms_needed > result) {
            result = platforms_needed;
        }
    }
    return result;
}

int main() {
    vector<int> arr;
    vector<int> dep;
    arr.push_back(900);
    arr.push_back(940);
    arr.push_back(950);
    arr.push_back(1100);
    arr.push_back(1500);
    arr.push_back(1800);

    dep.push_back(910);
    dep.push_back(1200);
    dep.push_back(1120);
    dep.push_back(1130);
    dep.push_back(1900);
    dep.push_back(2000);

    cout << "Minimum number of platforms required: " << findPlatform(arr, dep) << endl;

    return 0;
}