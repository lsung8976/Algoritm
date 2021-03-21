#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
vector< vector<bool> > map;

bool checkSpac(int size , int i, int j, int num)
{
    if((i + size) >= num || (j + size) >= num) return false;

    for(int k = i ; k < i + size; k++)
    {
        for(int l = j; l < j + size; l++)
        {
            if(map[k][l] == false)  return false;
        }
    }
    return true;
}

int main()
{
    int num;// 격자 값
    int total = 0;
    cin >> num;
    vector<int> cnt(num + 1, 0);
    vector< vector<bool> > fmap(num, vector<bool>(num,0));

    map = fmap;

    for(int i=0;i<num;i++)
    {
        string str;
        cin >> str;
        for(int j=num-1;j>=0;j--)
        {
            if(str.back() == '0')
            {
                map[i][j] = false;
            }
            else
            {
                map[i][j] = true;
            }
            str.pop_back();
        }
    }

    for(int size = 1; size <= num; size++)
    {
        if(size == 1)
        {
            for(int i=0;i < num;i++)    //첨자i
            {
                for(int j=0;j < num;j++)  //첨자j
                {
                    if(map[i][j])   cnt[size]++;
                }
            }
            continue;
        }
        for(int i=0;i < num;i++)    //첨자i
        {
            for(int j=0;j < num;j++)  //첨자j
            {
                if(checkSpac(size, i, j, num))   cnt[size]++;
            }
        }
    }

    for(int i=0;i<=num;i++)
    {
        cout << cnt[i] << " ";
    }
    cout << endl;

    for(int i=1;i<=num;i++)
    {
        if(cnt[i]<=0) break;
        total += cnt[i];
    }
    printf("total: %d\n", total);

    for(int i=1;i<=num;i++)
    {
        if(cnt[i]<=0) break;
        printf("size[%d]: %d\n", i , cnt[i]);
    }

    return 0;
}