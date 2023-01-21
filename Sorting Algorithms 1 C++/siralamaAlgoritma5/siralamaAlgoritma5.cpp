#include <iostream> // cin, cout vs.
#include <clocale> // Türkçe karakterler
#include <windows.h> // Arkaplan ve yazı rengi

using namespace std; // std::

int main() {
	setlocale(LC_ALL, "turkish"); // Türkçe Karakterleri Ekliyoruz.
	system("color f9"); // Arkaplan ve yazı rengi.

	int n;
	int temp; // Geçiçi değişken.

	// Girilecek sayı adetinin kullanıcıdan istenmesi.
	cout << "Kaç adet tam sayı gireceksiniz: ";
	cin >> n;

	// n elemanlı sayı dizisi.
	int sayi[n];

	// n adet sayının kullanıcıdan istenmesi.
	cout << endl << "Sayıları giriniz: " << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ". sayıyı giriniz: ";
		cin >> sayi[i];
	}

	// Bubble Sort (Kabarcık Sıralama) Algoritması.
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			// Dizideki sayı çiftlerini kontrol et.
			if (sayi[i] > sayi[j]) {
				// Yanlış sıralanmış sayı çiftlerinin yerini değiştir.
				temp = sayi[i];
				sayi[i] = sayi[j];
				sayi[j] = temp;
			}
		}
	}

	// Sonucun ekranda gösterilmesi.
	cout << endl;
	cout << "Girilen " << n << " adet sayının küçükten büyüğe sıralanmış hali: ";
	for (int i = 0; i < n; i++) {
		cout << sayi[i] << " ";
	}
	cout << endl;

	system("PAUSE");
	return 0;
}