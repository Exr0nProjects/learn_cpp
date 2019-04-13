/*
 * Problem #1201
 * count primes under number
 *
 * basic steps:
 * 1. sieve up to 1M
 * 2. when we get a number
 *   a. find about the index in our sieved thing: formula is 1/(log x -1) from https://primes.utm.edu/howmany.html
 *   b. go to that position in the sieved array
 *   c. step up or down based on if we are too big or too small
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

const int max_inq =  1000000;
//const int num_primes_under_max = 78500; // https://primes.utm.edu/howmany.html section 1.2
const int num_primes_under_max = 500002; // apparently we cant use a better approximation

int numbers[max_inq/2+2] = { }; // the +2 is to get a buffer to avoid array index out of range
int primes[num_primes_under_max]; // so that the biggest is bigger than the max inquery

int sievePrimes (void)
{
  int curr_write_idx = 0;
  primes[curr_write_idx ++] = 2;

  // sieve with odd numbers
  for (int fli=1; fli*2+1<max_inq; ++fli) // i represents number*2+1
  {
    if (numbers[fli] == 0) // prime!
    {
      int rep = fli*2+1;

      primes[curr_write_idx ++] = rep; // note it down

      for (int j=fli; j<max_inq/2+2; j += rep) numbers[j] = 1; // get rid of all multiples
    }
  }
  // fill the rest with max
  for (int fli=curr_write_idx; fli<num_primes_under_max; ++fli) primes[fli] = max_inq + 1; // fill the rest with max so we dont step over
  return 0;
}

int findPrimesUnder (int max)
{
  //int search = (int) max/(log(max)-1); // approximate number of primes under max according to science
  int search = max/2; // really bad approximation

  if (max < 2) return 0;
  else if (max == 2) return 1;

  //cout << max << endl;
  if (primes[search] < max)
  {
    while (primes[search+1] < max) {
      //cout << search << ": next is " << primes[search+1] << endl;
      ++search;
    }
  }
  else // greater than max
  {
    do
    {
      --search;
      //cout << search << endl;
    }
    while (primes[search] > max);
  }
  //cout << search << endl;
  return search+1;
}

int main ()
{
  sievePrimes();
  //cout << "finished sieving!" << endl;
  int num_inqs, temp;
  cin >> num_inqs;

  for (int i=0; i<num_inqs; ++i)
  {
    cin >> temp;
    cout << findPrimesUnder(temp) << endl;
  }

  return 0;
}
