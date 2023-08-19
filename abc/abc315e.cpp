#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

vector<int> topological_sort(vector<vector<int>> graph) {
	int n = graph.size();
	vector<int> indegree(n);
	for (int i = 0; i < n; i++) for (int j : graph[i]) indegree[j]++;
	vector<int> res;
	queue<int> que;
	for (int i = 0; i < n; i++) if (indegree[i] == 0) que.push(i);
	while (!que.empty()) {
		int ver = que.front(); que.pop();
		res.push_back(ver);
		for (int i : graph[ver]) {
			indegree[i]--;
			if (indegree[i] == 0) que.push(i);
		}
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> graph(n, vector<int>());
	rep(i, n) {
		int c;
		cin >> c;
		rep(_, c) {
			int v;
			cin >> v;
			v--;
			graph[i].push_back(v);
		}
	}
	queue<int> que;
	que.push(0);
	vector<bool> f(n);
	while (!que.empty()) {
		int q = que.front(); que.pop();
		for (int i : graph[q]) {
			if (!f[i]) {
				f[i] = true;
				que.push(i);
			}
		}
	}
	vector<int> t = topological_sort(graph);
	vector<int> order(n);
	rep(i, n) order[t[i]] = i;
	vector<int> ans;
	for (int i = 1; i < n; i++) if (f[i]) ans.push_back(i);
	sort(ans.begin(), ans.end(), [&](int x, int y) {return order[x] > order[y]; });
	for (int i = 0; i < ans.size(); i++) cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
}
