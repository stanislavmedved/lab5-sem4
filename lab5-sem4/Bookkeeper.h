#ifndef BOOK_CATALOG_H
#define BOOK_CATALOG_H

#include <vector>
#include <string>
namespace Bookkeeper {
    struct Book {
        int id;
        std::string author;
        std::string title;
        int pages;
    };

    // Функции для работы с каталогом книг
    std::vector<Book> readBooksFromFile(const std::string& filename);
    void writeBooksToFile(const std::string& filename, const std::vector<Book>& books);
    void addBook(std::vector<Book>& books, int id, std::string  author, std::string  title, int pages);
    void printBooks(const std::vector<Book>& books);

    // Функции для поиска записей
    Book findBookById(const std::vector<Book>& books, int id);
    Book findBookByAuthor(const std::vector<Book>& books, const std::string& author);
    Book findBookByTitle(const std::vector<Book>& books, const std::string& title);

    // Функция для удаления записи по ID
    void deleteBookById(std::vector<Book>& books, int id);
    // Функция для редактирования записей
    void editBookById(std::vector<Book>& books, int id, std::string author, std::string title, int pages);
}
#endif