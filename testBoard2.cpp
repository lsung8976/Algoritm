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

	for(int i=0;i < str.size();i++)
    {
        if(str[i] == '1')
        {
            cnt++;
        }

        if(str[i] == '0')
        {
            ans *= d[cnt];
            cnt = 0;
        }
    }

    ans *= d[cnt];

    cout << ans << endl;

    printf("%d, %d", sizeof(int), sizeof(long));
    return 0;
    
}