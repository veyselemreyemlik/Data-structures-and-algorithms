#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//İkili ağaç düğüm yapısı
typedef struct NODE {
	int x;
	struct NODE* left;
	struct NODE* right;
}NODE;


//İkili ağaç yapısı
typedef struct {
	NODE* root;
}BST;
//İkili arama ağacı oluşturan fonksiyon.
BST* CreateBST() {
	BST* bst;
	bst = (BST*)malloc(sizeof(BST));
	if (bst) {
		bst->root = NULL;
	}
	return bst;
}



//Yeni bir düğüm oluşturan fonksiyon.
NODE* CreateNode(int x) {
	NODE* node;
	//Sistemden yeni düğüm için bellek ayrılıyor.
	node = (NODE*)malloc(sizeof(NODE));
	if (node) {
		//Düğüm verisi kaydediliyor.
		node->x = x;
		//Alt düğümler boşaltılıyor.
		node->left = NULL;
		node->right = NULL;
	}
	return node;
}


//Yeni oluşturulan düğümü ikili ağaca ekleyen fonksiyon.
// root: Kök düğümü 
// node: İkili ağaca eklenecek yeni düğüm.
int InsertNode(NODE* root, NODE* node) {
	if (root == NULL) {
		return 1;
	}
	//Düğüm verisi karşılaştırılıyor.
	if (root->x < node->x) {
		//Yeni düğüm verisi büyük ise sağ düğüm kontrol ediliyor.
		if (root->right == NULL) {
			//Düğüm boşsa yeni düğüm buraya kaydediliyor.
			root->right = node;
			return 0;
		}
		//Düğüm boş değilse ekleme fonksiyonu sağ düğümle
		//yeniden çağrılıyor.
		return InsertNode(root->right, node);

		//Düğüm verisi karşılaştırılıyor.
	}
	else if (root->x > node->x) {
		//Yeni düğüm verisi küçük ise sol düğüm kontrol ediliyor.
		if (root->left == NULL) {
			//Düğüm boşsa yeni düğüm buraya kaydediliyor.
			root->left = node;
			return 0;
		}
		//Düğüm boş değilse ekleme fonksiyonu sol düğümle
		//yeniden çağrılıyor.		
		return InsertNode(root->left, node);

	}

	//Düğüm verileri eşit ise yeni düğüm eklenmiyor.
	//Fonksiyondan çıkılıyor.
	return 1;
}

//Silinecek düğümün yerine geçecek yeni düğümü bulan fonksiyon.
//parent: silinecek düğümün bağlı olduğu düğüm
//node  : silinecek düğüm
NODE* _getLeftNode(NODE* parent, NODE* node) {
	if (node->left) {
		return _getLeftNode(node, node->left);
	}
	//Yeni düğümün alt düğümü bir üst düğüme kaydediliyor.
	//Bulunduğu yerden çıkarılmış oluyor.
	parent->left = node->right;
	// Dönüş değeri silinecek düğümün yerine geçecek düğüm;
	return node;
}



//Eğer silinecek düğümün sağ ve sol düğümleri dolu ise,
//düğüm bu fonksiyonla siliniyor.
// root: silinecek düğümün bağlı olduğu düğüm
// node: silinecek düğüm
NODE* _deleteNode(NODE* root, NODE* node) {
	NODE* tmp;
	tmp = node->right;
	//Önce silinecek düğümün yerine geçecek düğüm bulunuyor.
	if (tmp->left) {
		tmp = _getLeftNode(node, node->right);
		//Bulunan düğüme silinecek düğümün sağ ve sol düğümleri
		//kaydediliyor.		
		tmp->right = node->right;
		tmp->left = node->left;
	}
	else {
		//Bulunan düğüm sağdaki ilk düğüm ise yalnızca sol düğüm
		//kaydediliyor.
		tmp->left = node->left;
	}


	//İlk düğüm ise dönüş değeri bulunan düğümün adresi.
	if (root == NULL) {
		free(node);
		return tmp;
	}

	//Yeni düğüm silinecek düğümün yerine kaydediliyor.
	//Böylece düğüm ikili ağaçtan silinmiş oluyor.
	if (root->left == node) {
		root->left = tmp;
	}
	else {
		root->right = tmp;
	}

	free(node);

	//Fonksiyon dönüş değeri silinen düğümün adresi.
	return root;
}



//Düğüm verisi ile ikili ağaçtan düğüm silen fonksiyon.
// root: İkili ağacın kök düğümü.
// x: Silinecek düğüme ait veri.
NODE* DeleteNode(NODE* root, int x) {
	NODE* node;
	//Düğüm verisi karşılaştırılıyor.
	if (root->x < x) {
		//Aranan düğüm verisi büyük ise sağ düğüme gidiliyor.
		if (root->right == NULL) {
			//Düğüm boşsa silinecek düğüm bulunamadı.
			return NULL;
		}
		//Sağ düğüm geçici bir değişkene aktarılıyor ve 
		//alt düğümü ile silinecek düğüm versi karşılaştırılıyor.
		node = root->right;
		if (node->x == x) {
			//Silinecek düğüm bulundu.
			//Bulunan düğümün alt düğümleri kontrol ediliyor düğümlerden
			// en az biri boş ise düğüm burada siliniyor.
			if (node->right == NULL) {
				//Sağ düğümü boş ise sol düğümü bir üst düğüme kaydediliyor.
				root->right = node->left;
				//Silinen düğüm adresi ile fonksiyondan çıkılıyor.
				free(node);
				return root;
			}
			else if (node->left == NULL) {
				//Sol düğümü boş ise sağ düğümü bir üst düğüme kaydediliyor.
				root->right = node->right;
				//Silinen düğüm adresi ile fonksiyondan çıkılıyor.
				free(node);
				return root;
			}
			else {
				//Sağ ve sol düğümler dolu ise silme fonksiyonu çağrılıyor.
				return _deleteNode(root, node);
			}
		}

		//Silinecek root düğümünün sağ düğümünde aranıyor. 
		return DeleteNode(root->right, x);

		//Düğüm verisi karşılaştırılıyor.	
	}
	else if (root->x > x) {
		//Aranan düğüm verisi büyük ise sol düğüme gidiliyor.
		if (root->left == NULL) {
			//Düğüm boşsa silinecek düğüm bulunamadı.
			return NULL;
		}
		//Sağ düğüm geçici bir değişkene aktarılıyor ve 
		//alt düğümü ile silinecek düğüm versi karşılaştırılıyor.		
		node = root->left;
		if (node->x == x) {
			//Silinecek düğüm bulundu.
			//Bulunan düğümün alt düğümleri kontrol ediliyor düğümlerden
			// en az biri boş ise düğüm burada siliniyor.			
			if (node->right == NULL) {
				//Sol düğümü boş ise sağ düğümü bir üst düğüme kaydediliyor.
				root->left = node->left;
				//Silinen düğüm adresi ile fonksiyondan çıkılıyor.
				free(node);
				return root;
			}
			else if (node->left == NULL) {
				//Sol düğümü boş ise sağ düğümü bir üst düğüme kaydediliyor.
				root->left = node->right;
				//Silinen düğüm adresi ile fonksiyondan çıkılıyor.
				free(node);
				return root;
			}
			else {
				//Sağ ve sol düğümler dolu ise silme fonksiyonu çağrılıyor.
				return _deleteNode(root, node);
			}
		}
		//Silinecek root düğümünün sol düğümünde aranıyor.
		return DeleteNode(root->left, x);
	}

	//Silinecek düğüm ilk düğüm ise üst düğümü olmadığı için 
	//Özel olarak siliniyor.
	//Sağ yada sol düğümlerden yanlızca biri varsa o düğüm 
	//fonksiyonun dönüş değeri.
	if (root->left == NULL) {
		node = root->right;
		free(root);
		return node;
	}
	else if (root->right == NULL) {
		node = root->left;
		free(root);
		return node;
	}

	//İki düğümüde dolu ise silme fonksiyonu ile siliniyor.
	return _deleteNode(NULL, root);
}

//İkili ağacın tüm dallarını dolaşan ve düğüm verilerini
//ekrana yazan fonksiyon.

int _printTree(NODE* root, int x, char* data) {
	int i;
	int t;
	if (root == NULL) {
		return 0;
	}

	x += 80;

	t = 1;
	i = 5 - (x / 80);
	//t=2^(5-derinlik)
	//Konsol ekranında çizilebilir derinlik 5.
	for (;i > 0;i--) {
		t *= 2;
	}

	//Düğümün sol tarafı çiziliyor.
	if (data[x - t] == 0) {
		data[x - t] = '\xda';
	}

	//Düğüm verisi yazılıyor.
	sprintf(&data[x], "%d", root->x);

	//Satırda boş alanlara düz çizgi çiziliyor.
	for (i = -t;i < t;i++) {
		if (data[x + i] == 0) {
			data[x + i] = '\xc4';
		}
	}

	//Düğümün sağ tarafı çiziliyor.	
	if (data[x + t] == 0) {
		data[x + t] = '\xbf';
	}

	_printTree(root->left, x - t, data);
	_printTree(root->right, x + t, data);

	return 0;
}




int PrintTree(NODE* root) {
	int i = 0;
	//Konsol ekranı 80*25 karakter. 
	//Çizim alanı yarım ekran.
	char pdata[80 * 12];
	//Çizim için önce bellek içeriği siliniyor.
	for (i = 0;i < 80 * 12;i++) {
		pdata[i] = 0;
	}
	//40. karakterden başlanıyor (ekran genişliği 80 karakter)
	//yatay olarak konsol ekranının ortası.
	_printTree(root, 40, pdata);
	//Çizim yapılan bellek çıkış akışına kaydediliyor.
	fwrite(pdata, 1, 80 * 12, stdout);
	return 0;
}

int main()
{
    NODE* root;
	NODE* node;
	int x = 1;
	int i = 0;
	char c = 'a';
	BST* bst;
	bst = CreateBST();

	printf("Silme  : s \n");

	while (1) {
		root = bst->root;
		if (root) {
			if (root->x == x) {
				bst->root = DeleteNode(bst->root, x);
			}
			else {
				DeleteNode(bst->root, x);
			}
		}

		PrintTree(bst->root);
	}
}

