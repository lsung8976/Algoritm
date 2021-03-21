#include <iostream>
#include <cstring>
#include <vector>
#include <utility>

using namespace std;

int main() {
	int num;//총인원수
    int smax = -987654321;
    int fmin = 987654321;
	vector<string> sTimeVec(num);
    vector< pair<int, int> > sIntVec(num);
    vector<string> fTimeVec(num);
    vector< pair<int, int> > fIntVec(num);

	cin >> num; //  인원수 입력;

	for(int i=0;i<num;i++)
	{
        char temp;
		cin >> sTimeVec[i];
        cin >> temp;
        cin >> fTimeVec[i];
	}

    for(int i=0;i<num;i++)
	{
        //시작
        string temp;
        temp = sTimeVec[i].substr(0, 2);    //시간
        sIntVec[i].first = stoi(temp);
        temp.clear();

        temp = sTimeVec[i].substr(3, 2);    //분
        sIntVec[i].second = stoi(temp);

        temp.clear();
        //마침
        temp = fTimeVec[i].substr(0, 2);    //시간
        fIntVec[i].first = stoi(temp);
        temp.clear();

        temp = fTimeVec[i].substr(3, 2);    //분
        fIntVec[i].second = stoi(temp);
    }

    for(int i=0;i<num;i++)
	{
       smax = (smax < sIntVec[i].first * 100 + sIntVec[i].second) ? sIntVec[i].first * 100 + sIntVec[i].second : smax;
       fmin = (fmin > fIntVec[i].first * 100 + fIntVec[i].second) ? fIntVec[i].first * 100 + fIntVec[i].second : fmin;
    }
    if(smax > fmin)
    {
        printf("-1");
    }
    else
    {
        printf("%02d:%02d ~ %02d:%02d",smax/100, smax%100, fmin/100, fmin%100);
    }
    
    return 0;
}