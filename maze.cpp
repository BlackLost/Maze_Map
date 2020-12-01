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
    int dir; //˳ʱ����ҷ���
}point;//�洢�ڵ�
typedef struct
{
    point data[MaxSize] ;
    int top;
}SType;//����ջ
Status map_slove(int x0,int y0,int xe,int ye)//x0->xe
{
    int i,j,k,di;//i,j,di����λ�ã�kѭ������
    int find;//find���ж��Ƿ���ߣ�0Ϊ��ʼ״̬��1Ϊ����״̬
    SType st;
    st.top=-1;//��ʼ��ջ��
    st.top++;
    st.data[st.top].i=x0;//��ʼ������λ��
    st.data[st.top].j=y0;
    st.data[st.top].dir=-1;
    maze_map[x0][y0]=-1;
    while (st.top>-1)//ջ����ʱ��ջ
    {
        i=st.data[st.top].i;//�������
        j=st.data[st.top].j;
        di=st.data[st.top].dir;
        if (i==xe&&j==ye)//�ҵ��յ�,����ջ��Ԫ��
        {
            cout<<"�Թ�·������"<<endl;
            for(k=0;k<=st.top;k++)
            {
                printf("\t(%d,%d)��",st.data[k].i,st.data[k].j);
                if((k+1)%5==0) cout<<endl;
            }
            cout<<endl;
            return 0;
        }
        find=0;//��ʼѰ��·��
        while(di<4&&find==0)//��ʼѰ�ҷ���
        {
            di++;
            switch(di)//��������Ѱ��·��
            {
            case 0://������
                i=st.data[st.top].i-1;
                j=st.data[st.top].j;
                break;
            case 1://������
                i=st.data[st.top].i;
                j=st.data[st.top].j+1;
                break;
            case 2://������
                i=st.data[st.top].i+1;
                j=st.data[st.top].j;
                break;
            case 3://������
                i=st.data[st.top].i;
                j=st.data[st.top].j-1;
                break;
            }
            if(maze_map[i][j]==0) find=1;
        }
        if(find==1)//��·
        {
            st.data[st.top].dir=di;
            st.top++;//��ջ
            st.data[st.top].i=i;
            st.data[st.top].j=j;
            st.data[st.top].dir=-1;//���÷���
            maze_map[i][j]=-1;//���
        }
        else//��·
        {
            maze_map[st.data[st.top].i][st.data[st.top].j]=0;//�˸�
            st.top--;//��ջ
        }
    }
    return (0);
}
int main()
{
    int x,y,k,t;
    cout<<"�յ�����Ϊ��8,8��"<<endl;
    while(1)
    {
        cout<<"�������������"<<endl;
        cout<<"�����귶Χ 0~9�������귶Χ��0~9"<<endl;
        cin>>x>>y;
        if(maze_map[x][y]==1)
        {
            cout<<"������Ϊ�ϰ�������������"<<endl;
        }
        else{
            break;
        }
    }
    map_slove(x,y,M,N);
    cout<<"ͼ���ʾΪ��"<<endl;
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
    cout<<"oΪ·��"<<endl;
    int tmp;
    cin>>tmp;
    return 0;
}

