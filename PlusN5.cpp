//boj.kr/15990
#include <iostream>
#include <vector>
using namespace std;

vector< vector<long long> > d(100001, vector<long long>(4,0));

int main()
{
    int T;
    int n;
    long long ans = 0;
   

    cin >> T;

    d[1][1] = d[2][2] = d[3][1] = d[3][2] = d[3][3] = 1;

    for(int i=4;i<100001;i++)
    {
        d[i][1] = (d[i-1][2] + d[i-1][3]) % 1000000009;
        d[i][2] = (d[i-2][1] + d[i-2][3]) % 1000000009;
        d[i][3] = (d[i-3][1] + d[i-3][2]) % 1000000009;
    }

    while(T--)
    {
        cin >> n;

        for(int i=1;i<=3;i++)
        {
            ans += d[n][i];
        }
        cout << ans % 1000000009 << endl;
        
        ans = 0;
    }
    
    return 0;
}