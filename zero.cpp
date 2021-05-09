//10773 제로
#include <iostream>
#include <stdio.h>
#include <stack>
#include <cstring>

using namespace std;

int main()
{
    long long k, temp, sum;
    scanf("%lld", &k);
    sum = 0;
    stack<long long> stk;
    
    sum = 0;
    for(int i=0;i<k;i++)
    {
        scanf("%lld", &temp);
        if(temp == 0)
            stk.pop();
        else
            stk.push(temp);
    }

    while(!stk.empty())
    {
        sum += stk.top(); stk.pop();
    }

    printf("%lld\n", sum);
    return 0;
}