#include<iostream>
#include<algorithm>
using namespace std;

int parent[10001];
bool visit[10001];
int T, N, A, B, u, v;

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> N;

		for (int i = 1; i <= N; i++)
		{
			visit[i] = false;
			parent[i] = i;
		}

		for (int i = 0; i < N - 1; i++)
		{
			cin >> A >> B;
			parent[B] = A;
		}

		cin >> u >> v;
		visit[u] = true;

		while (u != parent[u])
		{
			u = parent[u];
			visit[u] = true;
		}
		while (true)
		{
			if (visit[v])
			{
				cout << v << '\n';
				break;
			}
			v = parent[v];
		}

	}
}