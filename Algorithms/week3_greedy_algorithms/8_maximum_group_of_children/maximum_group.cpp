#include<iostream>
#include<vector>
using namespace std;

void create_groups(int segment, vector<int> & children_ages) {
int n = children_ages.size();
    vector<vector<int>> groups;
    vector<int> current_groups;
for(int i = 0 ; i<n ;i++){
   if(current_groups.empty()){
            current_groups.push_back(children_ages[i]);
        }else if(abs(current_groups[0]-children_ages[i])<= segment){
            current_groups.push_back(children_ages[i]);
            
        }else{
            groups.push_back(current_groups);
            current_groups.clear();
            current_groups.push_back(children_ages[i]);
        }
    }
    if(!current_groups.empty()){
        groups.push_back(current_groups);
    }

    for(int i = 0;i<groups.size();i++){ 
        cout<<endl<<"Group: "<<i+1<<endl;
        for(int j =0; j<groups[i].size();j++){
            cout<<groups[i][j]<<" ";
        }
    }
}


int main(){
    int n,segment;
    cout<<"Enter the number of children"<<endl;
    cin>>n;
    cout<<"Enter ages of these childrens"<<endl;
    vector<int> children_ages(n);
    for(int i = 0; i<n;i++){
      cin>>children_ages[i];
    }
    cout<<"Enter the age gap permited to form a group of children"<<endl;
    cin>>segment;
    create_groups(segment,children_ages);
    
    }
