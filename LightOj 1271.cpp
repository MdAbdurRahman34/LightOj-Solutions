// Problem name : 1271 - Better Tour
// Algorithm : BFS/DFS
// Contest/Practice : Off Line Practice
// Source : Light Oj
// Comment : Whenever you start to believe  yourself, people also start to believe in you
// Date : 23-Oct-14

#include<bits/stdc++.h>

#define pause system("pause");
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
#define mod 1000000007
#define inf 1<<30
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define sz(x) ((int)x.size())
#define sqr(x) ( (x)* (x) )
#define eps 1e-9
#define gcd(x,y) __gcd(x,y)
#define on(x,w)  x=x|(1<<w)
#define check(x,w) (x&(1<<w))==(1<<w)?true:false
#define all(x) (x).begin(),(x).end()
#define pf printf
#define reset(x,v) memset(x,v,sizeof(x));
#define AND &&
#define OR ||

typedef long long ll;
typedef unsigned long long ull;

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
inline void memset1(vector<T>&v,T value)
{
    for(int i=0;i<sz(v);i++)
        v[i]=value;
}

template<class T>
inline void memset2(vector<vector<T> >&v,T value)
{
    for(int i=0;i<sz(v) ;i++)
        for(int j=0;j<sz(v[i]);j++)
            v[i][j]=value;
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
#  define print(x) 0;
#endif

//.......Code start from here ! ......


vector<int>aj_list[50005];
//nod visit[50005];
int visit[50005];
int n,num,source,des;

inline void input()
{
    scanf("%d",&n);
//     n==in<int>();
//    scanf("%d",&num);
    num=in<int>();
    source=des=num;

    for(int i=1;i<n;i++)
    {
//        scanf("%d",&num);
        num=in<int>();
        aj_list[des].pb(num);
        aj_list[num].pb(des);

        des=num;
    }
}

inline void bfs()
{
    queue<int>q;
    vector<int>kp;

    q.push(source);

    visit[source]=-1;
    while(!q.empty())
    {
        int nw=q.front();

        q.pop();

        if(nw==des)
        {
            break;
        }

        for(int i=0;i<sz(aj_list[nw]);i++)
        {
            if(visit[aj_list[nw][i]]==0)
            {
                kp.pb(aj_list[nw][i]);
                visit[aj_list[nw][i]]=nw;
            }
        }
        sort(all(kp));
        for(int i=0;i<sz(kp);i++)
        {
            q.push(kp[i]);
        }
        kp.clear();
    }
}

inline void print_path()
{
    vector<int>ans;

    int temp=des;

    ans.pb(temp);

    while(visit[temp]!=-1)
    {
        ans.pb(visit[temp]);

        temp=visit[temp];
    }

    for(int i=sz(ans)-1;i>=0;i--)
    {
        printf("%d",ans[i]);

        if(i>0)
            printf(" ");
    }

    printf("\n");
}


int main()
{
    int t,tcase=1;

//    scanf("%d",&t);
    t=in<int>();
    while(t--)
    {
        for(int i=0;i<50005;i++)
            aj_list[i].clear();
        memset(visit,0,sizeof(visit) );

        input();

        bfs();

        printf("Case %d:\n",tcase++);

        print_path();
    }
    return 0;
}


