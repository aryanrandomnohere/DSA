#include <iostream>

int get_change(int m) { 
std::vector<int> denomination = {1, 5 ,6}; 
std::vector<int> minCoins(m+1, INT_MAX);
minCoins[0] = 0;
for( int i = 1; i < minCoins.size();i++){
  for(int coin : denomination){
      if(coin<=i && minCoins[i-coin] != INT_MAX ){
        minCoins[i] = std::min(minCoins[i-coin] + 1, minCoins[m]);
      }
  }
}
return minCoins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
