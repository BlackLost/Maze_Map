#include <iostream>
#include<stdio.h>
#include<stack>
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
    int dir; //顺时针0上，3左
}point;//存储节点
typedef struct
{
    point data[MaxSize] ;
    int top;
}SType;//构建栈
Status map_slove(int x0,int y0,int xe,int ye)
{
    int i,j,k,di,find;//i,j,di是位置，k是循环变量，find是判断变量
    SType st;
    st.top=-1;//初始化栈
    st.top++;
    st.data[st.top].i=x0;//初始坐标设置
    st.data[st.top].j=y0;
    st.data[st.top].dir=-1;
    maze_map[x0][y0]=-1;
    while (st.top>-1)//栈不空时循环
    {
        i=st.data[st.top].i;//设置起点
        j=st.data[st.top].j;
        di=st.data[st.top].dir;
        if (i==xe&&j==ye)//找到终点,弹出栈内元素
        {
            cout<<"迷宫路径如下"<<endl;
            for(k=0;k<=st.top;k++)
            {
                cout<<"\t"<<"("<<st.data[k].i,st.data[k].j<<")";
                if((k+1)%5==0) cout<<endl;
            }
            cout<<endl;
            return 0;
        }
        find=0;//从0开始寻找
        while(di<4&&find==0)
        {
            di++;
            if (di==0)
            {
                i=st.data[st.top].i-1;
                j=st.data[st.top].j;
                break;
            }
            if (di==1)
            {
                i=st.data[st.top].i;
                j=st.data[st.top].j+1;
                break;
            }
            if(di==2)
            {
                i=st.data[st.top].i+1;
                j=
            }
        }

    }

}

