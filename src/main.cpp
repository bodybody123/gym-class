#include <iostream>

using namespace std;

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

