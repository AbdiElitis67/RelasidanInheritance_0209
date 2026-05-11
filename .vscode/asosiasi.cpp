#include <iostream>
#include <vector>
using namespace std;

//deklarasi class dokter
class dokter;

//deklarasi dan pembuatan class pasien
class pasien {
public:
    //deklarasi member variabel dari class pasien
    string nama;
    vector<dokter*> daftar_dokter;

    //pembuatan constructor dan destructor dari class pasien
    pasien(string pNama) :nama(pNama) {
        cout << "Pasien \"" << nama << "\" ada\n";
    };

    ~pasien() {
        cout << "Pasien \"" << nama << "\" tidak ada\n";
    };

    //deklarasi prosedur tambahDokter() dan cetakDokter()
    void tambahDoker(dokter*);
    void cetakDokter();

};

//pembuatan class dokter
class dokter {
public:
    //deklarasi member variabel dari class dokter
    string nama;
    vector<pasien*> daftar_pasien;

    //pembuatan constructor dan destructor dari class dokter
    dokter(string pNama) :nama(pNama) {
        cout << "Dokter \"" << nama << "\" ada\n";
    }

    ~dokter() {
        cout << "Dokter \"" << nama << "\" tidak ada\n";
    }

    //deklarasi prosedur tambahPasien() dan cetakPasien()
    void tambahPasien(pasien*);
    void cetakPasien();

};

//pendefinisian prosedur - prosedur dari class dokter dan class pasien diluar class
void pasien::tambahDoker(dokter* pDokter) {
    daftar_dokter.push_back(pDokter);
};

void pasien::cetakDokter() {
    cout << "Daftar Dokter yang menangani pasien \"" << this->nama << "\":\n";
    for (auto& a : daftar_dokter)
    {
        cout << a->nama << "\n";
    }
    cout << endl;
}

void dokter::tambahPasien(pasien* pPasien) {
    daftar_pasien.push_back(pPasien);
    pPasien->tambahDoker(this);
}

void dokter::cetakPasien() {
    cout << "Daftar Pasien dari Dokter \"" << this->nama << "\":\n";
    for (auto& a : daftar_pasien)
    {
        cout << a->nama << "\n";
    }
    cout << endl;
}

int main()
{
    //deklarasi dan pemberian nilai variabel pointer untuk objek dari class dokter dan pasien
    dokter* varDokter1 = new dokter("dr. Budi");
    dokter* varDokter2 = new dokter("dr. Tono");
    pasien* varPasien1 = new pasien("Andi");
    pasien* varPasien2 = new pasien("Lia");

    //pemanggilan dan pemberian argument prosedur tambahPasien() dari class dokter
    varDokter1->tambahPasien(varPasien1);
    varDokter1->tambahPasien(varPasien2);
    varDokter2->tambahPasien(varPasien1);

    //pemanggilan prosedur cetakPasien() dari class dokter
    varDokter1->cetakPasien();
    varDokter2->cetakPasien();
    varPasien1->cetakDokter();
    varPasien2->cetakDokter();

    //mendelete variabel - variabel pointer dari memori
    delete varPasien1;
    delete varPasien2;
    delete varDokter1;
    delete varDokter2;

    return 0;
}