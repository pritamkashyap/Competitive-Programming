/******************************************
* AUTHOR : PRITAM KUMAR *

* INSTITUTION : BIT SINDRI *
******************************************/
#include <bits/stdc++.h>
using namespace std;


#define int long long int
#define N 100005
#define MOD 1000000007
#define dd double
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define ld long double
#define P pair<int,int>


template<typename T>

class Graph {

	map<T, list<T>> l;
public:
	void addEdge(int x, int y) {
		l[x].pb(y);
		l[y].pb(x);
	}




	void dfs_helper(T src, map<T, bool> &visited) {
		cout << src << " ";
		visited[src] = true;

		for (T nbr : l[src]) {
			if (!visited[nbr]) {
				dfs_helper(nbr, visited);

			}
		}
	}

	void dfs(T src) {

		map<T, bool> visited;
		for (auto p : l) {
			T node = p.F;
			visited[node] = false;
		}

		dfs_helper(src, visited);


	}


};


int32_t main() {


#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {


		Graph <int> g;

		//Graph <int>g;
		int n;
		cin >> n;

		for (int i = 0 ; i < n; i++) {
			int j, k;
			cin >> j >> k;
			g.addEdge(j, k);

		}





		g.dfs(0);
		cout << endl;


	}
	return 0;
}
