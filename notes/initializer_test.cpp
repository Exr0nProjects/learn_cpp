// std::fill test (Exr0n, 16 Jan 2020)

/**
 * Takeaways:
 * range based for loops are fast if you use `-O2`
 * ! memset is hecka speedy, and its even faster on vectors than on vanilla arrays.
 * ! You can only use memset on vectors if the vector contains Plain Old Data (https://stackoverflow.com/questions/4178175/what-are-aggregates-and-pods-and-how-why-are-they-special/7189821)
 */

const int SIZE = 1000000;


#include <cstdio>
#include <chrono>
#include <vector>
#include <cstring>
#include <algorithm>

typedef long double ld;

using namespace std;

const char UNITS[] = "\xC2\xB5s,"; // https://stackoverflow.com/a/5060616
// const char UNITS[] = "s,";

inline ld getTime()
{
  // https://stackoverflow.com/a/41582957/
  return (ld) std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

int arr[SIZE];
vector<int> vec(SIZE, 1);

int main()
{
  ld start_time;
  
  printf("SIZE = %d\n", SIZE);
  printf("\n\n{\n");

  // on array
  start_time = getTime();
  for (int i=0; i<SIZE; ++i)
  {
    arr[i] = 0;
  }
  printf("\"for loop over array\": %Lf%s\n", getTime()-start_time, UNITS);

  start_time = getTime();
  for (int &i : arr)
  {
    i = 0;
  }
  printf("\"range based for loop over array\": %Lf%s\n", getTime()-start_time, UNITS);
  
  start_time = getTime();
  fill(arr, arr+SIZE, 0);
  printf("\"fill over array\": %Lf%s\n", getTime()-start_time, UNITS);
  
  start_time = getTime();
  memset(arr, 0, sizeof(arr));
  printf("\"memset over array\": %Lf%s\n", getTime()-start_time, UNITS);
  
  // on vector
  start_time = getTime();
  for (int i=0; i<SIZE; ++i)
  {
    vec[i] = 0;
  }
  printf("\"for loop over vector\": %Lf%s\n", getTime()-start_time, UNITS);
  
  vec.assign(vec.size(), 1);
  
  start_time = getTime();
  for (int &r : vec)
  {
    r = 0;
  }
  printf("\"range based for loop over vector\": %Lf%s\n", getTime()-start_time, UNITS);
  
  vec.assign(vec.size(), 1);
  
  start_time = getTime();
  fill(vec.begin(), vec.end(), 0);
  printf("\"fill over vector\": %Lf%s\n", getTime()-start_time, UNITS);
  
  vec.assign(vec.size(), 1);
  
  start_time = getTime();
  vec.assign(vec.size(), 0); // http://www.cplusplus.com/reference/vector/vector/assign/ via https://stackoverflow.com/a/52454693
  printf("\"assign over vector\": %Lf%s\n", getTime()-start_time, UNITS);
  
  vec.assign(vec.size(), 1);
  
  start_time = getTime();
  memset(&vec[0], 0, sizeof(vec[0]) * vec.size()); // https://stackoverflow.com/a/1665038 (warning, this method is very prone to error)
  printf("\"memset over vector (PODs only)\": %Lf\n", getTime()-start_time);
  
  
  printf("}\n\n");
}