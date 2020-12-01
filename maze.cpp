#include <iostream>
#include<stdio.h>
using namespace std;
#define MaxSize 100
typedef int Status;
#define M 8
#define N 8
Status maze_map[M+2][N+2]={
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};
typedef struct 
{
    int i;
    int j;
    int dir; //顺时针查找方向
}point;//存储节点
typedef struct
{
    point data[MaxSize] ;
    int top;
}SType;//构建栈
Status map_slove(int x0,int y0,int xe,int ye)//x0->xe
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
int main()
{
    int x,y,k,t;
    cout<<"终点坐标为（8,8）"<<endl;
    while(1)
    {
        cout<<"请输入起点坐标"<<endl;
        cout<<"横坐标范围 0~9，纵坐标范围：0~9"<<endl;
        cin>>x>>y;
        if(maze_map[x][y]==1)
        {
            cout<<"该坐标为障碍，请重新输入"<<endl;
        }
        else{
            break;
        }
    }
    map_slove(x,y,M,N);
    cout<<"图像表示为："<<endl;
    for(t=0;t<10;t++)
    {
        cout<<"\t\t";
        for(k=0;k<10;k++)
        {
            if(maze_map[t][k]==1)
            {
                cout<<"#";
            }else if(maze_map[t][k]==0)
            {
                cout<<" ";
            }else{
                printf("o");
            }
        }
        if(k==10) cout<<endl;
    }
    cout<<"o为路径"<<endl;
    int tmp;
    cin>>tmp;
    return 0;
}

