/*
 Problem name : 1050 - Marbles
 Algorithm : Probability
 Contest/Practice : Off Line Practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 20-Nov-14
*/

#include<bits/stdc++.h>

#define pause           system("pause");
#define FOR(s,e,inc)    for(int i=s;i<=e;i+=inc)
#define mod             1000000007
#define inf             1<<30
#define pb              push_back
#define ppb             pop_back
#define mp              make_pair
#define F               first
#define S               second
#define sz(x)           ((int)x.size())
#define sqr(x)          ( (x)* (x) )
#define eps             1e-9
#define gcd(x,y)         __gcd(x,y)
#define lcm(x,y)        (x/gcd(x,y))*y
#define on(x,w)         x=x|(1<<w)
#define check(x,w)      (x&(1<<w))
#define all(x)          (x).begin(),(x).end()
#define pf              printf
#define pi              acos(-1.0)
#define reset(x,v)      memset(x,v,sizeof(x));
#define AND             &&
#define OR              ||

typedef long long ll;
typedef unsigned long long llu;

using namespace std;


template<class T>
inline T mod_v(T num)
{
    if(num>=0)
        return num%mod;
    else
        return (num%mod+mod)%mod;
}

template<class T>
T fast_pow(T n , T p)
{
    if(p==0) return 1;
    if(p%2)
    {
        T g=mod_v ( mod_v(n) * mod_v(fast_pow(n,p-1)) );
        return g;
    }
    else
    {
        T g=fast_pow(n,p/2);
        g=mod_v( mod_v(g) * mod_v(g) ) ;
        return g;
    }
}

template<class T>
inline T modInverse(T n)
{
    return fast_pow(n,mod-2);
}

template<class T>
inline void debug(string S1,T S2,string S3)
{
    cout<<S1<<S2<<S3;
}

template<class T>
inline T in()
{
    register char c=0;
    register T num=0;
    bool n=false;
    while(c<33)c=getchar();
    while(c>33){
        if(c=='-')
            n=true;
        else num=num*10+c-'0';
        c=getchar();
    }
    return n?-num:num;
}

#ifndef ONLINE_JUDGE
#  define p(x) cout<<x<<endl;
#else if
#  define p(x) 0;
#endif

/*...... ! Code start from here ! ......*/


int r,b;
double dp[505][505][2];
bool take[505][505][2];

double re(int red,int blue,int turn)
{
    //printf("%d %d %d\n",red,blue,turn);pause

    if (red == 0)           return 1.0;
   // if (blue == red)        return 0.0;
    if (blue <= 0)          return 0.0;

    double &res=dp[red][blue][turn];

    if(take[red][blue][turn]) return res;

    take[red][blue][turn]=true;
    res=0.0;

    if(!turn)
    {
        if(red)
        res+=( (double)red*(1.0/double(red+blue*1.0))*re(red-1,blue,1-turn));
        if(blue)
        res+=( (double)blue*(1.0/double(red+blue*1.0))*re(red,blue-1,1-turn));
    }
    else if(blue)
        res=re(red,blue-1,1-turn);

    return res;
}

int main()
{
    int t,tcase=1;

    t=in<int>();

    reset(take,false);

    while(t--)
    {
        r=in<int>();
        b=in<int>();

        printf("Case %d: %lf\n",tcase++,re(r,b,0));
    }
    return 0;
}

