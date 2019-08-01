/*
 * Post-array test (sub): Problem #3
 * 14 June 2019
 *
 */

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstring>


using namespace std;
typedef long long ll;

void propogate (vector<string>& myname, vector<long long>& score, int& idx)
{
  if (idx == 0) return;
  ll tscore = score[idx-1];
  string tname = myname[idx-1];
  score[idx-1] = score[idx];
  myname[idx-1] = myname[idx];
  score[idx] = tscore;
  myname[idx] = tname;
  -- idx;
}

int main ()
{
  int num;
  cin >> num;
  vector<string> myname(num);
  vector<ll> score(num);
  for (int i=0; i<num; ++i)
  {
    cin >> myname[i];
    cin >> score[i];
    int pt = i;
    while (score[pt] > score[pt-1] && pt !=0) propogate(myname, score, pt);
    // alphabetical
    if (score[pt] == score[pt-1])
      while (myname[pt].compare(myname[pt-1]) < 0  &&  pt != 0) propogate(myname, score, pt);
  }

  for (int i=0; i<num; ++i) cout << myname[i] << endl;

  return 0;
}
