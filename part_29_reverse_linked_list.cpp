#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *reverseLinkedList(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *front = NULL;

    while (curr != NULL)
    {
        front = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = front;
    }

    return prev;
}

/*  prev curr next
           1    2   3   4
*/


int main()
{

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    cout << "Original Linked List \n";
    print(head);
    head = reverseLinkedList(head);
    cout << "\nReversed Linked List\n";
    print(head);

    return 0;
}