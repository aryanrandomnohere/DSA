#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}
int get_pisano(int m){
   int prev = 0;
    int current = 1;
    for(int i = 0; i<m*m;i++){
        long long temp = (prev + current)%m;
        prev = current;
        current = temp;
        if(prev == 0 && current == 1){
            return i+1;
        }
     
    }
   return m*m;
}
long long get_fibonacci_huge_fast(int n, int m){
    int pisano_period = get_pisano(m);
    n = n%pisano_period;
    if(n<=1){
        return n;
    }
    long long prev = 0,current = 1;
    for(int i =2; i<=n-1;i++){
    long long temp = (prev +current)%m;
    prev = current;
        current = temp;
    }
    return current;

}
int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
