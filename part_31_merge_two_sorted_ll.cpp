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

void insertAtTail(Node *&tail, int val)
{
    Node *temp = new Node(val);
    tail->next = temp;
    tail = temp;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *mergeTwoList(Node *head1, Node *head2)
{
    Node *dummy = new Node(0);
    Node *curr = dummy;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            curr->next = head1;
            head1 = head1->next;
        }

        else
        {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }

    while (head1 != NULL)
    {
        curr->next = head1;
        curr = curr->next;
        head1 = head1->next;
    }

    while (head2 != NULL)
    {
        curr->next = head2;
        curr = curr->next;
        head2 = head2->next;
    }

    return dummy->next;
}

int main()
{

    Node *head1 = new Node(1);
    Node *tail1 = head1;
    insertAtTail(tail1, 3);
    insertAtTail(tail1, 3);
    insertAtTail(tail1, 6);
    insertAtTail(tail1, 11);
    insertAtTail(tail1, 13);

    Node *head2 = new Node(2);
    Node *tail2 = head2;
    insertAtTail(tail2, 4);
    insertAtTail(tail2, 8);
    insertAtTail(tail2, 20);
    cout << "Before the merging of two lists\n";
    print(head1);
    print(head2);
    cout << "After merging the two linked lists\n";
    Node *head = mergeTwoList(head1, head2);
    print(head);

    return 0;
}