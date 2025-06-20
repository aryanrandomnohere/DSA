#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_optimized(int a, int b){
  int maxItem = a>b?a:b;
  for(long l =maxItem; l<=(long long) a*b;l++){
    if(l%a == 0 && l%b ==0){
      return l;
    }
  }
  return (long long) a*b;
}

long long lcm_fast(int a, int b){
  int x = a, y = b;
  while(y != 0){
    int temp = y;
    y = x%y;
    x = temp;
  }
  return (1LL * a * b)/x;

}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  std::cout<<lcm_fast(a,b)<<std::endl;
  return 0;
}
