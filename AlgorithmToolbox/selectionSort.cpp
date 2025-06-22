#include<iostream>
using namespace std;


void selectionSort(int *a, int n){
for(int i=0;i<n;i++){
    int min =i;
for(int j=i+1;j<n;j++){
    if(a[j]<a[min]){
        min = j;
            }
     }
      int temp = a[i];
         a[i] = a[min];
        a[min] = temp;

    } 

    return;
}


void Merge(int *a, int n, int m) {
    int m1[n], m2[m], k = n + m;

    for (int i = 0; i < n; i++) {
        m1[i] = a[i];
    }

    for (int i = 0; i < m; i++) {
        m2[i] = a[n + i];
    }

    int i = 0, j = 0, idx = 0;

    // Merge both sorted arrays
    while (i < n && j < m) {
        if (m1[i] <= m2[j]) {
            a[idx++] = m1[i++];
        } else {
            a[idx++] = m2[j++];
        }
    }

    // Copy remaining elements from m1
    while (i < n) {
        a[idx++] = m1[i++];
    }

    // Copy remaining elements from m2
    while (j < m) {
        a[idx++] = m2[j++];
    }
}


void MergeSort(int*a, int n){
    if(n == 1){
        return;
    }
    MergeSort(a,n/2);
    MergeSort(a+n/2,n-(n/2));
    Merge(a,n/2,n-(n/2));
    return;
}


int main(){
cout<<"Enter the length of the array \n";
    int n;
cin>>n;
    int a[n];
    cout<<"Enter the elements of the array \n";
    for(int i =0; i<n;i++){ 
        cin>>a[i];
    }
    cout<<"Unsorted Array is :"<<endl;
    for(int i=0; i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"Array after selection sort :"<<endl;
    selectionSort(a, n);
    MergeSort(a,n);
     for(int i=0; i<n;i++){
        cout<<a[i]<<" ";
    }

return 0;
}
