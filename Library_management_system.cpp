#include <iostream>
using namespace std;

class Book {
private:
    int bookID;
    string title;
    string author;
    bool isIssued;

public:
    void addBook() {
        cout << "Enter Book ID: ";
        cin >> bookID;
        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);
        isIssued = false;
    }

    void displayBook() {
        cout << "\nBook ID: " << bookID;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nStatus: " << (isIssued ? "Issued" : "Available") << endl;
    }

    int getID() {
        return bookID;
    }

    void issueBook() {
        if (!isIssued) {
            isIssued = true;
            cout << "Book issued successfully!\n";
        } else {
            cout << "Book already issued!\n";
        }
    }

    void returnBook() {
        if (isIssued) {
            isIssued = false;
            cout << "Book returned successfully!\n";
        } else {
            cout << "Book was not issued!\n";
        }
    }
};

int main() {
    Book books[100];
    int count = 0;
    int choice, id;

    do {
        cout << "\n===== Library Menu =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            books[count].addBook();
            count++;
            break;

        case 2:
            for (int i = 0; i < count; i++) {
                books[i].displayBook();
            }
            break;

        case 3:
            cout << "Enter Book ID to search: ";
            cin >> id;
            for (int i = 0; i < count; i++) {
                if (books[i].getID() == id) {
                    books[i].displayBook();
                }
            }
            break;

        case 4:
            cout << "Enter Book ID to issue: ";
            cin >> id;
            for (int i = 0; i < count; i++) {
                if (books[i].getID() == id) {
                    books[i].issueBook();
                }
            }
            break;

        case 5:
            cout << "Enter Book ID to return: ";
            cin >> id;
            for (int i = 0; i < count; i++) {
                if (books[i].getID() == id) {
                    books[i].returnBook();
                }
            }
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}