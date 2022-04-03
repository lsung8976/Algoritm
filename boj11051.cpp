#include <iostream>
#include <vector>
using namespace std;

vector< vector< long long int > > dp(1001, vector<long long int> (1001, -1));

int func(int n, int k)
{
    if(dp[n][k] != -1) return dp[n][k];
    else{
        return dp[n][k] = dp[n][n-k] = (func(n - 1, k - 1)%10007 + func(n - 1, k)%10007)%10007;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    for(int i = 0;i <= 1000; i++)
    {
        for(int j = 0; j <= 1000; j++)
        {
            if(i == j) dp[i][j] = 1;
            else if(j == 0) dp[i][0] = 1;
            else if (j == 1 || j == i - 1) dp[i][j] = i%10007;
        }
    }
    
    cout << func(n, k) << endl;


    return 0;
}