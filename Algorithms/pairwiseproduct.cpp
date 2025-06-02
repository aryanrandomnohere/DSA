#include<iostream>
using namespace std;


int maximumPairwiseProduct(vector<int>number){
int result = 0 ;
int max_index1 = -1;
    for(int i = 0 ; i<number.size(); i++){
    if((number[i]>number[max_index1]) || max_index1 == -1){
            max_index1 = i;
        }
    }
int max_index2 = -1;
    for(int i = 0; i<number.size()-1; i++){
        if(((i != max_index1) && max_index2 == -1 || number[i]>number[max_index2]) ){
            max_index2 = i;
        }
    }
    result = number[max_index2] * number[max_index1];
    return result;
}

int main() {
    cout<<"Enter the size of the array \n";
    int n;
    cin>>n;
    vector<int> numbers(n);
    cout<<"Enter the number frr pairing \n";
    for(int i = 0; i<n; i++){
    cin>>numbers[i];
    };
    int result = maximumPairwiseProduct(numbers);
    cout<<"The Maximum Pairwise Product for the given numbers is "<<result;
}
