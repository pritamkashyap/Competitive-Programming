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


const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];
long long prim(int x)
{
	priority_queue<PII, vector<PII>, greater<PII> > Q;
	int y;
	long long minimumCost = 0;
	PII p;
	Q.push(make_pair(0, x));
	while (!Q.empty())
	{
// Select the edge with minimum weight
		p = Q.top();
		Q.pop();
		x = p.second;
// Checking for cycle
		if (marked[x] == true)
			continue;
		minimumCost += p.first;
		marked[x] = true;
		for (int i = 0; i < adj[x].size(); ++i)
		{
			y = adj[x][i].second;
			if (marked[y] == false)
				Q.push(adj[x][i]);
		}
	}
	return minimumCost;
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


	int nodes, edges, x, y;
	long long weight, minimumCost;
	cin >> nodes >> edges;
	for (int i = 0; i < edges; ++i)
	{
		cin >> x >> y >> weight;
		adj[x].push_back(make_pair(weight, y));
		adj[y].push_back(make_pair(weight, x));
	}
// Selecting 1 as the starting node
	minimumCost = prim(1);
	cout << minimumCost << endl;
	return 0;


	return 0;
}


