#include <iostream>
using namespace std;
void get_change(int m) {
  int tens = m/10;
  m %= 10;
  int fives = m/5;
   m %= 5;
  int ones = m;
if (tens > 0) std::cout << tens << " ";
if (fives > 0) std::cout << fives << " ";
if (ones > 0) std::cout << ones << "\n";

}

int main() {
  int m;
  cin >> m;
  get_change(m);
}
