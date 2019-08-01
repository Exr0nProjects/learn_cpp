/*
 * dev.xjoi 1211 1
 * 30 July 2019
 */

#include <iostream>
#include <cstdio>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
#include <math.h>
#include <random>
#include <set>
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

#define un unsigned
#define ll long long
#define dl double
#define ld long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 1; // todo

class Dir
{
  string name = "";
  Dir* parent = NULL;
  int layer = -1;
  map<string, Dir> children;
public:
  Dir () {this->layer = -1;};
  Dir (Dir* _prnt, const int _layr, const string _n)
  {
    this->parent = _prnt;
    this->layer = _layr;
    this->name = _n;
  };
  void addChild (const string& path, const int pt=0)
  {
    if (pt >= path.length()-1) return;
    int idx = path.find('/', pt);
    
    string childid = path.substr(pt, idx-pt);
    
   //d*/ printf("    parsed child %s\n", childid.c_str());
    
    if (children[childid].name == "")
      children[childid] = Dir (this, this->layer+1, childid);
    
    children[childid].addChild(path, idx+1);
  };
  
  void printRep () const
  {
    if (layer > 0)
    {
      printf("|");
      for (int i=1; i<layer; ++i) printf("    |");
      printf("----");
    }
    printf("%s", this->name.c_str());
    if (this->name.length() > 0) printf("\n");
    for (pair<string, Dir> p : children)
      p.second.printRep();
  };
  
  int getNameLen() const {return this->name.length();}
};

int main ()
{
  /*
  Dir root (NULL, 0, "root");
  root.addChild("lay1/lay2/");
  root.addChild("lay1/lay3/");
  root.addChild("cow/");
  root.printRep();
   */
  int num;
  scanf("%d\n", &num);
  string t;
  
  Dir root (NULL, -1, "");
  
  for (int i=0; i<num; ++i)
  {
    getline(cin, t);
    root.addChild(t+"/");
  }
  
  root.printRep();
  
  return 0;
}
