#include<bits/stdc++.h>
using namespace std;

struct group{
int u,v,w;
};


int find_set(int parent[],int x)
{
       while(parent[x]!=-1)
       {
           x=parent[x];
       }
       return x;
}

void union_set(int parent[],int u,int v)
{
    parent[v]=u;
}


char find_hash(int x)
{
    switch(x)
    {
    case 1:
        return 'a';
    case 2:
        return 'b';
    case 3:
        return 'c';
    case 4:
        return 'd';
    case 5:
        return 'e';
    case 6:
        return 'f';
    case 7:
        return 'g';
    case 8:
        return 'h';
    case 9:
        return 'i';

    }
}

int find_hash(char x)
{
    switch(x)
    {
    case 'a':
        return 1;
    case 'b':
        return 2;
    case 'c':
        return 3;
    case 'd':
        return 4;
    case 'e':
        return 5;
    case 'f':
        return 6;
    case 'g':
        return 7;
    case 'h':
        return 8;
    case 'i':
        return 9;

    }
}


int main()
{

    int weight,edges;

    int nodes;

    int u,v;
    cout<<"Enter number of edges and nodes"<<endl;
    cin>>edges>>nodes;

     int parent[nodes+1];

    for(int i=0;i<=nodes;i++)
        parent[i]=-1;

    group p[edges];
    char a,b;
    int w;
    cout<<"Enter u,v,w"<<endl;
    for(int i=0;i<edges;i++)
    {
        cin>>a>>b>>w;
        p[i].u=find_hash(a);
        p[i].v=find_hash(b);
        p[i].w=w;
    }

    for(int i=0;i<edges;i++)
    {
        for(int j=i;j<edges;j++)
        {
            if(p[i].w>p[j].w)
            {
                group x=p[i];
                p[i]=p[j];
                p[j]=x;
            }
        }
    }

    int m,n;
    cout<<"order in which edges are selected"<<endl;
    for(int i=0;i<edges;i++)
    {
         m=p[i].u;
         n=p[i].v;
         if(find_set(parent,m)!=find_set(parent,n))
         {
             cout<<find_hash(n)<<" "<<find_hash(m)<<endl;
             union_set(parent,m,n);
         }
    }



}
