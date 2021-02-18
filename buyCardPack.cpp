//boj.kr/11052
#include <iostream>
#include <vector>
using namespace std;

vector<int> d(10001, 0);   //카드 가격 최대 값


/*int func(int n, vector<int>& price)
{
    if(d[n] > 0) return d[n];

    if(n == 1) return price[1];
    if(n > 1)
    {
        d[n] = price[1] + func(n - 1, price);

        for(int i = 2;i <= n; i++)
        {
            int temp = price[i] + func(n - i, price);
            d[n] = (d[n] > temp) ? d[n] : temp;
        }
    }

    return d[n];
}*/

int main()
{
    int N;
    
    cin >> N;
    vector<int> p(N + 1);

    for(int i=1;i <= N ;i++)
    {
        cin >> p[i];    // 각각의 카드팩값 입력
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=i;j++)
        {
            d[i] = max(d[i], p[j] + d[i-j]);
        }
    }

    cout << d[N] << endl;

    return 0;
}