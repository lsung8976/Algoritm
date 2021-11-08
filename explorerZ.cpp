#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int sum = 0;

void find(int r,int c, int num)
{
    int _r, _c;
    if (num == 0) return;
    _r = r / num;
    _c = c / num;

    sum += ((_r * 2) + _c) * (num * num);

    r %= num; c %= num;

    find(r, c, num / 2);
}

int main()
{
    int N, r ,c;
    cin >> N >> r >> c;

    int num = pow(2, N);
    
    find(r, c, num / 2);

    cout << sum << endl;
    return 0;
}

