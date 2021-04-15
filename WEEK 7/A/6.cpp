#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << "Number of command-line arguments: " << argc << '\n';
    for (int i = 0; i < argc; i++)
    {
    cout << "Argument #" << i << " ... " << argv[i] << "\n";
    }
    return 0;
}

