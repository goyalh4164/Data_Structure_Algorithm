#include<bits/stdc++.h>
#include<queue>

using namespace std;
//To print the graph
//sv starting vertex from where printing should start

void printBFS(int ** edges,int n,int sv){
    queue<int> pendingVertices;
    bool * visited= new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
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
    
    //printing the Graph in BFS manner
    printBFS(edges,n,0);
    //Sample TestCase
    //INPUT
    // Enter no. of Vertices :8
    // Enter no. of Edges: 9
    // Enter first and second vertex
    // 0 4
    // Enter first and second vertex
    // 0 5
    // Enter first and second vertex
    // 4 3
    // Enter first and second vertex
    // 5 6
    // Enter first and second vertex
    // 3 6
    // Enter first and second vertex
    // 3 2
    // Enter first and second vertex
    // 3 1
    // Enter first and second vertex
    // 2 1
    // Enter first and second vertex
    // 6 7
    // OUTPUT
    // 0
    // 4
    // 5
    // 3
    // 6
    // 1
    // 2
    // 7
    return 0;
}