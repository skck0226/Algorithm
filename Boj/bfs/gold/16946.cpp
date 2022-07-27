#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int one = 0;
int n, m;
int arr[101][101];
int visited[101][101];
void bfs(int y, int x)
{
    queue<int> qy, qx;
    qy.push(y);
    qx.push(x);
    while (!qy.empty())
    {
        int vy = qy.front();
        qy.pop();
        int vx = qx.front();
        qx.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = vy + dy[i];
            int nx = vx + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (visited[ny][nx])
                continue;
            if (arr[ny][nx] == 1)
            {
                visited[ny][nx] = 1;
                arr[ny][nx] = 0;
                one--;
            }
            else if (arr[ny][nx] == 0)
            {
                visited[ny][nx] = 1;
                qy.push(ny);
                qx.push(nx);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                one++;
        }
    }
    int cnt = 0;
    int last = one;
    while (1)
    {
        for (int i = 0; i < n; i++)
        {
            memset(visited[i], 0, sizeof(visited[i]));
        }
        visited[0][0] = 1;
        bfs(0, 0);
        cnt++;
        if (one == 0)
        {
            cout << cnt << endl
                 << last << endl;
            return 0;
        }
        last = one;
    }
    return 0;
}