#include <iostream>
#include <vector>
using namespace std;
using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int total_sum = 0;
  for(int i=1; i<n;i++){
    if((total_sum + i)<n){
      summands.push_back(i);
      total_sum += i;
    }else if((total_sum + i) == n){
      summands.push_back(i);
      break;
    }else if((total_sum +i)>n){
      int diff = (total_sum + i) - n;
      cout<<diff;
      summands[summands.size()-1] += i-diff;
      cout<<summands.back(); 
      break;
  }
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
