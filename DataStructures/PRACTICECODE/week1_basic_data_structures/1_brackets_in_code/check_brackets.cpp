#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

 int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
           Bracket temp(next,position);
           opening_brackets_stack.push(temp);
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if(opening_brackets_stack.empty()) {
                std::cout<<"String is not valid";
                return -1;
            }
            Bracket popped = opening_brackets_stack.top();
            if(next == ')' && popped.type != '(') break;
            if(next =='}' && popped.type != '{') break;
            if(next ==']' && popped.type != '[') break;
            opening_brackets_stack.pop();

        }
    }

    // Printing answer, write your code here
      if(!opening_brackets_stack.empty()){
        std::cout<<"The given string is not valid"<<"\n";
        return -1;
    }
    std::cout<<"The given string is valid";

    return 0;
}
