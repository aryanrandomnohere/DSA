#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> dp_optimat_solution(int n){
  vector<int> optimalNumbers(n+1, INT_MAX);
  vector<int> paths(n+1, -1);
   optimalNumbers[1] = 0;
  for(int i = 2 ; i<=n;i++){
    if(optimalNumbers[i-1] + 1 < optimalNumbers[i] ){
      paths[i] = i-1;
      optimalNumbers[i] = optimalNumbers[i - 1] + 1;
     }
     if(i%2 == 0 && optimalNumbers[i/2] + 1 < optimalNumbers[i]){
      optimalNumbers[i] = optimalNumbers[i/2] + 1;
      paths[i] = i/2;
     }
     if(i%3 == 0 && optimalNumbers[i/3] + 1 < optimalNumbers[i]){
      optimalNumbers[i] = optimalNumbers[i/3] + 1;
      paths[i] = i/3;
     }
  }

  vector<int> sequence;
  for(int x = n; x != -1; x=paths[x]){
    sequence.push_back(x);
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;

  
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
