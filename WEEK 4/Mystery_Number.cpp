#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    long sumA {0};
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin>>temp;
        sumA += temp;
    }
    long sumB {0};
    for (int i=0; i<=n; ++i)
    {
        int temp;
        cin>>temp;
        sumB+=temp;
    }
    cout<<(sumB - sumA);
    return 0;
}

