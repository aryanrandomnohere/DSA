#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

class StackWithMax {
    vector<int> stack;
    vector<int> max_stack;
  public:

    void Push(int value) {
        stack.push_back(value);
        if(max_stack.empty()|| max_stack.back()<= value){
            max_stack.push_back(value);
        }    }

    void Pop() {
        assert(stack.size());
        int back = stack.back();
        stack.pop_back();
        if(max_stack.back() == back ){
            max_stack.pop_back();
        }
    }

    int Max() const {
        assert(stack.size());
        return *max_element(stack.begin(), stack.end());
    }
    int Max_Stack(){
        return max_stack.back();
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
            cout<<stack.Max_Stack()<<std::endl;
        }
        else {
            assert(0);
        }
    }
    return 0;
}
