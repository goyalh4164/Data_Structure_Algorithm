#include<bits/stdc++.h>
#include <climits>
using namespace std;

int findMinVertex(int * distance,bool * visited,int n){
    int minVertex=-1;
    for(int i=0;i<n;i++){
        if((!visited[i]) && (minVertex == -1 || distance[i]<distance[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void Dijkastra(int ** edges,int n){
    int * distance=new int[n];
    bool * visited=new bool[n];
    for(int i=0;i<n;i++){
        distance[i]=INT_MAX;
        visited[i]=false;
    }
    distance[0]=0;
    for(int i=0;i<n;i++){
        int minVertex=findMinVertex(distance,visited,n);
        visited[minVertex]=true;
        for(int j=0;j<n;j++){
            if(edges[minVertex][j] != 0 && !visited[j]){
                int dist=distance[minVertex] + edges[minVertex][j];
                if(dist < distance[j]){
                    distance[j]= dist;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
    delete [] visited;
    delete [] distance;
}
int main()
{
    int n;
    int e;
    cin>>n>>e;
    int ** edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s,weight;
        cin>>f>>s>>weight;
        edges[f][s]=weight;
        edges[s][f]=weight;
    }
    cout<<endl;
    Dijkastra(edges,n);
    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete [] edges;
    return 0;
}
// TESTCASE
// 5 7
// 0 1 4
// 0 2 8
// 1 3 5
// 1 2 2
// 2 3 5
// 2 4 9
// 3 4 4
// OUTPUT
// 0 0
// 1 4
// 2 6
// 3 9
// 4 13
