#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int temp;
    int n;
    int hap = 0;
    
    vector<int> line;

    cin >> n;
    vector<int> p(n);

    for(int i=0;i<n;i++)
    {
        cin >> p[i];
    }

    sort(p.begin(), p.end());

    for(int i=0;i<n;i++)
    {
        hap += p[i];
        line.push_back(hap);
    }
    hap = 0;
    for(int i=0;i<n;i++)
    {
        hap += line[i];
    }
    cout << hap << endl;
    return 0;
}