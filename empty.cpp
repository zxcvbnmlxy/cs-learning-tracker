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

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,M;
struct Node{
   long long   data;
   int lazy=0;
};
vector<Node>tree;
vector<long long>a;
void build(int node,int l,int r){
    if(l==r){
        tree[node].data=a[l];return ;
    }
    int mid=l+(r-l)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    tree[node].data=tree[node*2].data+tree[node*2+1].data;
}
//lazy标记下沉，当查询到时候才，将lazy相加，不用每加一次就将区间内的数相加上k
void pushDown(int node,int l,int r){
    if(tree[node].lazy!=0){
        int mid=l+(r-l)/2;
        tree[node*2].data+=tree[node].lazy*(mid-l+1);
        tree[node*2+1].data+=tree[node].lazy*(r-mid);
        tree[node*2].lazy+=tree[node].lazy;
        tree[node*2+1].lazy+=tree[node].lazy;
        tree[node].lazy=0;
    }
}
void update(int node,int l,int r,int ql,int qr,ll k){
    if(qr<l||ql>r)return ;
    if(ql<=l&&qr>=r){
        tree[node].data+=k*(r-l+1);
        tree[node].lazy+=k;
        return ;
    }
    int mid=l+(r-l)/2;
    pushDown(node,l,r);//劈成两个区间，将当前的lazy标记下沉到儿子
    update(node*2,l,mid,ql,qr,k);
    update(node*2+1,mid+1,r,ql,qr,k);
    tree[node].data=tree[node*2].data+tree[node*2+1].data;
}
long long  query(int node,int l,int r,int ql,int qr){
    if(ql>r||qr<l){
        return 0;
    }
    if(ql<=l&&qr>=r)return tree[node].data;
    int mid=l+(r-l)/2;
    pushDown(node,l,r);
    long long leftsum=query(node*2,l,mid,ql,qr);
    long long rightsum=query(node*2+1,mid+1,r,ql,qr);
    return leftsum+rightsum;
}
int main(){
    cin>>N>>M;
    tree.resize(4*N+1);
    a.resize(N+1);
    
    for(int i=1;i<=N;i++){
        cin>>a[i];
    }
    build(1,1,N);
    while(M--){
        int op;cin>>op;
        if(op==2){
            int x,y;cin>>x>>y;
            cout<<query(1,1,N,x,y)<<endl;;
        }
        else {
            int x,y;ll k;cin>>x>>y>>k;
            update(1,1,N,x,y,k);
        }
    }
    return 0;
}