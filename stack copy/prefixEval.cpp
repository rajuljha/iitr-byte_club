#include<iostream>
#include<stack>
#include<math.h>
#include<string.h>
using namespace std;

int prefixEvaluation(string s) {
    stack<int> st;
    for (int i = s.length()-1; i >= 0; i--) {

        if (st[i] >= '0' && st[i] <= '9'){
            st.push(s[i]-'0');
        }
        else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (s[i]) {
                case "+":
                    st.push(op1 + op2);
                    break;
                case "-":
                    st.push(op1 - op2);
                    break;
                case "*":
                    st.push(op1 * op2);
                    break;
                case "/":
                    st.push(op1 / op2);
                    break;
                case "^":
                    st.push(pow(op1, op2));
                    break;
            }
        }
    }
    return st.top();
}
int main() {
    std::string expression;
    std::cout << "Enter the prefix expression: " << std::endl;
    std::cin >> expression;
    std::cout << "Expression evaluated to: " << prefixEvaluation(expression) << std::endl;
    return 0;
}