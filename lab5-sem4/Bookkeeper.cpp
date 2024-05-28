#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "Bookkeeper.h"

std::vector<Bookkeeper::Book> Bookkeeper::readBooksFromFile(const std::string& filename)
{
    std::vector<Bookkeeper::Book> books;

    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::stringstream ss(line);
            Book book;
            ss >> book.id >> book.author >> book.title >> book.pages;
            books.push_back(book);
        }
        file.close();
    }

    return books;
}

void Bookkeeper::writeBooksToFile(const std::string& filename, const std::vector<Book>& books)
{
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (const auto& book : books) {
            outputFile << book.id << " " << book.author << " " << book.title << " " << book.pages << std::endl;
        }
        outputFile.close();
    }
}

void Bookkeeper::addBook(std::vector<Book>& books, int id, std::string author, std::string title, int pages)
{
    Book newBook = { id, author, title, pages };
    books.push_back(newBook);
}

void Bookkeeper::printBooks(const std::vector<Book>& books)
{
    std::cout << "\nКаталог книг:\n";
    for (const auto& book : books) {
        std::cout << book.id << " " << book.author << " " << book.title << " " << book.pages << std::endl;
    }
}

Bookkeeper::Book Bookkeeper::findBookById(const std::vector<Book>& books, int id)
{
    for (const auto& book : books) {
        if (book.id == id) {
            return book;
        }
    }

    return Book{ -1, "", "", -1 };
}

Bookkeeper::Book Bookkeeper::findBookByAuthor(const std::vector<Book>& books, const std::string& author)
{
    for (const auto& book : books) {
        if (book.author == author) {
            return book;
        }
    }

    return Book{ -1, "", "", -1 };
}

Bookkeeper::Book Bookkeeper::findBookByTitle(const std::vector<Book>& books, const std::string& title)
{
    for (const auto& book : books) {
        if (book.title == title) {
            return book;
        }
    }

    return Book{ -1, "", "", -1 };
}

void Bookkeeper::deleteBookById(std::vector<Book>& books, int id)
{
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->id == id) {
            books.erase(it);
            return;
        }
    }
}

void Bookkeeper::editBookById(std::vector<Book>& books, int id, std::string author, std::string title, int pages)
{
    for (auto& book : books) {
        if (book.id == id) {
            book.author = author;
            book.title = title;
            book.pages = pages;
            return;
        }
    }
}
