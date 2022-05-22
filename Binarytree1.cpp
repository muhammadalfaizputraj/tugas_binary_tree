#include<iostream>
#define SPACE 10
using namespace std;

// deklarasi class sebuah tree
class TreeNode {
	public:
    	int value;
		  TreeNode * kiri;
		  TreeNode * kanan;

	  	TreeNode() {
	    	value = 0;
	    	kiri = NULL;
	    	kanan = NULL;
	  	}
	  	TreeNode(int v) {
	    	value = v;
	    	kiri = NULL;
	    	kanan = NULL;
	  	}
};

class BST {
  	public:
    	TreeNode * root;
  		BST() {
    		root = NULL;
  		}
  		bool isTreeEmpty() {
   			if (root == NULL) {
      			return true;
    		} 
			else {
      			return false;
    		}
  		}

// fungsinya untuk menambahkan node yang baru
	void insertNode(TreeNode * node_baru) {
  	// jika saja root masih kosong
	    if (root == NULL) {
	      	// pengalokasian memori dari node yang telah dibuat
	      	root = node_baru;
	      	cout << "Nilai Dimasukkan sebagai simpul akar!" << endl;
	    } else {
		    TreeNode * temp = root;
		    while (temp != NULL) {
		        if (node_baru -> value == temp -> value) {
		          	cout << "Nilai Sudah ada," <<
		            "Masukkan nilai lain!" << endl;
		          	return;
	        	} else if ((node_baru -> value < temp -> value) && (temp -> kiri == NULL)) {
	          		temp -> kiri = node_baru;
	          		cout << "Nilai Disisipkan ke kiri!" << endl;
	          	break;
	        	} else if (node_baru -> value < temp -> value) {
	          		temp = temp -> kiri;
	        	} else if ((node_baru -> value > temp -> value) && (temp -> kanan == NULL)) {
	          		temp -> kanan = node_baru;
	          		cout << "Nilai Disisipkan di sebelah kanan!" << endl;
	          	break;
	        	} else {
	          		temp = temp -> kanan;
	        	}
	      	}
	    }
  	}
  			TreeNode* insertRecursive(TreeNode *r, TreeNode *node_baru){
				if(r==NULL){
					r=node_baru;
					cout <<"Penyisipan berhasil"<<endl;
					return r;
				}if(node_baru ->value < r->value){
					r->kiri = insertRecursive(r->kiri,node_baru);
				}else if (node_baru->value > r->value){
					r->kanan = insertRecursive(r->kanan,node_baru);
				}else{
			     	cout << "Tidak ada nilai duplikat yang diizinkan!" << endl;
			     	return r; 
				}
				return r;
			}

  	void print2D(TreeNode * r, int space) {
    // base case 1
		if (r == NULL)
	      	return;
    // untuk memperluas jarak antara level 2
		space += SPACE;
	// proses anak kanan dulu 3
    	print2D(r -> kanan, space);
    		cout << endl;
    	for (int i = SPACE; i < space; i++)
	  		cout << " ";
			cout << r -> value << "\n";
    // proses anak kiri 7
		print2D(r -> kiri, space);
  	}

  // simpul saat ini, kiri, kanan
  	void printPreorder(TreeNode * r){
	    if (r == NULL)
	      	return;
    		cout << r -> value << " ";		// untuk mencetak data simpul pertama
    		printPreorder(r -> kiri);		// kemudian akan muncul kembali di subpohon kiri
    		printPreorder(r -> kanan);		// sekarang akan muncul kembali di subpohon kanan
  	}	

  // kiri, simpul terkini, kanan
  	void printInorder(TreeNode * r)
  {
    if (r == NULL)
      return;
    // pertama muncul kembali di anak kiri
    printInorder(r -> kiri);
    // kemudian mencetak data di simpul
    cout << r -> value << " ";
    // sekarang akan muncul kembali di anak kanan
    printInorder(r -> kanan);
  }

  // kiri, kanan, akar
  void printPostorder(TreeNode * r)
  {
    if (r == NULL)
      return;
    // pertama muncul kembali di subpohon kiri 
    printPostorder(r -> kiri);
    // kemudian akan muncul kembali di subpohon kanan
    printPostorder(r -> kanan);
    // sekarang sepaket dengan simpul
    cout << r -> value << " ";
  }

  TreeNode * iterativeSearch(int v) {
    if (root == NULL) {
      return root;
    } else {
      TreeNode * temp = root;
      while (temp != NULL) {
        if (v == temp -> value) {
          return temp;
        } else if (v < temp -> value) {
          temp = temp -> kiri;
        } else {
          temp = temp -> kanan;
        }
      }
      return NULL;
    }
  }

  TreeNode * recursiveSearch(TreeNode * r, int val) {
    if (r == NULL || r -> value == val)
      return r;

    else if (val < r -> value)
      return recursiveSearch(r -> kiri, val);

    else
      return recursiveSearch(r -> kanan, val);
  }

  int height(TreeNode * r) {
    if (r == NULL)
      return -1;
    else {
      // tinggi komputer satu sama lain | persaaman tinggi sampul kanan | kiri
      int lheight = height(r -> kiri);
      int rheight = height(r -> kanan);

      // menggunakan yang terbesar
      if (lheight > rheight)
        return (lheight + 1);
      else return (rheight + 1);
    }
  }

  // mencetak simpul
  void printGivenLevel(TreeNode * r, int level) {
    if (r == NULL)
      return;
    else if (level == 0)
      cout << r -> value << " ";
    // level > 0
	else
    {
      printGivenLevel(r -> kiri, level - 1);
      printGivenLevel(r -> kanan, level - 1);
    }
  }
  void printLevelOrderBFS(TreeNode * r) {
    int h = height(r);
    for (int i = 0; i <= h; i++)
      printGivenLevel(r, i);
  }

  TreeNode * minValueNode(TreeNode * node) {
    TreeNode * current = node;
    // perulangan untuk menemukan daun paling kiri
    while (current -> kiri != NULL) {
      current = current -> kiri;
    }
    return current;
  }

};

int main() {
	//Mengubah nama class menjadi objek
  	BST obj;
	int pilihan, nilai;

	do {
		cout << "========= Menu =========" << endl;
		cout << "0. Keluar Program" << endl;
		cout << "1. Masukkan Simpul" << endl;
	    cout << "2. Mencetak Nilai BFS" << endl;
	    cout << endl;

		cin >> pilihan;
	    // untuk mengubah variable;
	    TreeNode * node_baru = new TreeNode();

	    switch (pilihan) {
	    	case 0:
		      	break;
		    case 1:
			  	cout << "Masukkan Angka : ";
				cin >> nilai;
				node_baru -> value = nilai;
				obj.root = obj.insertRecursive(obj.root,node_baru);
				cout << endl;
		    break;
		    case 2:
			    cout << "Cetak" << endl;
			    obj.print2D(obj.root, 5);
			    cout << endl;
			    cout << "Mencetak Level Order BFS: \n";
			    obj.printLevelOrderBFS(obj.root);
			    cout << "\n\n";
		    break;
		    default:
		      	cout << "Nomor yang anda masukkan tidak sesuai";
		}
	}
	while (pilihan != 0);

	return 0;
}
