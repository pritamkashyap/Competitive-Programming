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

	map < string, list<pair<string, int>>> mp1;

public :

	void addEdge(string x, string y, bool bidir, int wt) {

		mp1[x].pb(mp(y, wt));
		if (bidir) {
			mp1[y].pb(mp(x, wt));
		}

	}

	void printAdjList() {


		for (auto p : mp1) {
			string city = p.F;
			list<pair<string, int>> nbrs = p.S;

			cout << city << "-->";

			for (auto nbr : nbrs) {
				string dest = nbr.first;
				int dist = nbr.S;
				cout << dest << " " << dist << ",";

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



		Graph g;

		for (int i = 0 ; i < 5; i++) {

			string m, l;
			bool q;
			int w;
			cin >> m >> l >> q >> w;
			g.addEdge(m, l, q, w);

		}





		g.printAdjList();


	}
	return 0;
}
