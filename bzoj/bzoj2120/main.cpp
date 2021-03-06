#include <cstdio>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <cstring>
#define CLEAR(a) memset((a),0,sizeof(a))
#define FLAG(a) memset((a) , -1 , sizeof(a))
#define  varName(x) #x
#define  deBug(exp) cout<< " == > " << #exp<<" : "<< (exp) << endl
#define Case printf("Case %d: ",kase++)
#define Ans(x) printf("%d\n",(x))
#define readfile(path) freopen( (path) , "r", stdin )
#define writefile(path) freopen( (path) , "w", stdout )
using namespace std;

typedef long long llt;
int const SIZE = 1091100;
int BLOCK_SIZE ;

/**< 记录每次查询 */
struct mo_t{
    int s,e; /**< 左右端点 */
    int last_op_time; /**< 上次修改进行的时间 */
    int idx; /**< 在答案中的位置 */
    friend bool operator <(const mo_t&a,const mo_t&b){
        int ln = a.s / BLOCK_SIZE;
        int rn = b.s / BLOCK_SIZE;
        return ln < rn || ( ln==rn && a.e < b.e );
    }
};
/**< 记录修改操作 */
struct mo_op{
    /**< 修改的节点,修改后的值,修改前的值 */
    int node,value,last_value;
};

int n,m_query,m_oper;
int A[SIZE]; /**< 源数组 */
int const Q_SIZE = SIZE;
int const O_SIZE = SIZE;

mo_t Mo_query[Q_SIZE];
mo_op Mo_Oper[Q_SIZE];
int Answer[Q_SIZE];
int Cnt[SIZE];
int MoAns;
/**< 对一个点有可能进行多次修改,所以还原的时候要逐次还原 */
int OperCache[SIZE];  /**< 缓存一下修改的值 */
int cur_left,cur_right; /**< 当前处理区间的游标 */


inline void insert( int n ){
    Cnt[n]++;
    (Cnt[n] == 1 ) ? MoAns ++ :false;
}
inline void remove( int n ){
    (Cnt[n] == 1 ) ? MoAns -- :false;
    Cnt[n]--;
}
inline void change( int node,int v){
    /**< 如果改变的节点在区间里面 */
    if ( cur_left <= node && node <= cur_right )
        remove( A[node] ) , insert( v );
    A[node] = v;
}
void Mo(){
    sort(Mo_query,Mo_query+m_query);
    cur_left = 1;
    cur_right = 0;
    MoAns = 0;
    int OpTime = 0;
    for (int i = 0;i < m_query;++i ){

        /**< 先把这次查询前的修改做了 */
        while ( OpTime < Mo_query[i].last_op_time ) change( Mo_Oper[OpTime].node,Mo_Oper[OpTime].value ) ,OpTime++;
        /**< 再把这次查询后的修改恢复 */
        while ( OpTime > Mo_query[i].last_op_time ) OpTime-- , change( Mo_Oper[OpTime].node,Mo_Oper[OpTime].last_value );

        while ( cur_right < Mo_query[i].e ) insert(A[++cur_right]);
        while ( cur_left > Mo_query[i].s  ) insert(A[--cur_left]);
        while ( cur_right > Mo_query[i].e ) remove(A[cur_right--]);
        while ( cur_left < Mo_query[i].s  ) remove(A[cur_left++]);
        Answer[Mo_query[i].idx] = MoAns ;

    }
}

int main(){
    int q;
    while ( scanf("%d%d",&n,&q) != EOF ){

        BLOCK_SIZE = (int)sqrt((double)n);
        CLEAR(Cnt);

        for (int i = 1;i <= n;++i ){
            scanf("%d",A+i);
            OperCache[i] = A[i];
        }
        char op[2];
        m_query = m_oper = 0;
        int x,y;
        for (int i = 0;i < q;++i ){
            scanf("%s%d%d",op,&x,&y);
            if ( *op == 'Q'){
                if ( y < x )swap(x,y);
                Mo_query[m_query].s = x;
                Mo_query[m_query].e = y;

                Mo_query[m_query].last_op_time = m_oper;
                Mo_query[m_query].idx = m_query++;
            }
            else{
                Mo_Oper[m_oper].node = x;
                Mo_Oper[m_oper].value = y;
                Mo_Oper[m_oper++].last_value = OperCache[x];
                OperCache[x] = y;
            }

        }
        Mo();
        for (int i = 0;i < m_query;++i )
            Ans(Answer[i]);
    }
    return 0;
}
