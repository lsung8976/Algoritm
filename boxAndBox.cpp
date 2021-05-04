#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int temp;
    cin >> n;
   
    vector<int> box;
    
    vector<int> dp(n, 1);

    while(n--)
    {
        cin >> temp;
        box.push_back(temp);
    }

    for(int i=1;i<box.size();i++)
    {
        for(int j=i;j>=0;j--)
        {
            if(box[i] > box[j])
            {
                dp[i] += dp[j];
                break;
            }
        }
    }

    sort(dp.begin(), dp.end(), greater<int>());
    
    cout << dp[0] << endl;

    return 0;
}