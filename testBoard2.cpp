#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    string str;
    int num;
    int cnt = 0;
    unsigned long long ans = 1;
    
    unsigned long long d[51];
    
    d[0] = 1;
    d[1] = 1;
    d[2] = 1;

    cin >> num;
    cin >> str;
    
    for(int i=3;i<51;i++)
    {
        d[i] = d[i-1] + d[i-2];
    }
	//cout  << d[50] << endl;
	for(int i=0;i<str.size();i++)
    {
        if(str[i] == '0')
        {
            ans = ans * d[cnt];
            cnt = 0;
        }
        if(str[i] == '1')
        {
            cnt++;
            ans = d[cnt];
        }
    }
    
    cout << ans << endl;

    return 0;

}