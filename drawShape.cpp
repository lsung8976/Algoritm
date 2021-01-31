#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tailNumber(int index, vector<int> vec)
{
    vector<int> temp;
    for(int i = index; i < vec.size(); i++){
        temp.push_back(vec[i]);
    }
    for(int i = 0; i < index; i++)
    {
        temp.push_back(vec[i]);
    }
    return temp;
}

vector< vector<int> > trueVec;

int main()
{
    int listLen;  // list길이
    int listNum;   //집어넣을 list갯수
    int temp;
    bool chk;
    int cnt = 0;    // 카운트 갯수

    cin >> listLen; 
    vector<int> baseShape(listLen);

    for(int i=0;i<listLen;i++){
        cin >> baseShape[i];
    }

    cin >> listNum;
    vector< vector<int> > listVec(listNum); // 입력받은 또다른 리스트들 저장 벡터
    
    for(int i = 0; i < listNum ; i++){
        for(int j = 0; j < listLen; j++){
            cin >> temp;
            listVec[i].push_back(temp);
        }
    }

    for(int i=0;i<listNum;i++){
        chk = false;
        for(int j=0;j<listLen;j++){
            if(baseShape == tailNumber(j, listVec[i]))
                chk = true;
        }
        if(chk == true) {
            cnt++;
            trueVec.push_back(listVec[i]);
        }
    }

    
    for(int i = 0; i < baseShape.size(); i++){
        switch(baseShape[i]){
            case 1 : baseShape[i] = 3;
                break;
            case 2 : baseShape[i] = 4;
                break;
            case 3 : baseShape[i] = 1;
                break;
            case 4 : baseShape[i] = 2;
                break;
            default : break;
        }
    }
    reverse(baseShape.begin(),baseShape.end()); //base 다각형 모양을 거꾸로 변환

    for(int i=0;i<listNum;i++){
        chk = false;
        for(int j=0;j<listLen;j++){
            if(baseShape == tailNumber(j, listVec[i]))
                chk = true;
        }
        if(chk == true) {
            cnt++;
            trueVec.push_back(listVec[i]);
        }
    }

    cout << cnt << endl;
    for(int i=0;i<trueVec.size();i++){
        for(int j=0;j<listLen;j++){
            cout << trueVec[i][j] << " ";
        }
        cout << endl;
    }
   
    return 0;
}

