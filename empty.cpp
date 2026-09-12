// #include<iostream>
// #include<sys/socket.h>
// #include<netinet/in.h>
// #include<unistd.h>
// #include<arpa/inet.h>
// #include<cstring>
// using namespace std;
// int main(){
//     //1拿总机
//     int fd=socket(AF_INET,SOCK_STREAM,0);
//     //2bind()装SIM
//     struct sockaddr_in addr;
//     memset(&addr,0,sizeof(addr));
//     addr.sin_family=AF_INET;//IPV4
//     addr.sin_addr.s_addr=htonl(INADDR_ANY);//可以访问本机任意IP
//     addr.sin_port=htons(8888);//端口号
//     if(bind(fd,(struct sockaddr*)&addr,sizeof(addr))<0){
//         perror("bind error");return -1;
//     }
//     //3 监听listen
//     if(listen(fd,5)<0){
//         perror("listen error");
//         return -1;
//     }
//     //accept

//     char buf[1024];
//     struct sockaddr_in client_addr;
//     socklen_t len=sizeof(client_addr);
//     int client_fd=accept(fd,(struct sockaddr*)&client_addr,&len);
//     while(true){
//     int n=recv(client_fd,buf,sizeof(buf),0);
//     if(n<=0)break;
//     send(client_fd,buf,n,0);
// }
//     close(client_fd);
//     close(fd);
//     return 0;
// }


//单点修改，区间查询树状数组，b[i]存储的是原数组a下标从(i-lowbit(i)+1)到i连续数组的和
//还有一种类型是区间修改单点查询，b[i]=a[i]-a[i-1]存储的是相邻之差，差分数组 
// #include<bits/stdc++.h>
// using namespace std;
// vector<long long>b;
// int N;
// int lowbit(int x){
//     return x&(-x);
// }
// void add(int p,int k){
//     while(p<=N){
//         b[p]+=k;
//         p+=lowbit(p);
//     }
// }
// long long count(int p){
//     long long res=0;
//     while(p){
//         res+=b[p];
//         p-=lowbit(p);
//     }
//     return res;
// }
// long long query(int x,int y){
//     return coutn(y)-count(x-1);
// }
// int main(){
//     b.resize(N+1);
//     return 0;
// }

//线段树区间修改区间查询，区间和

        //         [1,4]
        //         /    \
        //        /      \
        //       [1,2]   [3,4]
        //      /    \    /   \
        //   [1,1] [2,2] [3,3] [4,4]

        //         [1,5]
        //     [1,3]    [4,5]
        // [1,2] [3,3][4,4] [5,5]

// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// int N,M;
// struct Node{
//    long long   data;
//    int lazy=0;
// };
// vector<Node>tree;
// vector<long long>a;
// void build(int node,int l,int r){
//     if(l==r){
//         tree[node].data=a[l];return ;
//     }
//     int mid=l+(r-l)/2;
//     build(node*2,l,mid);
//     build(node*2+1,mid+1,r);
//     tree[node].data=tree[node*2].data+tree[node*2+1].data;
// }
// //lazy标记下沉，当查询到时候才，将lazy相加，不用每加一次就将区间内的数相加上k
// void pushDown(int node,int l,int r){
//     if(tree[node].lazy!=0){
//         int mid=l+(r-l)/2;
//         tree[node*2].data+=tree[node].lazy*(mid-l+1);
//         tree[node*2+1].data+=tree[node].lazy*(r-mid);
//         tree[node*2].lazy+=tree[node].lazy;
//         tree[node*2+1].lazy+=tree[node].lazy;
//         tree[node].lazy=0;
//     }
// }
// void update(int node,int l,int r,int ql,int qr,ll k){
//     if(qr<l||ql>r)return ;
//     if(ql<=l&&qr>=r){
//         tree[node].data+=k*(r-l+1);
//         tree[node].lazy+=k;
//         return ;
//     }
//     int mid=l+(r-l)/2;
//     pushDown(node,l,r);//劈成两个区间，将当前的lazy标记下沉到儿子
//     update(node*2,l,mid,ql,qr,k);
//     update(node*2+1,mid+1,r,ql,qr,k);
//     tree[node].data=tree[node*2].data+tree[node*2+1].data;
// }
// long long  query(int node,int l,int r,int ql,int qr){
//     if(ql>r||qr<l){
//         return 0;
//     }
//     if(ql<=l&&qr>=r)return tree[node].data;
//     int mid=l+(r-l)/2;
//     pushDown(node,l,r);
//     long long leftsum=query(node*2,l,mid,ql,qr);
//     long long rightsum=query(node*2+1,mid+1,r,ql,qr);
//     return leftsum+rightsum;
// }
// int main(){
//     cin>>N>>M;
//     tree.resize(4*N+1);
//     a.resize(N+1);
    
//     for(int i=1;i<=N;i++){
//         cin>>a[i];
//     }
//     build(1,1,N);
//     while(M--){
//         int op;cin>>op;
//         if(op==2){
//             int x,y;cin>>x>>y;
//             cout<<query(1,1,N,x,y)<<endl;;
//         }
//         else {
//             int x,y;ll k;cin>>x>>y>>k;
//             update(1,1,N,x,y,k);
//         }
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// vector<ll>tree,a,rk;
// int n;
// void update(int node,int l,int r,int pos,int k){
//     if(l==r){tree[node]+=k;return;}
//     int mid=l+(r-l)/2;
//     if(pos<=mid)update(node*2,l,mid,pos,k);
//     else update(node*2+1,mid+1,r,pos,k);
//     tree[node]=tree[node*2]+tree[node*2+1];
// }
// ll query(int node,int l,int r,int ql,int qr){
//     if(qr<l||ql>r)return 0;
//     if(ql<=l&&qr>=r){return tree[node];}
//     int mid=l+(r-l)/2;
//     ll left=query(node*2,l,mid,ql,qr);
//     ll right=query(node*2+1,mid+1,r,ql,qr);
//     return left+right;
// }
// int main(){
//     cin>>n;
//     a.resize(n+1);
//     tree.resize(4*n+1);
//     rk.resize(n+1);
//     for(int i=1;i<=n;i++)cin>>a[i];
//     vector<ll>b(a.begin()+1,a.end());
//     sort(b.begin(),b.end());
//     for(int i=1;i<=n;i++){
//         rk[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;
//     }
//     ll ans=0;
//     for(int i=1;i<=n;i++){
//         ans+=ll(i-1)-query(1,1,n,q,rk[i]);
//         update(1,1,n,rk[i],1);
//     }
//     cout<<ans<<"\n";
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int>a(1);
//     int x;
//     while(cin>>x)a.push_back(x);
//     int n=a.size()-1;
//     vector<int>d1;
//     for(int i=1;i<=n;i++){
//         int p=upper_bound(d1.begin(),d1.end(),a[i],greater<int>())-d1.begin();
//         if(p==d1.size())d1.push_back(a[i]);
//         else d1[p]=a[i];
//     }
//         cout<<d1.size()<<"\n";
//     vector<int>d2;
//     for(int i=1;i<=n;i++){
//         int p=lower_bound(d2.begin(),d2.end(),a[i])-d2.begin();
//         if(p==d2.size())d2.push_back(a[i]);
//         else d2[p]=a[i];
//     }
//     cout<<d2.size()<<"\n";
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// vector<ll>tree,a,rk;
// void update(int node,int l,int r,int pos,ll dp){
//     if(l==r){tree[node]=max(tree[node],dp);return;}
//     int mid=l+(r-l)/2;
//     if(pos<=mid)update(node*2,l,mid,pos,dp);
//     else update(node*2+1,mid+1,r,pos,dp);
//     tree[node]=max(tree[node*2],tree[node*2+1]);
// }
// ll query(int node,int l,int r,int ql,int qr){
//     if(qr<l||ql>r)return 0;
//     if(ql<=l&&qr>=r){return tree[node];}
//     int mid=l+(r-l)/2;
//     ll left=query(node*2,l,mid,ql,qr);
//     ll right=query(node*2+1,mid+1,r,ql,qr);
//     return max(left,right);
// }
// int main(){
//     a.push_back(0);
//     ll h;
//     while(cin>>h)a.push_back(h);
//     vector<ll>b(a.begin()+1,a.end());
//     sort(b.begin(),b.end());b.erase(unique(b.begin(),b.end()),b.end());
//     int n=a.size()-1; rk.push_back(0);
//     for(int i=1;i<=n;i++){
//         int k=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;//lower_bound()在有序(升序数组中)找到第一个>=a的数的位置(迭代器\指针)
//         rk.push_back(k);
//     }
//     int m=b.size();
//     tree.assign(4*m+1,0);
//     //第一遍不上升
//     ll ans1=0;
//     for(int i=1;i<=n;i++){
//         ll dp=1+query(1,1,m,rk[i],m);
//         update(1,1,m,rk[i],dp);
//         ans1=max(dp,ans1);
//     }
//     tree.assign(4*m+1,0);
//     ll ans2=0;
//     for(int i=1;i<=n;i++){
//         ll g=1+query(1,1,m,1,rk[i]-1);
//         update(1,1,m,rk[i],g);
//         ans2=max(ans2,g);
//     }
//     cout<<ans1<<"\n"<<ans2;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// int main(){
//         int n,p;
//         cin>>n>>p;
//         vector<ll>inv(n+1);
//         inv[1]=1;
//         cout<<inv[1]<<"\n";
//         for(int i=2;i<=n;i++){
//                 inv[i]=(long long)(p-p/i)*inv[p%i]%p;
//                 cout<<inv[i]<<"\n";
//         }
//         return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int N;cin>>N;unordered_set<unsigned long long>s;
//     for(int i=0;i<N;i++){
//         string x;
//         cin>>x;unsigned long long hash=0;
//         for(char c:x){
//             hash=hash*131+(unsigned long long)c;
//         }
//         s.insert(hash);
//     }
//     cout<<s.size()<<"\n";
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// string turn(string &s){
//     for(int i=0;i<(int)s.size();i++){
//         if(s[i]>='A'&&s[i]<='Z'){
//             s[i]=s[i]-'A'+'a';
//         }
//     }
//     return " "+s+" ";
// }
// int main(){
//     string s,t;
//     int sum=0;
//     getline(cin,t);t=turn(t);
//     getline(cin,s);s=turn(s);
//     int len=t.size();
//     int index=(int)s.size()-len;
//     for(int i=0;i<=(int)s.size()-len;i++){
//         if(s.substr(i,len)==t){
//             sum++;
//             index=min(i,index);
//         }
//     }
//     if(sum==0)cout<<-1;
//     else cout<<sum<<" "<<index;
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// const int N=100005;
// int in[N];
// vector<int>g[N];
// vector<int>topo;
// int n,m;
// bool kahn(){
//         queue<int>q;
//         for(int i=1;i<=n;i++){
//               if(in[i]==0)q.push(i);  
//         }
//         while(!q.empty()){
//                 int u=q.front();q.pop();
//                 topo.push_back(u);
//                 for(int v:g[u]){
//                         in[v]--;
//                         if(in[v]==0)q.push(v);
//                 }
//         }
//         return topo.size()==n;
// }
// int main(){
//         cin>>n>>m;
//         for(int i=1;i<=m;i++){
//                 int u,v;cin>>u>>v;
//                 g[u].push_back(v);
//                 in[v]++;
//         }
//         if(kahn()){
//                 cout<<"YES\n";
//                 for(int x:topo)cout<<x<<" ";
//         }
//         else cout<<"no"<<"\n";
//         return 0;
// }

//简单线程池
#include<thread>
#include<iostream>
#include<functional>
#include<vector>
#include<queue>
#include<string>
#include<condition_variable>
#include<mutex>
#include<atomic>
class ThreadPool{
        public:
                ThreadPool(int nums):stop(false){                        for(int i=0;i<nums;i++){
                                threads.emplace_back([this]{
                                        while(1){
                                        std::function<void()>task;
                                        {
                                                std::unique_lock<std::mutex>lock(mtx);
                                               condition.wait(lock,[this]{
                                                return !tasks.empty()||stop;
                                               });
                                               if(stop&&tasks.empty())return ;
                                               task=std::move(tasks.front());
                                               tasks.pop();
                                        }
                                        task();
                                        }
                                });
                               
                        }
                }
                ~ThreadPool(){
                        {
                                std::unique_lock<std::mutex>lock(mtx);
                                stop=true;
                        }
                        condition.notify_all();
                        for(auto &t:threads){
                                t.join();
                        }
                }
                template<class F,class ...Agr>
                void enqueue(F &&f,Agr&& ... agrs){
                        std::function<void()>task=
                        std::bind(std::forward<F>(f),std::forward<Agr>(agrs)...);
                       { 
                        std::unique_lock<std::mutex>lock(mtx);
                        tasks.emplace(std::move(task));
                       }
                       condition.notify_all();
                }

        private :
                std::vector<std::thread> threads;
                std::queue<std::function<void()>> tasks;
                std::condition_variable  condition ;
                bool stop;
                std::mutex  mtx;
};
std::atomic<int>x=10;
void func(std::atomic<int> &x){
        for(int i=0;i<10;i++){
                x++;
        }  
}
int main(){
        {
        ThreadPool pool(5);
        for(int i=0;i<5;i++)
        pool.enqueue(func,std::ref(x));
        }
        std::cout<<x;
        return 0;
}