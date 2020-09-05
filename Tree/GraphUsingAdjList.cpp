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



class Graph {

	int v;
	list<int> *l;
public:
	Graph(int v) {
		this -> v = v;
		l = new list<int>[v];
	}

	void addEdge(int x, int y) {
		l[x].pb(y);
		l[y].pb(x);
	}

	void printAdjList() {

		for (int i = 0 ; i < v; i++) {
			cout << "Vertex  " << i << "-->";

			for (int nbr : l[i]) {
				cout << nbr << ",";
			}

			cout << endl;

		}

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



		int n;
		cin >> n;
		Graph g(n);

		for (int i = 0 ; i < n; i++) {

			int m, l;
			cin >> m >> l;
			g.addEdge(m, l);

		}

		g.printAdjList();


	}
	return 0;
}
