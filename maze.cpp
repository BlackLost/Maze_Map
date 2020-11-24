#include <iostream>
#include<stdio.h>
#include<stack>
using namespace std;
#define MaxSize 100
typedef int status;
//TO DO maze_map
int maze_map[M+2][N+2]=
{
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
    int dir;
}point;//存储节点
typedef struct
{
    point data[MaxSize] ;
    int top;
}SType;//构建栈
status map_slove(int x0,int y0,int xe,int ye)
{
    int i,j,k,di,find;
    SType st;
    st.top=-1;
    st.top++;
    st.data[st.top].i=x0;//初始坐标设置
    st.data[st.top].j=y0;
    st.data[st.top].dir=-1;
    maze_map[x0][y0]=-1;

}

