/*
 * Problem #1200
 * count letters in article
 * TODO: how can we stop inputting lines when its over?
 */

 #include <iostream>
 #include <string>
 #include <math.h>

 using namespace std;

 int count_arr[26] = {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0};

 int countChars (string line)
 {
   char temp;
   for (int i=0; i<line.length(); ++i)
   {
     temp = (int) line[i] - 97;

     if (temp < 0 || temp > 25) continue; // ignore spaces
     else ++ count_arr[temp]; // increment the proper index of the array
   }
   return 0;
 }

 int coutCounted (void)
 {
   for (int i=0; i<26; ++i)
   {
     if (count_arr[i] != 0) cout << (char) (i + 97) << ":" << count_arr[i] << endl;
   }
   return 0;
 }

int main ()
{
  string inp;
  while (getline(cin, inp))
  {
    countChars(inp);
  }
  coutCounted();
  return 0;
}
