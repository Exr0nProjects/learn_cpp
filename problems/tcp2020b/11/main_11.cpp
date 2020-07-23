// miles 11
#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <cctype>
#include <cstdlib>
#include <map>
#include <cmath>

using namespace std;
double calc(double one,double two,char expresson){
  if(expresson == '+'){
    return one+two;
  }
  if(expresson == '-'){
    return one-two;
  }
  if(expresson == '*'){
    return one*two;
  }
  if(expresson == '/'){
    return one/two;
  }
  if(expresson == '^'){
    return pow(one,two);
  }
  return 0;
}
double size(char thing){
  if(thing == '+'){
    return 1;
  }
  if(thing == '-'){
    return 1;
  }
  if(thing == '*'){
    return 2;
  }
  if(thing == '/'){
    return 2;
  }
  if(thing == '^'){
    return 3;
  }
  return 0;
}

int main() {
  stack <double> num;
  stack <char> op;
  string eq;
  getline(cin, eq);
  eq = '(' + eq + ')';
  int count = 0;
  double integer;
  while (count < eq.size()){
    integer = 0;
    if (isdigit(eq[count])){
      while (isdigit(eq[count])){
        integer = integer * 10 + eq[count] - 48;
        count++;
      }
      if (eq[count] == '.'){
        count++;
        double decimal = 0;
        double small = 0.1;
        while (isdigit(eq[count])) {
          decimal = decimal + small * (eq[count] - 48);
          small /= 10;
          count++;
        }
        integer += decimal;
      }
      num.push(integer);
    }else{
      if (eq[count - 1] == '(' && eq[count] != '('){
        num.push(0);
      }
      if (eq[count] == '('){
        op.push('(');
        count++;
        continue;
      }
      if (eq[count] == ')'){
        while (op.top() != '('){
          double first = num.top();
          num.pop();
          double second = num.top();
          num.pop();
          num.push(calc(second, first,op.top()));
          op.pop();
        }
        op.pop();
      }else{
        while (size(eq[count]) <= size(op.top())){
          double first = num.top();
          num.pop();
          double second = num.top();
          num.pop();
          num.push(calc(second, first,op.top()));
          op.pop();
        }
        op.push(eq[count]);
      }
      count++;
    }
  }
  cout.precision(3);
  cout << fixed << num.top() << endl;
  return 0;
}

