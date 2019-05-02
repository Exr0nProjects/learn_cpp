/*
 * Problem #3290
 * best students
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main ()
{
  int students, classes;
  cin >> students >> classes;

  string temp; getline(cin, temp);

  bool * isgood = new bool [students];

  short ** grades = new short * [students];
  for (int stud=0; stud<students; ++stud)
  {
    grades[stud] = new short [classes];

    getline(cin, temp);
    for (int j=0; j<classes; ++j) grades[stud][j] = (short) temp[j];
  }

  for (int c=0; c<classes; ++c)
  {
    // get max for that class
    short max = 0;
    for (int s=0; s<students; ++s) if (grades[s][c] > max) max = grades[s][c];
    // mark the best students as good
    for (int s=0; s<students; ++s) if (grades[s][c] == max) isgood[s] = true;
  }

  int good_students = 0;
  for (int s=0; s<students; ++s) if (isgood[s]) ++ good_students;

  cout << good_students;

  return 0;
}
