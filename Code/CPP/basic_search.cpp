#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph {
public:
    map<T, bool> visited;
    map<T, list<int> > adj;
 
    // function to add an edge to graph
    void addEdge(T v, T w){
    	adj[v].push_back(w);
    }
 
    // DFS traversal of the vertices
    // reachable from v
    void DFS(T v){

    	visited[v] = true;
		cout << v << " ";

		// Recursive

		// for(auto w : adj[v]){
		// 	if(!visited[w])
		// 		DFS(w);
		// }

		// Iterative

		stack<T> st;
		st.push(v);

		while(!st.empty()){

			T v = st.top();
			st.pop();

			if(!visited[v]){
				visited[v] = true;
				cout << v << " ";
			}

			for(T w: adj[v]){
				if(!visited[w])
					st.push(w);
			}

		}

		cout << endl;
    }

    void BFS(T v){
    	visited[v] = true;
    	cout << v << " ";

    	queue<T> q;
    	q.push(v);

    	while(!q.empty()){
    		T v = q.front();
    		for(T w: adj[v]){
    			if(!visited[w]){
    				visited[w] = true;
    				cout << w << " ";
    				q.push(w);
    			}
    		}
    		q.pop();
    	}
    	cout << endl;
    }

    // void IDS_DFS(T v,T goal, int limit){
    // 	if(v == goal)
    // 		return true;

    // 	if(limit <= 0)
    // 		return false;

    // 	for(T w : adj[v]){
    // 		if(!visited[w]){
    // 			visited[w]
    // 		}
    // 	}
    // }

    // void IDS(T v,int max_depth){

    // 	for()

    // }
};


int main()
{
	Graph<char> g;

	g.addEdge('A','B');
	g.addEdge('A','C');
	g.addEdge('A','D');
	
	g.addEdge('B','E');
	g.addEdge('B','F');
	g.addEdge('B','G');
	
	g.addEdge('C','F');
	g.addEdge('C','G');
	
	g.addEdge('D','G');
	g.addEdge('D','H');
	
	g.addEdge('E','I');
	g.addEdge('E','J');
	
	g.addEdge('F','E');
	g.addEdge('F','G');
	g.addEdge('F','I');

	g.addEdge('G','H');
	g.addEdge('G','J');

	g.addEdge('H','C');

	g.DFS('A');
	// g.BFS('A');


}