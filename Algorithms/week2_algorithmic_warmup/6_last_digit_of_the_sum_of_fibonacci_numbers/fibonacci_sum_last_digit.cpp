#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int get_pisano(int m){
    int prev = 0, current = 1;
    for(int i=0; i<m*m;i++){
        long long temp = (prev+current)%m;
        prev = current;
        current = prev;
        if(prev == 0 && current == 1 ){
            return i+1;
        }
        
    }
    return m*m;
}
int fibonacci_mod(int n, int m){
    if(n<=1){
        return 1;
    }
    int prev = 0, current = 1;
    for(int i = 0; i<n;i++){
    int temp = (prev +current)%m;
        prev = current;
        current = prev;
    }
    return current;
}
int fibonacci_sum_fast(int n){
    int pisano = get_pisano(10);
    int n_plus_2 =(n+2)%pisano;
    int fib_n_plus_2 = fibonacci_mod(n_plus_2,10);
    return (fib_n_plus_2 + 9)%10;


}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
}
