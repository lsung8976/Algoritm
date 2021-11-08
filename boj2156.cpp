#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int maxCup = 0;
    int sum = 0;
    cin >> maxCup;
    
    vector<int> cup(maxCup + 1, 0);
    vector< vector<int> > dp(maxCup + 1, vector<int> (3, 0));

    for(int i = 1; i <= maxCup; i ++)
    {
        cin >> cup[i];
    }

    for(int i = 1; i <= maxCup; i ++)
    {
        dp[i][0] = (dp[i-1][0] > dp[i-1][1]) ? dp[i-1][0] : dp[i-1][1];
        dp[i][0] = (dp[i][0] > dp[i-1][2]) ? dp[i][0] : dp[i-1][2];
        dp[i][1] = dp[i-1][0] + cup[i];
        dp[i][2] = dp[i-1][1] + cup[i];
    }

    sum = (dp[maxCup][0] > dp[maxCup][1])? dp[maxCup][0] : dp[maxCup][1];
    sum = (sum > dp[maxCup][2])? sum : dp[maxCup][2];

    cout << sum << endl;
    
    return 0;
}

