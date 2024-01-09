#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
		vector<int> dist(V, 1e8);
		dist[S] = 0;
		for (int i = 0; i < V - 1; i++) {
			for (auto it : edges) {
				int u = it[0];
				int v = it[1];
				int wt = it[2];
				if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
				}
			}
		}
		// Nth relaxation to check negative cycle
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    cout<<"negative weight cycle found"<<endl;
				return { -1};
			}
		}


		return dist;
	}
};


int main() {

	int V,e;
	cin>>V>>e;
	vector<vector<int>> edges(e, vector<int>(3));

	 for (int i = 0; i < 5; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }


	int S = 0;
	Solution obj;
	vector<int> dist = obj.bellman_ford(V, edges, S);

	for (auto d : dist) {

		cout << d << " ";
	}
	cout << endl;


	return 0;
}
