/******************************************
* AUTHOR : PRITAM KUMAR *

* INSTITUTION : BIT SINDRI *
******************************************/




#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long int
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(t)            int t; cin>>t; while(t--)
#define endl             '\n'
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;



class Graph {
	int v;
	list<pair<int, int> > l;

public:
	Graph(int v) {
		this->v = v;
	}
	void addEdge(int u, int v) {
		l.pb(mp(u, v));
	}

	int findset(int i, int parent[]) {

		if (parent[i] == -1) {
			return i;
		}
		return parent[i] = findset(parent[i], parent);
	}

	void unionset(int x, int y, int parent[], int rank[]) {
		int s1 = findset(x, parent);
		int s2 = findset(y, parent);


		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else {

				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}

	bool contains_cycle() {

		int *parent = new int[v];
		int *rank = new int[v];
		for (int i = 0 ; i <= v; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}

		for (auto edge : l) {
			int i = edge.ff;
			int j = edge.ss;

			int s1 = findset(i, parent);
			int s2 = findset(j, parent);

			if (s1 != s2) {
				unionset(s1, s2, parent, rank);
			}
			else {
				cout << "Same Parents " << s1 << " and " << s2 << endl;
				return true;
			}
		}

		delete [] parent;
		return false;

	}

};



void pritam()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}



int32_t main()
{

	pritam();
	w(t) {
		Graph g(4);
		g.addEdge(0, 1);
		g.addEdge(1, 2);
		g.addEdge(2, 3);
		//g.addEdge(3, 0);
		cout << g.contains_cycle();

	}


	return 0;
}


