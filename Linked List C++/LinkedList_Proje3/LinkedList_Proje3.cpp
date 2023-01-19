#include <iostream>
using namespace std;

//Yeni bir node oluşturuyoruz.
class Node {
public:
    double data;
    Node* next;
public:
    Node(){}
    void ekle(int);
   
}; Node* head;

void Node::ekle(int sayi) {
    Node* newlist = new Node;     // eklenecek nense için yer açılır.
    newlist->data = sayi;         // data ve next pointer lar atanır.
    newlist->next = 0;
    Node* p = head;             // listede dolaşıcak bir pointer tanımlanır.
    if (p == 0)
        head = newlist;
    else
    {
        while (p->next != 0)
            p = p->next;
        p->next = newlist;    // en sona gelindiğinde eleman eklenmiş olur.

    }
}


int main()
{
    Node a;
    int i;
    cout << "Eklemek Istediğiniz Sayi :" << endl << endl;
    cin >> i;
    a.ekle(i);
    
}
