#include <iostream>
#include <queue>

using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q[point].push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while (q[point].size() > 1) {
			q[1-point].push(q[point].front());
			q[point].pop();
		}
		q[point].pop();
		point = 1 - point;
    }

    // Get the top element.
    int top() {
        while (q[point].size() > 1) {
			q[1-point].push(q[point].front());
			q[point].pop();
		}
		int tmp = q[point].front();
		q[1-point].push(q[point].front());
		q[point].pop();
		point = 1 - point;
		
		return tmp;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q[point].size() == 0 ? true : false;
    }

private:
	queue<int> q[2];
	int point = 0;
};

int main(int argc, char** argv)
{
	Stack *s = new Stack;
	s->push(1);
	s->push(2);
	s->push(3);
	cout << s->top() << endl;
	s->pop();
	cout << s->top() << endl;
	s->pop();
	cout << s->top() << endl;
	cout << s->empty() << endl;
	s->pop();
	cout << s->empty() << endl;
	return 0;
}