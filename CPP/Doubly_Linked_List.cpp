#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *previous;
    Node(int value)
    {
        this->data = value;
        this->next = NULL;
        this->previous = NULL;
    }
};
void NodePrint(Node *&head, Node *&end)
{
    Node *temp_head = head;
    int count = 0;
    cout << "First to Last Node:" << endl;
    while (temp_head != NULL)
    {
        cout << temp_head->data << " ";
        temp_head = temp_head->next;
        count++;
    }
    cout << endl;
    cout << "--> " << head->data << " & " << end->data << " <--" << endl;
    cout << "Length: " << count << endl;
    // cout<<temp_head->next->data<<endl;
}
void HeadInsert(Node *&head, Node *&end, int data)
{
    if (head == NULL)
    {
        Node *temp_head = new Node(data);
        head = temp_head;
        end = temp_head;
        NodePrint(head, end);
    }
    else
    {

        Node *temp_head = new Node(data);
        temp_head->next = head;
        head->previous = temp_head;
        head = temp_head;
        // cout<<temp_head->data<<endl;
        NodePrint(head, end);
    }
}
void EndInsert(Node *&head, Node *&end, int data)
{
    if (end == NULL)
    {
        Node *temp_end = new Node(data);
        end = temp_end;
        head = temp_end;
        NodePrint(head, end);
    }
    else
    {

        Node *temp_end = new Node(data);
        end->next = temp_end;
        temp_end->previous = end;
        end = temp_end;
        NodePrint(head, end);
    }
}
void AnyPositionInsert(Node *&head, Node *&end, int position, int data)
{
    Node *temp_last = head;
    int last = 1;
    while (temp_last != NULL)
    {
        last++;
        temp_last = temp_last->next;
    }
    // cout<<last<<endl;
    if (position == 1)
    {
        Node *temp_head = new Node(data);
        temp_head->next = head;
        head->previous = temp_head;
        head = temp_head;
        NodePrint(head, end);
    }
    else if (position == last)
    {
        Node *temp_end = new Node(data);
        end->next = temp_end;
        temp_end->previous = end;
        end = temp_end;
        NodePrint(head, end);
    }
    else
    {
        Node *temp = head;
        Node *temp_data = new Node(data);

        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        temp_data->next = temp->next;
        temp->next->previous = temp_data;
        temp->next = temp_data;
        temp_data->previous = temp;
        NodePrint(head, end);
        // cout<<end->previous->data<<endl<<head->next->data<<" & "<<head->previous->data;
    }
}
void DeleteNode(Node *&head, Node *&end, int position)
{
    Node *temp_last = head;
    int last = 0;
    while (temp_last != NULL)
    {
        last++;
        temp_last = temp_last->next;
    }
    cout << last << endl;
    if (position == 1)
    {
        // for (int i = 0; i < position; i++)
        // {

        //     Node *temp_head = head;
        //     temp_head->next->previous = NULL;
        //     temp_head->next = NULL;
        // }
        Node *temp_head = head->next;
        temp_head->previous = NULL;
        head->next = NULL;
        head = temp_head;
        NodePrint(head, end);
    }
    else if (position == last)
    {
        Node *temp_end = end->previous;
        temp_end->next = NULL;
        end->previous = NULL;
        end = temp_end;
        NodePrint(head, end);
    }
    else
    {
        // Node *temp_head = head;
        Node *temp_posi = head;
        // Node *temp_pre = NULL;
        for (int i = 0; i < position; i++)
        {
            temp_posi = temp_posi->next;
            temp_posi->next->previous = head;
            temp_posi->next = NULL;
            temp_posi->previous = NULL;
        }
        NodePrint(head, end);
    }
}
void DeleteHead(Node *&head, Node *&end)
{
    Node *temp_head = head->next;
    temp_head->previous = NULL;
    head->next = NULL;
    head = temp_head;
    NodePrint(head, end);
}
void DeleteEnd(Node *&head, Node *&end)
{
    Node *temp_end = end->previous;
    temp_end->next = NULL;
    end->previous = NULL;
    end = temp_end;
    NodePrint(head, end);
}
void OutputTest(Node *&head, Node *&end)
{
    // cout << head->data << endl;
    // cout << head->next->next->next->next->data << endl;
    // cout << end->previous->previous->previous->next->next->next->data << endl;
    // cout << head->previous->data << endl;
    Node *temp_end = end, *temp_head = head;
    int last = 0;
    while (temp_head != NULL)
    {
        temp_head = temp_head->next;
        last++;
    }
    cout << "Last Position: " << last << endl;
    // cout<<"First to Last:"<<endl;
    cout << "Last to First Node:" << endl;
    for (int i = last; temp_end != NULL; i--)
    {
        cout << temp_end->data << " ";
        temp_end = temp_end->previous;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // Node *n1;
    // n1 = new Node(10);
    // Node *head = n1, *end = n1;
    Node *head = NULL;
    Node *end = NULL;
    // NodePrint(head, end);
    HeadInsert(head, end, 221);
    // NodePrint(head,end);
    EndInsert(head, end, 20);
    // NodePrint(head,end);
    HeadInsert(head, end, 2475);
    EndInsert(head, end, 30);
    AnyPositionInsert(head, end, 1, 40);
    AnyPositionInsert(head, end, 1, 70);
    DeleteNode(head, end, 1);
    DeleteNode(head, end, 5);
    HeadInsert(head, end, 100);
    EndInsert(head, end, 97);
    DeleteHead(head, end);
    DeleteEnd(head, end);

    OutputTest(head, end);
    return 0;
}