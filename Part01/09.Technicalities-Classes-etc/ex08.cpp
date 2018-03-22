/*
  Create a Patron class for the library. The class will have a user's name,
  library card numbers, and library fees(if owed). Have functions that access
  this data, as well as a function to set the fee of the user. Have a helper
  function that returns a Boolean (bool) depending on whether or not the user
  owes a fee.
*/
#include "../std_lib_facilities.h"
#include "Chrono.h"

enum class Genre
{
  fiction, nonfiction, periodical, biography, children
};
const char* g_Genre_txt[] = {"fiction", "nonfiction", "periodical", "biography", "children"};

class Book
{
public:
  class Invalid {};
  Book();
  Book(string ISBN, string title, string author, Chrono::Date date, bool checkedOut, Genre genre);

  string getISBN() const { return m_ISBN; }
  string getTitle() const { return m_Title; }
  string getAuthor() const { return m_Author; }
  Chrono::Date getDate() const { return m_Date; }
  bool isCheckedOut() const { return m_CheckedOut; }
  Genre getGenre() const { return m_Genre; }

  void checkIn() { m_CheckedOut = false; }
  void checkOut() { m_CheckedOut = true; }

private:
  string m_ISBN;
  string m_Title;
  string m_Author;
  Chrono::Date m_Date;
  bool m_CheckedOut;
  Genre m_Genre;
};

bool isValidBook(const Book& book)
{
  if (book.getISBN().size() != 7) {
    return false;
  }

  char *items = new char[book.getISBN().length() + 1];
  strcpy(items, book.getISBN().c_str());
  int size = sizeof(items) / sizeof(char);
  for (int i = 0; i < size-2; ++i) { // size - 2 == 0-0-0 instead of 0-0-0-a
    if (i % 2 == 0) {
      if (!isdigit(*(items + i))) {
          delete[] items;
          return false;
      }
    }
  }
  delete[] items;

  return true;
}

Book::Book(string ISBN, string title, string author, Chrono::Date date, bool checkedOut, Genre genre)
    : m_ISBN(ISBN), m_Title(title), m_Author(author), m_Date(date), m_CheckedOut(checkedOut), m_Genre(genre)
{
  if (!isValidBook(*this)) throw Invalid();
}

const Book& default_book()
{
  static Book db {"0-0-0-a", "Unknown Title", "Unknown Author", Chrono::Date(), false, Genre::nonfiction};
  return db;
}

Book::Book()
  : m_ISBN(default_book().getISBN()), m_Title(default_book().getTitle()),
    m_Author(default_book().getAuthor()), m_Date(default_book().getDate()),
    m_CheckedOut(default_book().isCheckedOut()), m_Genre(default_book().getGenre())
    {
    }

bool operator==(const Book& book, const Book& other)
{
  return book.getISBN() == other.getISBN();
}

bool operator!=(const Book& book, const Book& other)
{
  return !(book == other);
}

ostream& operator<<(ostream& os, const Book& book)
{
  return os << "--------------------------------\n"
            << "Book's ISBN: " << book.getISBN() << '\n'
            << "Book's title: " << book.getTitle() << '\n'
            << "Book's genre: " << g_Genre_txt[int(book.getGenre())] << '\n'
            << "Book's year: " << book.getDate().year() << '\n';
}

int main()
{
  try {
    Book book;
    Book book2 {"2-3-2-b", "The Mist", "Stephen King", Chrono::Date(2007, Chrono::Month::oct, 2), true, Genre::fiction};
    cout << book;
    cout << book2;

  } catch (Book::Invalid& e) {
    cout << "Invalid Book!\n";
  }

  return 0;
}
