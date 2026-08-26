// P1020 导弹拦截 - 线段树版(stdin驱动, 供洛谷提交/样例验证)
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN=200005;
int seg[MAXN*4];

void update(int node,int l,int r,int pos,int val){
    if(l==r){seg[node]=max(seg[node],val);return;}
    int mid=l+(r-l)/2;
    if(pos<=mid)update(node*2,l,mid,pos,val);
    else update(node*2+1,mid+1,r,pos,val);
    seg[node]=max(seg[node*2],seg[node*2+1]);
}
int query(int node,int l,int r,int ql,int qr){
    if(ql>r||qr<l)return 0;
    if(ql<=l&&qr>=r)return seg[node];
    int mid=l+(r-l)/2;
    return max(query(node*2,l,mid,ql,qr),
               query(node*2+1,mid+1,r,ql,qr));
}

int main(){
    vector<int> a(1);
    int x;
    while(scanf("%d",&x)==1)a.push_back(x);
    int n=a.size()-1;

    vector<int> b(a.begin()+1,a.end());
    sort(b.begin(),b.end());
    vector<int> rk(n+1);
    int k=0;
    // 手写去重+排名(等价 lower_bound)
    for(int i=1;i<=n;i++)
        rk[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;
    k=b.size();

    // ① 不上升
    memset(seg,0,sizeof(seg));
    vector<int> f(n+1);
    int ans1=0;
    for(int i=1;i<=n;i++){
        f[i]=1+query(1,1,k,rk[i],k);
        update(1,1,k,rk[i],f[i]);
        ans1=max(ans1,f[i]);
    }
    // ② 严格上升
    memset(seg,0,sizeof(seg));
    vector<int> g(n+1);
    int ans2=0;
    for(int i=1;i<=n;i++){
        g[i]=(rk[i]-1>=1)?1+query(1,1,k,1,rk[i]-1):1;
        update(1,1,k,rk[i],g[i]);
        ans2=max(ans2,g[i]);
    }
    printf("%d\n%d\n",ans1,ans2);
    return 0;
}
