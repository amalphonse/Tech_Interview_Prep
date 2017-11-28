//bfs for hacker rank.

#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>


using namespace std;


//adjacency list adj variable
list<int> *adj;

//visited boolean
bool *visited;

//add edge to the vertex.
void add_edge(int u, int v) {
	cout << "u-1: " << u - 1 << " v-1: " << v - 1<<endl;
	adj[u-1].push_back(v-1);
	adj[v - 1].push_back(u - 1);
}

//fucntion that takes in the startig point and the 
//nnumber of vertices.
void bfs(int s, int n) {
//s = s - 1
	cout << "s: " << s << endl;
	visited = new bool[n];
	int *dist = new int[n];
	//initialising all the nodes as visited false.
	for (int i = 0; i < n; i++) {
		visited[i] = false;
		cout << "i:" << i << " visited[i]" << visited[i] << endl;
	}

	//distance initializing to all -1
	for(int i = 0; i < n; i++) {

		dist[i] = -1 ;
		cout << "i:"<<i<<" dist[i]" << dist[i] << endl;
	}
	int len_d = 0;
	//queue for bfs.
	queue<int>q;
	list<int>::iterator i;
	visited[s] = true;
	dist[s]=0;
	cout << "s: "<<s<<" visited[s] " << visited[s] << endl;
	q.push(s);
	cout << "In the queue: " << endl;
	while (!q.empty()) {
		s = q.front();
		cout << "s: "<<s << endl;
		q.pop();
		
		for (i = adj[s].begin(); i != adj[s].end(); i++) {
			cout << "i: " << *i << endl;
			
			if (!visited[*i]&&dist[*i]==-1) {
				dist[*i] = dist[s]+ 1;
				len_d++;
				visited[*i] = true;
				q.push(*i);
				cout <<"*i: "<<*i<<" dist[*i]: " << dist[*i] << endl;
			}
		}
	}
	//int size = sizeof(dist) / sizeof(dist[0]);
	for (int i = 0; i <n; i++) {
		if (dist[i] == -1) {
			cout << "i: " << i << " dist[i]:" << dist[i] << endl;
		}
		else if (dist[i] != 0) {
			cout << "i: " << i << " dist[i]:" << dist[i]*6 << endl;
		}
	}

}

int main() {
	int n = 4;
	int m = 2;
	//int n = 3;
	//int m = 1;
	
	adj = new list<int>[n];
	add_edge(1, 2);
	add_edge(1, 3);
	//add_edge(3, 1);
	//add_edge(2, 3);
	//int s = 2;
	int s = 1;
	bfs(s-1, n);
	//int size = sizeof(dist) / sizeof(dist[0]);
	//cout << "size: " << size<<endl;
	//for (int i = 0; i <size; i++) {
	//	cout << dist[i] << endl;
	//}

	return 0;
}