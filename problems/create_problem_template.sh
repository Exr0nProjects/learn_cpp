git pull

cd $1
mkdir $2
cd $2

cat >> main.cpp <<EOF
/*
 * Problem #$2
 *
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{


  return 0;
}
EOF

./git_push.sh "creating new problem folder: $1 $2"
