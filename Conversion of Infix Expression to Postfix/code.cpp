#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char op) {
    if(op == '+' || op == '-') 
        return 1;
    if(op == '*' || op == '/') 
        return 2;
    return 0;
}

int applyOperator(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if(b != 0) return a / b;
            else {
                cout << "Error! Division by zero." << endl;
                exit(1);
            }
        default: return 0;
    }
}

string infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix = "";
    int i = 0;

    while (i < infix.length()) {
        if (isdigit(infix[i])) {
            while (i < infix.length() && isdigit(infix[i])) {
                postfix += infix[i];
                i++;
            }
            postfix += ' ';
        }
        else if (infix[i] == '(') {
            s.push(infix[i]);
            i++;
        }
        else if (infix[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop();
            i++;
        }
        else {
            while (!s.empty() && precedence(s.top()) >= precedence(infix[i])) {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int evaluatePostfix(const string& postfix) {
    stack<int> s;
    int i = 0;

    while (i < postfix.length()) {
        if (isdigit(postfix[i])) {
            int num = 0;
            while (i < postfix.length() && isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            s.push(num);
        }
        else if (postfix[i] == ' ') {
            i++;
        }
        else {
            if (s.size() < 2) {
                cout << "Error! Invalid postfix expression." << endl;
                exit(1);
            }
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            s.push(applyOperator(a, b, postfix[i]));
            i++;
        }
    }

    if (s.size() != 1) {
        cout << "Error! Invalid postfix expression." << endl;
        exit(1);
    }

    return s.top();
}

int main() {
    string infix;
    cout << "Enter the infix expression (with operands and operators): ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Result of the postfix evaluation: " << result << endl;

    return 0;
}
