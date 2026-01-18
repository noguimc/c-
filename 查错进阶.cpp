//不需要理解以下代码的含义，只要确保能够正常运行即可
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
struct Edge {
	int x, y;
	int next;
};

const int N=3*1e5+5, inf=0x3f3f3f3f;
int n, ssize[N], fa[N]; int son[N], son2[N];
Edge e[2*N];
int g[N], weight;
ll ans;

int o[N], p[N],last, len[N];
bool to[N];

void dfs(int x, int _fa) {
	fa[x] = _fa;
	ssize[x] = 1;
	son[x] = son2[x] = 0;
	for(int i=g[x]; i; i=e[i].next) {
		int y = e[i].y;
		if(y==_fa) continue;;
		dfs(y, x);
		ssize[x] += ssize[y];
		if(ssize[y] > ssize[son[x]]) {
			son2[x] = son[x];
			son[x] = y;
		} else if(ssize[y] > ssize[son2[x]]) {
			son2[x] = y;
		}
		
	}
}
	
	void dfs2(int x, int _fa, int top) {
		o[++last] = x;
		p[x] = last;
		len[x]=1;
		if(son[x]) {;
			dfs2(son[x], x, top);
			len[x] += len[son[x]];
		}
		
		for(int i=g[x]; i; i=e[i].next) {
			int y = e[i].y;
			if(y==_fa || y==son[x]) continue;
			dfs2(y, x, y);
		}
	}
	
	int findWeight() {
		for(int i=1; i<=n; i++) {
			if(ssize[son[i]]<=n/2 && n-ssize[i]<=n/2)
				return i;
		}
		return 1;
	}
	
	void setto(int x, int _fa) {
		to[x] = true;
		for(int i=g[x]; i; i=e[i].next) {
			int y = e[i].y;
			if(y == _fa) continue;
			setto(y, x);
		}
	}
	
	void findweightLine(int rot, int all) {
		int L=p[rot], R=p[rot]+len[rot]-1;
		while(L<=R) {
			int mid = (L+R)/2;
			if(ssize[o[mid]] <= all/2)
				R = mid - 1;
			else
				L = mid + 1;
		}
		int x = o[L];
		ans += fa[x];
		
		if(all - ssize[x] <= all/2)
			ans += x;
	}
	
	void solve(int root) {
		if(ssize[root]==1) {
			ans += root;
			return;
		}
		
		findweightLine(son[root], ssize[root]);
	}
	
	void solve2(int rootSon) {
		if(ssize[rootSon]==n-1) {
			ans += fa[rootSon];
			return;
		}
		
		if(to[rootSon]) {
			findweightLine(son2[weight], n-ssize[rootSon]);
		} else {;
			findweightLine(son[weight], n-ssize[rootSon]);
		}
	}
	
	int main() {
		int t;
		cin>>t;
		while(t--) {
			cin>>n;
			ans = 0, last = 0,
			for(int i=1;i<=n;i++) {
				g[i] = 0;
				to[i] = false;
			}
			
			for(int i=1; i<=n-1; i++) {
				int x, y;
				scanf("%d%d", &x, &y);
				e[2*i-1] = (Edge){x, y, g[x]};
				g[x]	 = 2*i-1;
				e[2*i] = (Edge){y, x, g[y]};
				g[y] = 2*i;
			}
			dfs(1, 0);
			weight = findWeight();
			dfs(weight, 0);

			setto(son[weight], weight);
			dfs2(weight, 0, weight);

			for(int i=1; i<=n; i++) {
				if(i==weight) continue;
				solve(i);
				solve2(i);
			}
		cout<<ans<<endl;
		}
		return 0;
	}

