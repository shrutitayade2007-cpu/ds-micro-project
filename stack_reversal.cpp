/*
 * Stack-Based Book / Item Reversal System (C++)
 * ---------------------------------------------
 * Implements a stack using an array and demonstrates
 * push, pop, peek and display operations.
 * The stack is then used to reverse the entered sequence of items.
 */

#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 100;

class Stack {
private:
    string items[MAX_ITEMS];
    int top;

public:
    Stack() : top(-1) {}

    bool isEmpty() const { return top == -1; }
    bool isFull() const { return top == MAX_ITEMS - 1; }

    // Push: add an item on top of the stack
    void push(const string &item) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot add more items.\n";
            return;
        }
        items[++top] = item;
        cout << "\"" << item << "\" pushed onto the stack.\n";
    }

    // Pop: remove the top item and return it through 'out'
    bool pop(string &out) {
        if (isEmpty()) {
            cout << "Stack Underflow! The stack is empty.\n";
            return false;
        }
        out = items[top--];
        return true;
    }

    // Peek: view the top item without removing it
    void peek() const {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to peek.\n";
            return;
        }
        cout << "Top item: \"" << items[top] << "\"\n";
    }

    // Display: show the stack from top to bottom
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "\nStack (top -> bottom):\n";
        for (int i = top; i >= 0; i--) {
            cout << "  " << (top - i + 1) << ". " << items[i];
            if (i == top) cout << "   <-- TOP";
            cout << "\n";
        }
    }

    // Reverse: pop every item from a copy of the stack.
    // Popping gives the items in reverse order of entry.
    // A copy is used so the original stack stays intact.
    void reverseSequence() const {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to reverse.\n";
            return;
        }

        Stack temp = *this;
        string item;
        int count = 1;

        cout << "\nOriginal order (entered):\n";
        for (int i = 0; i <= top; i++)
            cout << "  " << (i + 1) << ". " << items[i] << "\n";

        cout << "\nReversed order (using stack):\n";
        while (temp.pop(item))
            cout << "  " << count++ << ". " << item << "\n";
    }
};

int main() {
    Stack stack;
    int choice = 0;
    string item, line;

    do {
        cout << "\n===== Stack-Based Book/Item Reversal System =====\n";
        cout << "1. Push (add an item)\n";
        cout << "2. Pop (remove top item)\n";
        cout << "3. Peek (view top item)\n";
        cout << "4. Display stack\n";
        cout << "5. Reverse the entered sequence\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        getline(cin, line);
        try {
            choice = stoi(line);
        } catch (...) {
            choice = 0;
        }

        switch (choice) {
            case 1:
                cout << "Enter book/item name: ";
                getline(cin, item);
                if (item.empty())
                    cout << "Item name cannot be empty.\n";
                else
                    stack.push(item);
                break;
            case 2:
                if (stack.pop(item))
                    cout << "\"" << item << "\" popped from the stack.\n";
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                stack.display();
                break;
            case 5:
                stack.reverseSequence();
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
