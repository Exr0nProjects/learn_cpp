/*
 * Problem #7084
 * binary tree encoding
 */

#include <bits/stdc++.h> // includes "everything"
#define ll long long
#define dl double

using namespace std;
https://github.com/Exr0n/learn_cpp/tree/master/problems/2.13
string encode (const vector<int> inp, const int siz);

int main ()
{
	int num, layers = 1;
	cin >> num;
	layers <<= num;
//d	printf("%d\n", layers);
	
	vector<int> tree(layers);
	for (int i=0; i<layers; ++i) { char t; cin >> t; tree[i]=(int)t-48; }
	
	cout << encode(tree, layers);
	
    return 0;
}

string encode (const vector<int> inp, const int siz)
{
	if (siz == 1) return (inp[0] == 0 ? "B" : "C"); // break case
	
	vector<int> inp2(siz/2);
	for (int i=0; i<siz/2; ++i) inp2[i] = inp[siz/2+i];
/*debug	
	printf("    encode called, size %d\n    inp: ");
	for (int i=0; i<siz/2; ++i) printf("%d ", inp[i]);
	for (int i=0; i<siz/2; ++i) printf("%d ", inp2[i]);
*/
	string ret = encode(inp, siz/2) + encode(inp2, siz/2);
	
	int msum = 0;
	for (int i=0; i<siz; ++i) msum += inp[i];
	
	if (msum == 0) return ret + "B";
	if (msum == siz) return ret + "C";
	else return ret + "A";
}
