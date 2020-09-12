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
const int N = 100005, M = 22;
vector<int> gr[N];
int vis[N];
bool odd_cycle = 0;

void dfs(int curr, int par, int col) {

	// cout << curr << " " << par << " " << col << endl;
	vis[curr] = col;
	for (auto child : gr[curr]) {
		if (vis[child] == 0) {

			dfs(child, curr, 3 - col);
		}
		else if (child != par && col == vis[child]) {

			// //backedge and odd length<< cycle
			odd_cycle = 1;
		}
	}
	return;
}


void solve() {

	int i, j, k, n, m, ans = 0 , cnt = 0 , sum = 0;
	cin >> n >> m;

	for (i = 0 ; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].pb(y);
		gr[y].pb(x);

	}

	//for (int i = 0 ; i <= )

	dfs(1, 0, 1);

	if (odd_cycle) {
		cout << "Not Bipartite" << endl;
	}
	else {
		cout << "Bipartite" << endl;
	}
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
		solve();



	}


	return 0;
}


