#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
const int maxn=100005;
int n,tot,minn,sum,root,delta,seed=2333;
struct node{
	int ch[2],val,rd,sum,siz;
}t[maxn];
int rand_(){return seed=(int)((((seed^998244353)+19260817ll)*19890604ll)%1000000007);}
void update(int x){
	t[x].siz=t[t[x].ch[0]].siz+t[t[x].ch[1]].siz+t[x].sum;
}
void rorate(int &x,int p){
	int son=t[x].ch[p];
	t[x].ch[p]=t[son].ch[p^1],t[son].ch[p^1]=x;
	update(x); update(son); x=son;
}
void insert(int &x,int val){
	if (!x) {
		x=++tot,t[x].val=val,t[x].sum=t[x].siz=1,t[x].rd=rand_();
		return;
	}
	t[x].siz++; int p;
	if (t[x].val==val) {t[x].sum++; return;}
	if (val>t[x].val) p=1; else p=0;
	insert(t[x].ch[p],val);
	if (t[x].rd>t[t[x].ch[p]].rd) rorate(x,p);
}
void del(int &x,int val){
	if (!x) return;
	if (t[x].val==val) {
		if (t[x].sum>1) {
			t[x].sum--,t[x].siz--; return;
		}else {
			int d=t[t[x].ch[0]].rd>t[t[x].ch[1]].rd;
			if (t[x].ch[0]==0||t[x].ch[1]==0) x=t[x].ch[0]+t[x].ch[1];
			else {rorate(x,d); del(x,val);}
		}
	} else{
		t[x].siz--;
		del(t[x].ch[t[x].val<val],val);
	}
}
int kth(int x,int k){
	if (k>t[x].siz||k<=0) return -1;
	while (1){
		if (k<=t[t[x].ch[0]].siz) x=t[x].ch[0];
		else if (k>t[t[x].ch[0]].siz+t[x].sum)
			k-=t[t[x].ch[0]].siz+t[x].sum,x=t[x].ch[1];
		else return t[x].val;
	}
}
int main(){
	scanf("%d%d",&n,&minn);
	for (int i=1;i<=n;i++) {
		char ch=getchar();
		while (ch!='I'&&ch!='A'&&ch!='S'&&ch!='F') ch=getchar();
		int x; scanf("%d",&x);
		if (ch=='I') if (x>=minn) insert(root,x-delta);
		if (ch=='A') delta+=x;
		if (ch=='S') {
			delta-=x;
			int p=t[root].siz;
			for (int i=1;i<=p;i++){
				int kt=kth(root,1);
				if (kt+delta<minn) {sum++,del(root,kt);} else break;
			}
		}
		if (ch=='F') {
			int k=kth(root,t[root].siz-x+1);
			if (k!=-1) k+=delta; printf("%d\n",k);
		}
	}
	printf("%d\n",sum);
	return 0;
}

