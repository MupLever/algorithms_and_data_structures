#include <iostream>
class Stack {
public:
    Stack();
    ~Stack() { delete [] buffer; }
    bool is_empty() { return head == size; }
    void push(int value);    
    int pop();
    void print();

private:
    void grow();
    int *buffer;
    int head;
    int size;
};

Stack::Stack() {
    this->size = 3;
    this->head = size;
    this->buffer = new int [size];
}
void Stack::push(int value) {
    if (!head)
        grow();
    buffer[--head] = value;
}

int Stack::pop() {
    if (!is_empty()) {
        return buffer[head++];
    } else {
        return -1;
    }
}

void Stack::grow() {
    int tmp_size = this->size * 2;
    int *tmp_buffer = new int [tmp_size];
    head = size;
    for (int i = 0; i < size; ++i) {
        tmp_buffer[i + head] = buffer[i];
    }
    delete [] buffer;
    buffer = tmp_buffer;
    this->size = tmp_size;
}
void Stack::print() {
    for (int i = 0; i < this->size; ++i ) {
        std::cout << buffer[i] << ' ';
    }
}

class Queue {
public:
    void push_back(int value);
    int pop_front();
    void print();
private:
    int size = 0;
    Stack first_stack, second_stack;
};

void Queue::push_back(int value) {
    first_stack.push(value);
}
void Queue::print() {
    while(!second_stack.is_empty()) {
        std::cout << second_stack.pop() << ' ';
    }
}
int Queue::pop_front() {
        if (second_stack.is_empty()) {
            while(!first_stack.is_empty()) {
                second_stack.push(first_stack.pop());
            }
        }
        return second_stack.pop();
    }
int main() {
    Queue queue;
    bool flag = false;
    int count = 0, code = 0, value = 0;
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
    std::cin >> code;
        if (code == 3) {
            std::cin >> value;
            queue.push_back(value);
        } else if (code == 2) {
            std::cin >> value;
            if (value != queue.pop_front())
                flag = true;
        }
    }
    if (flag)
        std::cout << "NO";
    else
        std::cout <<"YES";

  return 0;
}
