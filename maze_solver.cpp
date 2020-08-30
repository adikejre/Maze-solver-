#include<bits/stdc++.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

void generatemaze(char nodes[],int n)
{

    int upper=100;
    int lower=0;
    for(int i=0;i<n*n;i++)
    {
    int num = (rand() %
           (upper - lower + 1)) + lower;




    if(num<25)
        nodes[i]='X';

    else
        nodes[i]='.';

    if((i+1)%n==0&&i!=0)

            cout<<nodes[i]<<endl;
            else
            cout<<nodes[i]<<' ';
    }
}



void printsol(char nodes[],int n,vector<int> &solution,int dst,int src)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     int i,f=0,num;
     num=n*n;
     vector<int> trace;
     for(auto &a:solution)
        trace.push_back(a);

     sort(solution.begin(),solution.end());
     for(i=0;i<num;i++)
    {
        if(i==dst){
            SetConsoleTextAttribute(hConsole, 12);
              if((i+1)%n==0&&i!=0)
                cout<<'E'<<endl;
            else

            cout<<'E'<<' ';
            SetConsoleTextAttribute(hConsole, 15);
            f++;
            continue;
        }
        if(i==src){
            SetConsoleTextAttribute(hConsole, 12);
            if((i+1)%n==0&&i!=0)
                cout<<'S'<<endl;
            else
            cout<<'S'<<' ';
            SetConsoleTextAttribute(hConsole, 15);
            f++;
            continue;
        }

        if(i==solution[f])
        {

                SetConsoleTextAttribute(hConsole, 10);
                if((i+1)%n==0&&i!=0)
                    cout<<'p'<<endl;
                else
                      cout<<'p'<<' ';


            f++;
            SetConsoleTextAttribute(hConsole, 15);
            continue;
        }

        if((i+1)%n==0&&i!=0)

            cout<<nodes[i]<<endl;


        else
            cout<<nodes[i]<<' ';

    }
}
void neighbours(char nodes[],int n,int ele,int visited[],queue<int> &q ,int path[])
{
    int i,vert,num;
    num=n*n;
    int directions[4]={1,n,-n,-1};


    for(i=0;i<4;i++)
    {
        vert=ele+directions[i];
        if(vert>=0&&vert<num&&visited[vert]!=1&&nodes[vert]!='X')
        {
            if((ele%n==0&&vert==ele-1)||(vert%n==0&&ele==vert-1))
                continue;
            else{
            q.push(vert);
            visited[vert]=1;
            path[vert]=ele;
            }

        }
    }
    return ;

}

bool givepath(char nodes[],int src,int dst,int n,int path[])
{
    int num=n*n;
    bool found=false;
    int visited[num]={0};
    int ele=src;
    queue<int> q;
    q.push(src);
    visited[src]=1;

    while(!q.empty())
    {
        ele=q.front();
        q.pop();
        if(ele==dst)
        {
            found=true;
            break;
        }
     neighbours(nodes,n,ele,visited,q,path);

    }
    if(found==true)
        return true ;
    else
        {
        cout<<"no path";
        return false;
        }
}



int main()
{

    cout<<"Enter n ";
    int n,i,num,j,k;
    cin>>n;

    num=n*n;
    char nodes[num];
    int src=-1,dst=-1;
    cout<<"Random maze of size n x n"<<endl;
    generatemaze(nodes,n);

    int sx,sy,dx,dy,ch;
    cout<<"options: 1. Enter single coordinates 2. Enter x,y coordinates"<<endl;
    cin>>ch;
    cout<<"Enter source and destination coordinates"<<endl;
    if(ch==1)
    {
        cin>>src>>dst;
    }
    if(ch==2){

    cin>>sx>>sy>>dx>>dy;
     src= n*(sx-1) + sy-1;
     dst = n*(dx-1) + dy-1;
    }
    cout<<"maze solution with bfs is"<<endl;

    int path[num];
    for( k=0;k<num;k++)
        path[k]=-1;




   bool ispath;
    ispath=givepath(nodes,src,dst,n,path);
    j=dst;


    cout<<endl;
    vector<int>solution;
    while(j!=-1)
    {

        solution.push_back(j);
        j=path[j];
    }


if(ispath)
    printsol(nodes,n,solution,dst,src);

return 0;
}

