#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N;
int map[20][20];
int player_size = 2;
int dy[] = { 0,0,1,-1 }, dx[] = { 1,-1,0,0 };
int timer = 0;
struct point {
	int y, x;
	int dist;
};
struct cmp
{
	bool operator() (point a, point b) {
		if (a.dist == b.dist) {
			if (a.y == b.y) {
				return a.x > b.x;
			}
			return a.y > b.y;
		}
		return a.dist > b.dist;
	}
};
point player;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9) {
				map[i][j] = 0;
				player = { i,j,0 };
			}
		}
	}
}

int bfs() {
	priority_queue<point, vector<point>, cmp>pq;
	pq.push(player);
	int visit[20][20];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visit[i][j] = 21e8;
		}
	}
	visit[player.y][player.x] = 0;
	while (!pq.empty())
	{
		point now = pq.top();
		pq.pop();
		if (map[now.y][now.x] < player_size && map[now.y][now.x] != 0) {
			map[now.y][now.x] = 0;
			player = { now };
			return 1;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			int nextcost = visit[now.y][now.x] + 1;
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
			if (visit[ny][nx] <= nextcost) continue;
			if (map[ny][nx] > player_size) continue;
			visit[ny][nx] = nextcost;
			pq.push({ ny,nx,nextcost });
		}
		/*for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if(visit[i][j] == 21e8)cout  << "X ";
				else cout << visit[i][j] << " ";
			}
			cout << "\n";
		}*/
	}
	return 0;
}

int main() {
	input();
	int exp = 0;
	while (bfs()) {
		exp++;
		timer += player.dist;
		if (exp == player_size) {
			player_size++;
			exp = 0;
		}
	}
	cout << timer;

	return 0;
}