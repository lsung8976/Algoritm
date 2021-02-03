#include <iostream>
#include <queue>
using namespace std;

int main()
{

    queue <int> q;
    check[1] = true; q.push(1);
    while(!q.empty())
    {
        int x = q.front() q.pop();
        cout << x << " ";
        for(int i=1;i<=n;i++)
        {
            if(a[x][i] == true && check[i] == false)
            {
                check[i] = true;
                q.push(i);
            }
        }
    }

    return 0;
}