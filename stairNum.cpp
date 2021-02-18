//boj.kr 10844
#include <iostream>
#include <vector>
using namespace std;

vector< vector<long long> > d(101, vector<long long> (10, 0));

int p[2] = {-1, 1}; 

int main()
{
    int N;
    long long ans = 0;
    scanf("%d", &N);

    for(int i=1;i<10;i++)
    {
        d[1][i] = 1;
    }

    for(int i = 2;i < 101;i++)
    {
        for(int j = 0;j < 10; j++)
        {
            for(int k=0;k<2;k++)
            {
                int nj = j + p[k];
                if(0 <= nj && nj <= 9)
                {
                    d[i][j] += (d[i-1][nj]) % 1000000000;
                }
            }
        }
    }

    for(int i=0;i<10;i++)
    {
        ans += d[N][i];
    }
    cout << ans % 1000000000 << endl;

    return 0;
}