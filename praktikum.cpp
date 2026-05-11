#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// ============================================================
// Base Class: User
// ============================================================
class User {
protected:
    static int globalId;   // ID counter bersama untuk semua user
    int         id;
    string      nama;
    string      email;

    int generateId() {
        return ++globalId;
    }

public:
    User(const string& nama, const string& email)
        : nama(nama), email(email)
    {
        this->id = generateId();
    }

    // Getter
    int           getId()    const { return id;    }
    const string& getNama()  const { return nama;  }
    const string& getEmail() const { return email; }

    virtual ~User() = default;
};

// Inisialisasi static member
int User::globalId = 0;


// ============================================================
// Derived Class: Member
// ============================================================
class Member : public User {
private:
    bool status; // true = aktif, false = non-aktif

public:
    Member(const string& nama, const string& email, bool status = true)
        : User(nama, email), status(status) {}

    bool getStatus() const { return status; }
    void setStatus(bool s) { status = s;    }

    void showProfile() const {
        cout << "========== Profil Member ==========\n";
        cout << "ID     : " << id                              << "\n";
        cout << "Nama   : " << nama                            << "\n";
        cout << "Email  : " << email                           << "\n";
        cout << "Status : " << (status ? "Aktif" : "Non-Aktif") << "\n";
        cout << "===================================\n";
    }
};


// ============================================================
// Derived Class: Admin
// ============================================================
class Admin : public User {
private:
    vector<Member*> daftarMember; // Admin mengelola daftar member

public:
    Admin(const string& nama, const string& email)
        : User(nama, email) {}

    // Tambah member ke daftar (untuk keperluan manajemen)
    void addMember(Member* m) {
        daftarMember.push_back(m);
    }

    // Tampilkan seluruh member beserta statusnya
    void showAllMember() const {
        cout << "\n========== Daftar Semua Member ==========\n";
        if (daftarMember.empty()) {
            cout << "(Belum ada member terdaftar)\n";
        } else {
            cout << left;
            cout.width(5);  cout << "ID";
            cout.width(20); cout << "Nama";
            cout.width(25); cout << "Email";
            cout              << "Status\n";
            cout << string(60, '-') << "\n";

            for (const Member* m : daftarMember) {
                cout.width(5);  cout << m->getId();
                cout.width(20); cout << m->getNama();
                cout.width(25); cout << m->getEmail();
                cout              << (m->getStatus() ? "Aktif" : "Non-Aktif") << "\n";
            }
        }
        cout << "=========================================\n";
    }

    // Toggle status aktif/non-aktif berdasarkan ID member
    void toggleActivationMember(int memberId) {
        auto it = find_if(daftarMember.begin(), daftarMember.end(),
                          [memberId](const Member* m) {
                              return m->getId() == memberId;
                          });

        if (it != daftarMember.end()) {
            Member* m      = *it;
            bool    before = m->getStatus();
            m->setStatus(!before);

            cout << "[Admin] Status member \"" << m->getNama() << "\" diubah: "
                 << (before ? "Aktif" : "Non-Aktif")
                 << " -> "
                 << (m->getStatus() ? "Aktif" : "Non-Aktif")
                 << "\n";
        } else {
            cout << "[Admin] Member dengan ID " << memberId << " tidak ditemukan.\n";
        }
    }

    ~Admin() = default;
};


// ============================================================
// Main — Contoh Penggunaan
// ============================================================
int main() {
    // Buat admin
    Admin admin("Budi", "budi@admin.com");
    cout << "Admin terdaftar: " << admin.getNama()
         << " (ID: " << admin.getId() << ")\n";

    // Buat member
    Member m1("Andi",  "andi@mail.com");
    Member m2("Sari",  "sari@mail.com");
    Member m3("Rudi",  "rudi@mail.com", false); // langsung non-aktif

    // Daftarkan member ke admin
    admin.addMember(&m1);
    admin.addMember(&m2);
    admin.addMember(&m3);

    // Tampilkan semua member
    admin.showAllMember();

    // Tampilkan profil salah satu member
    m1.showProfile();

    // Toggle aktivasi
    admin.toggleActivationMember(m1.getId()); // Andi: Aktif -> Non-Aktif
    admin.toggleActivationMember(m3.getId()); // Rudi: Non-Aktif -> Aktif
    admin.toggleActivationMember(99);         // ID tidak ada

    // Tampilkan ulang setelah perubahan
    admin.showAllMember();

    return 0;
}