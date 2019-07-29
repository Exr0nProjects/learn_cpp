const int MAXSZ = 1; // todo

class EdgeList
{
  const static int maximum_size = MAXSZ; // maximum number of nodes
  
  struct Edge
  {
    int to, next;
  } edges[2*maximum_size];

  int next = 0;
  int _head[maximum_size];
  
public:
  EdgeList () {};
  void add (const int a, const int b)
  {
    edges[next].next = _head[a];
    _head[a] = next ++;
    
    edges[next].next = _head[b];
    _head[b] = next ++;
  };
  Edge& head (const int n) { return &( edges[_head[n]] ); };
  void setTo
};
