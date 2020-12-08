#include <iostream>
#include<vector>
#include<stdio.h>
#include<time.h>
using namespace std;
#define MaxSize 100
#define WALL 0
#define ROUTE 1
typedef int Status;
int N;
typedef struct //ÿ�����
{
    int i;
    int j;
    int dir; //˳ʱ����ҷ���
}point;//�洢�ڵ�
typedef struct//ջ����
{
    point data[MaxSize] ;
    int top;
}SType;//����ջ
Status map_slove(vector<vector<int>> &maze_map,int x0,int y0)//��⺯��x0->xe,y0->ye
{
    int xe;int ye;
    if (maze_map[N-3][N-4]==ROUTE)
    {
        xe=N-3;ye=N-4;
    }
    if(maze_map[N-3][N-4]!=ROUTE)
    {
        cout<<"�޽�"<<endl;
        return (0);
    }
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
                maze_map[st.data[k].i][st.data[k].j]=-2;
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
            if(maze_map[i][j]==ROUTE) find=1;
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
            maze_map[st.data[st.top].i][st.data[st.top].j]=-1;//�˸�
            st.top--;//��ջ
        }
    }
    return (0);
}
void dig(vector<vector<int>> &maze_map,int x ,int y)//�ھ���
{
    if (maze_map[x][y]==WALL)
    {
        if(maze_map[x+1][y]+maze_map[x-1][y]+maze_map[x][y-1]+maze_map[x][y+1]<=ROUTE)//��������С�ڵ���1��ͨ·���õ���Ϊͨ·
        {
            maze_map[x][y]=ROUTE;

            int dir[4]={0,1,2,3};
            for(int i=4;i>0;--i)
            {
                int _rand_ =rand()%i;//�������
                swap(dir[_rand_],dir[i-1]);//��������ھ���
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
void printMaze(vector<vector<int>> &maze_map)//��ӡ�Թ�
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (maze_map[i][j] == ROUTE||maze_map[i][j]==-1)
            {
                cout << " ";
            }
            else if (maze_map[i][j]==-2)
            {
                cout<<"O";
            }

            else
            {
                cout << "#";
            }
        }
        cout << endl;
    }
    cout << endl;
}
void init_maze (vector<vector<int>> &maze_map)
{
    maze_map[N-2][N-3]==ROUTE;
    if(maze_map[N-3][N-4])
    {
        maze_map[N-2][N-4]=ROUTE;
    }
    else if (maze_map[N-3][N-4]==ROUTE)
    {
        maze_map[N-2][N-4]==ROUTE;
    }
}
int main()
{
    do{cout<<"��ѡ���Թ���ģ��10~28��:";
    cin>>N;}while(N<10||N>=28);
    srand((unsigned)time(NULL));
    vector<vector<int>> maze_map(N,vector<int>(N,WALL));
    for(int i=0;i<N;++i)//��֤������һ�㲻���ڴ�
    {
        maze_map[i][N-1]=ROUTE;
        maze_map[N-1][i]=ROUTE;
        maze_map[i][0]=ROUTE;
        maze_map[0][i]=ROUTE;
    }
    cout<<"���Եȣ�������������Թ������Ͻ�Ϊ��ڣ����½�Ϊ���ڣ���#����ǽ�ڣ���O�������ͨ·"<<endl;
    dig(maze_map,2,2);//��ʼ�ڵ�λ��
    init_maze(maze_map);
    cout<<"�������Թ�"<<endl;
    printMaze(maze_map);
    for(int i=1;i<=N-2;i++)//��ֹ�߱�·
    {
        maze_map[i][N-2]=WALL;
        maze_map[N-2][i]=WALL;
        maze_map[1][i]=WALL;
        maze_map[i][1]=WALL;
    }
    
    map_slove(maze_map,2,2);
    maze_map[N-2][N-4]=-2;
    printMaze(maze_map);
    cout<<"���������ַ��رմ���"<<endl;
    int tmp;
    cin>>tmp;
    return 0;
}

