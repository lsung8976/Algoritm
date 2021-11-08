#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> map;

int inspectFunc(int ch, int i)
{
    int min = abs(ch - i);
    min = (min > abs(100-i))? abs(100-i) : min;
    return min;
}

int main()
{
    int firstChannel = 100;
    int channel;
    int brokenBtn;
    int min = 987654321;
    vector<int> vec(brokenBtn);
    map = vec;

    cin >> channel >> brokenBtn;
    for(int i=0;i<brokenBtn;i++)
        cin >> vec[i];
    
    for(int i=0;i<channel;i++)
    {
        int ret = inspectFunc(channel, i);
        min = (min > ret) ? ret : min;
    }

    /*
    cout << channel << " " << brokenBtn << endl;

    for(int i=0;i<brokenBtn;i++)
        cout << vec[i] << " ";
    cout << endl;
    */
    return 0;
}