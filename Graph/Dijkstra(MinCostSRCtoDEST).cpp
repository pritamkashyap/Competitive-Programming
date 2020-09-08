#include<bits/stdc++.h>
using namespace std;

class Graph {

	int v;
	list<pair<int, int> > *l;

public:
	Graph(int v) {
		this->v = v;
		l = new list<pair<int, int> >[v];
	}
	void addEdge(int x, int y, int cost, bool bidir = false) {
		l[x].push_back(make_pair(y, cost));
		if (bidir) {
			l[y].push_back(make_pair(x, cost));
		}
	}




	void printAdj() {

		for (int i = 0 ; i < v; i++) {
			cout << i << " --> ";
			for (auto p : l[i]) {
				cout << " ( " << p.first << "," << p.second << " ) ";
			}
			cout << endl;
		}

	}


	void dijkstra(int src , int dest ) {
		int *dist = new int[v];

		for (int i = 0; i < v; i++) {
			dist[i] = INT_MAX;
		}
		dist[src] = 0;
		set<pair<int, int> > s;
		s.insert(make_pair(0, src));

		while (!s.empty()) {
			auto p  = *(s.begin());
			int parent = p.second;
			s.erase(s.begin());

			for (auto childPair : l[parent]) {

				int childNode = childPair.first;
				int edgeLen = childPair.second;

				if (dist[parent] + edgeLen < dist[childNode]) {

					auto f = s.find(childPair);
					if (f != s.end()) {
						s.erase(f);
					}


					dist[childNode] = dist[parent] + edgeLen;
					s.insert(make_pair(dist[childNode], childNode));
				}
			}
		}
		// for (int i = 0; i < v; i++) {
		// 	cout << "Node is " << i << " and at a dist " << dist[i] << endl;
		// }
		if (dist[dest] == INT_MAX) {
			cout << "-1" << endl;
		}
		else {
			cout << dist[dest] << endl;
		}
	}
};

int main() {


	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int city, roads, que;
	cin >> city >> roads >> que;

	Graph g(city + 1);

	for (int i = 0; i < roads; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		g.addEdge(x, y, cost);
	}
	g.printAdj();



	for (int i = 0 ; i < que; i++) {
		int source, dest;
		cin >> source >> dest;
		g.dijkstra(source, dest);
	}





}
