#include "Maze.h"
#include <queue>

using namespace std;

#define INF 2345
static int dx[4] = {-1, 0, 1, 0};
static int dy[4] = {0, -1, 0, 1};

static Maze* maze;

void bfs(int x, int y)
{
	// alocare si initializare matrice de distante
	int** dist = new int*[maze->get_height()];
	for (int i = 0; i < maze->get_height(); i++) {
		dist[i] = new int[maze->get_width()];
		for (int j = 0; j < maze->get_width(); j++)
			dist[i][j] = INF;
	}
	dist[x][y] = 0;
	
	//declarare si initializare coada
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	//TODO: completati BFS
    while (!q.empty()) {
cout << q.front().first << " " << q.front().second <<endl;
        int i;
cout << "1";
        // add neighbors
        for (i=0; i<4; i++) {
            if (maze->is_walkable(q.front().first+dx[i], q.front().second+dy[i]) && dist[q.front().first+dx[i]][q.front().second+dy[i]] == INF) {
                q.push(make_pair(q.front().first+dx[i], q.front().second+dy[i]));
                dist[q.front().first+dx[i]][q.front().second+dy[i]] = 1 +
                    dist[q.front().first][q.front().second];
            }
        }
        
        q.pop();
    }

	// afisare matrice distanta
	for (int i = 0; i < maze->get_height(); i++) {
		for (int j = 0; j < maze->get_width(); j++)
			if (dist[i][j] == INF)
				cout<<"#"<<" ";
			else
				cout<<dist[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	std::ifstream in("robot.in");
	int m, n;
	in >> m >> n;

	maze = new Maze(m, n);
	in >> *maze;

	int x, y;
	in >> x >> y;
	bfs(x, y);

	delete maze;
	return 0;
}
