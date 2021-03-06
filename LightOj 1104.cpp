/*
 Problem name : 1104 - Birthday Paradox
 Algorithm : Probability
 Contest/Practice : Off Line practice
 Source : Light Oj
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 24-Aug-15
 Last Update : 25-Mar-2015
*/

/*
	It’s gonna be ok, it’s gonna be ok
	this issue is temporary so attempt to wait for one - more - day
	There’s nothing wrong with you, it’s them - they’re just backwards
	You’re in the future, they’re in the past
	and they would abuse you if they knew the facts about it
	It’s gonna be ok, it’s gonna be ok
	this issue is temporary so attempt to wait until - you’re - safe
	You love her, don’t ever feel you should apologise
	can’t control your feelings or compromise,
	i know it’s difficult to find a guiding a light now but you’ll come out alive
	So

	HOLD ON
	Until you find the friends who’ll support you
	Until you find a place you feel secure, you need to
	HOLD ON
	Until you’re independent
	Wherever in the spectrum you are

	It’s gonna be ok
	It’s gonna be ok


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
#define lcm(x,y)        (abs(x) /gcd(x,y))* abs(y)
#define on(x,w)         x|(1<<w)
#define check(x,w)      (x&(1<<w))
#define all(x)          (x).begin(),(x).end()
#define pf              printf
#define sf              scanf
#define pi              acos(-1.0)
#define reset(x,v)      memset(x,v,sizeof(x));
#define AND             &&
#define OR              ||
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";

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
inline T gcd(T a,T b)
{
    a=abs(a);
    b=abs(b);

    while(b) b ^= a ^= b ^= a %= b;
    return a;
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

bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}


template<class T>
inline int in(register T& num)
{
    register char c=0;
    num=0;
    bool n=false;
    while(c<33)c=getchar();
    while(c>33){
        if(c=='-')
            n=true;
        else num=num*10+c-'0';
        c=getchar();
    }
    num=n?-num:num;
    return 1;
}

/******* ! Code start from here ! *******/


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
//        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    double d;
    int t,tcase=1;

    in(t);

    while(t--)
    {
        scanf("%lf",&d);

        ll res=0;


        double get=1.0;

        while(1)
        {
            get*=( (d- (ll) res)/d  ) ;

            if(lessThanEqual(get,0.5)) break;  res++;
        }

        pf("Case %d: %lld\n",tcase++,res);
    }


    return 0;
}

