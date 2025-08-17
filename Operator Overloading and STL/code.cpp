#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Class to represent an Item
class Item {
public:
    int itemCode;  // Item code
    string itemName; // Item name
    float cost;     // Item cost
    int quantity;   // Item quantity

    // Constructor to initialize item
    Item(int code, string name, float price, int qty)
        : itemCode(code), itemName(name), cost(price), quantity(qty) {}

    // Overload the '==' operator to compare Item based on itemCode
    bool operator==(const Item &other) const {
        return itemCode == other.itemCode;
    }

    // Overload the '<' operator to compare Items based on itemCode for sorting
    bool operator<(const Item &other) const {
        return itemCode < other.itemCode;
    }

    // Function to display Item details
    void display() const {
        cout << "\nItem Code: " << itemCode << "\n";
        cout << "Item Name: " << itemName << "\n";
        cout << "Cost: " << cost << "\n";
        cout << "Quantity: " << quantity << "\n";
    }
};

// Function to display all items in the vector
void displayItems(const vector<Item> &items) {
    for (const auto &item : items) {
        item.display();
    }
}

// Comparison function to sort by item cost (in ascending order)
bool compareByCost(const Item &a, const Item &b) {
    return a.cost < b.cost;
}

// Function to search an item by itemCode
void searchItem(vector<Item> &items, int code) {
    auto it = find(items.begin(), items.end(), Item(code, "", 0, 0));
    if (it != items.end()) {
        cout << "Item found:\n";
        it->display();
    } else {
        cout << "Item with code " << code << " not found.\n";
    }
}

void insert(vector<Item>& items) {
    int code, qty;
    string name;
    float price;

    do {
        cout << "\nEnter Item Code: ";
        cin >> code;
        cout << "Enter Item Name: ";
        cin >> name;
        cout << "Enter Item Cost: ";
        cin >> price;
        cout << "Enter Item Quantity: ";
        cin >> qty;
        
        items.push_back(Item(code, name, price, qty)); // Add item to vector

        // Ask the user if they want to add more items
        char choice;
        cout << "\nDo you want to add more items? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            break; // Exit the loop if the user does not want to add more items
        }
    } while (true);
}

int main() {
    vector<Item> items; // Vector to store items
    int choice;

    do {
        cout << "\n***** Menu *****";
        cout << "\n1. Add Item";
        cout << "\n2. Display All Items";
        cout << "\n3. Sort Items by Item Code";
        cout << "\n4. Search Item by Item Code";
        cout << "\n5. Sort Items by Cost";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insert(items); // Insert items into the vector
                break;

            case 2:
                cout << "\nDisplaying all items:\n";
                displayItems(items);
                break;

            case 3:
                sort(items.begin(), items.end());  // Sort items by itemCode (default comparison)
                cout << "\nItems sorted by Item Code:\n";
                displayItems(items);
                break;

            case 4: {
                int searchCode;
                cout << "\nEnter Item Code to search: ";
                cin >> searchCode;
                searchItem(items, searchCode);
                break;
            }

            case 5:
                sort(items.begin(), items.end(), compareByCost);  // Sort items by cost
                cout << "\nItems sorted by Cost:\n";
                displayItems(items);
                break;

            case 6:
                cout << "\nExiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6); // Loop until user selects exit option

    return 0;
}
