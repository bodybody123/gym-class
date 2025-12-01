#include <iostream>

using namespace std;

struct dataKelas
{
    string id_Kelas;
    string nama_kelas;
    string jadwal_kelas;
    int kapasitas_kelas;
    int biaya_kelas;
    string nama_coach;
    dataKelas* next;
};

struct dataPeserta
{
    string id_Peserta;
    string nama_peserta;
    dataPeserta* next;
};

struct dataKehadiran
{
    string tanggal_registrasi;
    string status_kehadiran;
    string presensi;
    int rating;
    string catatan;
    dataKehadiran* next;
    dataPeserta* peserta;
    dataKelas* kelas;
};

void insertDataPeserta(dataPeserta** head, const string& id, const string& nama) {
    dataPeserta* newPeserta = new dataPeserta();
    newPeserta->id_Peserta = id;
    newPeserta->nama_peserta = nama;
    newPeserta->next = *head;
    *head = newPeserta;
}

void insertDataKehadiran(dataKehadiran** head, const string& tanggal, const string& status, const string& presensi, int rating, const string& catatan, dataPeserta* peserta, dataKelas* kelas) {
    dataKehadiran* newKehadiran = new dataKehadiran();
    newKehadiran->tanggal_registrasi = tanggal;
    newKehadiran->status_kehadiran = status;
    newKehadiran->presensi = presensi;
    newKehadiran->rating = rating;
    newKehadiran->catatan = catatan;
    newKehadiran->peserta = peserta;
    newKehadiran->kelas = kelas;
    newKehadiran->next = *head;
    *head = newKehadiran;
}

void deleteDataPeserta(dataPeserta** head, const string& id) {
    dataPeserta* temp = *head;
    dataPeserta* prev = nullptr;

    while (temp != nullptr && temp->id_Peserta != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return; // Not found

    if (prev == nullptr) {
        *head = temp->next; // Delete head
    } else {
        prev->next = temp->next; // Bypass the node to be deleted
    }
    delete temp;
}

void deleteDataKehadiran(dataKehadiran** head, const string& tanggal) {
    dataKehadiran* temp = *head;
    dataKehadiran* prev = nullptr;

    while (temp != nullptr && temp->tanggal_registrasi != tanggal) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return; // Not found

    if (prev == nullptr) {
        *head = temp->next; // Delete head
    } else {
        prev->next = temp->next; // Bypass the node to be deleted
    }
    delete temp;
}

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}

