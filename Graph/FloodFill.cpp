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

#define M 8
#define N 8

long dx[] = { -1, 0, 1, 0};
long dy[] = {0, -1, 0, 1};



void printmat(int input[][N]) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << input[i][j] << " ";
		}
		cout << endl;
	}
}


void floodfill(int arr[][N], int i, int j, int ch, int color) {

	if (i < 0 || i >= M || j >= N) {
		return;
	}

	if (arr[i][j] != ch) {
		return;
	}

	arr[i][j] = color;

	for (int k = 0 ; k < 4; k++) {
		floodfill(arr, i + dx[k], j + dy[k], ch, color);
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



		int screen [M][N];

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cin >> screen[i][j];
			}

		}

		floodfill(screen, 4, 4, 2, 3);
		printmat(screen);


	}


	return 0;
}


