
#include <iostream>

struct ogrenci {
    char ad;
    int yas;
    float boy;
};

// Ogrenci adında bir yapı oluşturuyoruz.

int main()
{
    // Burda ise struct içinde tanımladıklarımız ögelere değer atıyoruz
    struct ogrenci ogr1; // ogr1 adında nesne türetiyoruz.
    ogr1.ad =  'A';
    ogr1.yas = 21;
    ogr1.boy = 1.78;
    struct ogrenci ogr2 = { 'B',19,1.75};  // ogr2 adında nesne türetiyoruz. 
    if (ogr1.boy > ogr2.boy) //if kontrolü ile hangi nesne daha uzun onu kontrol ediyoruz.
        std:: cout << ogr1.ad << "daha uzundur\n";
    else
       std:: cout << ogr2.ad << "daha uzundur\n";

    return 0;
}

