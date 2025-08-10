#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValidExpression(const string& expression) {
    stack<char> s;
    
    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) {
                return false; 
            }
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') || 
                (ch == '}' && top != '{') || 
                (ch == ']' && top != '[')) {
                return false; 
            }
        }
    }

    return s.empty(); 
}

int main() {
    string expression;
    
    cout << "Enter the expression: ";
    getline(cin, expression);
    
    if (isValidExpression(expression)) {
        cout << "The expression is well parenthesized.\n";
    } else {
        cout << "The expression is not well parenthesized.\n";
    }

    return 0;
}
