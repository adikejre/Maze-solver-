#include<bits/stdc++.h>
using namespace std;

bool solvemaze(char maze[][20],int i,int j,char soln[][20],int n,int &num)
{
    if(i==n-1&&j==n-1)
    {
        //print
        soln[i][j]='1';
       for(int p=0;p<n;p++)
        {
            for(int q=0;q<n;q++ )
                cout<<soln[p][q]<<"  ";
            cout<<endl;
        }
cout<<endl;

        num++;

        return true;
    }
    soln[i][j]='1';
    bool down,right;
    if(soln[i+1][j]!='X'&&i<n-1)
    {

        down= solvemaze(maze,i+1,j,soln,n,num);
    }

    if(soln[i][j+1]!='X'&&j<n-1){

         right = solvemaze(maze,i,j+1,soln,n,num);
    }

    soln[i][j]='0';
    if(right||down)
        return true;

    return false;

}

int main()
{
    int n,i,j,num=0;
    cin>>n;
    char maze[20][20];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>maze[i][j];
        }
    }

    char soln[20][20];

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(maze[i][j]=='X')
                soln[i][j]='X';
            else
                soln[i][j]='0';
        }
    }




    bool ans = solvemaze(maze,0,0,soln,n,num);
    cout<<"number of solutions"<<num;
    return 0;

}
