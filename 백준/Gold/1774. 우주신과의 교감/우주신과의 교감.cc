#include <bits/stdc++.h>

using namespace std;

struct Pos { int x, y; };
struct Edge { int num1, num2; double cost; }; // num1 우주신과 num2 우주신 사이의 연결 통로. 세 개의 데이터를 묶을 수 있도록 구조체 선언함.
vector<int> parent;
 
// a 정점의 부모가 누구인지. (즉, a 가 현재 속해있는 트리의 루트 리턴)
// 그와 동시에 만약 이 함수를 호출하기 전인 사전에 루트의 부모가 바뀌었다면(즉, 다른 그래프에 속하도록 병합되었다면) 그것에 대한 자식들 수정까지 모두 이루어질 수 있도록 재귀 호출에서 대입 연산도 해준다. 
int getParent(int a) {
	if (a == parent[a]) return a;
	return parent[a] = getParent(parent[a]);
}

// 두 그래프 병합 (루트가 더 작은 쪽으로 병합하기로 함)
// 병합되는쪽의 루트의 부모를 바꿔주면 된다. 
void connect(int a, int b) {
	int par_a = getParent(a);
	int par_b = getParent(b);
	if (par_a < par_b) parent[par_b] = par_a;
	else parent[par_a] = par_b;
}

// 같은 그래프에 속해있는지
bool isConnected(int a, int b) {
	int par_a = getParent(a);
	int par_b = getParent(b);
	if (par_a == par_b) return true;
	else return false;
}

bool cmp(const Edge& a, const Edge& b) {
	return a.cost < b.cost;
}

double getDistance(Pos pos1, Pos pos2) {
	return sqrt(pow((pos1.x - pos2.x), 2) + pow((pos1.y - pos2.y), 2));
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N;
	cin >> M;
	vector<Pos> pos(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> pos[i].x;
		cin >> pos[i].y;
	}
	vector<pair<int, int>> connected(M);
	for (int i = 0; i < M; ++i) {
		cin >> connected[i].first;
		cin >> connected[i].second;
	}

    // 1. 두 우주신 간의 거리를 모두 구한다. 즉 nC2 개의 간선 구해서 edges 배열에 저장!  
    // nC2 조합 구하는게 아래와 같이 되는 이유는.. [1,2,3,4] 의  2개 뽑는 조합은 (1,2), (1,3), (1,4), (2,3), (2,4), (3,4) 이 된다는 것을 생각하면 이해할 수 있을 것이다. 
	vector<Edge> edges;
	for (int i = 1; i <= N - 1; ++i)
		for (int j = i + 1; j <= N; ++j)
			edges.push_back({ i, j, getDistance(pos[i], pos[j]) });
	// 2. 정렬 (거리 별 정렬)
    sort(edges.begin(), edges.end(), cmp);

    // 3. 오름차순 정렬 되었으니 최소 간선부터 연결 (단, 부모가 같지 않은 노드만 연결. 즉 같은 그래프에 속해있지 않은 것만) 
	parent.resize(N + 1);
	for (int i = 1; i <= N; ++i)
		parent[i] = i;
	for (int i = 0; i < M; ++i)
		connect(connected[i].first, connected[i].second); // 문제에서 주어진, 이미 연결되어 있다는 우주신들 연결 처리
	double connect_cost = 0.0f;
	for (int i = 0; i < edges.size(); ++i) {
		if (isConnected(edges[i].num1, edges[i].num2) == false) {
			connect(edges[i].num1, edges[i].num2);
			connect_cost += edges[i].cost;
		}
	}

    // 4. 소수점 둘째자리까지 출력하도록
	cout << fixed;
	cout.precision(2);
	cout << connect_cost;
}