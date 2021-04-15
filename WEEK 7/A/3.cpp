#include<bits/stdc++.h>
using namespace std;
int count_event (vector<int> ar, int l)
{
    int count{0};
    for (int i = 0 ; i < l; ++i)
    {
        if (ar[i] % 2 == 0)
            ++count;
    }
    return count;
}
int main(int argc, char* argv[])
{
    srand(time(NULL));
   vector <int> arr;
   int n;
   cin>>n;
   while (n--)
   {
       int temp = rand() ;
       arr.push_back(temp);
   }
   for (auto i : arr)
    cout<<i<<' ';
   cout<<'\n'<<count_event (arr,arr.size());
    return 0;
}

