#include <iostream>
#include <vector>
using namespace std;
int min(int A, int B) { if (A < B) return A; return B; }

int main()
{
    int num;
    scanf("%d", &num);
    vector< vector<int> > vec(num, vector<int>(3, 0));
    vector< vector<int> > dpVec(num, vector<int>(3, 0));

    for(int i = 0;i < num; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%d", &vec[i][j]);
            if (i == 0) dpVec[i][j] = vec[i][j];
        }
    }


    for(int i = 1 ; i < num ; i++)
    {
        dpVec[i][0] = min(dpVec[i - 1][1], dpVec[i - 1][2]) + vec[i][0];
        dpVec[i][1] = min(dpVec[i - 1][0], dpVec[i - 1][2]) + vec[i][1];
        dpVec[i][2] = min(dpVec[i - 1][0], dpVec[i - 1][1]) + vec[i][2];
    }

    cout << min(min(dpVec[num-1][0], dpVec[num-1][1]), dpVec[num-1][2]) << endl;
}