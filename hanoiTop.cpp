#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
using namespace std;

stack<int> s1, s2 ,s3;
queue< pair<int, int> > q;

bool checkTop(stack<int> s)
{
    int num = 1;
    while(!s.empty())
    {
        int a = s.top(); s.pop();
        if(a != num++) return false;
    }
    return true;
}

void func(stack<int> &s1, stack<int> &s2, stack<int> &s3)
{
    if(s3.size() !=0 && checkTop(s3) == true) return;
    
    //1->2
    if(s2.empty() || s1.top() < s2.top())
    {
        s2.push(s1.top());
        s1.pop();
        func(s1, s2, s3);
    }
    //1->3
    if(s3.empty() || s1.top() < s3.top())
    {
        s3.push(s1.top());
        s1.pop();
        func(s1, s2, s3);
    }
    //2->3
    if(s3.empty() || s2.top() < s3.top())
    {
        s3.push(s2.top());
        s2.pop();
        func(s1, s2, s3);
    }
    //2->1
    if(s1.empty() || s2.top() < s1.top())
    {
        s1.push(s2.top());
        s2.pop();
        func(s1, s2, s3);
    }
    //3->1
    if(s1.empty() || s3.top() < s1.top())
    {
        s1.push(s3.top());
        s3.pop();
        func(s1, s2, s3);
    }
    //3->2
    if(s2.empty() || s3.top() < s2.top())
    {
        s2.push(s3.top());
        s3.pop();
        func(s1, s2, s3);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
    {
        s1.push(i);
    }

    func(s1, s2, s3);
    
    while(!s3.empty())
    {
        int a = s3.top();   s3.pop();
        cout << a << endl;
    }

    return 0;
}