#include<bits/stdc++.h>
using namespace std;
struct Edge{//边的类
    int v,length;
};
int N,M,K,Ds,station=-1;//station表示符合要求的加油站编号
double minDis=-1,avgDis=1e9;//到最近的住宅区距离、到所有住宅区的平均距离
vector<Edge>graph[1015];//图
int dis[1015];//到住宅区和加油站的最短距离
bool visit[1015];//是否已访问过
int trans(const string&s){//将加油站的“Gi”形式的编号转换成N+i，住宅区的编号不变
    if(s[0]=='G')
        return stoi(s.substr(1))+N;
    else
        return stoi(s);
}
void Dijkstra(){
    for(int j=0;j<N+M;++j){//循环N+M次
        int v=-1,MIN=INT_MAX;
        for(int i=1;i<=N+M;++i)//找出目前距离最小的编号
            if(!visit[i]&&dis[i]<MIN){
                MIN=dis[i];
                v=i;
            }
        if(v==-1)//如果图不连通，直接返回
            return;
        visit[v]=true;//当前编号已访问
        for(Edge&e:graph[v])//更新能到达的编号的最短距离
            if(!visit[e.v]&&dis[e.v]>dis[v]+e.length)
                dis[e.v]=dis[v]+e.length;
    }
}
int main(){
    scanf("%d%d%d%d",&N,&M,&K,&Ds);
    for(int i=0;i<K;++i){
        string s1,s2;
        int k1;
        cin>>s1>>s2>>k1;
        int k2=trans(s1),k3=trans(s2);
        graph[k2].push_back({k3,k1});
        graph[k3].push_back({k2,k1});
    }
    for(int i=N+1;i<=N+M;++i){//对M个加油站使用M次Dijkstra算法
        fill(dis,dis+N+M+1,INT_MAX);
        dis[i]=0;
        fill(visit,visit+M+N+1,false);
        Dijkstra();
        double currentMindis=INT_MAX*1.0,currentAvgDis=0.0;//记录当前加油站到最近的住宅区距离、到所有住宅区的平均距离
        bool flag=true;//表示到所有住宅区的距离是否都在服务范围内
        for(int j=1;j<=N&&flag;++j)//更新相应变量信息
            if(j!=i&&dis[j]<=Ds){
                currentMindis=min(currentMindis,dis[j]*1.0);
                currentAvgDis+=dis[j]*1.0;
            }
            else if(dis[j]>Ds)
                flag=false;
        currentAvgDis/=N;
        if(flag&&(currentMindis>minDis||(currentMindis==minDis&&currentAvgDis<avgDis))){
            station=i;
            minDis=currentMindis;
            avgDis=currentAvgDis;
        }
    }
    if(station!=-1)//有符合要求的加油站，输出
        printf("G%d\n%.1f %.1f",station-N,minDis,avgDis);
    else
        printf("No Solution");
    return 0;
}
