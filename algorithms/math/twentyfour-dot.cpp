/*
 * Twenty Four Dot
 * 30 July 2019
 * Take in four integers and output a way to make 24 if possible
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

#define ll long long
#define dl double
#define ld long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 4; // todo
const ld TOLER = 0.0001;

struct ExitExp : exception
{
  int type;
  ExitExp () {}
  ExitExp (const int _t) { this->type = _t; }
};

template <class ItemType, class UnaryF>
bool choose (const vector<ItemType>& pool, const int amnt, UnaryF clbk, const int layr=0, vector<ItemType> slct=vector<ItemType>{}, const int bitr=0)
{
  if (layr == amnt)
  { clbk(slct); return true; }
  
  for (int i=bitr; i<pool.size(); ++i)
  {
    if (layr == 0)
      slct = vector<ItemType> (amnt);
    slct[layr] = pool[i];
    choose(pool, amnt, clbk, layr+1, slct, i+1);
  }
  return false;
}

void dfc (const vector<ld>& nums, const int target, const vector<string>& expr)
{
  if (nums.size() == 1 && abs(nums[0] - target) <= TOLER)
  {
    printf("%s", expr[0].c_str());
    throw ExitExp {0};
  }
  
  for (int i=0; i<nums.size(); ++i)
  {
    for (int j=i+1; j<nums.size(); ++j)
    {
      vector<ld> next (nums.size()-1);
      vector<string> nxpr (nums.size()-1);
      int pt=0;
      for (int k=0; k<nums.size(); ++k)
      {
        if (k==i || k==j) continue;
        next[pt++] = nums[k];
      }
      
      pt = next.size()-1;
      
      next[pt] = nums[i]+nums[j];
      nxpr[pt] = "("+expr[i]+")+("+expr[j]+")";
      dfc (next, target, nxpr);
      
      next[pt] = nums[i]-nums[j];
      nxpr[pt] = "("+expr[i]+")-("+expr[j]+")";
      dfc (next, target, nxpr);
      next[pt] = nums[j]-nums[j];
      nxpr[pt] = "("+expr[j]+")-("+expr[i]+")";
      dfc (next, target, nxpr);
      
      next[pt] = nums[i]*nums[j];
      nxpr[pt] = "("+expr[i]+")*("+expr[j]+")";
      dfc (next, target, nxpr);
      
      next[pt] = nums[i]/nums[j];
      nxpr[pt] = "("+expr[i]+")/("+expr[j]+")";
      dfc (next, target, nxpr);
      next[pt] = nums[j]/nums[j];
      nxpr[pt] = "("+expr[j]+")/("+expr[i]+")";
      dfc (next, target, nxpr);
    }
  }
}

int main ()
{
  vector<int> nums;
  for (int i=0; i<MAXSZ; ++i) { int _; scanf("%d", &_); nums.push_back(_); }
  
//d*/  choose<int>( nums, 2, [](const vector<int>& v){ for (int i=0; i<v.size(); ++i) printf("%d ", v[i]); printf("\n"); } );
  
  
  return 0;
}
