// usaco bronze 2016 january #1: thats as pure as it gets
#include <cstdio>
int main ()
{
  int s1, g1, p1, s2, g2, p2;
  std::fscanf(fopen("promote.in", "r"), "%d%d%d%d%d%d%d%d", &s1, &s1, &s1, &s2, &g1, &g2, &p1, &p2);
  std::fprintf(fopen("promote.out", "w+"), "%d\n%d\n%d\n", s2-s1 + (g2-g1+(p2-p1)), g2-g1+(p2-p1), p2-p1);
}
