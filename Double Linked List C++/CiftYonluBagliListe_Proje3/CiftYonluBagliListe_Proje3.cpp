
#include <iostream>
using namespace std;

struct Node {
    int veri;
    struct Node* prev;
    struct Node* next;
};
struct Node* head = NULL;


// insert() işlevi, verileri çift bağlantılı listenin başına ekler.
//Bir yeni düğüm oluşturur ve sayıyı yeni düğümün veri alanına ekler.
void insert(int yeniveri) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->veri = yeniveri;
    newnode->prev = NULL;
    newnode->next = head;
    if (head != NULL)
        head->prev = newnode;
    head = newnode;

    //Head NULL değilse, head öğesinin önceki işaretçisi yeniveriy'i gösterir.
}
//display() işlevi, çift bağlantılı listenin tamamını görüntüler. İlk ptr başa işaret eder.
//Ardından, düğümlerin tüm veri değerleri yazdırılana kadar sürekli olarak bir sonraki düğüme iletiyorız.
void display() {
    struct Node* ptr;
    ptr = head;
    while (ptr != NULL) {
        cout << ptr->veri << " ";
        ptr = ptr->next;
    }
}
int main()
{
    // veri giriyoruz ve yazdırıyoruz.
    insert(5);
    insert(0);
    insert(9);
    insert(1);
    cout << "Çift Bağlı Liste : ";
    display();
    return 0;
}

