#include<bits/stdc++.h>
using namespace std;


int min_index(int u[],bool sel[])
{
    int min=100,index=-1;
    for(int i=0;i<9;i++)
    {
        if(u[i]<=min&&sel[i]==false)
        {
            min=u[i];
            index=i;
        }
    }

    return index;
}

char find_hash(int x)
{
    switch(x)
    {
    case 0:
        return 'a';
    case 1:
        return 'b';
    case 2:
        return 'c';
    case 3:
        return 'd';
    case 4:
        return 'e';
    case 5:
        return 'f';
    case 6:
        return 'g';
    case 7:
        return 'h';
    case 8:
        return 'i';

    }
}

int main()
{

    int g[9][9]={{0,4,0,0,0,0,0,8,0}
                ,{4,0,8,0,0,0,0,11,0}
                ,{0,8,0,7,0,4,0,0,2}
                ,{0,0,7,0,9,14,0,0,0}
                ,{0,0,0,9,0,10,0,0,0}
                ,{0,0,4,14,10,0,2,0,0}
                ,{0,0,0,0,0,2,0,1,6}
                ,{8,11,0,0,0,0,1,0,7}
                ,{0,0,2,0,0,0,6,7,0}};

    int u[9];

    for(int i=0;i<9;i++)
        u[i]=10000;

    bool selected[9];
    for(int i=0;i<9;i++)
        selected[i]=false;

    selected[0]=true;

    int x=0,sum=0;

    int index=0;



    cout<<"The order in which the vertices are selected is:"<<endl;
        cout<<find_hash(0)<<endl;


        for(int j=0;j<9;j++)
        {

        for(int i=1;i<9;i++)
        {
            if(g[index][i]!=0&&g[index][i]<u[i]&&selected[i]==false)
            {
                u[i]=g[index][i];
            }
        }

        index=min_index(u,selected);
        if(index!=-1)
         {
             cout<<find_hash(index)<<" "<<endl;
             sum+=u[index];
         }
        selected[index]=true;

        }


    cout<<"Minimum weight is"<<endl;
    cout<<sum;

}
