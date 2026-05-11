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

//pembuatan class pelajar sebagai pewaris dari class orang
class pelajar : public orang {
public:
    //deklarasi member variabel dari class pelajar
    string sekolah;

    //pembuatan constructor dan destructor dari class pelajar
    pelajar(string pNama, string pSekolah) :orang(pNama), sekolah(pSekolah) {
        cout << "Pelajar dibuat\n" << endl;
    }

    ~pelajar() {
        cout << "Pelajar dihapus\n" << endl;
    }

    //pembuatan function perkenalan()
    string perkenalan() {
        return "Hallo, nama saya " + nama + " dari sekolah " + sekolah + "\n\n";
    }

};

