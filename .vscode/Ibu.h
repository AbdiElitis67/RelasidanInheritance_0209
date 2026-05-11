#ifndef IBU_H
#define IBU_H

class anak;

//membuat class ibu pada file header ibu.h
class Ibu {
public:
    //deklarasi member variabel pada class ibu
    string nama;
    vector<anak*> daftar_anak;

    //membuat constructor dan destructor pada class ibu
    Ibu(string pNama) :nama(pNama) {
        cout << "Ibu \"" << nama << "\" ada\n";
    };

    ~Ibu() {
        cout << "Ibu \"" << nama << "\" tidak ada\n";
    };

    //deklarasi prosedur tambahAnak() dan cetakAnak()
    void tambahAnak(anak* pAnak);
    void cetakAnak();
};

//pendefinisian prosedur - prosedur pada class ibu diluar class
void Ibu::tambahAnak(anak* pAnak) {
    daftar_anak.push_back(pAnak);
}

void Ibu::cetakAnak() {
    cout << "Daftar Anak dari Ibu \"" << this->nama << "\":\n";
    for (auto& a : daftar_anak)
    {
        cout << a->nama << "\n";
    }
    cout << endl;
}

#endif