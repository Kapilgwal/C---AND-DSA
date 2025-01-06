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

bool detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            return true;
        }
    }

    return false;
}

bool detectCycleBrute(Node *head)
{
    Node *temp = head;
    unordered_map<Node *, int> mp;

    while (temp != NULL)
    {
        if (mp.find(temp) != mp.end())
        {
            return true;
        }

        mp[temp] = 1;
        temp = temp->next;
    }

    return false;
}
int main()
{

    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third;

    // bool ans = detectCycle(head);
    bool ans = detectCycleBrute(head);
    cout << ans;

    return 0;
}