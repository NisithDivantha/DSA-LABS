#include <cstring>
#include <string>
#include <iostream>
using namespace std;

struct HashTable {
    int MAX_LENGTH = 4;
    string * password = new string[MAX_LENGTH];

    void initialize_hashtable() {
        for (int i = 0; i < MAX_LENGTH; i++) {
            password[i].clear();
        }
    }

    bool isFull() {
        int count = 0;
        for (int i = 0; i < MAX_LENGTH; i++) {
            if (password[i].empty()) {
                count++;
            }
        }
        return count == 0;
    }

    int hashfunc(string user_name) {
        int sum = 0;
        int hash = 0;

        // calculate sum of ASCII values of each character in the username
        for (int i = 0; i < user_name.length(); i++) {
            int k = static_cast<int>(user_name[i]);
            sum += k;
        }

        // compute hash using modulo MAX_LENGTH
        hash = sum % MAX_LENGTH;

        return hash;
    }

    bool is_slot_empty(int hash) {
        return password[hash].empty();
    }

    void insert(string user_name, string user_password) {
        int hash = hashfunc(user_name);
        bool empty = is_slot_empty(hash);

        if (empty == true) {
            password[hash] = user_password;
        } else {
            cout << "Password can't be saved." << endl;
        }
    }

    void hash_lookup(string user_name) {
        int hash = hashfunc(user_name);
        bool empty = is_slot_empty(hash);

        if (empty == false) {
            cout << password[hash] << endl;
        } else {
            cout << "Password cannot be found." << endl;
        }
    }
    
    void delete_item(string user_name) {
        int hash = hashfunc(user_name);
        bool empty = is_slot_empty(hash);

        if (empty) {
            cout << "No item found" << endl;
        } else {
            password[hash].clear();
            cout << "User deleted" << endl;
        }
    }

    void print_hashtable() {
        for (int i = 0; i < MAX_LENGTH; i++) {
            cout << "[" << i << "]-->" << password[i] << endl;
        }
    }
};

int main() {
    HashTable * hashtbl = new HashTable;
    hashtbl->initialize_hashtable();
    cout << hashtbl->isFull() << endl;

    int command = 0;
    string user_name;
    string password;
    while (command != -1) {
        cout << "Type command: ";
        cin >> command;
        switch (command) {
        case 1:
            cout << "Enter user name: ";
            cin >> user_name;
            cout << "Enter password to be saved: ";
            cin >> password;
            hashtbl->insert(user_name, password);
            break;
        case 2:
            cout << "Enter user name to be deleted: ";
            cin >> user_name;
            hashtbl->delete_item(user_name);
            break;
        case 3:
            cout << "Enter user name to look up password: ";
            cin >> user_name;
            hashtbl->hash_lookup(user_name);
            break;
        case 4:
            hashtbl->print_hashtable();
            break;
        case -1:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid command." << endl;
            break;
        }

    
    }
    return 0;
}
