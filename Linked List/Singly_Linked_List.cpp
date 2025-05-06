#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
} *n1;
void FrontInsert(Node *&head, int data)
{
    Node *temp_head = new Node(data);
    temp_head->next = head;
    head = temp_head;
}
void EndInsert(Node *&end, int value)
{
    Node *temp_end = new Node(value);
    end->next = temp_end;
    end = temp_end;
}
void InsertByPosition(Node *&head, Node *&end, int posi, int data)
{
    Node *temp_head = head, *temp_end = end;
    Node *temp_value = new Node(data);
    Node *temp_count = head;
    int count = 1;
    while (temp_count != NULL)
    {
        temp_count = temp_count->next;
        count++;
    }
    // cout << count << endl;
    if (posi == 1)
    {
        temp_value->next = head;
        head = temp_value;
    }

    else
    {
        for (int i = 1; i < posi - 1; i++)
        {
            temp_head = temp_head->next;
        }
        temp_value->next = temp_head->next;
        temp_head->next = temp_value;
        while (temp_end != NULL)
        {
            end = temp_end;
            temp_end = temp_end->next;
        }
    }
}
void DeleteNode(Node *head, int n)
{
    
}
void NodePrint(Node *&head, Node *&end)
{
    Node *temp = head;
    // for (int i = 1; temp != NULL; i++)
    cout << "Updated Values:" << endl;
    // int count =0;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
        // count++;
    }
    cout << endl;
    // cout << count << endl;
    cout << "--> " << head->data << " & " << end->data << " <--" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node *head1 = n1, *end1 = n1;
    // int value;
    // cin >> value;
    // n1 = new Node(value);
    // NodePrint(head1, end1);
    cout << "---> " << head1->data << " & " << end1->data << " <---" << endl;
    InsertByPosition(head1, end1, 1, 21);
    NodePrint(head1, end1);
    // cout << "---> " << head1->data << " & " << end1->data << " <---" << endl;
    // FrontInsert(head1, 19);
    // EndInsert(head1, 35);
    InsertByPosition(head1, end1, 2, 38);
    NodePrint(head1, end1);
    // cout << "---> " << head1->data << " & " << end1->data << " <---" << endl;
    InsertByPosition(head1, end1, 1, 49);
    NodePrint(head1, end1);
    // cout << "---> " << head1->data << " & " << end1->data << " <---" << endl;
    InsertByPosition(head1, end1, 4, 57);
    NodePrint(head1, end1);
    InsertByPosition(head1, end1, 3, 82);
    NodePrint(head1, end1);
    InsertByPosition(head1, end1, 7, 221);
    NodePrint(head1, end1);
    // cout << "---> " << head1->data << " & " << end1->data << " <---" << endl;
    FrontInsert(head1, 31);
    NodePrint(head1, end1);
    EndInsert(end1, 75);
    NodePrint(head1, end1);
    return 0;
}