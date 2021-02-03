#include <iostream>
#include <vector>

using namespace std;
vector < vector<int> > space;
vector<int> amount;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int checkSpace(int width, int height)
{
    int cnt = 0;
    for(int i = 0;i < height; i++){
        for(int j= 0;j < width;j++){
            if(space[i][j]) {
                cnt++;
            }
        }
    }
    return cnt;
}

void bfs(int y, int x, int width, int height) {
    if(space[y][x] == 2){
        space[y][x] = 0;
        for(int i=0;i<4;i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx >= 0 && ny >= 0 && nx < width && ny < height)
                bfs(ny, nx, width, height);
        }
    }
    else if(space[y][x] == 1 && space[y][x] == 0) return;
}

bool checkCloseUnit(int y, int x, int width, int height)
{
    if(x > 0 && space[y][x - 1] == 0)           return true;
    if(y > 0 && space[y - 1][x] == 0)            return true;
    if(x < (width - 1) && space[y][x + 1] == 0)   return true;
    if(y < (height - 1) && space[y + 1][x] == 0)  return true;
    return false;
}

void airSwap(int y, int x)
{
    if(space[y][x] == 3)
        space[y][x] = 0;
}

int main() {
    int height;
    int width;
    
    int worldCnt = 0;
    int temp;
    
    cin >> height;
    cin >> width;

    vector< vector<int> > funcSpace(height);
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cin >> temp;
            funcSpace[i].push_back(temp);
        }
    }

    space = funcSpace;

    //공기로 입력된곳을 2로 채우기
    for(int i = 0; i < height ; i++){
        for(int j = 0; j < width ; j++){
            if(space[i][j] == 0){
                space[i][j] = 2;
            }
        }
    }

    //빈공간을 찾고 나머지 공기롤 변환
    bfs(0,0, width, height);

    while(checkSpace(width, height) != 0){
        amount.push_back(checkSpace(width, height));
        // 가장자리 3으로 변환
        for(int i = 0; i < height ; i++){
            for(int j = 0; j < width ; j++){
                if(space[i][j] == 1 && checkCloseUnit(i, j, width, height)){
                space[i][j] = 3;
                }
            }
        }

        //3으로 변환된곳을 녹임
        for(int i = 0; i < height ; i++){
            for(int j = 0; j < width ; j++){
                airSwap(i, j);
            }
        }

        //빈공간 공기로 변환
        for(int i = 0; i < height ; i++){
            for(int j = 0; j < width ; j++){
                bfs(i, j, width, height);
            }

        }
        worldCnt++;
    }
    
    cout << worldCnt << endl;
    cout << amount.back() << endl;
   
    return 0;
}