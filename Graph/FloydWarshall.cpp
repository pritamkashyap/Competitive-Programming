
#include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
#define INF 99999
#define V 5

using namespace std;
template<typename T>
class Graph
{
	unordered_map<T, list<pair<T, int> > > m;
	int graph[V][V];
	int parent[V][V];
public:
	//Adjacency list representation of the graph
	void addEdge(T u, T v, int dist, bool bidir = false)
	{
		m[u].push_back(make_pair(v, dist));
		/*if(bidir){
		m[v].push_back(make_pair(u,dist));
		}*/
	}
	//Print Adjacency list
	void printAdj()
	{
		for (auto j : m)
		{
			cout << j.first << "->";
			for (auto l : j.second)
			{
				cout << "(" << l.first << ", " << l.second << ")";
			}
			cout << endl;
		}
	}
	void matrix_form(int u, int v , int w)
	{
		graph[u - 1][v - 1] = w;
		parent[u - 1][v - 1] = u;
		return;
	}
	//Adjacency matrix representation of the graph
	void matrix_form2()
	{
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (i == j)
				{
					graph[i][j] = 0;
					parent[i][j] = 0;
				}
				else
				{
					graph[i][j] = INF;
					parent[i][j] = 0;
				}
			}
		}
		return;
	}
	//Print Adjacency matrix
	void print_matrix()
	{
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (graph[i][j] == INF)
					cout << "INF" << " ";
				else
					cout << graph[i][j] << " ";
			}
			cout << endl;
		}
	}
	//Print predecessor matrix
	void printParents(int p[][V])
	{
		cout << "Parents Matrix" << "\n";
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (p[i][j] != 0)
					cout << p[i][j] << " ";
				else
				{
					cout << "NIL" << " ";
					//cout<<p[i][j]<<“ ";"

				}
			}
			cout << endl;
		}
	}
	//All pair shortest path matrix i.e D
	void printSolution(int dist[][V])
	{
		cout << "Following matrix shows the shortest distances"
		     " between every pair of vertices" << "\n";
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (dist[i][j] == INF)
					cout << "INF" << " ";
				else
					cout << dist[i][j] << " ";
			}
			cout << endl;
		}
	}
	//Print the shortest path , distance and all intermediate vertex
	void print_path(int p[][V], int d[][V])
	{
		// cout<<“Hello”<<“\n”;
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				// cout<<“Hello1”<<“\n”;
				if (i != j)

				{
					cout << "Shortest path from " << i + 1 << " to " << j + 1 << " => ";
					cout << "[Total Distance : " << d[i][j] << " ( Path : ";

					int k = j;
					int l = 0;
					int a[V];
					a[l++] = j + 1;
					while (p[i][k] != i + 1)
					{

						a[l++] = p[i][k];
						k = p[i][k] - 1;
					}
					a[l] = i + 1;

					for (int r = l; r > 0; r--)
					{

						cout << a[r] << " —— > ";
					}
					cout << a[0] << " )";
					cout << endl;
				}
			}
		}
	}
	//Floyd Warshall Algorithm
	void floydWarshall ()
	{
		int dist[V][V], i, j, k;
		int parent2[V][V];
		for (i = 0; i < V; i++)
			for (j = 0; j < V; j++)
				dist[i][j] = graph[i][j];
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				parent2[i][j] = parent[i][j];
			}
		}
		for (k = 0; k < V; k++)
		{
			for (i = 0; i < V; i++)
			{
				for (j = 0; j < V; j++)
				{
					if (dist[i][k] + dist[k][j] < dist[i][j])
					{
						dist[i][j] = dist[i][k] + dist[k][j];
						parent2[i][j] = parent2[k][j];
					}
				}
			}
		}
		printSolution(dist);
		cout << "\n\n";
		printParents(parent2);
		cout << "\n\n";
		cout << "All pair shortest path is given below : " << endl;;
		print_path(parent2, dist);
	}
};
//Main Function
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Graph<int> g;
	g.matrix_form2();


	g.addEdge(1, 2, 3);
	g.matrix_form(1, 2, 3);
	g.addEdge(1, 3, 8);
	g.matrix_form(1, 3, 8);
	g.addEdge(1, 5, -4);
	g.matrix_form(1, 5, -4);
	g.addEdge(2, 4, 1);
	g.matrix_form(2, 4, 1);
	g.addEdge(2, 5, 7);
	g.matrix_form(2, 5, 7);
	g.addEdge(3, 2, 4);
	g.matrix_form(3, 2, 4);
	g.addEdge(4, 3, -5);
	g.matrix_form(4, 3, -5);
	g.addEdge(4, 1, 2);
	g.matrix_form(4, 1, 2);
	g.addEdge(5, 4, 6);
	g.matrix_form(5, 4, 6);
	cout << "Graph in the form of adjecency list representation : " << "\n";
	g.printAdj();
	cout << "Graph in the form of matrix representation : " << "\n";
	g.print_matrix();
	cout << "\n\n";
	g.floydWarshall();
}
