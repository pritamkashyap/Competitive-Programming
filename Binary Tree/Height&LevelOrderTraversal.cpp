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



class node {

public:
	int data;
	node *left;
	node *right;

	node (int d) {
		data = d;
		left = NULL;
		right = NULL;
	}

};




node *buildTree() {

	int d;
	cin >> d;


	if (d == -1) {
		return NULL;
	}

	node * root = new node(d);

	root -> left = buildTree();
	root -> right = buildTree();

	return root;

}



int height(node *root) {
	if (root == NULL) {
		return 0;
	}

	int h1 = height(root-> left);
	int h2 = height(root -> right);
	return max(h1, h2) + 1;



}


void printklevel(node *root, int k) {
	if (root == NULL ) {
		return;
	}
	if (k == 1) {
		cout << root->data << " ";
		return;
	}

	printklevel(root->left, k - 1);
	printklevel(root-> right, k - 1);
	return ;
}
void printAlllevels(node * root) {
	int H = height(root);

	for (int i = 1 ; i <= H ; i++) {
		printklevel(root, i);
		cout << endl;
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
		node *root = buildTree();

		int H = height(root) << endl;
		printAlllevels(root);



	}


	return 0;
}


