#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

enum Genre { FICTION, NONFICTION, SCIENCE, HISTORY, TECHNOLOGY };

class Book {
private:
    int bookID;
    float rating;
    double price;
    char status;          // 'A' = Available, 'B' = Borrowed
    bool isReference;
    string title;
    Genre genre;

public:
    // Default constructor
    Book() : bookID(0), rating(0.0), price(0.0), status('A'),
             isReference(false), title("Untitled"), genre(FICTION) {}

    // Parameterized constructor
    Book(int id, float r, double p, char s, bool ref, const string& t, Genre g)
        : bookID(id), rating(r), price(p), status(s),
          isReference(ref), title(t), genre(g) {}

    ~Book() { cout << "Book object with ID " << bookID << " destroyed.\n"; }

    // Getters
    int getID() const { return bookID; }
    float getRating() const { return rating; }
    double getPrice() const { return price; }
    char getStatus() const { return status; }
    bool getRef() const { return isReference; }
    string getTitle() const { return title; }
    Genre getGenre() const { return genre; }

    // Setters
    void setID(int id) { bookID = id; }
    void setRating(float r) { rating = r; }
    void setPrice(double p) { price = p; }
    void setStatus(char s) { status = s; }
    void setRef(bool ref) { isReference = ref; }
    void setTitle(const string& t) { title = t; }
    void setGenre(Genre g) { genre = g; }

    // Member functions
    void updateAvailability(bool borrowed) { status = borrowed ? 'B' : 'A'; }

    void display() const {
        string g;
        switch (genre) {
            case FICTION: g = "Fiction"; break;
            case NONFICTION: g = "NonFiction"; break;
            case SCIENCE: g = "Science"; break;
            case HISTORY: g = "History"; break;
            case TECHNOLOGY: g = "Technology"; break;
        }
        cout << "\nID: " << bookID
             << "\nTitle: " << title
             << "\nPrice: " << price
             << "\nRating: " << rating
             << "\nStatus: " << (status == 'A' ? "Available" : "Borrowed")
             << "\nReference: " << (isReference ? "Yes" : "No")
             << "\nGenre: " << g << "\n";
    }
};

// Global functions
void markAsReference(Book &b) {
    b.setRef(true);
    cout << "Book \"" << b.getTitle() << "\" marked as Reference Only.\n";
}

bool isAffordable(const Book &b, double budget) {
    return b.getPrice() <= budget;
}

void printList(const Book books[], int n) {
    cout << left << setw(6) << "ID" << setw(20) << "Title"
         << setw(10) << "Price" << setw(8) << "Rate"
         << setw(10) << "Status" << setw(12) << "Reference" << "\n";
    cout << "-------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << left << setw(6) << books[i].getID()
             << setw(20) << books[i].getTitle()
             << setw(10) << books[i].getPrice()
             << setw(8) << books[i].getRating()
             << setw(10) << (books[i].getStatus() == 'A' ? "Available" : "Borrowed")
             << setw(12) << (books[i].getRef() ? "Yes" : "No") << "\n";
    }
}

int main() {
    Book books[3] = {
        Book(101, 4.5, 299.99, 'A', false, "C++ Primer", TECHNOLOGY),
        Book(102, 3.8, 150.00, 'B', true, "Design Patterns", SCIENCE),
        Book()
    };

    int choice;
    do {
        cout << "\n=== Library Menu ===\n"
             << "1. Add book\n2. Mark as reference\n3. Check affordable\n"
             << "4. Update availability\n5. Show one book\n6. Show all books\n7. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            int id, g; float r; double p; char s; bool ref; string t;
            cout << "Enter ID: "; cin >> id;
            do { cout << "Rating (0-5): "; cin >> r; } while (r < 0 || r > 5);
            do { cout << "Price (>0): "; cin >> p; } while (p <= 0);
            cout << "Status (A/B): "; cin >> s;
            cout << "Reference (0/1): "; cin >> ref;
            cin.ignore();
            do { cout << "Title: "; getline(cin, t); } while (t.empty());
            cout << "Genre (0-Fiction,1-NonFiction,2-Science,3-History,4-Technology): ";
            cin >> g;
            books[2] = Book(id, r, p, s, ref, t, (Genre)g);
            cout << "Book added!\n";
        }
        else if (choice == 2) markAsReference(books[0]);
        else if (choice == 3) {
            double budget; cout << "Enter budget: "; cin >> budget;
            cout << (isAffordable(books[0], budget) ? "Affordable\n" : "Too expensive\n");
        }
        else if (choice == 4) {
            bool b; cout << "Borrow? (1/0): "; cin >> b; books[0].updateAvailability(b);
        }
        else if (choice == 5) books[0].display();
        else if (choice == 6) printList(books, 3);
        else if (choice == 7) cout << "Exiting...\n";
        else cout << "Invalid choice\n";
    } while (choice != 7);

    return 0;
}
