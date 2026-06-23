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
     if (head == NULL) {
            cout << "\nBelum ada event.\n";
            return;
        }

        int id;

        cout << "\nMasukkan ID Event : ";
        cin >> id;
        cin.ignore();

        Event* temp = head;

        while (temp != NULL) {

            if (temp->id == id) {

                Peserta p;

                cout << "Nama Peserta : ";
                getline(cin, p.nama);

                cout << "Prodi/Jurusan : ";
                getline(cin, p.prodi);

                temp->peserta.push(p);

                cout << "\nPendaftaran berhasil.\n";
                return;
            }

            temp = temp->next;
        }

        cout << "\nEvent tidak ditemukan.\n";
    }

    // Anggota 3
    void lihatPeserta() {}
       if (head == NULL) {
            cout << "\nBelum ada event.\n";
            return;
        }

        int id;

        cout << "\nMasukkan ID Event : ";
        cin >> id;

        Event* temp = head;

        while (temp != NULL) {

            if (temp->id == id) {

                cout << "\n===== DAFTAR PESERTA =====\n";
                cout << "Event : " << temp->namaEvent << endl;

                if (temp->peserta.empty()) {
                    cout << "Belum ada peserta.\n";
                    return;
                }

                queue<Peserta> salinan = temp->peserta;

                int no = 1;

                while (!salinan.empty()) {

                    Peserta p = salinan.front();

                    cout << "\nPeserta " << no++ << endl;
                    cout << "Nama  : " << p.nama << endl;
                    cout << "Prodi : " << p.prodi << endl;

                    salinan.pop();
                }

                return;
            }

            temp = temp->next;
        }

        cout << "\nEvent tidak ditemukan.\n";
    }
    // Anggota 4
    void cariEvent() {}
    if (head == NULL) {
            cout << "\nBelum ada event.\n";
            return;
        }

        cin.ignore();

        string keyword;

        cout << "\nMasukkan Nama Event : ";
        getline(cin, keyword);

        Event* temp = head;

        bool ditemukan = false;

        while (temp != NULL) {

            if (temp->namaEvent.find(keyword) != string::npos) {

                cout << "\n===== EVENT DITEMUKAN =====\n";
                cout << "ID      : " << temp->id << endl;
                cout << "Nama    : " << temp->namaEvent << endl;
                cout << "Tanggal : " << temp->tanggal << endl;
                cout << "Lokasi  : " << temp->lokasi << endl;

                ditemukan = true;
            }

            temp = temp->next;
        }

        if (!ditemukan)
            cout << "\nEvent tidak ditemukan.\n";
    }

    // Anggota 5
    void hapusEvent() {}
     if (head == NULL) {
            cout << "\nBelum ada event.\n";
            return;
        }

        int id;

        cout << "\nMasukkan ID Event : ";
        cin >> id;

        Event* temp = head;
        Event* prev = NULL;

        while (temp != NULL && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "\nEvent tidak ditemukan.\n";
            return;
        }

        if (prev == NULL)
            head = head->next;
        else
            prev->next = temp->next;

        delete temp;

        cout << "\nEvent berhasil dihapus.\n";
    }
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
