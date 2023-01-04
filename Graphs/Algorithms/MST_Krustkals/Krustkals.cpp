#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int source;
    int dest;
    int weight;
};
//compare function to sort the edges by minimum weights
bool compare(Edge e1,Edge e2){
    return e1.weight<e2.weight;
}
//findparent function
int findParent(int v,int * parent){
    //top most parent return
    if(parent[v]==v){
        return v;
    }
    return findParent(parent[v],parent);
}
void kruskals(Edge * input,int n,int e){
    //1) Sort the input array -ascending order based on weights
    sort(input,input+e,compare);
    //Output Array to store MST it has size equal to n-1
    Edge * output=new Edge[n-1];
    //parent array for union find cycle detection algorithm
    int * parent=new int[n];
    for(int i=0;i<n;i++){
        //initializing all as their parent ownself
        parent[i]=i;
    }
    //current no. of edges added into the MST
    int count=0;
    //maintaining the index pointer of the input array
    int i=0;
    while (count != n-1)
    {
        Edge currentEdge=input[i];
        //check if we can add the current edge in the MST or not
        int sourceParent=findParent(currentEdge.source,parent);
        int destParent=findParent(currentEdge.dest,parent);
        //safe to add if 
        if(sourceParent != destParent){
            output[count]=currentEdge;
            count++;
            //make parent-child relation
            parent[sourceParent]=destParent;
        }
        //else move forward
        i++;
    }
    cout<<"---------------Printing MST-----------------"<<endl;
    for(int i=0;i<n-1;i++){
        //checking just to maintain the order smaller vertex should come first
        if(output[i].source < output[i].dest){
            cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else{
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
        }
    }
    
}

int main()
{
    //n-->no. of vertices
    //e-->no. of edges
    int n,e;
    cin>>n>>e;
    Edge * input=new Edge[e];
    //taking e edge input
    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source=s;
        input[i].dest=d;
        input[i].weight=w;
    }
    kruskals(input,n,e);
    // OUTPUT
// 6 11
// 0 1 2
// 1 3 1
// 0 2 4
// 2 4 9
// 4 5 5
// 3 5 7
// 4 3 11
// 2 5 10
// 0 3 3
// 2 1 8
// 2 3 6
// ---------------Printing MST-----------------
// 1 3 1
// 0 1 2
// 0 2 4
// 4 5 5
// 3 5 7
    return 0;
}