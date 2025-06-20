#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
using std::vector;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size(); 
  //write your code here
  for(int i = 0; i < a.size(); i++ ){
    int mid = left + (right - left)/2; 
    if(left == right) {
      cout<<"This is the position on which "<<x<<"should be set";
      return left;
    }
    if(a[mid] == x) return mid;
    if(a[mid] > x) {
      left = mid +1;
    }
    if(a[mid]< x) right = mid-1;
  }
  return left-1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << linear_search(a, b[i]) << ' ';
  }
}
