/*#include <iostream>
#include <stack>

using namespace std;

string reverseText(string text) {
    stack<char> charStack;
    for (char i : text) {
        charStack.push(i);
    }

    string reversedText;
    while (!charStack.empty()) {
        reversedText += charStack.top();
        charStack.pop();
    }

    return reversedText;
}

int main() {
    string originalText = "Hello, world!";
    string reversedText = reverseText(originalText);
    cout << "Original text: " << originalText << endl;
    cout << "Reversed text: " << reversedText << endl;
    return 0;
}*/
/*#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<char> chStack;
    string str { "English texts for beginners to practice reading and comprehension \n"
                 "online and for free. Practicing your comprehension of written English \n"
                 "will both improve your vocabulary and understanding" };
    string currentWord;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ') {
            currentWord += str[i];
        }
        else {
            while (!currentWord.empty()) {
                chStack.push(currentWord.back());
                currentWord.pop_back();
            }
            chStack.push(' ');
        }
    }

    while (!currentWord.empty()) {
        chStack.push(currentWord.back());
        currentWord.pop_back();
    }

    while (!chStack.empty()) {
        cout << chStack.top();
        chStack.pop();
    }

    cout << endl;

    return 0;
}*/
#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node {
    T value;
    Node* next;
    Node(const T& val) : value(val), next(nullptr) {}
    ~Node() {
        std::cout << "destroyed\n";
    }
};

template <typename T>
class Stack {
    Node<T>* top = nullptr;
    int size = 0;

public:
    T& top_m() {
        if (top)
            return top->value;
    }

    void push(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
        size++;
    }

    void pop() {
        if (top != nullptr) {
            Node<T>* tmp = top;
            top = top->next;
            delete tmp;
            size--;
        }
    }

    bool empty() const {
        if (top == nullptr)
            return true;
        return false;
    }

    int size_m() const {
        return size;
    }

    ~Stack() {
        while (top != nullptr) {
            Node<T>* tmp = top->next;
            delete top;
            top = tmp;
        }
    }

    void print() const {
        Node<T>* tmp = top;
        while (tmp != nullptr) {
            std::cout << tmp->value << " next node address: " << tmp->next << std::endl;
            tmp = tmp->next;
        }
    }
};

int main() {
    Stack<char> chStack;
    chStack.top_m();
    std::string str{ "English" };
    for (int i = 0; i < str.size(); i++) {
        chStack.push(str.at(i));
    }
    cout << "Size of the stack: " << chStack.size_m() << endl;
    while (!chStack.empty()) {
        cout << chStack.top_m();
        chStack.pop();
    }

    return 0;
}


