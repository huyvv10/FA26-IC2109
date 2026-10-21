#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#define MAX 100
using namespace std;

class Graph{
	private:
		int size;
		int adj[MAX][MAX];
	public:
		Graph(){
			size=0;
		}
		
		int getSize(){
			return size;
		}
		
		void loadGraph(const string& fName){
			ifstream fin(fName);
			if (!fin.is_open()){
				cout<<"Can not open "<<fName<<endl; return;
			}
			fin>>size;
			if (size<0 || size>MAX) return;
			for (int i=0; i<size; i++)
				for (int j=0; j<size; j++)
					fin>>adj[i][j];
					
			//Mirror via main diagonal
			for (int i=0; i<size; i++)
				for (int j=0; j<size; j++)
					adj[j][i]=adj[i][j];		
			
			fin.close();		
		}
		
		void displayGraph(){
			for (int i=0; i<size; i++){
				for (int j=0; j<size; j++)
					cout<<adj[i][j]<<" ";
				cout<<endl;	
			}
			cout<<endl;	
		}

		void visit(char v){
			cout<<v<<" ";
		}		
		
		int toInt(char c){
			return (int)(c-65);
		}
		
		char toChar(int i){
			return (char)(i+65);			
		}
		
		void BFS(char v){
			queue<int> myQ;
			bool visited[size]={false};
			myQ.push(toInt(v));
			while (!myQ.empty()){
				int p = myQ.front();
				visit(toChar(p));
				visited[p]=true;
				myQ.pop();
				for (int i=0; i<size; i++)
					if (!visited[i] && adj[i][p]!=0){
						myQ.push(i);
						visited[i]=true;
					} 
			}
		}
		
		//Return the degree of a vertex v
		int deg(char v){
			int count=0;
			for (int i=0; i<size; i++)
				if (adj[i][toInt(v)] != 0) count++;
			return count;	
		}
		
		void DFS_Visit(char v, bool visited[]){
			visit(v);
			visited[toInt(v)]=true;
			for (int i=0; i<size; i++)
				if (!visited[i] && adj[i][toInt(v)]!=0)
					DFS_Visit(toChar(i), visited);
		}
		
		void DFS(char v){
			bool visited[size]={false};
			DFS_Visit(v, visited);
		}
};

int main(){
	Graph myG;
	myG.loadGraph("Graph.txt");
	myG.displayGraph();
	cout<<"--BFS--"<<endl;
	char startVertex = 'G';
	cout<<"Start traversal by BFS from: "<<startVertex<<endl;
	myG.BFS(startVertex);
	cout<<endl<<endl;
	for (int i=0; i<myG.getSize(); i++)
		cout<<"The degree of "<<myG.toChar(i)<<": "
			<<myG.deg(myG.toChar(i))<<endl;
	cout<<"\nDFS start from vertex: "<<startVertex<<endl;
	myG.DFS(startVertex);		
	return 0;
}
