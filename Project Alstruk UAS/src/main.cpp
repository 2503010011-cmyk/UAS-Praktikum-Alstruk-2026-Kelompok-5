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
    Event* baru = new Event;
        baru->id = nextId++;

        cin.ignore();

        cout << "\n===== TAMBAH EVENT =====\n";

        cout << "Nama Event : ";
        getline(cin, baru->namaEvent);

        cout << "Tanggal : ";
        getline(cin, baru->tanggal);

        cout << "Lokasi : ";
        getline(cin, baru->lokasi);

        cout << "Jumlah Panitia (Maks 5): ";
        cin >> baru->jumlahPanitia;
        cin.ignore();

        if (baru->jumlahPanitia > 5)
            baru->jumlahPanitia = 5;

        for (int i = 0; i < baru->jumlahPanitia; i++) {

            cout << "\nPanitia ke-" << i + 1 << endl;

            cout << "Nama : ";
            getline(cin, baru->panitia[i].nama);

            cout << "Jabatan : ";
            getline(cin, baru->panitia[i].jabatan);
        }

        baru->next = NULL;

        if (head == NULL) {
            head = baru;
        }
        else {

            Event* temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = baru;
        }

        cout << "\nEvent berhasil ditambahkan.\n";
    }
    // Anggota 2
    void tampilkanEvent() {}
    if (head == NULL) {
            cout << "\nBelum ada event.\n";
            return;
        }

        Event* temp = head;

        cout << "\n========== DAFTAR EVENT ==========\n";

        while (temp != NULL) {

            cout << "\nID Event : " << temp->id;
            cout << "\nNama     : " << temp->namaEvent;
            cout << "\nTanggal  : " << temp->tanggal;
            cout << "\nLokasi   : " << temp->lokasi;

            cout << "\n\nStruktur Panitia:\n";

            for (int i = 0; i < temp->jumlahPanitia; i++) {

                cout << "- "
                     << temp->panitia[i].nama
                     << " ("
                     << temp->panitia[i].jabatan
                     << ")\n";
            }

            cout << "Jumlah Peserta : "
                 << temp->peserta.size()
                 << endl;

            cout << "\n------------------------------\n";

            temp = temp->next;
        }
    }
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
