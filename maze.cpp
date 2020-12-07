#include <iostream>
#include<vector>
#include<stdio.h>
#include<time.h>
using namespace std;
#define MaxSize 100
#define WALL 0
#define ROUTE 1
typedef int Status;
#define N 20
typedef struct //每个结点
{
    int i;
    int j;
    int dir; //顺时针查找方向
}point;//存储节点
typedef struct//栈定义
{
    point data[MaxSize] ;
    int top;
}SType;//构建栈
Status map_slove(vector<vector<int>> &maze_map,int x0,int y0,int xe,int ye)//求解函数
{
    int i,j,k,di;//i,j,di坐标位置，k循环变量
    int find;//find是判断是否可走，0为初始状态，1为可走状态
    SType st;
    st.top=-1;//初始化栈顶
    st.top++;
    st.data[st.top].i=x0;//初始化坐标位置
    st.data[st.top].j=y0;
    st.data[st.top].dir=-1;
    maze_map[x0][y0]=-1;
    while (st.top>-1)//栈不空时入栈
    {
        i=st.data[st.top].i;//设置起点
        j=st.data[st.top].j;
        di=st.data[st.top].dir;
        if (i==xe&&j==ye)//找到终点,弹出栈内元素
        {
            cout<<"迷宫路径如下"<<endl;
            for(k=0;k<=st.top;k++)
            {
                printf("\t(%d,%d)→",st.data[k].i,st.data[k].j);
                if((k+1)%5==0) cout<<endl;
            }
            cout<<endl;
            return 0;
        }
        find=0;//开始寻找路径
        while(di<4&&find==0)//开始寻找方向
        {
            di++;
            switch(di)//上右下左寻找路径
            {
            case 0://向上走
                i=st.data[st.top].i-1;
                j=st.data[st.top].j;
                break;
            case 1://向右走
                i=st.data[st.top].i;
                j=st.data[st.top].j+1;
                break;
            case 2://向下走
                i=st.data[st.top].i+1;
                j=st.data[st.top].j;
                break;
            case 3://向左走
                i=st.data[st.top].i;
                j=st.data[st.top].j-1;
                break;
            }
            if(maze_map[i][j]==0) find=1;
        }
        if(find==1)//有路
        {
            st.data[st.top].dir=di;
            st.top++;//加栈
            st.data[st.top].i=i;
            st.data[st.top].j=j;
            st.data[st.top].dir=-1;//重置方向
            maze_map[i][j]=-1;//标记
        }
        else//死路
        {
            maze_map[st.data[st.top].i][st.data[st.top].j]=0;//退格
            st.top--;//退栈
        }
    }
    return (0);
}
void dig(vector<vector<int>> &maze_map,int x ,int y)//挖掘函数
{
    if (maze_map[x][y]==WALL)
    {
        if(maze_map[x+1][y]+maze_map[x-1][y]+maze_map[x][y-1]+maze_map[x][y+1]<=ROUTE)//上下左右小于等于1条通路，该点标记为通路
        {
            maze_map[x][y]=ROUTE;
            if(x+2==N-1&&y+2==N-1)
            {
                maze_map[x+1][y]=ROUTE;
                return;
            }
            int dir[4]={0,1,2,3};
            for(int i=4;i>0;--i)
            {
                int _rand_ =rand()%i;//随机变量
                swap(dir[_rand_],dir[i-1]);//设置随机挖掘方向
                switch (dir[i-1])
                {
                case 0:
                    dig(maze_map,x-1,y);
                    break;
                case 1:
                    dig(maze_map,x+1,y);
                    break;                
                case 2:
                    dig(maze_map,x,y-1);
                    break;
                case 3:
                    dig(maze_map,x,y+1);
                    break;
                default:
                    break;
                }
            }
        }
    }
}
void printMaze(vector<vector<int>> &maze_map)//打印迷宫
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (maze_map[i][j] == ROUTE)
            {
                cout << "  ";
            }
            else
            {
                cout << "国";
            }
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    srand((unsigned)time(NULL));
    vector<vector<int>> maze_map(N,vector<int>(N,WALL));
    for(int i=0;i<N;++i)//保证最外面一层不会挖穿
    {
        maze_map[i][N-1]=ROUTE;
        maze_map[N-1][i]=ROUTE;
        maze_map[i][0]=ROUTE;
        maze_map[0][i]=ROUTE;
    }
    dig(maze_map,2,1);//开始挖的位置
    printMaze(maze_map);



    int tmp;
    cin>>tmp;
    return 0;
}

