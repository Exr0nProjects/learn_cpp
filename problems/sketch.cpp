#include <cstdio>

int main() {
  std::printf("%lu\n", sizeof(long long));
  long long ll;
  ll = 1 << 31;
  std::printf("%lld\n", ll);
}

