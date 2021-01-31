#include <iostream>
using namespace std;

bool c[10]; //check array
int a[10];  //number_list
void go(int index, int n, int m)
{
    if(index == m) 
    {
        /////
        for(int i = 0;i < m; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        ///// ->출력부
        return;
    } 
    for(int i = 1; i <= n; i++)  
    {
        if(c[i]) continue;
        c[i] = true;
        a[index] = i;
        go(index + 1, n, m);
        c[i] = false;
    }

}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    go(0, n, m);
    
    return 0;
}
