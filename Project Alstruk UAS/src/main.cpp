#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Panitia {
    string nama;
    string jabatan;
};

struct Peserta {
    string nama;
    string prodi;
};

struct Event {
    int id;
    string namaEvent;
    string tanggal;
    string lokasi;

    Panitia panitia[5];
    int jumlahPanitia;

    queue<Peserta> peserta;

    Event* next;
};

class EventManager {
private:
    Event* head;
    int nextId;

public:
    EventManager() {
        head = NULL;
        nextId = 1;
    }

    // Anggota 2
    void tambahEvent() {}

    // Anggota 2
    void tampilkanEvent() {}

    // Anggota 3
    void daftarPeserta() {}

    // Anggota 3
    void lihatPeserta() {}

    // Anggota 4
    void cariEvent() {}

    // Anggota 4
    void hapusEvent() {}
};

int main() {

    EventManager sistem;
    int pilihan;

    do {
        cout << "\n1. Tambah Event";
        cout << "\n2. Lihat Event";
        cout << "\n3. Daftar Peserta";
        cout << "\n4. Lihat Peserta";
        cout << "\n5. Cari Event";
        cout << "\n6. Hapus Event";
        cout << "\n7. Keluar";
        cout << "\nPilihan : ";

        cin >> pilihan;

    } while (pilihan != 7);

    return 0;
}
