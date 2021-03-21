//boj.kr/1012
#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > map;
int p[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int cnt = 0;    //지렁이 갯수

void go(int i, int j, int H, int W)
{
    map[i][j] = 0;

    for(int index=0;index<4;index++)
    {
        int ni = i + p[index][0];
        int nj = j + p[index][1];

        if(ni >= 0 && nj >= 0 && ni < H && nj < W)
        {
            if(map[ni][nj] == 1)
            {
                go(ni, nj, H, W);
            }
        }
    }
    return;
}

int main()
{
    int T;  //테스트 케이스
    int M;  //가로
    int N;  //세로
    int K;  //심겨져있는 배추 갯수

    
    int temp1;
    int temp2;  //입력 자료형
    
    scanf("%d", &T);

    while(T--)
    {
        scanf("%d", &M);    //가로입력
        scanf("%d", &N);    //세로입력
        scanf("%d", &K);    //배추 갯수입력

        vector< vector<int> > fmap(N, vector<int> (M, 0));
        map = fmap;

        for(int i = 0; i < K; i++) //배추 심기
        {
            scanf("%d", &temp1);
            scanf("%d", &temp2);
            map[temp2][temp1] = 1;  
        }


        for(int i=0;i < N;i++)
        {
            for(int j= 0;j < M;j++)
            {
                if(map[i][j] == 1)
                {
                    go(i, j, N, M); cnt++;
                    /*
                    for(int a=0;a<N;a++)
                    {
                        for(int b=0;b<M;b++)
                        {
                            cout << map[a][b] << " ";
                        }
                        cout << endl;
                    }
                    cout << endl;
                    */
                }
                
            }
        }
        cout << cnt << endl;
        cnt = 0;
    }

    return 0;
}