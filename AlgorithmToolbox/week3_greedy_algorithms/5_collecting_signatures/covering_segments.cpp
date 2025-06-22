#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  int last_point =-1;
  sort(segments.begin(), segments.end(),[](Segment a, Segment b){
    return a.end<b.end;
  });
  for(Segment s : segments){
    if(last_point<s.start){
      last_point = s.end;
      points.push_back(s.end);
    }
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
