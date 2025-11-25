#include <iostream>
#include <vector>
using namespace std;

// simple structure for storing one expense
struct Expense {
    float amount;
    string category;
};

vector<Expense> allExpenses;   // list to store all entries

void addExpense() {
    Expense e;
    cout << "Amount: ";
    cin >> e.amount;

    cout << "Category: ";
    cin >> e.category;

    allExpenses.push_back(e);

    cout << "Saved.\n";
}

void displayExpenses() {
    if(allExpenses.size() == 0) {
        cout << "No expenses added yet.\n";
        return;
    }

    cout << "\n--- Expense List ---\n";
    for(int i = 0; i < allExpenses.size(); i++) {
        cout << i+1 << ") " 
             << allExpenses[i].amount 
             << "  -  " 
             << allExpenses[i].category 
             << "\n";
    }
    cout << endl;
}

void total() {
    float t = 0;
    for(int i = 0; i < allExpenses.size(); i++) {
        t += allExpenses[i].amount;
    }
    cout << "Total Spent: " << t << "\n\n";
}

int main() {
    int ch;

    while(true) {
        cout << "\n1. Add\n2. Show\n3. Total\n4. Exit\n";
        cout << "Select: ";
        cin >> ch;

        if(ch == 1) {
            addExpense();
        }
        else if(ch == 2) {
            displayExpenses();
        }
        else if(ch == 3) {
            total();
        }
        else if(ch == 4) {
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
