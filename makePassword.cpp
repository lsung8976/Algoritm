#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> pswdStorage;

void go(vector<int> v, int c, int i)
{
    if(c == i) return;
    vector<int> pswd;
    pswd.push_back(v[i]);
    go(vector<int> v)
    
}

int main()
{
    int length;
    int combo;
    int index= 0;

    cin >> length; //(L)
    cin >> combo; //(C)

    vector<char> vec(combo);

    for(int i=0;i<combo;i++)
       cin >> vec[i];

    go(vec, combo, index);

}