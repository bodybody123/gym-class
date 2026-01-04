#include <iostream> // Meng-include header standar C++ untuk input/output (cout, cin, dll).
#include "AttendeeList.hpp" // Meng-include file header bernama AttendeeList.hpp.

using namespace std; // Mengizinkan penggunaan nama-nama dari namespace std (seperti cout, string, endl) tanpa harus menulis std:: di depannya.

// Deklarasi fungsi insertAttendee yang bertugas menambahkan attendee baru ke linked list.
void insertAttendee(Attendee* &head, Attendee *attendee) { 
// (Attendee* &head): merupakan referensi ke pointer head (agar perubahan head di dalam fungsi memengaruhi variabel asli di luar fungsi).
// (Attendee *attendee): parameter ini merupakan pointer ke node Attendee yang akan ditambahkan.

    attendee->next = head; // Baris ini menyambungkan field next pada node baru (attendee) ke head lama, supaya node baru menjadi kepala list baru (insert di depan).
    head = attendee; // Mengubah head menjadi node baru, supaya node baru menjadi elemen pertama di list.
}

// Fungsi untuk menghapus node dengan ID tertentu.
void deleteAttendee(Attendee* &head, const string& id) {
// Fungsi deleteAttendee menghapus node attendee dengan ID yang sesuai dari linked list, dengan parameter Attendee* &head sebagai referensi ke pointer head agar head dapat diubah jika node pertama dihapus, dan const string& id sebagai ID target yang dicari untuk penghapusan secara efisien.

    Attendee* temp = head; // Pointer temp untuk traversal mencari node yang akan dihapus, yang dimulai dari head.
    Attendee* prev = nullptr; // Pointer prev untuk menyimpan node sebelum temp.

    while (temp != nullptr && temp->data.id != id) { // Selama temp belum nullptr (artinya list belum habis) DAN ID pada node temp saat ini belum sama dengan id yang dicari
    // Selama temp belum mencapai akhir list (nullptr) DAN ID pada node saat ini belum cocok dengan id yang dicari, loop terus berjalan.
    prev = temp; 
    // Simpan pointer node saat ini ke prev, agar prev selalu menunjuk node sebelum temp.
    temp = temp->next; 
    // Pindah temp ke node berikutnya dalam linked list untuk melanjutkan pencarian.
    }

    if (temp == nullptr) return; // Jika tidak menemukan node dengan ID tersebut (temp menjadi nullptr), langsung keluar dari fungsi (tidak ada yang dihapus).

    if (prev == nullptr) { // Jika prev masih nullptr, berarti node yang akan dihapus adalah node pertama (head).
        head = temp->next; // Ubah head menjadi node berikutnya (melewati node yang dihapus).
    } else { // jika bukan / prev tidak nullptr
        prev->next = temp->next; // Hubungkan node sebelumnya langsung ke node setelah temp, sehingga temp terlepas dari list.
    }

    delete temp; // menghapus memori yang dialokasikan untuk node yang dihapus.
}

// Fungsi untuk mencetak detail satu attendee.
void printAttendeeDetails(Attendee *attendee)
{
    if (attendee != nullptr) { // Cek apakah pointer valid.
        cout << "Attendee ID: " << attendee->data.id << ", Name: " << attendee->data.name << endl; // Cetak ID dan nama attendee.
    } else { // Jika pointer nullptr
        cout << "Attendee not found." << endl; // Cetak pesan bahwa attendee tidak ditemukan.
    }
}

// Fungsi untuk mencetak semua attendee dalam list.
void getAllAttendees(Attendee *head)
{
    Attendee* current = head; // Mulai mengunjungi dan mencetak semua attendee secara berurutan dari node pertama (head) sampe terakhir, satu persatu tanpa melewatkan satupun
    
    while (current != nullptr) { // Selama belum sampai akhir list (current masih menunjuk node valid)
        printAttendeeDetails(current); // "Kunjungi" node saat ini → lakukan aksi: cetak detail attendee
        current = current->next;       // Pindah ke node berikutnya untuk dikunjungi
    }
}

Attendee *getAttendeeById(Attendee *head, string id) // Deklarasi fungsi yang mengembalikan pointer ke Attendee, dengan parameter head (awal list) dan id yang dicari.
// Mengembalikan Attendee* (pointer ke node jika ketemu, nullptr jika tidak).
{
    Attendee* current = head; // Buat pointer current dan inisialisasi dengan head untuk memulai traversal dari node pertama.
    while (current != nullptr) { // Mulai loop: selama current belum nullptr (masih ada node yang valid), lakukan traversal.
        if (current->data.id == id) { // Periksa apakah ID pada node saat ini sama dengan id yang dicari.
            return current; // Kembalikan pointer ke node tersebut.
        }
        current = current->next; // Jika tidak cocok, lanjut ke node berikutnya.
    }
    return nullptr; // Jika loop selesai tanpa menemukan, kembalikan nullptr.
}

// Fungsi untuk meng-update nama attendee berdasarkan ID.
void updateAttendee(Attendee *head, Attendee *attendee) // Parameter (attendee) di sini berisi data baru (khususnya ID dan name yang diinginkan).
{
    Attendee* foundAttendee = getAttendeeById(head, attendee->data.id); // Cari node yang memiliki ID sama dengan yang ingin di-update.

    if (foundAttendee == nullptr)
    { // Jika tidak ditemukan
        return; // langsung keluar (tidak ada yang di-update).
    }

    foundAttendee->data.name = attendee->data.name; // Update hanya field name dari node yang ditemukan dengan nilai name baru.
    // fungsi ini hanya meng-update nama, tidak meng-update ID.
}

Attendee *getAttendeeByUsername(Attendee *head, string username) // Deklarasi fungsi yang mengembalikan pointer ke Attendee, dengan parameter head (awal list) dan username (nama yang dicari).
// Fungsi untuk mencari attendee berdasarkan nama (di sini disebut "username").
{
    Attendee* current = head; // Buat pointer current dan inisialisasi dengan head untuk memulai traversal dari node pertama.
    while (current != nullptr) { // Mulai loop: selama current belum nullptr (masih ada node valid), lakukan traversal.
        if (current->data.name == username) { // Periksa apakah field name pada node saat ini sama dengan username yang dicari.
            return current; // Jika cocok, kembalikan pointer ke node tersebut.
        }
        current = current->next; // Jika tidak cocok, pindah current ke node berikutnya untuk melanjutkan pencarian.
    }
    return nullptr; // Jika loop selesai tanpa menemukan nama yang cocok, kembalikan nullptr.
}