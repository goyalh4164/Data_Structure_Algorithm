#include<bits/stdc++.h>
using namespace std;
//To print the graph
//sv starting vertex from where printing should start
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
    bool * visited=new bool[n]; //to keep the tract of visited vertex
    //initializing it to zero as no vertex is visited initially
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    //printing the Graph in DFS manner
    printDFS(edges,n,0,visited);
    return 0;
    //Sample TestCase
    //INPUT
    // Enter no. of Vertices :7
    // Enter no. of Edges: 7
    // Enter first and second vertex
    // 0 1
    // Enter first and second vertex
    // 0 2
    // Enter first and second vertex
    // 1 5
    // Enter first and second vertex
    // 2 3
    // Enter first and second vertex
    // 5 4
    // Enter first and second vertex
    // 3 4
    // Enter first and second vertex
    // 2 6
    // output
    // 0
    // 1
    // 5
    // 4
    // 3
    // 2
    // 6
}