#ifndef MANUSIA_H
#define MANUSIA_H
//membuat class manusia di file header manusia.h
class Manusia {
public:
    //membuat member variabel class manusia
    string name;
    Jantung varJantung;

    //membuat constructor dan destructor class manusia
    Manusia(string pName) : name(pName) {
        cout << name << "Hidup\n";
    }
    ~Manusia() {
        cout << name << "Mati\n";
    }
};
#endif // !MANUSIA_H