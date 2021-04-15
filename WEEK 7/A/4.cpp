#include<bits/stdc++.h>
using namespace std;
void binary_search (int *arr, int l,int s)
{
    cout<<"find "<<s<<'\n';
    int down{0},up{l-1};
    int k = (up + down)/2 ;
    while (!((k==up)||(k==down)||(up<down)))
    {
      // cout<<arr[k]<<" arr[k] " <<k<<" k "<<up<<" up "<<down<<" down \n";
        if (arr[k] > s){
            up = k ;}
        else if (arr[k] < s){
            down = k ;}
        else if (arr[k]==s){
            cout<<k<<'\n';
            break;
        }
         k = (up - down)/2 + down;
    }
}
int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(NULL));
    int n;
    cin>>n;
    int *arr = new int [n];
    for(int i = 0 ; i < n; ++i)
        arr[i] = i;
    binary_search(arr,n, rand()%n);
    delete []arr;
    return 0;
}

