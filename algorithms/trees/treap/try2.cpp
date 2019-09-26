/*
26 Sep 2019
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1010;
typedef int nix;
typedef int nval;
typedef int nrnd;
nix child[MAXSZ*2]; // children of i are at child[2*i] and child[2*i+1]
nval val[MAXSZ];
nrnd rnd[MAXSZ];