#include<iostream>
#include"admachine.h"
using namespace std;

class MySourceStack {
public:
    int x, y, q, temp;
    MySourceStack() {
        x = 2;
        y = 1;
    }

    int top() {
        if ((x == 2 && y == 1) || (y < 1)) return -1;
        return x/y;
    }

    bool push(int val) {
        if (val < 1) return false;

        temp = x;
        x = temp*val + y;
        y = temp;

        return true;
    }

    void pop() {
        if (y < 1) return;
        if (x == 2 && y == 1) return;

        temp = x;
        q = x/y;
        x = y;
        y = temp%y;
    }

    void print() {
        cout << "Stack : ";
        int x_dummy = x;
        int y_dummy = y;
        
        while (y_dummy >= 1) {
            temp = x_dummy;
            q = x_dummy/y_dummy;
            x_dummy = y_dummy;
            y_dummy = temp%y_dummy;

            if (y_dummy >= 1) cout << q << " ";
        }

        cout << endl;
    }
};

class MyStack {
private:
    MySourceStack* data;
    MySourceStack* check;
public:
    MyStack() {
        data = new MySourceStack();
        check = new MySourceStack();
    }

    int top() {
        if (check->top() == 2) return 0;
        else if (check->top() == 3) return data->top();
        else return -data->top();
    }

    bool push(int val) {
        if (val == 0) {
            check->push(2);
            return true;
        }
        else if (val < 1) {
            check->push(1);
            val = -val;        
        }
        else {
            check->push(3);
        }

        data->push(val);

        return true;
    }

    void pop() {
        if (check->top() == 2) {
            check->pop();
        }
        else if (check->top() == 3 || check->top() == 1) {
            check->pop();
            data->pop();
        }
    }

    void print() {
        int x_c = check->x;
        int x_d = data->x;
        int y_c = check->y;
        int y_d = data->y;

        int temp;
        int q_c;
        int q_d;

        while (y_c >= 1) {
            temp = x_c;
            q_c = x_c/y_c;
            x_c = y_c;
            y_c = temp%y_c;

            if (y_c >= 1) {
                if (q_c == 2) {
                    cout << 0 << " ";
                }
                else {
                    temp = x_d;
                    q_d = x_d/y_d;
                    x_d = y_d;
                    y_d = temp%y_d;

                    if (y_c == 1) {
                        cout << -q_d << " ";
                    }
                    else {
                        cout << q_d << " ";
                    }
                }
            }
        }

        cout << endl;
    }
};

int main() {
    MyStack* stack = new MyStack();
    stack->push(-3);
    stack->push(4);
    stack->push(0);
    stack->push(7);

    stack->print();

    stack->pop();
    
    stack->print();

    stack->pop();
    stack->pop();
    stack->pop();
    stack->pop();
    stack->pop();

    stack->print();

    return 0;
}
