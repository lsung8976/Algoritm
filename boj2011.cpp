#include <iostream>
#include <string>
using namespace std;

int main()
{
    string num = "25115";
    int dp[5001];
    int len = 0;

    cin >> num;
    if (num[0] == '0') {
        printf("0\n");
        return 0;
    }
    dp[0] = 0;
    dp[1] = 1; //첫번째 자리는 무조건 1
    int a1 = num[0] - '0';
    int b1 = num[1] - '0';
    if (a1 * 10 + b1 <= 26)
    {
        dp[2] = 2;
    }
    else{
        dp[1] = 1;
    }
    
    len = num.length();

    for(int i = 3; i <= len; i++)
    {
        int a = num[i - 2] - '0';
        int b = num[i - 1] - '0';
        if (a * 10 + b <= 26)
        {
            dp[i] = dp[i - 1]%1000000 + dp[i - 2]%1000000;
        }
        else if ((a * 10 + b) == '0') {
            printf("0\n");
        return 0;
        }
        else
        {
            dp[i] = dp[i - 1]%1000000;
        }
        
    }
    /*
    for(int i=0;i<=len;i++)
    {
        printf("%d",dp[i]);
    }*/
    printf("%d", dp[len]%1000000);
    return 0;
}
