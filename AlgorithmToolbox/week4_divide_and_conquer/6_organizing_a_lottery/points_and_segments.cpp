#include <iostream>
#include <vector>

using std::vector, std::sort;

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  sort(starts.begin(), starts.end());
  sort(ends.begin(), ends.end());
  for(int i = 0; i<points.size(); i++){
    int p = points[i];
    int start_counts = std::upper_bound(starts.begin(), starts.end(), p) - starts.begin();
    int end_counts =   std::lower_bound(ends.begin(),ends.end(),p) - ends.begin();
    cnt[i] = start_counts - end_counts; 
  } 
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

//Divide them then sort them after sorting sort points too nlogn alright now what we can do is

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = naive_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
