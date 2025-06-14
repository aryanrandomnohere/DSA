#include <iostream>
#include <vector>

using std::vector;


void Merge(vector<int> &weights, vector<int> &values,int left,int mid,int right){
int n1 = mid -left +1;
  int n2 = right - mid;
int x1[n1],x2[n2];
int y1[n1],y2[n2];
  for(int i=0;i<n1;i++){
    x1[i] = weights[i];
    y1[i] = values[i];
  }
  for(int i=0;i<n2;i++){
    x2[i] = weights[i+n1];
    y2[i] = values[i+n1];
  }
  int idx=0,i=0,j=0;
  while(i<n1&& j<n2){
    if((double)y1[i]/x1[i]>=(double)y2[j]/x2[j]){
      weights[idx] = x1[i];
      values[idx] = y1[i];
      idx++;
      i++;
    }else{
      weights[idx] = x2[j];
      values[idx] = y2[j];
      idx++;
      j++;
    }
  }
    while (i < n1) {
        weights[idx] = x1[i];
        values[idx] =  y1[i];
        idx++;
        i++;
    }

    while (j < n2) {
        weights[idx] = x2[j];
        values[idx] = y2[j];
        idx++;
        j++;
    }


}



void MergeSort(vector<int> &weights, vector<int> & values,int left, int right) {
  if(left >= right) return;
  int mid = (left +right/2);
  MergeSort(weights,values,left, mid);
  MergeSort(weights,values,mid+1,right);
  Merge(weights,values,left,mid,right);
   return; 
}



double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  MergeSort(weights,values,0,weights.size()-1);
   std::cout<<"sorted value per pound"<<std::endl;
  for(int i=0; i< weights.size(); i++){
    std::cout<<(double)values[i]/weights[i]<< " ";
  } 
for(int i=0; i<weights.size() && capacity != 0;i++){
    
    if(weights[i]<capacity){
      capacity -= weights[i];
      value += values[i];
    }else{
          value +=capacity*((double)values[i]/weights[i]);
          capacity = 0;
    }
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
