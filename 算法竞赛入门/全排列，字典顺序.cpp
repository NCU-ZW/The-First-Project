#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


int n, A[50], isp[50], vis[50];
int cnt;
int recur;
void dfs(int cur) {
    recur++;
  if(cur == n ) {
      cnt++;
    for(int i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");
  }
  else for(int i = 1; i <= n; i++)
    if(!vis[i]) {
      A[cur] = i;
      vis[i] = 1;
      dfs(cur+1);
      vis[i] = 0;
    }
}

int main() {
  scanf("%d", &n);
  memset(vis, 0, sizeof(vis));
  dfs(0);
  printf("%d\n", cnt);
  printf("%d\n", recur);
  return 0;
}
