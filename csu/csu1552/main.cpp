#include "../../headers.h"

/// ------------------------------ code line ------------------------------//



typedef llt int_t;
/**< 非递归的gcd */
int_t gcd(int_t a,int_t b){
    if (0L == a || 0L == b) return 1;
    if ( a < 0 ) a = -a;
    if ( b < 0 ) b = -b;
    while(b){
        int_t t = a % b;
        a = b;
        b = t;
    }
    return a;
}

/** \非递归的扩展欧几里德算法
 *返回a、b的gcd，同时x、y满足ax+by=gcd
 */
int_t exEuclid(int_t a,int_t b,int_t&x,int_t&y){
    int_t x0 = 1, y0 = 0;
    int_t x1 = 0, y1 = 1;
    x = 0; y = 1;
    int_t r = a % b;
    int_t q = ( a - r ) / b;
    while( r ){
        x = x0 - q * x1;
        y = y0 - q * y1;
        x0 = x1; y0 = y1;
        x1 = x; y1 = y;
        a = b; b = r; r = a % b;
        q = ( a - r ) / b;
    }
    return b;
}
/**< 求a相对于p的逆元，a、p互质才存在逆元 */
int_t inv(int_t a,int_t p){
    int_t x,y , r = exEuclid(a,p,x,y);
    if ( r != 1 ) return 0;
    x = x % p;
    return ( x < 0 ) ? x+p : x;
}

/**< 快速乘取模 */
int_t multiMod(int_t a,int_t b,int_t mod){
    int_t ret = 0LL;
    a %= mod;
    while( b ){
        if ( b & 1LL ) ret = ( ret + a ) % mod, --b;
        b >>= 1LL;
        a = ( a + a ) % mod;
    }
    return ret;
}
/**< 快速幂取模 */
int_t Pow_Mod( int_t x,int_t n , int_t mod ){
    int_t ans = 1LL;
    x %= mod;
    while ( n ){
        if ( n & 1LL ) ans = multiMod(ans,x,mod); //ans = ans*x%mod;
        n >>= 1; x = multiMod(x,x,mod); //x = x*x%mod;
    }
    return ans;
}

/**<  Miller-Rabin测试,测试n是否为素数 */
bool Miller_Rabin(int_t n,int repeat){
    if ( 2LL == n || 3LL == n ) return true;
    if ( !( n & 1LL ) ) return false;

    /**< 将n分解为2^s*d */
    int_t d = n - 1LL;
    int s = 0;
    while( !( d & 1LL ) ) ++s, d>>=1LL;

    //srand((unsigned)time(0));
    for(int i=0;i<repeat;++i){ /**< 重复repeat次  */
        int_t a = rand() % ( n - 3 ) + 2;//取一个随机数,[2,n-1)
        int_t x = Pow_Mod(a,d,n);
        int_t y = 0LL;
        for(int j=0;j<s;++j){
            y = multiMod(x,x,n);
            if ( 1LL == y && 1LL != x && n-1LL != x ) return false;
            x = y;
        }
        if ( 1LL != y ) return false;
    }
    return true;
}



/** \Pollard-Rho方法分解整数因子
 *  n == 1 特判 会死循环
 *
 */
int const Repeat = 5; /**< Miller_Rabin 测试次数 */
int_t Fac[100]; /**< 质因数分解结果（刚返回时是无序的） */
int FCnt; /**<  质因数的个数。数组小标从0开始 */
int_t Pollard_Rho(int_t n,int_t c){
    int_t k = 2;
    int_t x = rand() % n;
    int_t y = x;
    for (int_t i = 1;;i++){
        x = ( multiMod(x,x,n) - c ) % n;
        if ( x < 0 ) x += n;
        int_t d = gcd(y-x,n);
        if (d!=1LL && d!=n) return d;
        if (y == x) return n;
        if ( i == k ) y = x, k <<= 1;
    }
}
void Find_fac(int_t n){
    if ( Miller_Rabin(n,Repeat) ){
        Fac[FCnt++] = n;
        return;
    }
    int_t p;
    while( ( p = Pollard_Rho(n,rand()%(n-3)+3) ) == n );
    Find_fac(p);
    Find_fac(n/p);
}
/** \RSA
 *  两个大质数 p,q ;
 *  n = p*q ,  φ(n) = (p-1)*(q-1) ; ( φ(n) 即欧拉函数 )
 *  公钥  e = 随机选择一个整数e，条件是1< e < φ(n)，且e与φ(n) 互质。
 *  密钥  d = e对于φ(n)的模反元素
 *  加密  m -> C : ( m^e % n )
 *  解密  C -> m : ( c^d % n )
 */
inline int_t _encode( int_t m,int_t e,int_t n ){return Pow_Mod(m,e,n);}
inline int_t _decode( int_t C,int_t d,int_t n ){return Pow_Mod(C,d,n);}
void RSA( int_t p,int_t q,int_t e,int_t &nub,int l=0 ){
    int_t n = p*q;
    int_t fn = (p-1)*(q-1);
    int_t d = inv(e,fn);
//    for (int i = 0;i < l;++i )
//        nub[i] = _encode(nub[i],e,n);   /**< e是公钥,用于加密 */
//        nub[i] = _decode(nub[i],d,n);   /**< d是私钥,用于解密 */
    nub = _decode(nub,d,n);
}

///========================================== code line ========================================//

typedef int weight_t;
/** \二分图最大匹配（匈牙利算法的DFS实现）
 * 临界表 无向边(ans/2)
 * CALL:ret=hungary();输出最大匹配数
 * 时间复杂度:O(VE);
 *********
 */
const int SIZE_V = 2000+500;
const int SIZE_E = 10000+500;
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
int Link[SIZE_V]; //对于右边集合的 i, link[i]即对应左边集合的 node
bool vis[SIZE_V];
/**< 对于左边的集合的node节点 求增广路径 */
bool DFS( int u){
    /**< 对右边集合的每个结点遍历一次 */
    for (int next = Ver[u];next;next = Edge[next].next ){
        int v = Edge[next].node;
        /**< 如果已经找过 */
        if ( vis[v] )continue; vis[v] = true;
        /**< 如果这个点上未盖点 或者该点还能找到增广路径 */
        if ( Link[v] == -1 || DFS( Link[v] ) ){
            Link[v] = u;
            return true;
        }
    }
    return false;
}

int hungary(int n ){
    int ret = 0;
    memset(Link , -1 ,sizeof(Link));
    /**< 对左边集合的每个点求增广路径 */
    for (int u = 1;u <= n;++u){
        memset(vis,0,sizeof(vis));
        if (DFS(u)) ret++;
    }
    return ret;
}

const int SIZE = 1000000;
llt nub[SIZE];
int main(){
    int n;
    while ( scanf("%d",&n) != EOF ){
        init_Graph();
        for (int i = 0;i < n;++i ) scanf("%lld",nub+i);
        for (int i = 0;i < n;++i )for (int j = i+1;j < n;++j ){
            llt x = nub[i]+nub[j];
            if ( Miller_Rabin(x,3) )
                mkEdge(i+1,j+1);
        }
        Ans( hungary(n)/2 );
    }
    return 0;
}
