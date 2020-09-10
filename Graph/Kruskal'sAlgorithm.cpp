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
int id[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];



void initialize()
{
	for (int i = 0; i < MAX; ++i)


		id[i] = i;
}
int root(int x)
{
	while (id[x] != x)
	{
		id[x] = id[id[x]];
		x = id[x];
	}
	return x;
}
void union1(int x, int y)
{
	int p = root(x);
	int q = root(y);
	id[p] = id[q];
}



long long kruskal(pair<long long, pair<int, int> > p[])
{
	int x, y;
	long long cost, minimumCost = 0;
	for (int i = 0; i < edges; ++i)
	{
// Selecting edges one by one in increasing order from the beginning
		x = p[i].second.first;
		y = p[i].second.second;
		cost = p[i].first;
// Check if the selected edge is creating a cycle or not
		if (root(x) != root(y))
		{
			cout << x << " " << y << " " << cost << endl;
			minimumCost += cost;
			union1(x, y);
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
	w(t) {

		int x, y;
		int weight, cost, minimumCost;
		initialize();
		cin >> nodes >> edges;
		for (int i = 0; i < edges; ++i)
		{
			cin >> x >> y >> weight;
			p[i] = make_pair(weight, make_pair(x, y));
		}
// Sort the edges in the ascending order
		sort(p, p + edges);
		minimumCost = kruskal(p);
		cout << minimumCost << endl;
	}


	return 0;
}


