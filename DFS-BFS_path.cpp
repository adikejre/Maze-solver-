#include<bits/stdc++.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

class solve_dfs
{
    public: int n=0,num=0,k;

    vector<char> nodes;
    vector<int> path;
    vector<int> visited;


    int directions[4];
    solve_dfs(int no)
    {
        n=no;
        num=no*no;
        directions[0]=1;
        directions[1]=no;
        directions[2]=-no;
        directions[3]=-1;
    }
    solve_dfs()
    {

    }

    public:

    bool found=false;

void generatemaze(int dim)
{
    nodes.resize(num);
    path.resize(num);
    visited.resize(num);

    for( k=0;k<num;k++){
        path[k]=-1;
        visited[k]=0;
    }


    int upper=100;
    int lower=0;
    for(int i=0;i<dim*dim;i++)
    {
    int number = (rand() %
           (upper - lower + 1)) + lower;

    if(number<25)
        nodes[i]='X';

    else
        nodes[i]='.';

    if((i+1)%dim==0&&i!=0)

            cout<<nodes[i]<<endl;
            else
            cout<<nodes[i]<<' ';
    }
  }
void givepath(int ele,int dst)
{


    int i;
    int vert;

    visited[ele]=1;

    if(ele==dst)
    {
        found=true;

        return ;
    }

    if(found==false)
    {
     for(i=0;i<4;i++)
    {
      if(found)
        break;

        vert=ele+directions[i];

        if(vert>=0&&vert<num&&visited[vert]!=1&&nodes[vert]!='X')
        {
            if((ele%n==0&&vert==ele-1)||(vert%n==0&&ele==vert-1))
                continue;
            else{

            path[vert]=ele;

            givepath(vert,dst);
            }

        }
    }
    }


}

void printsol(int src,int dst)
{

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     int i,f=0,j=dst;

    vector<int>solution;
    while(j!=-1)
    {

        solution.push_back(j);
        j=path[j];
    }


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
    cout<<endl;
    cout<<"length of path is "<<solution.size()-1<<endl;
}

void getsolution(int src,int dst)
{

    givepath(src,dst);
    if(found)
        printsol(src,dst);

    else
        cout<<"No path found";

}

};

class solve_bfs : public solve_dfs
{
    public:
    queue<int> q;

    solve_bfs(solve_dfs o)
    {
        nodes=o.nodes;
        num=o.num;
        n=o.n;


        path.resize(num);
        visited.resize(num);
        for( k=0;k<num;k++)
        {
        path[k]=-1;
        visited[k]=0;
        }


    }


   void getneighbours(int ele)
   {
    int i,vert,no;

    int direction[4]={1,n,-n,-1};


    for(i=0;i<4;i++)
    {
        vert=ele+direction[i];
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


  bool bfspath(int src,int dst)
{

    found=false;

    int ele=src;

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
     getneighbours(ele);

    }
    if(found==true)
        return true ;
    else
        {

        return false;
        }
}


void solutionbfs(int src,int dst)
{
    bool path_exists=bfspath(src,dst);
    if(!path_exists)
        cout<<"no path found";
    else{
        printsol(src,dst);
    }

}

};

int main()
{
    int num,n;
    cout<<"Enter n ";

    cin>>n;

    num=n*n;
    solve_dfs obj(n);

    int src=-1,dst=-1;
    cout<<"Random maze of size n x n"<<endl;
    obj.generatemaze(n);

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


   solve_bfs ob(obj);
    cout<<"maze solution with bfs is"<<endl;
     ob.solutionbfs(src,dst);
     cout<<endl;

    cout<<"maze solution with dfs is"<<endl;
    obj.getsolution(src,dst);


return 0;
}



