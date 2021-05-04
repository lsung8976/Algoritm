#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>

using namespace std;

int main()
{
    int k, temp, sum;
    scanf("%d", &k);
    queue<int> q;
    
    for(int i=0;i<k;i++)
    {
        scanf("%d", &temp);
        if(temp== 0)
            q.pop();
        else
            q.push(temp);
    }

    while(k--)
    {
        sum += q.back(); q.pop();
    }
    
    printf("%d", &sum);
    return 0;
}