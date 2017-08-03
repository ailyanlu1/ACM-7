//基本版
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

const int SIZE = 50;

int a[SIZE][SIZE];//增广矩阵
int x[SIZE];//解集
bool free_x[SIZE];//标记是否是不确定的变元

/*
void Debug(int equ,int var)
{
    int i, j;
    for (i = 0; i < equ; i++)
    {
        for (j = 0; j < var + 1; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


*/


int gcd(int x,int y){
    if ( !x || !y ) return x > y ? x : y ;
    for (int t;t = x % y ;x = y , y = t );
    return y ;
}
inline int lcm(int a,int b){
    return a/gcd(a,b)*b;//先除后乘防溢出
}

// 高斯消元法解方程组(Gauss-Jordan elimination).(-2表示有浮点数解，但无整数解，
//-1表示无解，0表示唯一解，大于0表示无穷解，并返回自由变元的个数)
//有equ个方程，var个变元。
//增广矩阵行数为equ,分别为0到equ-1,列数为var+1,分别为0到var.
int Gauss(int equ,int var)
{
    int k;
    int max_r;// 当前这列绝对值最大的行.
    int col; //当前处理的列

    int temp;
    int free_x_num;
    int free_index;

    int ta,tb,LCM;

    fill(x,x+var+1,0);
    fill(free_x,free_x+var+1,1);

    //转换为阶梯阵.

    col = 0; // 当前处理的列

    // 枚举当前处理的行.
    for(k = 0; k < equ && col < var; k++,col++){


        // 找到该col列元素绝对值最大的那行与第k行交换.(为了在除法时减小误差)
        max_r=k;
        for(int i = k + 1; i < equ; i++ )
            if( abs( a[i][col] ) > abs( a[max_r][col] ) ) //abs是整数取绝对值，fabs是浮点数取绝对值
                max_r = i ;

        // 如果最大的不是k行,就与第k行交换.
        if( max_r != k )
            for( int j = k; j < var+1; j++ )
                swap( a[k][j] , a[max_r][j] );

        // 说明该col列第k行以下全是0了，则处理当前行的下一列.
        if ( a[k][col] == 0 ){
            k--;
            continue;
        }

        // 枚举行 ,把col 列 清0
        for(int i = k+1; i < equ; i++ ){


            if( a[i][col] != 0 ){

                /*
                    如果是两两之间是异或而不是加的话，那么按照方案二
                */

                /*
                //方案一
                LCM = lcm(abs(a[i][col]),abs(a[k][col]));
                ta = LCM/abs(a[i][col]);
                tb = LCM/abs(a[k][col]);
                if( a[i][col]*a[k][col] < 0 ) tb =- tb;//异号的情况是相加
                for( int j = col; j < var+1; j++ )
                    a[i][j] = a[i][j]*ta - a[k][j]*tb;
                /**/

                //*
                // 方案二
                for(int j = col;j < var+1 ;j++ )
                    a[i][j] ^= a[k][j];

                /**/
            }
        }
    }

    //  Debug();

    // 1. 无解的情况: 化简的增广阵中存在(0, 0, ..., a)这样的行(a != 0).
    //表示k还没到尽头，但col已经到了变量那一列。这就意味着后面的几行只有一个常量，如果常量不是0.则无解
    // 对于无穷解来说，如果要判断哪些是自由变元，那么初等行变换中的交换就会影响，则要记录交换.
    for (int i = k; i < equ; i++)
        if ( a[i][col] != 0 ) return -1;

    // 2. 无穷解的情况: 在var * (var + 1)的增广阵中出现(0, 0, ..., 0)这样的行，即说明没有形成严格的上三角阵.
    // 且出现的行数即为自由变元的个数.
    if (k < var){
        /*以下到return之前均为求变元*/
        // 首先，自由变元有var - k个，即不确定的变元至少有var - k个.
        for (int i = k - 1; i >= 0; i--){
            // 第i行一定不会是(0, 0, ..., 0)的情况，因为这样的行是在第k行到第equ行.
            // 同样，第i行一定不会是(0, 0, ..., a), a != 0的情况，这样的无解的.
            free_x_num = 0; // 用于判断该行中的不确定的变元的个数，如果超过1个，则无法求解，它们仍然为不确定的变元.
            for ( int j = 0; j < var; j++)
                if (a[i][j] != 0 && free_x[j])
                    free_x_num++, free_index = j;

            if (free_x_num > 1) continue; // 无法求解出确定的变元.
            // 说明就只有一个不确定的变元free_index，那么可以求解出该变元，且该变元是确定的.
            temp = a[i][var];
            for (int j = 0; j < var; j++)
                if (a[i][j] != 0 && j != free_index) temp -= a[i][j] * x[j];

            x[free_index] = temp / a[i][free_index]; // 求出该变元.
            free_x[free_index] = 0; // 该变元是确定的.
        }
        return var - k; // 自由变元有var - k个.
    }
    // 3. 唯一解的情况: 在var * (var + 1)的增广阵中形成严格的上三角阵.
    // 计算出Xn-1, Xn-2 ... X0.
    //同上。如果是模二就要用方案二
    //方案一

    /*
    for (i = var - 1; i >= 0; i--)
    {
        temp = a[i][var];
        for (j = i + 1; j < var; j++)
            if (a[i][j] != 0)
                temp -= a[i][j] * x[j];

        if (temp % a[i][i] != 0) return -2; // 说明有浮点数解，但无整数解.
        x[i] = temp / a[i][i];
    }
    /**/
    //*
    //方案二
    for(int i = var-1; i >= 0;i-- ){
        x[i] = a[i][var];
        for(int j = i+1;j < var; j++ )
            x[i] ^= ( a[i][j] && x[j] );
    }
    /**/
    return 0;
}
int main(){

    int t ;
    scanf("%d",&t);
    for (int k = 0;k < t;++k ){
        for (int i = 0;i < 30;++i )
            scanf("%d",&a[i][30]);

        int kn,km,kx,ky;
        for(int i=0;i<30;i++){      //构造30个方程
            kn = i/6;
            km = i%6;
            for(int j=0;j<30;j++){
                kx = j/6;
                ky = j%6;
                if( abs(kx-kn) + abs(ky-km) <= 1 )
                    a[i][j] = 1;
                else
                    a[i][j] = 0;
            }
        }

        Gauss(30,30);
        printf("PUZZLE #%d\n",k+1);
        for (int i = 0; i < 5; i++)
        {
            for ( int j = 0; j < 5; j++)
                printf("%d ", x[6 * i + j]);
            printf("%d\n",x[6*i+5]);
        }
    }

    return 0;
}


