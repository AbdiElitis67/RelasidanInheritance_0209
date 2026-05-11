#include <iostream>
#include <string>
using namespace std;

//pembuatan class orang
class orang {
public:
    //deklarasi member variabel dari class orang
    string nama;

    //pembuatan constructor dan destructor dari class orang
    orang(string pNama) :nama(pNama) {
        cout << "Orang dibuat\n" << endl;
    }

    ~orang() {
        cout << "Orang dihapus\n" << endl;
    }

    //pembuatan function jumlah
    int jumlah(int a, int b) {
        return a + b;
    }

};

