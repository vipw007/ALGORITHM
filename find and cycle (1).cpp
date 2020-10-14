#include<bits/stdc++.h>
using namespace std;

struct group{
int u,v;
};

int find_set(int parent[],int x)
{
    if(parent[x]==-1)
        return x;
    return find_set(parent,parent[x]);
}

void union_set(int parent[],int u,int v)
{
    parent[v]=u;
}

int main()
{

    int nn,f;
    cout<<"Enter size of the tree"<<endl;
    cin>>nn;
    int tree[nn],par[nn];

    for(int i=0;i<nn;i++)
        par[i]=-1;

    cout<<"Enter nodes on tree"<<endl;
    for(int i=0;i<nn;i++)
        cin>>tree[i];

    for(int i=0;i<nn;i++)
    {
        if(i!=0)
         par[tree[i]]=tree[0];
    }

    cout<<"Enter node to find its parent"<<endl;
    cin>>f;

    cout<<"Parent of "<<f<<" is :"<<find_set(par,f)<<endl<<endl<<endl;


    cout<<"Detecting cycle in graph............"<<endl<<endl<<endl;


    int edges;
    int nodes;
    int u,v;
    cout<<"Enter number of edges and nodes"<<endl;
    cin>>edges>>nodes;

     int parent[nodes+1];

    for(int i=0;i<=nodes;i++)
        parent[i]=-1;

    group p[edges];
    cout<<"Enter u , v"<<endl;
    for(int i=0;i<edges;i++)
    {
        cin>>p[i].u>>p[i].v;
    }

    int m,n;

    for(int i=0;i<edges;i++)
    {
         m=p[i].u;
         n=p[i].v;
         if(find_set(parent,m)!=find_set(parent,n))
         {
             union_set(parent,m,n);
         }else{
           cout<<"cycle exist in graph....."<<endl;
           return 0;
         }
    }

    cout<<"cycle do not exist......."<<endl;
}
