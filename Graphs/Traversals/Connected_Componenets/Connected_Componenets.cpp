#include<bits/stdc++.h>
#include<queue>

using namespace std;
//To print the graph
//sv starting vertex from where printing should start

void printBFS(int ** edges,int n,int sv,bool * visited){
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv]=true;
    while (!pendingVertices.empty()){
        int currentVertex=pendingVertices.front();
        pendingVertices.pop();
        cout<<currentVertex<<endl;
        for(int i=0;i<n;i++){
            if(i==currentVertex) continue;
            if(edges[currentVertex][i] == 1 && !visited[i]){
                pendingVertices.push(i);
                visited[i]=true;
            }
        }
    }
    
    
}
void printDFS(int ** edges,int n,int sv,bool * visited){
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(edges[sv][i]){
            if(visited[i]){
                continue;
            }
            printDFS(edges,n,i,visited);
        }
    }
}
void DFS(int ** edges,int n){
    bool * visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            printDFS(edges,n,i,visited);
        }
    }
    
}
void BFS(int ** edges,int n){
    bool * visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            printBFS(edges,n,i,visited);
        }
    }
}


int main()
{
    int n; //no. of vertices
    int e; //no. of edges
    cout<<"Enter no. of Vertices :";
    cin>>n;
    cout<<"Enter no. of Edges: ";
    cin>>e;
    //2-D Matrix
    int ** edges=new int*[n];
    //Initialzing all values to the zero removing Garbage value
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    //taking input from user as first vertex and second vertex and connectinng them
    for(int i=0;i<e;i++){
        cout<<"Enter first and second vertex"<<endl;
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    cout<<"Printing DFS"<<endl;
    DFS(edges,n);
    cout<<"Printint BFS"<<endl;
    BFS(edges,n);
    //TestCase 
    // INPUT
    // Enter no. of Vertices :7
    // Enter no. of Edges: 5
    // Enter first and second vertex
    // 0 2
    // Enter first and second vertex
    // 0 3
    // Enter first and second vertex
    // 2 3
    // Enter first and second vertex
    // 1 4
    // Enter first and second vertex
    // 5 6
    // OUTPUT
    // Printing DFS
    // 0
    // 2
    // 3
    // 1
    // 4
    // 5
    // 6
    // Printint BFS
    // 0
    // 2
    // 3
    // 1
    // 4
    // 5
    // 6

    
    
    return 0;
}