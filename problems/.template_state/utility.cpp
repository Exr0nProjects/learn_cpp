void addEdge(cn a, cn b, cn w)
{
  edges[ect].f = a;
  edges[ect].t = b;
  edges[ect].w = w;
  edges[ect].n = head[a];
  head[a] = ect++;
}

ll binarySearch(ll l, ll r) // include l, exclude r
{
  if (l+1 >= r) return l;
  ll m = (l+r)/2;
  if (sim(m)) return binarySearch(m, r);
  else return binarySearch(l, m);
}

void setIO(const string &name)
{
  ios_base::sync_with_stdio(0); cin.tie(0); // fast cin/cout
  if (fopen((name+".in").c_str(), "r") != nullptr)
  {
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w+", stdout);
  }
}