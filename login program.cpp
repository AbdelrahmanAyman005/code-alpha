#include <bits/stdc++.h>
using namespace std;

bool fileExists(const string& filename) {
    ifstream file(filename);
    return file.good();
}

void registerUser() {
    string username, password;
    cout << "Enter new username: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> password;

    string filename = username + ".txt";
    if (fileExists(filename)) {
        cout << "Username already exists.\n";
        return;
    }

    ofstream file(filename);
    file << username << endl << password;
    file.close();
    cout << "Registration successful.\n";
}

void loginUser() {
    string username, password, fileUsername, filePassword;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    string filename = username + ".txt";
    ifstream file(filename);

    if (!file) {
        cout << "User not found.\n";
        return;
    }

    getline(file, fileUsername);
    getline(file, filePassword);
    file.close();

    if (username == fileUsername && password == filePassword) {
        cout << "Login successful.\n";
    } else {
        cout << "Incorrect credentials.\n";
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n1. Register\n2. Login\n3. Exit\nChoose option: ";
        cin >> choice;
        if (choice == 1) registerUser();
        else if (choice == 2) loginUser();
        else if (choice == 3) break;
        else cout << "Invalid option.\n";
    }
    return 0;
}
