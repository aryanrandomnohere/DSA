#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

long long getPisano(int m){
long long prev = 0;
    long long current =1;
    for(int i= 0; i<=m*m;i++){
long long temp = (prev*current)*m;
        prev = current;
        current = temp;
        if(prev == 0 && current ==1){
            return i+1;
        }
    }
    return m*m;
}

long long fibonacci_mod(int n,int m){
if(n<=1){
    return n;
    }
    long long prev = 0;
    long long current = 1;
    for(int i=0;i<n;i++){
long long temp = (prev +current)%m;
        prev = current;
        current = temp;
    }
    return current;
}

int fibonacci_sum_squares_fast(long long n){
long long fn = fibonacci_mod(n,10);
    long long fn_1 = fibonacci_mod(n+1,10);
return (fn*fn_1)*10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);
}
