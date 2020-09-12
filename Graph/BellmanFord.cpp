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



vector<int> bellman_ford(int n, int src,
                         vector<vector<int>> edges ) {
	vector<int> dis(n + 1, INT_MAX - 1000);
	dis[src] = 0;

	//relax all the edges n-1 times
	for (int i = 0 ; i < n - 1; i++) {
		for (auto x : edges) {
			int from = x[0], to = x[1], weight = x[2];
			if (dis[to] > dis[from] + weight) {
				dis[to] = dis[from] + weight;
			}
		}
	}



	//negative weight cycle
	for (auto x : edges) {
		int from = x[0], to = x[1], weight = x[2];
		if (dis[to] > dis[from] + weight) {
			cout << "Negative Weight Cycle" << endl;
			exit(0);
		}
	}

	return dis;

}







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

		int n, m;
		cin >> n >> m;

		vector<vector<int>> edges;

		for (int i = 0 ; i < m; i++) {
			int from, to, weight;
			cin >> from >> to >> weight;
			edges.pb({from, to , weight});

		}
		vector<int> dis = bellman_ford(n, 1, edges);

		for (int i = 1 ; i <= n ; i++) {
			cout << "dis from src to " << i << " is " << dis[i] << endl;
		}

	}


	return 0;
}


