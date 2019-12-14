 11:27 AM
grading falure due to network outage
i finished the first problem though
<Y> 11:27 AM
Yeah, continue your coding, you can wait a bit and resubmit in 0.5h
<Exr0n> 11:28 AM
ok
<Y> 11:28 AM
USACO website is not that stable
<Exr0n> 11:56 AM
image.png 
image.png


<Y> 11:57 AM
Good
You pass for the first problem as well?
<Exr0n> 11:57 AM
checking now...
network error again
<Y> 11:58 AM
:rolling_on_the_floor_laughing:
Try it again later
Continue with problem 3 please
<Exr0n> 12:18 PM
i don't understand problem 3
all of my own test cases work but it only works for the sample on the website
/*
ID: spoytie2
TASK: cowjog
LANG: C++14
*/
/*
 * Problem cowjog (usaco/bronze/cowjog)
 * Created Wed 27 Nov 2019 @ 12:02 (PST)
 * Accepted [!meta:end!]
 * problem # 489
 */
#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
#include <math.h>
#include <random>
#include <set>
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#define cn const int
#define ca const auto &
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338
using namespace std;
//auto fin = fopen("cowjog.in", "r");
//auto fout = fopen("cowjog.out", "w+");
const int MAXSZ = 1; // todo
int n;
int main ()
{
  scanf("%d", &n);
  int groups = 0, slowest = -1, prev = -1;
  for (int i=0; i<n; ++i)
  {
    int p, s;
    scanf("%d%d", &p, &s);
    // check
    if (s < slowest || slowest == -1)
    {
      groups ++;
      slowest = s;
    }
    else if (s == slowest)
    {
      if (p > prev + 1 || prev == -1) // another group will form
      {
        groups ++;
      }
    }
    // update
    prev = p;
  }
  printf("%d\n", groups);
  return 0;
}
/*
5
0 5
1 4
2 4
3 5
4 4
expect: 2
5
0 5
1 4
2 4
3 5
5 4
expect: 3
 */
<Y> 12:28 PM
Lets continue the test
We talk about problem after it
<Exr0n> 12:28 PM
yes i am working on #4 now
although i have to leave kinda soon
<Y> 12:29 PM
Surr
Sure
Don't worry, we can resume after you come back
<Exr0n> 1:24 PM
I wrote my codes for #4 as well, but couldn't subti
*submit
i gotta go now too
pause: 2h 15m
<Y> 1:35 PM
Sure
No worry
<Exr0n> 5:44 PM
problem #1
image.png 
image.png


<Y> 5:46 PM
How about the others?
You sent me problem 2
<Exr0n> 5:46 PM
still submitting, #3 is only first test case remember?
anyways im just submitting the problems rn i don't have time to sit down and work
maybe i do let me check
okay i will continue working now
well, in 2 minutes
<Y> 5:49 PM
Sure
<Exr0n> 5:49 PM
network error again
i cannot submit #4
and i don't know whats wrong with #3
<Y> 5:50 PM
The website is sad
So your problem 3 worked only for the first sample test case?
<Exr0n> 5:51 PM
yes
heres my code:
/*
ID: spoytie2
TASK: cowjog
LANG: C++14
*/
/*
 * Problem cowjog (usaco/bronze/cowjog)
 * Created Wed 27 Nov 2019 @ 12:02 (PST)
 * Accepted [!meta:end!]
 * problem # 489
 */
#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
#include <math.h>
#include <random>
#include <set>
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#define cn const int
#define ca const auto &
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338
using namespace std;
 auto fin = fopen("cowjog.in", "r");
 auto fout = fopen("cowjog.out", "w+");
const int MAXSZ = 1; // todo
int n;
int main ()
{
  fscanf(fin, "%d", &n);
  int groups = 0, slowest = -1, prev = -1;
  for (int i=0; i<n; ++i)
  {
    int p, s;
    fscanf(fin, "%d%d", &p, &s);
    // check
    if (s < slowest || slowest == -1)
    {
      groups ++;
      slowest = s;
    }
    else if (s == slowest)
    {
      if (p > prev + 1 || prev == -1) // another group will form
      {
        groups ++;
      }
    }
    // update
    prev = p;
  }
  fprintf(fout, "%d\n", groups);
  return 0;
}
@<Y> what should i Do?
<Y> 5:53 PM
Did you make up some other test cases?
<Exr0n> 5:53 PM
yes, i tihnk i am understanding the problem wrong
<Y> 5:54 PM
Oh okay
<Exr0n> 7:34 PM
okay, test ended
i got #1 and #2, 1/10 for #3 and 10/13 for #4
i might have fixed number 4 but i couldn't submit before the test was over
still cant submit, network outage
knowledge: I didn't really use anything advanced, i just used iteration for everything. The first two problems were relativly simple, and I think the third one should be as well, but i don't think i understood it right. the fourth one I ended up writing some really complex logic and i think there should be a better way to do it than my 80 lines of if statements.
strategy: I think my test-taking strategy was okay because I was able to do the first two problems quickly and had a lot of time to do the others. I need to work on debugging though, because It wasn't until I had less than 45 minutes left that I started creating a rigorous set of test cases for the last problem (#4) so I should remember to do that next time and not get lazy and put it off
action items: I think primarily i need to find out where my holes are and work on fixing them before I can progress, and I hope to be able to do problems quickly because that was very fun, encouraging, and de-stressing. I am worried that if I have too many difficult problems then i will become unmotivated and not want to work on this, which is what happened for the past few weeks. It is nice to go through and find out where the holes are and patch them so I feel like I am making progress instead of pointlessly debugging
I feel like there are other action items too, but I need your help to find them because experience with students is probably the most effective way to find these action items
<Y> 8:18 PM
Albert, I'm busy right now. I'll process your message and help you find action items. You should be able to see them tomorrow
The detailed information is very very useful
Thanks for the write-up
<Exr0n> 9:46 PM
okay, no problem
thanks!
<Exr0n> 9:19 AM
hi @<Y> i can do another test tomorrow
<Y> 10:19 AM
Sounds good
We can do another bronze test
<Exr0n> 8:29 PM
are there any specific action items i should keep in mind?
and @<Y> which bronze test should I do?
<Y> 8:20 AM
Hey Albert, let's do bronze 2015 Jan if you have time today
Let's get some more data points for gaps
<Exr0n> 8:36 AM
ok
<Exr0n> 8:57 AM
do I need to go over the answers from the last test and correct them or atleast look at what might have happened?
<Y> 9:05 AM
Yes, you should take a look. Let's discuss together after the test today.
You can look at the solutions after the tests once it ends. Don't worry about it
<Exr0n> 11:46 AM
hi @<Y> I am starting the test now
<Y> 12:22 PM
Good
<Exr0n> 1:52 PM
hi @<Y> i have only done one problem and am having trouble generating sample test cases for #1 to debug it
here is my timing so far:
12:02 started analysing problem 3
12:09 pause to look at problem #4, start coding #4
1254: realize that for #4 my dfs was counting steps not dist
1:13: give up on debugging #1, analyse #3
1:30: found out that #3 is a quadratic? taking break and returning to debugging #1
1:52 work on #2 altho #1 has no progress
<Exr0n> 3:46 PM
2:40 finished first version of #2, 9/10 test cases (missing case #4), now working on brute force soln for #3
3:15 finished brute force for #3 whatbase, TLE 1/11 correct
3:22 fixed cowroute 1, (i was processing the input as it came in but breaking the loop if the soln was found, but then the rest of the loop didn't consume the input it was supposed to), now working on fixing cowroute 2 (one test case)
3:31: fixed #2 cowroute 2, now working on optimizing brute force for #3 to gain one or two test cases (hopefully)
3:45: test over, AC # 1, 2, 4, 0/11 for #3 (i submitted a code last minute that ended up REing somehow)
<Exr0n> 3:52 PM
knowledge: again, no advanced algorithms or anything, I used iteration for the first and second, brute force for the third, and dfs for #4. I didn't know how to do the third problem so I just used a O(n^2) brute force solution, which was not so good. I tried to optimize it by tabulating incase there were repeated test cases, but it was a fruitless effort that lost me one test case
strategy: Again, I am pretty happy with my test taking strategy, because I started by doing the first problem simply and didn't debug for the full points at first,  because after I submitted for the first time I just moved on to other problems to get the easy points, because they say 80% results can be achieved in 20% time and the last 20% results requires 80% of the time. Thus, I wrote quick codes for all of the easy problems (1, 2, 4), and then went back to debug. I tried to debug section by section as I was writting the code, but usually I forget to, and also I am still figuring out how best to test my codes because at first I was using xcode but then I would have to switch my scanfs into fscanfs etc, so then I started using gcc but my compiler broke half way through. Need to consider the bets way to develop/test, better ide's? fix my gcc?
action items: I don't really know what else to put here, although it would be helpful if you could go over the problems with me so I know what exactly I can work on
I may be able to take another test tomorrow.
<Exr0n> 1:08 PM
Hi @<Y> i fixed my codes for cowjog (dec 2014 bronze 3) and whatbase (jan 2015 3), but I am still working on learning (dec 2014 bronze 4). My problem with cowjog was that I thought that cows went in the negative direction, so that the cow at position 6 had to go through position 0 (i thought the positions were a ranking).
<Exr0n> 1:10 PM
11:50: starting contest usaco bronze feb 2015
12:06: finished first version of censor, AC first 7/15 cases, others are TLE, working on hopscotch dfs with tabulation
12:25: AC hopscotch (#3), now working on  analysing #2
13:08: first version of #2 COW, 3/10 (others RE)
<Y> 1:11 PM
Wait, I just received these now
Continue with the test, I'm reading all your previous messages
<Exr0n> 1:26 PM
1:25: found the RE issue, (had incorrect for loop bounds), now 7/10 cases with TLE, working on optimizing recursion depth to make it slightly faster O(2n) instead of O(3n)
actually its much slower than that, ignore my time complexity analysis
<Exr0n> 1:41 PM
1:41: made algorithm slightly faster, but still 7/10 test cases. Now working on analysing #1 more
<Exr0n> 1:50 PM
1:50: working on a divide/conquer algorithim for #1 censoring
<Exr0n> 2:44 PM
2:21: finished psudocode for divide/conquer algorithm
4:28: realizing that my divide/conquer algorithm doesn't solve the problem (doesn't account for new instances of t being created through deletion)
image.png 
image.png


image.png 
image.png


image.png 
image.png


<Y> 2:50 PM
For COW, it's a simple DP problem
<Exr0n> 2:51 PM
I still TLE?
<Y> 2:51 PM
Let me explain a bit
<Exr0n> 2:51 PM
here is my code:
/*
ID: spoytie2
TASK: cow
LANG: C++14
*/
/*
 * Problem cow (usaco/bronze/feb2015/cow)
 * Created Sun 01 Dec 2019 @ 11:49 (PST)
 * Accepted [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
#include <math.h>
#include <random>
#include <set>
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#define cn const int
#define ca const auto &
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338
using namespace std;
FILE *fin = fopen("cow.in", "r");
FILE *fout = nullptr;
const int MAXSZ = 100000;      // todo
bool field[10][MAXSZ + 10];    // 3 letters in cow + padding
long long tab[10][MAXSZ + 10]; // dp tabulation
int n;
long long dfs(cn y, cn x, cn stp = 0)
{
  for (int i = 0; i < stp; ++i)
    //d*/  printf("  ");
    //d*/printf("dfs: %d, %d\n", y, x);
    if (y < 0 || x < 0)
      throw "y or x out of bounds!";
    else if (y >= 2)
      return tab[3][x + 1];
    else if (y >= 3)
      return 1; // made the word cow
    else if (x >= n)
      return 0; // ran out of letters
    else if (tab[y][x] >= 0)
      return tab[y][x];
  long long ret = 0;
  for (int j = x + 1; j < n; ++j) // doesn't have to go up to n because that spot would have to be an W to be worth anything anyways, and we deal with W in the base case
  {
    if (field[y + 1][j])
      ret += dfs(y + 1, j, stp + 1);
  }
  tab[y][x] = ret;
  return ret;
}
int main()
{
  if (fin)
  {
    fout = fopen("cow.out", "w+");
  }
  else
  {
    fin = stdin;
    fout = stdout;
  }
  fscanf(fin, "%d\n", &n);
  for (int j = 1; j <= n; ++j)
  {
    for (int i = 1; i <= 4; ++i) // this used to be `i<=n` which would fail for large numbers of n
      tab[i][j] = -1;            // init tabulation array
    char c;
    fscanf(fin, "%c", &c);
    if (c == 'C')
      field[1][j] = true;
    else if (c == 'O')
      field[2][j] = true;
    else if (c == 'W')
      field[3][j] = true;
  }
  tab[3][n] = field[3][n];
  for (int j = n - 1; j > 0; --j)
  {
    if (field[3][j])
      ++tab[3][j]; // ends up as either 0 or -1
    tab[3][j] += tab[3][j + 1] + 1;
  }
  tab[0][0] = -1;
  fprintf(fout, "%lld\n", dfs(0, 0));
  return 0;
}
/*
4
CWOW
=> 1
4
COWW
=> 2
6
CCOOWW
=> 8
6
COOWWW
=> 6
5
WOCOW
=> 1
7
WOCOWWO
=> 2
8
WCWOCOWO
=> 3
 */
<Y> 2:52 PM
you only care about some different kinds of combinations up to the "current index"
for example, if the current char is a 'O', you only care about how many 'C' appear before it
if the current char is a 'W', you only care about how many 'C' and 'O' combinations are there before it
<Exr0n> 2:54 PM
yes, my code does that
<Y> 2:54 PM
You can just iterate through the whole string once, and then update these things
Why you need a DFS?
<Exr0n> 2:55 PM
oh you mean combinations
hmm ok i will think about it
<Y> 2:55 PM
It does not need DFS. It's just some counting. :slightly_smiling_face:
The actual codes could be 20 lines. Let's use this opportunity to see how can you simplify your codes.
It's good. I'm actually happy that we could find a hole here.
It's typical thing that you might over-complicate a problem.
<Exr0n> 2:56 PM
i don't understand how it is just counting? dont you have to worry about order
say we have WOCOOW
<Y> 2:57 PM
yes
<Exr0n> 2:57 PM
what do you mean by counting
<Y> 2:57 PM
Then the W and O as the 1st and 2nd char doesn't help at all
<Exr0n> 2:57 PM
yes
<Y> 2:57 PM
when you reach the first C, you know there's a C up to this point
once you hit the next O after it, you know there's one CO
after the 2nd O
you know there're 2 CO
once you hit W
<Exr0n> 2:58 PM
oh i see
<Y> 2:58 PM
since you know there're two CO
you know okay i have 2 COW
<Exr0n> 2:58 PM
so you kind of run dp three times one for each letter?
<Y> 2:58 PM
no, just once is sufficient, right?
<Exr0n> 2:58 PM
i mean with three dp arrays
<Y> 2:58 PM
right
<Exr0n> 2:58 PM
okay i will try
<Y> 2:58 PM
:slightly_smiling_face:
Make the codes short and clean
<Exr0n> 2:59 PM
14:58: using teacher's single dp method for #2 COW
<Exr0n> 3:13 PM
15:13: finished cow
@<Y> what should I do next?
<Y> 3:14 PM
Did you pass?
<Exr0n> 3:14 PM
yes
<Y> 3:14 PM
Cool
Can you show me your codes?
<Exr0n> 3:14 PM
/*
ID: spoytie2
TASK: cow
LANG: C++14
*/
/*
 * Problem cow (usaco/bronze/feb2015/cow)
 * Created Sun 01 Dec 2019 @ 14:59 (PST)
 * Accepted [!meta:end!]
 * .
 ! This method was inspired by Teacher X, I thought it was 2D dp but that was too slow and there is a better way to use 1D dp, which is implemented here.
 * This method works by counting the number of possibilities of "COW" up to a given letter instead of counting the number of that letter and then fiddling with it at the end.
 * This is much faster because it works with just one pass over the data.
 ! Final compelxity O(n)
 * 
 * OG NOTE:
 * using new method: count how many combos up to a letter, 1D dp with three arrays
 */
#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
#include <math.h>
#include <random>
#include <set>
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#define cn const int
#define ca const auto &
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338
using namespace std;
FILE *fin = fopen("cow.in", "r");
FILE *fout = nullptr;
const int MAXSZ = 100000;      // todo
long long tab[10][MAXSZ + 10]; // dp tabulation
int n;
int main()
{
  if (fin)
  {
    fout = fopen("cow.out", "w+");
  }
  else
  {
    fin = stdin;
    fout = stdout;
  }
  fscanf(fin, "%d\n", &n);
  for (int j = 0; j <= n+1; ++j) tab[0][j] = 1;
  for (int j = 1; j <= n; ++j)
  {
    char c;
    fscanf(fin, "%c", &c);
    int k;
    if (c == 'C')
      k = 1;
    else if (c == 'O')
      k = 2;
    else if (c == 'W')
      k = 3;
    for (int i=1; i<4; ++i)
    {
      tab[i][j] = tab[i][j-1];
      if (i == k) tab[i][j] += tab[i-1][j]; // combinations
    }
  }
  fprintf(fout, "%lld\n", tab[3][n]);
  return 0;
}
/*
4
CWOW
=> 1
4
COWW
=> 2
6
CCOOWW
=> 8
6
COOWWW
=> 6
5
WOCOW
=> 1
7
WOCOWWO
=> 2
8
WCWOCOWO
=> 3
 */
<Y> 3:20 PM
image.png 
image.png


Your codes looks good
If you look at this piece of codes that USACO provides, do you think it looks simpler and easier to understand/debug than your codes? :slightly_smiling_face:
<Exr0n> 3:21 PM
yeah that makes sense
i have half an hour remaining in the contest...
<Y> 3:22 PM
Don't worry about the test now
<Exr0n> 3:22 PM
ok
<Y> 3:22 PM
So for the first problem, what's your thought
<Exr0n> 3:22 PM
i don't know how to do it
<Y> 3:22 PM
BTW, so this is a very good example to show what coding should look like
simpler codes makes it easier to write/read/debug
<Exr0n> 3:22 PM
yeah
here is my code for #1
/*
ID: spoytie2
TASK: censor
LANG: C++14                 
*/
/*
 * Problem censor (usaco/bronze/feb2015/censor)
 * Created Sun 01 Dec 2019 @ 11:49 (PST)
 * Accepted [!meta:end!]
 * 
 * first try finished at 12:06, 7/15 test cases, others TLE
 */
#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
#include <math.h>
#include <random>
#include <set>
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#define cn const int
#define ca const auto &
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338
using namespace std;
FILE* fin = fopen("censor.in", "r");
FILE* fout = nullptr;
const unsigned long MAXSZ = 1000000; // todo
int main ()
{
  if (fin) { fout = fopen("censor.out", "w+"); } else { fin = stdin; fout = stdout; }
  freopen("censor.in", "r", stdin);
  string s, c;
  cin >> s >> c;
  size_t i = s.find(c);
  while(i < MAXSZ)
  {
    s = s.substr(0, i) + s.substr(i+c.length());
    i = s.find(c);
  }
  fprintf(fout, "%s", s.c_str());
  return 0;
}
<Y> 3:23 PM
does string matching ring a bell for the knowledge that we've learnt?
<Exr0n> 3:23 PM
just run string.find over and over
it should be KMP right? but I am not familiar enough with it to code it
<Y> 3:23 PM
Right
KMP is one way to do it
If you look at your codes, you are trying to create a new string in each iteration
that's pretty expensive
the key point here is try not to create new strings or trigger expensive string concatenation or string erasing
<Exr0n> 3:25 PM
how should I do it then?
<Y> 3:25 PM
Take a look here
http://usaco.org/current/data/sol_censor_bronze.html
I'll need to step out to take a hair cut
Will come back later
<Exr0n> 3:26 PM
ok, i will take a look
<Y> 3:26 PM
after that, feel free to proceed with another bronze test
you don't have to wait for 301 people
<Exr0n> 3:26 PM
i probably won't do any more tests today
<Y> 3:27 PM
no worry
<Exr0n> 4:31 PM
hi @<Y> i am thinking i will go through all my contest codes and try to purify them
is that a good use of time?
or what should I do ?
<Y> 4:50 PM
yes, and I suggest you search for "USACO problem_name" in google, and try to find other people's codes
check whether it's easier than yours
and rewrite one if it does
It will be very very valuable use of your time
<Exr0n> 4:52 PM
ok
can i just look at the answer and write it based on that
<Y> 4:53 PM
yes
<Exr0n> 4:53 PM
should I like copy it
<Y> 4:53 PM
the answer in USACO website may not be the best version though
yep, read it and rewrite if you found simpler codes
<Exr0n> 4:53 PM
by rewrite do you mean memorize how they wrote it and then just rewrite it?
<Y> 4:54 PM
yes
<Exr0n> 4:54 PM
can i like copy off it but not simple copy paste
like look at it and rewrite it
maybe i will just do that and write in depth comments
<Y> 4:54 PM
it doesn't work that way, you can try it though
you can do the first time the way you described
<Exr0n> 4:55 PM
but if i am half way through and forgot whats next can I look again?
or do I have to start over?
<Y> 4:55 PM
but it doesn't become yours until you try to write it without looking at it
if you are half way, you can look back
start over would be good but not required though, depending on your time
<Exr0n> 4:56 PM
ok
i will try
<Y> 4:56 PM
It may sounds boring but it's the fastest way
it's the "shortcut"
<Exr0n> 4:56 PM
i understand
i am writting all my new versions with the file name "purify_<problemname>.cpp" and it will be on github
<Y> 4:57 PM
sg
<Exr0n> 4:57 PM
https://github.com/Exr0n/learn_cpp/tree/master/problems/usaco/bronze please take a look when you get a chance, starting in a few hours
i will let you know when I have finished a problem, I am starting with 2014 dec learning by example
<Exr0n> 5:09 PM
I didn't find any other implementations of learning by example, so I am just going with the usaco provided one
<Y> 5:10 PM
sounds good
<Exr0n> 6:40 PM
hi @<Y> i tried to code my own version of learning but it didn't work, and I have not yet gotten it AC'd. I need to go now, but next time I work on x-camp should I keep doing that or move on to other problems?
<Y> 6:41 PM
yes, you should get it done.
Did you look at the sample codes first?
<Exr0n> 6:43 PM
yes
i don't have a good understanding of how their intervals work so I was unable to code my own version
keep getting fencepost erros
<Exr0n> 4:17 PM
hi @<Y> can I take a break from learning by example? I feel like I don't understand the problem right... or i can't get rid of my fencepost errors
should I just work on rewriting something else? I have not yet done censor (feb 2015 bronze) but I don't know how to do it
<Y> 5:17 PM
censor is not a trivial question actually
you can skip it for now
<Exr0n> 8:34 PM
hi @<Y> I still cannot do learning (dec 2014 bronze)
<Y> 8:48 PM
Let's skip for now
You can proceed with the training site if you have limited time
If you have sufficient time, you can start a new bronze test
<Exr0n> 7:34 PM
to write pure codes, should i prefer base arrays or vectors?
Slackbot 7:34 PM
<Y> has paused their notifications for a bit, but they'll see your message when they're back.
If you need to get their attention right away, you can choose to notify them anyway.
<Exr0n> 7:35 PM
if i use base arrays then i have to set a size at the beginning, but if i use vectors then when scanf-ing i have to make a proxy variable, and push_back could be slow. it looks like most people use vectors...
<Exr0n> 9:07 PM
hi yuan, how should I search for good implementations of usaco bronze problems effectively? are there any good google keywords or repositories that i should look at? right now I am focusing on the usaco answers, http://www.cs.ucf.edu/~dmarino/progcontests/mysols/highschool/usaco/2014/bronze/, https://github.com/thecodingwizard/competitive-programming

GitHubGitHub
thecodingwizard/competitive-programming
Contribute to thecodingwizard/competitive-programming development by creating an account on Gi
