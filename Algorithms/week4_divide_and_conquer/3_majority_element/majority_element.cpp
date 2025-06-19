#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
int getCount(vector<int> &a, int left,int right, int candidate){
  int count=0;
  for(int i = left; i<=right;i++){
  if(a[i] == candidate) count++;
  }
  return count;
}


int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return a[left];
  if (left + 1 == right) return a[left];
  int mid = left + (right - left)/2;
  int left_candidate = get_majority_element(a,left,mid);
  int right_candidate = get_majority_element(a,mid+1,right);
  if(left_candidate == right_candidate) return left_candidate;
  int left_count = getCount(a,left,right,left_candidate);
  int right_count = getCount(a,left,right,right_candidate);
  int majority_threshold = (right-left)/2;
  if(left_count > majority_threshold ) return left_candidate;
  if(right_count > majority_threshold ) return right_candidate;
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()-1)) << '\n';
}
