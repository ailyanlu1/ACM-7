#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef double int_t;
double const eps = 1E-6;
double const PI = acos(-1);

inline int dcmp(double x)
{
    if(x > eps) return 1;
    return x < -eps ? -1 : 0;
}
struct point_t{
    int_t x,y;
    point_t( int_t xx=0,int_t yy=0 ): x(xx),y(yy){};
    point_t( point_t const&a ): x(a.x),y(a.y) {};
    point_t operator - ( point_t const&a ){
        return point_t( x-a.x,y-a.y);
    }
};
struct segment_t{
    point_t s,e;
    segment_t ( point_t aa = point_t(0,0),point_t bb = point_t(0,0) ):s(aa),e(bb) {};
};

struct round_t {
    int_t x, y, r;
    round_t( int_t xx=0,int_t yy=0,int_t rr=0): x(xx),y(yy),r(rr) {};
};

/**< 叉积 oa * ob */
int_t cross(point_t const &O,point_t const &A,point_t const &B){
    return (A.x - O.x) * (B.y - O.y) - (B.x - O.x) * (A.y - O.y);
}
int_t Point2Point(point_t a, point_t b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

/**< 点p到线段a,b的距离 */
int_t Point2Segment( point_t const&a,point_t const&b,point_t const&p){
    int_t ap_ab = (b.x - a.x)*(p.x - a.x)+(b.y - a.y)*(p.y - a.y);//cross( a , p , b );
    if ( ap_ab <= 0 )
        return sqrt( (p.x-a.x)*(p.x-a.x) + (p.y-a.y)*(p.y-a.y) );

    int_t d2 = ( b.x - a.x ) * ( b.x - a.x ) + ( b.y-a.y ) * ( b.y-a.y ) ;
    if ( ap_ab >= d2 ) return sqrt( (p.x - b.x )*( p.x - b.x ) + ( p.y - b.y )*( p.y - b.y ) ) ;

    int_t r = ap_ab / d2;
    int_t px = a.x + ( b.x - a.x ) *r;
    int_t py = a.y + ( b.y - a.y ) *r;
    return sqrt( (p.x - px)*(p.x - px) + (p.y - py)*(p.y - py) );
}

/**<  点po是否在线段ab上 */
bool PointOnSegment( point_t const&a,point_t const&b, point_t const&po ){
    return po.x >= min( a.x , b.x ) &&
           po.x <= max( a.x , b.x ) &&
           po.y >= min( a.y , b.y ) &&
           po.y <= max( a.y , b.y ) &&
           /**< 此处注意double 要判断 eps  */
           ( po.x - a.x ) * ( b.y - a.y ) == ( po.y - a.y ) * ( b.x - a.x );
}

/**< 点po是否在简单多边形(凸)中  ,点p需要先graham 排序 */
bool PointInSimple( point_t * p ,int n , point_t const&po ){

    p[n] = p[0];
    bool flag = 0;
    int tmp;
    for ( int i = 0; i < n;++i ){
        if ( PointOnSegment( p[i] , p[i+1] , po ) ) return true;
        if ( p[i].y == p[i+1].y ) continue;
        p[i].y < p[i+1].y ? tmp = i+1 : tmp = i ;
        if ( po.y == p[tmp].y && po.x < p[tmp].x ) flag ^= 1;
        p[i].y > p[i+1].y ? tmp = i+1 : tmp = i ;
        if ( po.y == p[tmp].y && po.x < p[tmp].x ) continue ;

        if ( po.x < max( p[i].x , p[i+1].x ) &&
             po.y > min( p[i].y , p[i+1].y ) &&
             po.y < max( p[i].y , p[i+1].y ) ) flag ^= 1;
    }
    return flag;
}

int_t Point2Simple( point_t * p ,int n , point_t const&po ){
    return 0;
}


/**< 计算多边形面积 ,点p需要先graham 排序*/
int_t PolygonArea(point_t p[], int n)
{
    if(n < 3) return 0.0;
    int_t s = p[0].y * (p[n - 1].x - p[1].x);
    p[n] = p[0];
    for(int i = 1; i < n; ++ i)
        s += p[i].y * (p[i - 1].x - p[i + 1].x);
    return s * 0.5;
}
/**< 线段相交 */
bool SegmentOnSegment(segment_t const &u,segment_t const &v){
    return max(u.s.x,u.e.x) >= min(v.s.x,v.e.x)
        && max(v.s.x,v.e.x) >= min(u.s.x,u.e.x)
        && max(u.s.y,u.e.y) >= min(v.s.y,v.e.y)
        && max(v.s.y,v.e.y) >= min(u.s.y,u.e.y)
        && cross(v.s,u.e,v.e) * cross(v.s,v.e,u.s) >= 0
        && cross(u.s,v.e,u.e) * cross(u.s,u.e,v.s) >= 0;
}

/**< A如果比B更靠下更靠左返回真 */
inline bool isLowLeft(point_t const&A,point_t const&B){
    return A.y < B.y || ( A.y == B.y && A.x < B.x );
}


/**< 按照对于pO的极角排序，极角相等的距离远的排在前面，因为后面要做一个unique */
point_t* pO;
bool comp4Graham(point_t const&A,point_t const&B){
    int_t t = cross(*pO,A,B);
    if ( t ) return t > 0LL;

    int_t a1 = A.x > pO->x ? A.x - pO->x : pO->x - A.x;
    int_t a2 = B.x > pO->x ? B.x - pO->x : pO->x - B.x;
    if ( a1 != a2 ) return a1 > a2;

    a1 = A.y > pO->y ? A.y - pO->y : pO->y - A.y;
    a2 = B.y > pO->y ? B.y - pO->y : pO->y - B.y;
    return a1 > a2;
}

/**< 相对于pO是否极角相等 */
inline bool isEqPolar(point_t const&A,point_t const&B){
    return 0LL == cross(*pO,A,B);
}

/**<  Graham求凸包，结果当中没有共线点，起点总是最下最左点 */
int Graham(point_t P[],int n){
    if ( 1 == n ) return 1;

    //寻找最下最左点
    point_t *p = min_element(P,P+n,isLowLeft);

    //交换
    swap(*p,P[0]);

    if ( 2 == n ) return 2;

    //按极角排序，极角相等，距离近的排在前面
    pO = P;
    sort(P+1,P+n,comp4Graham);

    //将相对于pO的共线点均剔除，只保留最后一个
    p = unique(P+1,P+n,isEqPolar);
    n = p - P;

    //真正的Graham循环
    int top = 2;
    for(int i=2;i<n;++i){
        while( top > 1 && cross(P[top-2],P[top-1],P[i]) <= 0LL )
            --top;
        P[top++] = P[i];
    }
    return top;
}

/**< RoundIntersectArea   */
int_t RIA(round_t a, round_t b) {
    int_t d = Point2Point( point_t(a.x,a.y),point_t(b.x,b.y) );
    if (d >= a.r + b.r)
        return 0;
    if (d <= fabs(a.r - b.r)) {
        int_t r = a.r < b.r ? a.r : b.r;
        return PI * r * r;
    }
    int_t ang1 = acos((a.r * a.r + d * d - b.r * b.r) / 2. / a.r / d);
    int_t ang2 = acos((b.r * b.r + d * d - a.r * a.r) / 2. / b.r / d);
    int_t ret = ang1 * a.r * a.r + ang2 * b.r * b.r - d * a.r * sin(ang1);
    return ret;
}


point_t lineCrossline(point_t a,point_t b,point_t c,point_t d)
{
    point_t  p0(0,0), u = a-c;
    int_t t = cross( p0,d-c,u ) / cross( p0,b-a,d-c );
    return point_t( a.x +(b.x-a.x)*t, a.y +(b.y-a.y)*t );
}

/**< ConvexPolygonIntersectArea */
int_t CPIA(point_t a[], point_t b[], int na, int nb)
{
    point_t p[20], tmp[20];
    int tn, sflag, eflag;
    a[na] = a[0], b[nb] = b[0];
    memcpy(p,b,sizeof(point_t)*(nb + 1));
    for(int i = 0; i < na && nb > 2; i++)
    {
        sflag = dcmp(cross(a[i],a[i + 1], p[0]));
        for(int j = tn = 0; j < nb; j++, sflag = eflag)
        {
            if(sflag>=0) tmp[tn++] = p[j];
            eflag = dcmp(cross(a[i],a[i + 1], p[j + 1]));
            if((sflag ^ eflag) == -2)
                tmp[tn++] = lineCrossline(a[i], a[i + 1], p[j], p[j + 1]); ///求交点
        }
        memcpy(p, tmp, sizeof(point_t) * tn);
        nb = tn, p[nb] = p[0];
    }
    if(nb < 3) return 0.0;
    return PolygonArea(p, nb);
}

/**< SimplePolygonIntersectArea 调用此函数 */
int_t SPIA(point_t a[], point_t b[], int na, int nb)
{
    int i, j;
    point_t t1[4], t2[4];
    int_t res = 0, num1, num2;
    a[na] = t1[0] = a[0], b[nb] = t2[0] = b[0];
    for(i = 2; i < na; i++)
    {
        t1[1] = a[i-1], t1[2] = a[i];
        num1 = dcmp(cross(t1[0],t1[1], t1[2]));
        if(num1 < 0) swap(t1[1], t1[2]);
        for(j = 2; j < nb; j++)
        {
            t2[1] = b[j - 1], t2[2] = b[j];
            num2 = dcmp(cross(t2[0],t2[1], t2[2]));
            if(num2 < 0) swap(t2[1], t2[2]);
            res += CPIA(t1, t2, 3, 3) * num1 * num2;
        }
    }
    return res;
}
const int SIZE = 550;

point_t p1[3], p2[4];
int n1, n2;
int main()
{
    double x1,y1,x2,y2;

    int kase = 1;
    while( scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2) != EOF )
    {
//         表示三角形的顶点坐标是 (x1,y1),(x1,y2),(x2,y1)， 矩形的顶点坐标是 (x3,y3),(x3,y4),(x4,y4),(x4,y3).

        p1[0] = point_t(x1,y1);
        p1[1] = point_t(x1,y2);
        p1[2] = point_t(x2,y1);

        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        p2[0] = point_t(x1,y1);
        p2[1] = point_t(x1,y2);
        p2[2] = point_t(x2,y2);
        p2[3] = point_t(x2,y1);




        double Area = SPIA(p1, p2, 3, 4);

//        cout << PolygonArea(p1,n1) << endl;
//        cout << PolygonArea(p2,n2) << endl;
        printf("%f\n",fabs(Area));
//        cout << fabs(PolygonArea(p1,n1)) + fabs(PolygonArea(p2,n2)) - Area<<endl;



    }
    return 0;
}

/**********************************************************************
	Problem: 1812
	User: bitwater
	Language: C++
	Result: AC
	Time:112 ms
	Memory:1288 kb
**********************************************************************/
