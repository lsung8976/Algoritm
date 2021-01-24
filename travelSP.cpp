#include <iostream>
#include <algorithm>
using namespace std;

bool permut(int *ptr, int n)
{
    int i, j;
    int temp;
    for(i = n-1; i>=0;i--)
    {
        if(ptr[i-1]<ptr[i]) break;
    }
    if(i <= 0) return false;
    for(j=n-1;j>=i;j--)
    {
        if(ptr[i-1] < ptr[j]) break;
    }
    //swap
    temp = ptr[j];
    ptr[j] = ptr[i-1];
    ptr[i-1] = temp;

    //sorting
    sort(ptr + i, ptr + n);
    return true;
}


int main()
{
    int size;
    int min = 987654321;
    int **arr;
    int *ptr;
    cin >> size;

    //1차원 배열에 숫자 채우기
    ptr = new int[size];

    for(int i = 0; i < size - 1;i++)
    {
        ptr[i] = i + 1;
    }

    arr = new int*[size];

    for(int i=0;i<size;i++)
    {
        arr[i] = new int[size];
    }

    for(int i =0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cin >> arr[i][j];
        }
    }
/*
    // 2차원 배열
    for(int i =0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
*/
    //  비용 계산
    do
    {
        int sum = 0;
        int i;
        for(i = 0;i < size - 2; i++)
        {
            sum = arr[ptr[i]][ptr[i+1]];
        }
        ++i;
        sum += ( arr[ptr[i]][0] + arr[0][ptr[0]]);
        //cout << i << endl;
        min = (min > sum) ? sum : min;
        cout << endl;
    }
    while(permut(ptr,size - 1));
    cout << min << endl;
    return 0;
}