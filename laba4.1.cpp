#include "iostream"
#include "RBclass.h"

using namespace std;

int main() {
    rb_map<string, string> map;

    while (true) {
        cout << "\n\nmap: ";
        map.print();
        cout << "\n\ntype 1 to insert value\ntype 2 to remove value\ntype 3 to get value\ntype 4 to debug red-black tree\ntype any other number to exit\n";

        int choice = 1;
        cin >> choice;
        switch (choice) {
        case 1: {
            string key, value;
            cout << "input key: ";
            cin >> key;
            cout << "input value: ";
            cin >> value;
            map[key] = value;
            break;
        }
        case 2: {
            string key, value;
            cout << "input key: ";
            cin >> key;
            if (map.remove(key)) {
                cout << "value was removed\n";
            }
            else {
                cout << "no such key\n";
            }
            break;
        }
        case 3: {
            string key, value;
            cout << "input key: ";
            cin >> key;
            if (map.has(key)) {
                cout << "value at " << key << " = " << map[key] << "\n";
            }
            else {
                cout << "no such key\n";
            }
            break;
        }
        case 4: {
            map.show_tree();
            break;
        }
        default:
            return 0;
        }
    }
}