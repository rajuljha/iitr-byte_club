#include <iostream>
#include <stack>
#include <string>

using namespace std;

class InfixToPostfix {
private:
    stack<char> operators;
    string postfix;

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
    // Converts infix expression to postfix
    void convert(string infix) {
        for (int i = 0; i < infix.length(); i++) {
            char c = infix[i];

            // If character is an operand, add it to postfix string
            if (isdigit(c))
                postfix += c;

            // If character is an operator
            else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
                // Pop operators with higher or equal precedence and add them to postfix string
                while (!operators.empty() && operators.top() != '(' && precedence(operators.top()) >= precedence(c)) {
                    postfix += operators.top();
                    operators.pop();
                }

                // Push current operator to stack
                operators.push(c);
            }

            // If character is opening parenthesis, push it to stack
            else if (c == '(')
                operators.push(c);

            // If character is closing parenthesis, pop operators until opening parenthesis is found
            else if (c == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    postfix += operators.top();
                    operators.pop();
                }

                // Pop opening parenthesis from stack
                operators.pop();
            }
        }

        // Pop remaining operators and add them to postfix string
        while (!operators.empty()) {
            postfix += operators.top();
            operators.pop();
        }
    }

    // Returns the postfix expression
    string getPostfix() {
        return postfix;
    }

    // Evaluates postfix expression
    int evaluate() {
        stack<int> operands;

        for (int i = 0; i < postfix.length(); i++) {
            char c = postfix[i];

            // If character is an operand, push it to stack
            if (isdigit(c))
                operands.push(c - '0');

            // If character is an operator, pop two operands, perform operation and push result to stack
            else {
                int op2 = operands.top();
                operands.pop();
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
            }
        }

        // Return final result
        return operands.top();
    }
};

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    InfixToPostfix obj;
    obj.convert(infix);

    cout << "Postfix expression: " << obj.getPostfix() << endl;
    cout << "Result: " << obj.evaluate() << endl;

    return 0;
}