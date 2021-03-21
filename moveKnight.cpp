#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int p[8][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };

vector< vector<int> > plate;
queue<int> q; // queue 큐 

int length;


void prtPlate()
{
    for(int i = 0; i < length; i++)
    {
        for(int j = 0;j < length;j ++)
        {
            cout << plate[i][j] <<  " ";
        }
        cout << endl;
    }
    
}

bool chkPlate()
{
    for(int i=0; i < length; i++)
    {
        for(int j =0;j< length;j ++)
        {
            if(plate[i][j] == 0) return false;
        }
    }
    return true;
}

void go(int x, int y, int cnt)
{
    if(chkPlate()) return;
    plate[x][y] = cnt++;
    for(int i=0;i<8;i++)
    {
        int nx = p[i][0] + x;
        int ny = p[i][1] + y;
        if(nx >=0 && ny >= 0 && nx < length && ny < length)
        {
            if(plate[nx][ny] == 0)
            {
                go(nx, ny, cnt);
            }
        }
    }
    return;
}

int main()
{
    int c;  //케이스 수
    int l; // 체스판 길이;
    int x, y;// 출발 위치;
    int dx, dy;//도착 위치;
    
    cin >> c;   //케이스 수 입력

    while(c--)
    {
        int cnt = 0;

        cin >> l;
        vector< vector<int> > fplate(l, vector<int> (l, 0)); //판 생성


        cin >> x >> y;

        cin >> dx >> dy;

        plate = fplate;
        length = l;
        
        if(x != dx || y != dy)
        {
            q.push(x);
            q.push(y);
            
            while(!q.empty())
            {
                int cx = q.front(); q.pop();
                int cy = q.front(); q.pop();
                for(int i=0;i<8;i++)
                {
                    int nx = p[i][0] + cx; 
                    int ny = p[i][1] + cy;
                    if(nx >=0 && ny >= 0 && nx < length && ny < length)
                    {
                        if(plate[nx][ny] == 0)
                        {
                            q.push(nx);
                            q.push(ny);
                            plate[nx][ny] = plate[cx][cy] + 1;
                        }
                    }
                }
            }

            cout << plate[dx][dy] << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        

        
    }

    return 0;
}