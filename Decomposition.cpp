#include <iostream>
#include <vector>
using namespace std;

vector< vector<long long> > d(201, vector<long long> (201, 1));

int main()
{
    int N, K;
    cin >> N;
    cin >> K;

    for(int i = 0; i < 201; i++)    
    {
        d[i][0] = 0; 
        d[0][i] = 0;
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1;j <= K; j++)
        {
            for(int L = 0; L <= i; L++)
            {
                d[i][j] += d[i - L][j - 1] % 1000000000;
            }  
        }
    }

    cout << d[N][K] % 1000000000 << endl;

    return 0;
}