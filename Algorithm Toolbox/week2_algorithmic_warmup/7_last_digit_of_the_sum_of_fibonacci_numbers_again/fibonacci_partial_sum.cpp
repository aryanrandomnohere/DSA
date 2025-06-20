#include <iostream>
#include <vector>
// using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}
long long getPisano(int m ){
long long prev = 0;
    long long current =1;
    for(int i =0; i<m*m; i++){
    long long temp = (prev+current)%m;
    prev = current;
        current = temp;
    
    if(prev == 0 && current == 1){
    return i+1;
    }
    }
    return m*m;
}

long long fibonacci_mod(int n, int m){
if(n<=0){
    return n;
    }
    long long prev = 0,current = 1;
    for(int i = 0;i<n ;i++){
    long long temp = (prev + current )%m;
        prev = current;
        current = temp;
    }
    return current; 
}

long long get_fibonacci_partial_sum_fast(int from, int to){
    long long pisano = getPisano(10);
    int to_mod = (to+2)%pisano;
    int from_mod = (from+1)%pisano;
    long long fib_to = fibonacci_mod(to_mod,10);
    long long fib_from = fibonacci_mod(from_mod,10);
    return (fib_to - fib_from + 10)%10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
