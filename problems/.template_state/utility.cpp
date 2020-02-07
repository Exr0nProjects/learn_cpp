const int MX = 20;
int N = MX-10;
using namespace std;

// edge list
struct Edge
{
  int f, t, w, n;
} edges[MX*MX];
int head[MX], ect=1;
void addEdge(cn a, cn b, cn w)
{
  edges[ect].f = a;
  edges[ect].t = b;
  edges[ect].w = w;
  edges[ect].n = head[a];
  head[a] = ect++;
}

// binary search
int binarySearch(const int l, const int r) // include l, exclude r
{
  if (l+1 >= r) return l;
  int m = (l+r)/2;
  if (sim(m)) return binarySearch(m, r);
  else return binarySearch(l, m);
}

// disjoint set
int djs_f[MX]; // father
int djs_s[MX]; // size
void init()
{
  for (int i=0; i<N; ++i)
    djs_s[i] = 1;
  iota(djs_f, djs_f + N, 0);
}
int find(const int n)
{
  //  printf("finding %d\n", n);
  if (djs_f[n] != n)
    djs_f[n] = find(djs_f[n]);
  return djs_f[n];
}
void merge(int a, int b)
{
  a = find(a);
  b = find(b);
  if (djs_s[a] < djs_s[b])
    swap(a, b);
  djs_s[a] += djs_s[b];
  djs_f[b] = a;
}

// io
void setIO(const string &name)
{
  ios_base::sync_with_stdio(0); cin.tie(0); // fast cin/cout
  if (fopen((name+".in").c_str(), "r") != nullptr)
  {
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w+", stdout);
  }
}