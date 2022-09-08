#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main() {
    int n = 20;
    int* arr = new int[n];
    // for(int i=0; i<n; i++)
    //     arr[i] = i;
    for(int i=0; i<n; i++)
        cout << "[" << i << "]: " << arr[i] << endl;
}