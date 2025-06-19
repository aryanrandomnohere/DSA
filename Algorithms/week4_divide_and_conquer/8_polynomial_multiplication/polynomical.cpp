#include<iostream>
using namespace std;
#include<vector>


vector<int> naive_polynomial_multiplication(vector<int> a, vector<int> b,int n){
    vector<int> c((2*n)-1);
    for(int i=0;i<(2*n)-1;i++){
    c[i] = 0;
    }
    for(int i =0;i<n;i++){
        for(int j =0 ; j<n;j++){
            cout<<a[i]*b[j];
            c[i+j] += a[i]*b[j]; 
        }
    }
    return c;
}

vector<int> naive_divide_and_conquer(vector<int>a, vector<int> b,int n, int a1, int b1){
    vector<int> c(2*n-1), x, y;
    if(n ==1) { 
        c[0] = a[a1]*b[b1];
        return c;
    }
      x = naive_divide_and_conquer(a,b,n/2,a1+n/2,b1+n/2);
    for(int i =n; i < 2*n-1;i++){
        c[i] = x[i-n];
    }
    x = naive_divide_and_conquer(a,b,n/2,a1, b1);   
    for(int i=0; i<x.size(); i++){
        c[i] = x[i];
        }
  
    x = naive_divide_and_conquer(a,b,n/2,(a1+n/2), b1);
    y = naive_divide_and_conquer(a,b,n/2,a1,b1+(n/2));
    for(int i = 0 ; i<n;i++){
        c[(n/2)+i] += x[i]+y[i];  
    } 
    
    return c;
}

vector<int> divide_and_conquer(vector<int> a, vector<int> b, int n,int a1, int b1){
    vector<int> c(2*n-1), D1E1(n-1), D0E0(n-1),D2(n/2),E2(n/2),D2E2(n-1);
    if(n == 1 ){
        c[0] = a[a1]*b[b1];
        return c;
    }
    D1E1 = divide_and_conquer(a,b,n/2,a1,b1);
    D0E0 = divide_and_conquer(a,b,n/2,a1+n/2,b1+n/2);
    for(int i= 0; i<n/2;i++){
        D2[i] = a[i]+a[n/2+i];
        E2[i] = b[i]+b[i+n/2];
    } 
    D2E2 = divide_and_conquer(D2,E2,n/2,0,0);
    for(int i = 0; i<n-1;i++){
        c[i] = D1E1[i];
        c[i+n] = D0E0[i];
    }
    for(int i = 0; i<n-1;i++){
        c[i+n/2] += D2E2[i]- D1E1[i] - D0E0[i];
    }



    return c;
}




int main(){
cout<<"Enter the size of the polynomial"<<endl;
    int n;
    cin>>n;
vector<int> a(n);
    vector<int> b(n);
    cout<<"Enter elements of a"<<endl;   
    for(size_t i =0; i<n;i++){
        cin>>a[i];   
    }
    cout<<"Enter elements of b"<<endl;
    for(size_t i = 0; i<n;i++){
        cin>>b[i]; 
         }
    vector<int> c = divide_and_conquer(a,b,n,0,0);
    cout<<"Answer from polynomial multiplication is: "<<endl;
    for(int i =0; i<c.size();i++){
        cout<<c[i]<<" ";
    }
  
}

