#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Books
{
private:
    string title;
    string author;
    bool borrowing;

public:
    Books(string title, string author)
        : title(title), author(author), borrowing(false) {}

    string get_title()
    {
        return title;
    }
    string get_author()
    {
        return author;
    }
    bool is_borrowed()
    {
        return borrowing;
    }
    void borrowed()
    {
        borrowing = true;
    }
    void returned_book()
    {
        borrowing = false;
    }
};

class Users
{

public:
    void borrowBook(Books &book)
    {
        if (!book.is_borrowed())
        {
            book.borrowed();
            borrowingBooks += book.get_title() + ", ";
            cout << "You have borrowed the book \"" << book.get_title() << "\" by " << book.get_author() << "." << endl;
        }
        else
        {
            cout << "The book is already borrowed." << book.get_title() << endl;
        }
    }

    void returnBook(Books &book)
    {
        if (borrowingBooks.find(book.get_title()) != string::npos)
        {
            book.returned_book();
            borrowingBooks.erase(borrowingBooks.find(book.get_title()), book.get_title().length() + 2);
            cout << "You have returned the book \"" << book.get_title() << "\" by " << book.get_author() << "." << endl;
        }
        else
        {
            cout << "You haven't borrowed the book \"" << book.get_title() << "\"." << endl;
        }
    }

    void displayBorrowedBooks()
    {
        if (borrowingBooks.empty())
        {
            cout << "You haven't borrowed any books." << endl;
        }
        else
        {
            cout << "You have borrowed the following books: " << borrowingBooks << "." << endl;
        }
    }

private:
    string borrowingBooks;
};

int main()
{
    Books book1("The Great Gatsby", "F. Scott Fitzgerald");
    Books book2("To Kill a Mockingbird", "Harper Lee");
    Books book3("1984", "George Orwell");

    Users user;

    user.borrowBook(book1);
    user.borrowBook(book2);
    user.returnBook(book1);
    user.displayBorrowedBooks();
}
