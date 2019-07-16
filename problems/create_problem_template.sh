git pull

cd $1
mkdir $2
cd $2

cat >> main.cpp <<EOF
/*
 * Problem #$2
 * 
 */

#include <bits/stdc++.h> // includes "everything"
#define ll long long
#define dl double
#define i32x 2147483647

using namespace std;


int main ()
{


  return 0;
}
EOF

cd ../..

./git_push.sh "script: creating new problem folder: $1 $2"
