
#include<iostream> 
#include <list> 
using namespace std; 
class Graph
{ 
	int V; // so node cua graph
	list<int> *adj; //mang con tro adj cua danh sach cac node lien ke (adjacent node)
public: 
	Graph(int V); 
	void addEdge(int v, int w); 
	void BFS(int s); 
	void connectedComponents(); 
	void DFSUtil(int v, bool visited[]);
}; 

Graph::Graph(int V) //onstructor - ham khoi tao
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) // them node w vao list cua node v (truong hop directed graph)
{ 
	adj[v].push_back(w); // 
} 

void Graph::BFS(int s) //breadth depth search
{ 
	//tao ra 1 mang bool cua cac node
	bool *visited = new bool[V]; 
	for(int i = 0; i < V; i++) 
		visited[i] = false; // nhung node nao chua duoc duyet qua thi danh dau false

	list<int> queue; // tao ra 1 queue de xu ly 

	visited[s] = true; // danh dau node truyen vao la true (dang dc duyet)
	queue.push_back(s); // day node nay vao queue 

	list<int>::iterator i; // con tro i dung de duyet cac node trong list adj[s] (cac node can ke node dang duyet)

	while(!queue.empty()) 
	{ 
		
		s = queue.front(); 
		cout << s << " "; //in ra node o dau queue
		queue.pop_front(); // roi xoa node o hang doi do

		for (i = adj[s].begin(); i != adj[s].end(); ++i) //duyet toan bo adjacent node cua node s
		{ 
			if (!visited[*i]) 
			{ 
			    //neu nhu node dang duyet chua duoc duyet qua lan nao
				visited[*i] = true; //dang dau la dang duoc duyet
				queue.push_back(*i); // day vao queue
			} 
		} 
	} 
} 
void Graph::connectedComponents() //in ra cac node lien ket voi nhau
{ 
    bool *visited = new bool[V]; //tao mang bool cua cac node de xem cac node da duoc duyet lan nao chua
    for(int v = 0; v < V; v++) 
        visited[v] = false; //mac dinh ban dau la false
    for (int v=0; v<V; v++) 
    { 
        if (visited[v] == false) 
        {  
            DFSUtil(v, visited); //in ra cac adjacent node lien ket voi node dang duoc duyet
  
            cout << "\n"; 
        } 
    } 
} 
  
void Graph::DFSUtil(int v, bool visited[]) //tham so truyen vao la node dc duyet va mang bool cua graph
{ 
    visited[v] = true; //danh dau node duoc duyet la true va in ra node do
    cout << v << " "; 

    list<int>::iterator i; //con tro i dung de duyet adjacent list cua node v
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            DFSUtil(*i, visited); // thuc hien goi de quy ham neu node chua duoc duyet bao gio
} 
// Driver program to test methods of graph class 
int main() 
{ 
	// Create a graph given in the above diagram 
	Graph g(4); 
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(1, 2); 
	g.addEdge(2, 0); 
	g.addEdge(2, 3); 
	g.addEdge(3, 3); 

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n"; 
	g.BFS(2); 

	return 0; 
} 

