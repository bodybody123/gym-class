#include <iostream>
// Meng-include header standar C++ untuk input/output stream.
// Digunakan untuk mencetak informasi ke layar menggunakan objek cout dan endl.

#include "ClassSessionList.hpp"
// Meng-include header file ClassSessionList.hpp yang berisi deklarasi semua fungsi yang akan diimplementasikan di file ini.
// Header ini juga secara tidak langsung meng-include ClassSession.hpp karena sudah di-include di dalamnya.

#include "../models/Date.hpp"
// Meng-include file header Date.hpp yang berada di folder models satu level di atas.
// File ini diasumsikan berisi definisi struct Date serta deklarasi fungsi getDateTime() yang digunakan untuk mengubah objek Date menjadi string yang dapat dibaca manusia.

void insertClassSessionData(ClassSession* &head, ClassSession *classSession) {
    // Mulai definisi fungsi untuk menambahkan sesi kelas baru ke linked list.
    // Fungsi ini menerima referensi ke pointer head agar bisa mengubah head jika list masih kosong.
    // Parameter kedua adalah pointer ke objek ClassSession baru yang sudah dialokasikan memori.
    
    classSession->next = head;
    // Menjadikan node baru (classSession) menunjuk ke head saat ini.
    // Ini berarti node baru akan menjadi node paling depan.
    
    head = classSession;
    // Mengubah head linked list menjadi node baru.
    // Hasilnya: node baru ditambahkan di awal linked list (insert di depan/prepend).
}

void deleteClassData(ClassSession* head, const string& id) {
// Mulai definisi fungsi untuk menghapus sesi kelas berdasarkan ID.
// Parameter head tidak menggunakan referensi karena fungsi ini tidak mengubah head secara langsung (kecuali jika node pertama yang dihapus, tapi pointer head asli tidak diubah di sini).
// Catatan: sebenarnya lebih baik head diberi referensi (&) agar head bisa diperbarui jika node pertama dihapus.

    ClassSession* temp = head; // Pointer temp digunakan untuk traversal mencari node yang akan dihapus.
    ClassSession* prev = nullptr; // Pointer prev digunakan untuk menyimpan node sebelum temp, agar bisa mengubah pointer next-nya saat penghapusan.

    while (temp != nullptr && temp->id != id) {
        // Loop selama belum sampai akhir list dan ID belum cocok.
    // Mencari node dengan id yang sesuai.
        prev = temp; // Simpan node saat ini sebagai previous sebelum pindah ke node berikutnya.
        temp = temp->next; // Pindah ke node berikutnya.
    }

    if (temp == nullptr) return;
    // Jika temp menjadi nullptr, berarti ID tidak ditemukan di seluruh list.
    // Fungsi langsung keluar tanpa melakukan apa-apa.

    if (prev == nullptr) { // Jika prev masih nullptr, berarti node yang dihapus adalah node pertama (head).
        head = temp->next;
        // Head dipindahkan ke node berikutnya.
        // Catatan: perubahan ini tidak akan terlihat di luar fungsi karena head bukan referensi!
    } else { // Jika bukan node pertama.
        prev->next = temp->next; // Hubungkan node previous langsung ke node setelah temp, sehingga temp terlepas dari list.
    }

    delete temp; // Bebaskan memori yang digunakan oleh node yang dihapus (penting untuk mencegah memory leak).
}

void printClassSessionDetails(ClassSession *classSession)
// Mulai definisi fungsi untuk mencetak detail lengkap satu sesi kelas.
// Parameter adalah pointer ke objek ClassSession yang ingin ditampilkan.
{
    if (classSession != nullptr) { // Cek apakah pointer tidak nullptr (artinya data ada).
        cout << "Class ID: " << classSession->id << endl; // Cetak ID kelas.
        cout << "Class Name: " << classSession->name << endl; // Cetak deskripsi kelas.
        cout << "Description: " << classSession->description << endl; // Cetak deskripsi kelas.
        cout << "Schedule: " << getDateTime(classSession->schedule) << endl; // Cetak jadwal dalam format string yang mudah dibaca, menggunakan fungsi getDateTime() dari Date.hpp.
        cout << "Capacity: " << classSession->capacity << endl; // Cetak kapasitas maksimal peserta.
        cout << "Fee: Rp." << classSession->fee << endl; // Cetak biaya dengan format mata uang Rupiah.
        cout << "Coach: " << classSession->coach << endl; // Cetak nama coach/instruktur.
    } else { // Jika pointer nullptr (data tidak ditemukan).
        cout << "Class session not found." << endl; // Tampilkan pesan bahwa sesi kelas tidak ditemukan.
    }
}

void getAllClassSessions(ClassSession *head)
// Mulai definisi fungsi untuk menampilkan detail semua sesi kelas dalam linked list.
{   
    ClassSession *curr = head; // Pointer curr untuk traversal dari head hingga akhir list.
    while (curr != nullptr) { // Loop selama masih ada node.
        // Cetak semua detail dari sesi kelas saat ini (sama seperti printClassSessionDetails).
        cout << "Class ID: " << curr->id << endl;
        cout << "Class Name: " << curr->name << endl;
        cout << "Description: " << curr->description << endl;
        cout << "Schedule: " << getDateTime(curr->schedule) << endl;
        cout << "Capacity: " << curr->capacity << endl;
        cout << "Fee: Rp." << curr->fee << endl;
        cout << "Coach: " << curr->coach << endl;

        curr = curr->next; // Pindah ke node berikutnya.
    }

    cout << endl; // Tambahkan baris kosong di akhir untuk pemisah yang rapi.
}

ClassSession *getClassSessionById(ClassSession *head, string id)
// Mulai definisi fungsi yang mencari dan mengembalikan pointer ke sesi kelas berdasarkan ID.
// Mengembalikan nullptr jika tidak ditemukan.
{
    ClassSession* current = head; // Pointer current untuk traversal.
    while (current != nullptr) { // Loop selama belum akhir list.
        if (current->id == id) { // Jika ID cocok.
            return current; // Kembalikan pointer ke node tersebut.
        }
        current = current->next; // Lanjut ke node berikutnya.
    }
    return nullptr; // Jika loop selesai tanpa menemukan, kembalikan nullptr.
}

void showAllClassSessions(ClassSession* head) {
    // Mulai definisi fungsi tambahan untuk menampilkan daftar singkat semua sesi kelas (hanya ID dan nama).
    // Berguna untuk menu pilihan atau overview cepat.
    ClassSession* current = head; // Pointer current untuk traversal.
    while (current != nullptr) { // Loop selama ada node.
        std::cout << current->id << " - "
                  << current->name << "\n";
        // Cetak ID diikuti tanda "-" dan nama kelas, diakhiri newline.
        // Menggunakan std::cout untuk konsistensi namespace.
        current = current->next; // Pindah ke node berikutnya.
    }
}