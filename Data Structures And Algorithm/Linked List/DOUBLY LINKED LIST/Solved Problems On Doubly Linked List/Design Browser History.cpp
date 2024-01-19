#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    string data;
    Node *next, *prev;
    Node() : data(0), next(nullptr), prev(nullptr) {};
    Node(string s) : data(s), next(nullptr), prev(nullptr) {};
    Node(string s, Node *next, Node *random) : data(s), next(next), prev(random) {};
};

// Time Complexity:- O(1)+O(1)+O(steps)+O(steps), one O(1) for the 
//                   constructor because we are just creating a new node,
//                   O(1) for the visit function because we are just upadting
//                   the links or the pointers, O(steps), for back() function
//                   because we are given the number of steps to that we have to
//                   go back, O(steps), for the forward() function because we are
//                   given the number of steps that we have to move forward.
// Space Complexity:- O(1), because we are not using any extra space.
class BrowserHistory {
    Node *currentPage;
public:
    BrowserHistory(string homepage) {
        currentPage = new Node(homepage);
    }
    void visit(string url) {
        Node *newNode = new Node(url);
        currentPage->next = newNode;
        newNode->prev = currentPage;
        currentPage = newNode;
    }
    string back(int steps) {
        while (steps) {
            if (currentPage->prev) {
                currentPage = currentPage->prev;
            } else {
                break;
            }
            steps--;
        }
        return currentPage->data;
    }
    string forward(int steps) {
        while (steps) {
            if (currentPage->next) {
                currentPage = currentPage->next;
            } else {
                break;
            }
            steps--;
        }
        return currentPage->data;
    }
};
int main() {
    BrowserHistory *obj = new BrowserHistory("https://www.google.com");
    obj->visit("https://www.facebook.com/page1");
    obj->visit("https://www.amazon.com/page2");
    obj->visit("https://www.microsoft.com/page3");

    cout << "Current page: " << obj->back(2) << endl; // Go back 2 steps
    cout << "Current page: " << obj->forward(1) << endl; // Go forward 1 step

    delete obj; // Don't forget to free memory
    return 0;
}
