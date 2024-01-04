#include <iostream>
#include<string.h>

using namespace std;
class Book
{
    public:
    string title;
    string author;
    int price;
};

class Node {
    public: 
    Book *book = NULL;
    Node *next = NULL;
};

Node *Library[26];

void initializeLibrary() {
    for (int i = 0; i < 26; i++) {
        Library[i] = NULL;
    }
}

void printLibrary() {
    for (int i = 0; i < 26; i++) {
        if(Library[i]==NULL) {
            continue;
        }
        else {
            Node *head = Library[i];
            while(head) {
                Book *book = head->book;
                cout << book->title << endl;
                head = head->next;
            }
        }
    }
}

void addBookAtEnd(string title, string author, int price) {
    char first = toupper(title[0]);
    int i = first - 'A';
    if(Library[i] == NULL) {
        Book *book = new Book();
        book->title = title;
        book->author = author;
        book->price = price;
        Node *temp = new Node();
        temp->book = book;
        Library[i] = temp;
    }
    else {
        Node *head = Library[i];
        Node *temp = head;
        int result = title.compare(head->book->title);
        while(result < 0) {
            temp = head;
            head = head->next;
            result = title.compare(head->book->title);
        }
        Book *book = new Book();
        book->title = title;
        book->author = author;
        book->price = price;
        Node *newNode = new Node();
        newNode->book = book;
        newNode->next = head->next;
        head->next = newNode;
    }
}

void deleteBook(string title) {
    char first = toupper(title[0]);
    int i = first - 'A';
    Node *head = Library[i];
    if(head->book->title == title) {
        free(head);
        Library[i] = NULL;
    }
    else {
        while(head->next->book->title != title) {
            head = head->next;
        }
        free(head->next);
        head->next = head->next->next;
    }
}

int main() {
    initializeLibrary();
    addBookAtEnd("Hello", "Krishna", 123);
    addBookAtEnd("Herro", "Krishna", 123);
    addBookAtEnd("Hillo", "Krishna", 123);
    printLibrary();
    return 0;
}