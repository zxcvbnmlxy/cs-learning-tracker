#include<iostream>
#include<cstring>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<thread>
#include<netinet/in.h>
#include<atomic>
#include<vector>
using namespace std;
atomic<int>ok{0},bad{0};
void client_work(int id){
    int fd=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    addr.sin_port=htons(8888);
    if(connect(fd,(struct sockaddr*)&addr,sizeof(addr))<0){
        perror("connect error");return ;
    }
    char buf[2048];
    for(int i=0;i<2048;i++)buf[i]=i%256;
    int sent=0;
    while(sent<2048){
        int n=send(fd,buf+sent,2048-sent,0);
        if(n<=0){bad++;return;}
        sent+=n;
    }
    unsigned char got[2048];
    int total=0;
    while(total<2048){
        int n=recv(fd,total+got,2048-total,0);
        if(n<=0){bad++;close(fd);return ;}
        total+=n;
    }
    for(int i=0;i<2048;i++){
        if(got[i]!=i%256){bad++;close(fd);return ;}

    }
    ok++;
    close(fd);
}
int main(){
    int N=500;
    vector<thread>ts;
    for(int i=0;i<N;i++)ts.emplace_back(client_work,i);
    for(auto &t:ts)t.join();
    cout<<"ok"<<ok<<"bad"<<bad<<endl;
    return 0;
}