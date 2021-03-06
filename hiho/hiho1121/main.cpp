#include "../../headers.h"

/**  \二分图判断，染色法，
 * 任意找一个未染色的点A，染色，然后给所有相邻的点染上相反的颜色
 * 不是二分图的充要条件 ： 如果相邻的点已经染了色，而且颜色跟点A相同
 * 实现方式 BFS ， 邻接矩阵
 * 序号1 ～ n 注意初始化
 */
const int SIZE_V = 20000+500;
const int SIZE_E = 100000+500;
struct edge_t{
    int node;
    int next;
}Edge[SIZE_E];
int Ecnt ; // = 0
int Ver[SIZE_V];
void mkEdge( int a,int b ){
    Edge[Ecnt].node = b;
    Edge[Ecnt].next = Ver[a];
    Ver[a] = Ecnt++;

    Edge[Ecnt].node = a;
    Edge[Ecnt].next = Ver[b];
    Ver[b] = Ecnt++;
}
void init_Graph(){
    Ecnt = 1;
    CLEAR(Ver);
}

//int Graph[SIZE][SIZE];
int color[SIZE_V];
bool BFS( int s,int n ){
    queue<int> que;
    que.push(s);
    color[s] = 1;
    while( !que.empty() ){
        int u = que.front(); que.pop();
        for (int next = Ver[u];next;next=Edge[next].next){
            int v = Edge[next].node;
            if( color[v] == -1 ){
                color[v] = !color[u];
                que.push(v);
            }
            if ( color[v] == color[u] )
                return false;
        }
    }
    return true;
}
bool just_Bipartite_Graph( int n ){
    for ( int i = 1;i <= n;++i )
        if ( color[i] == -1 && BFS(i,n) == 0 )
            return false;
    return true;
}
void init(){
    memset(color,-1,sizeof(color));
}

int main(){
    int n,m;
    int t;scanf("%d",&t);while( t-- ){
        scanf("%d%d",&n,&m);
        int x,y;
        init_Graph();
        init();
        while ( m-- ){
            scanf("%d%d",&x,&y);
            mkEdge(x,y);
        }
        if ( just_Bipartite_Graph(n) )
            printf("Correct\n");
        else
            printf("Wrong\n");
    }
    return 0;
}
