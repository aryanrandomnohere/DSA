#include<iostream>
using namespace std;


int EuclideanGcd(int n1, int n2) {
if(n2 == 0 ){
        return n1;
    }

return EuclideanGcd(n2,n1%n2);
}

int main(){
cout<<"Enter first number \n";
    int n1, n2, gcd;
    cin>>n1;
cout<<"Enter the second number \n";
    cin>>n2;

    if(n1<n2){ 
        for(int i = 1; i <= n1; i++){
if(n1%i==0 && n2%i == 0){
    gcd = i;
        }
    }
     } else for(int i = 1;i <= n2;i++){
    if(n1%i==0 && n2%i == 0){
      gcd = i;
        }
    }
    cout<<"The GCD for give numbers n1: "<<n1<<" and n2: "<<n2<<" is "<<gcd<<endl;
    gcd = EuclideanGcd(n1,n2);
    cout<<"By Euclidean Algorithm GCD is "<<gcd<<endl;
    return 0;

} 
