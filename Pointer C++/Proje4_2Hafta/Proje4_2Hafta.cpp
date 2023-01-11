
#include <iostream>

    using namespace std;
    int main() {
        int var = 5;

        // Isaretci degisken bildiriyoruz.
        int* pointVar;

        pointVar = &var;

        // var deeri yazdiriyoruz.
        cout << "var = " << var << endl;

        // var adresini yazdırıyoruz
        cout << "Address of var (&var) = " << &var << endl
            << endl;

        // pointVar ı yazdiriyoruz.
        cout << "pointVar = " << pointVar << endl;

        // pointVar ın isaret ettigi adres adresinin icerigini yazdırıyoruz.
        cout << "Content of the address pointed to by pointVar (*pointVar) = " << *pointVar << endl;

        return 0;
   
}


