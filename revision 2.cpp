#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

double applyOp(double a, double b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
    }
    return 0;
}

double evaluateExpression(const string& expression) {
    stack<double> values;
    stack<char> ops;
    stringstream ss(expression);

    string token;
    while (ss >> token) {
        if (isdigit(token[0])) {
            double num;
            stringstream(token) >> num;
            values.push(num);
        }
        else if (token == "(") {
            ops.push('(');
        }
        else if (token == ")") {
            while (!ops.empty() && ops.top() != '(') {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(a, b, op));
            }
            ops.pop(); 
        }
        else if (isOperator(token[0])) {
            while (!ops.empty() && precedence(token[0]) <= precedence(ops.top())) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(a, b, op));
            }
            ops.push(token[0]);
        }
    }

    while (!ops.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(a, b, op));
    }

    return values.top();
}

int main() {
    string expression;
    cout << "Enter a mathematical expression: ";
    getline(cin, expression);

    double result = evaluateExpression(expression);
    cout << "Result: " << result << endl;

    return 0;
}

