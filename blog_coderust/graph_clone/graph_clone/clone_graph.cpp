//Implement clone(deep copy) of a graph
#include<iostream>
#include<vector>
#include<map>
#include<queue>


using namespace std;

struct GraphNode {
	int val;
	vector<GraphNode*> neighbours;
};

GraphNode* clone_graph(GraphNode* src) {
	//Have a map that stores which nodes are cloned.
	map<GraphNode*, GraphNode*>m;
	//queue for accessing the node
	queue<GraphNode*> q;

	//Clone node
	GraphNode* node;

	q.push(src);
	node = new GraphNode();
	node->val = src->val;
	//Mapping it in the map which nodes are cloned.
	m[src] = node;

	while (!q.empty()) {
		GraphNode* u = q.front();
		q.pop();
		vector<GraphNode *> v = u->neighbours;
		int n = v.size();
		for (int i = 0; i < n; i++) {
			if (m[v[i]] == NULL) {
				node = new GraphNode();
				node->val = v[i]->val;
				m[v[i]] = node;
				q.push(v[i]);
			}
			m[u]->neighbours.push_back(m[v[i]]);
		}
		
	}
	return m[src];
}

GraphNode* build_graph() {
	GraphNode* node1 = new GraphNode();
	GraphNode* node2 = new GraphNode();
	GraphNode* node3 = new GraphNode();
	GraphNode* node4 = new GraphNode();

	node1->val = 1;
	node2->val = 2;
	node3->val = 3;
	node4->val = 4;

	vector<GraphNode*> v;
	v.push_back(node2);
	v.push_back(node4);
	node1->neighbours = v;
	v.clear();

	v.push_back(node1);
	v.push_back(node3);
	node2->neighbours = v;
	v.clear();
	v.push_back(node2);
	v.push_back(node4);
	node3->neighbours = v;
	v.clear();
	v.push_back(node3);
	v.push_back(node1);
	node4->neighbours = v;
	return node1;

}

void bfs(GraphNode* src) {
	map<GraphNode*, bool>visit;
	queue<GraphNode*> q;
	q.push(src);
	visit[src] = true;
	while (!q.empty()) {
		GraphNode* u = q.front();
		cout << "Value of node." << u->val << endl;
		q.pop();
		vector<GraphNode*> v = u->neighbours;
		int n = v.size();
		for (int i = 0; i < n; i++) {
			if (!visit[v[i]]) {
				visit[v[i]] = true;
				q.push(v[i]);
			}
		}
	}
	cout << endl;
}

int main() {
	GraphNode *src = build_graph();
	cout << "BFS Traversal before cloning\n";
	bfs(src);
	GraphNode *newsrc = clone_graph(src);
	cout << "BFS Traversal after cloning\n";
	bfs(newsrc);

	return 0;
}