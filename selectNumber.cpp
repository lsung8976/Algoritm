#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
            표
1 | 2 | 3 | 4 | 5 | 6 | 7
--------------------------
3 | 1 | 1 | 5 | 5 | 4 | 6
*/

/*
            표
1 | 2 | 3 | 4 | 5 |
-------------------
3 | 5 | 4 | 4 | 2 |
*/
vector<int> box = {3, 1, 1, 5, 5, 4, 6};

vector<int> check_vec1;
vector<int> check_vec2;

vector<int> count_vec(box.size());
vector<int> picked;
int cnt  = 0; // 탐색 숫자 카운트
int same_cnt = 0;   // 원소와 첨자가 같은것 카운트

void go(int first_low, int second_low)
{
    if(cnt > box.size())
    {
        cnt = 0;
        return;
    }
    if(cnt != 0)
    {
        if(check_vec1[0] == first_low+1) return;
    }
    check_vec1.push_back(first_low + 1);    // 0부터 시작하는 i 첨자로 넘기므로 1을 더해주어야함
    check_vec2.push_back(second_low);
    cnt++;
    go(second_low - 1, box[second_low - 1]);  // go( 원소값번째 첨자, 그 첨자에 해당하는 원소값 )
}

void printGo(int first_low, int second_low)
{
   if(cnt > box.size())
    {
        cnt = 0;
        return;
    }
    if(cnt > same_cnt)
    {
        if(check_vec1[0] == first_low+1) return;
    }
    check_vec1.push_back(first_low + 1);    // 0부터 시작하는 i 첨자로 넘기므로 1을 더해주어야함
    check_vec2.push_back(second_low);
    picked.push_back(first_low + 1);
    cnt++;
    printGo(second_low - 1, box[second_low - 1]);  // go( 원소값번째 첨자, 그 첨자에 해당하는 원소값 )
}
int main()
{
    int cnt_max = -1;

    // 첫째줄과 둘째줄이 같은 원소를 찾는 반복문
    for(vector<int>::size_type i = 0;i<box.size();i++)
    {
        if(i+1 == box[i])
        {
            picked.push_back(i+1);
            same_cnt++;
        }
    }

    for(vector<int>::size_type i =0;i<box.size();i++)
    {
        go(i, box[i]); // go(0, 3) 으로 넘김 // 실제로는 go(1(1번쨰), 1번째 원소값)
        sort(check_vec1.begin(), check_vec1.end());
        sort(check_vec2.begin(), check_vec2.end());
        if(check_vec1 == check_vec2)
        {
            count_vec[i] = cnt;
        }
        cnt = 0;
        check_vec1.clear();
        check_vec2.clear();
    }
    
    for(int i=0;i<count_vec.size();i++)
    {
        cnt_max = (cnt_max<count_vec[i])?count_vec[i] : cnt_max;
    }

    for(int i = 0;i<count_vec.size();i++)
    {
        if(cnt_max == count_vec[i])
        {
            printGo(i, box[i]);
            break;
        }
    }

    cnt_max+=same_cnt;

    cout<<cnt_max<<endl;

    sort(picked.begin(), picked.end());
  
    for(int i = 0;i<picked.size();i++)
    {
        cout << picked[i] << endl;
    }
    

    return 0;
}