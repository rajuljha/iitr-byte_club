#include <iostream>
#include <stack>
#include <string>

using namespace std;

class InfixToPostfix {
private:
    string infix;

    // Returns the precedence of an operator
    int precedence(char op) {
        if (op == '+' || op == '-')
            return 1;
        else if (op == '*' || op == '/')
            return 2;
        else if (op == '^')
            return 3;
        else
            return 0;
    }

public:
    // Constructor
    InfixToPostfix(string inf) {
        infix = inf;
    }

    // Converts infix expression to postfix
    int convert() {
        stack<int> operands;
        string postfix = "";

        for (int i; i<infix.length();++i) {
            char c = infix[i];
            // If character is an operand, add it to postfix expression and push it to stack
            if (isdigit(c)) {
                postfix += c;
                operands.push(c - '0');
            }

            // If character is an operator, pop two operands, perform operation and push result to stack
            else {
                if (operands.empty()) {
                    cerr << "Error: Invalid infix expression" << endl;
                    return 0;
                }

                int op2 = operands.top();
                operands.pop();

                if (operands.empty()) {
                    cerr << "Error: Invalid infix expression" << endl;
                    return 0;
                }

                int op1 = operands.top();
                operands.pop();

                switch (c) {
                    case '+':
                        operands.push(op1 + op2);
                        break;
                    case '-':
                        operands.push(op1 - op2);
                        break;
                    case '*':
                        operands.push(op1 * op2);
                        break;
                    case '/':
                        operands.push(op1 / op2);
                        break;
                    case '^':
                        operands.push(pow(op1, op2));
                        break;
                }

                // Add operator to postfix expression
                postfix += c;
            }
        }

        // Return final result
        return operands.top();
    }
};

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    InfixToPostfix itp(infix);
    int result = itp.convert();

    if (result != 0) {
        cout << "Postfix expression: " << infix << endl;
        cout << "Result: " << result << endl;
    }

    return 0;
}
