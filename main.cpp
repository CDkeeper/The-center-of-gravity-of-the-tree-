#include<iostream>
#include<cstring>
using namespace std;
int n,a,b;
const int maxn=1e5+5;
int st[maxn];
int h[maxn],e[maxn*2],ne[maxn*2],idx;
int ans=maxn;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int dfs(int x){
    st[x]=1;
    int sum=1,res=0;
    for(int i=h[x];i!=-1;i=ne[i]){
        int j=e[i];
        if(!st[j]){
        int dot=dfs(j);
        res=max(res,dot);
        sum+=dot;
        }
    }
    res = max(res,n-sum);
    ans = min(ans,res);
    return sum;
}
int main(){
    scanf("%d",&n);
    memset(h,-1,sizeof(h));
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&a,&b);
        add(a,b),add(b,a);
    }
    dfs(1);
    printf("%d",ans);
    return 0;
}
