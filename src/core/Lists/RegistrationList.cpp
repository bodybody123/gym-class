#include "RegistrationList.hpp"
// Meng-include header RegistrationList.hpp yang berisi deklarasi fungsi-fungsi ini serta definisi struct Registration. Header ini diperlukan agar compiler mengetahui tipe Registration dan prototipe fungsi.

#include <string>
// Meng-include header standar untuk menggunakan tipe std::string, yang dipakai pada parameter fungsi deleteRegistration untuk ID pencarian.

#include <iostream>
// Meng-include header standar untuk input/output, khususnya digunakan untuk std::cout pada fungsi getAllRegistration saat menampilkan data.

#include "ClassSessionList.hpp"
// Meng-include header yang kemungkinan besar berisi deklarasi fungsi printClassSessionDetails() yang digunakan untuk mencetak detail sesi kelas.

#include "AttendeeList.hpp"
// Meng-include header yang kemungkinan besar berisi deklarasi fungsi printAttendeeDetails() yang digunakan untuk mencetak detail peserta.

#include "../models/Date.hpp"
// Meng-include header Date.hpp yang mendefinisikan tipe Date serta kemungkinan besar berisi deklarasi fungsi getDate() yang mengubah objek Date menjadi string untuk ditampilkan.

void insertRegistration(Registration* &head, Registration *registration)
// Fungsi ini bertugas menambahkan data pendaftaran baru ke dalam linked list dengan cara yang paling cepat, yaitu langsung di posisi awal (di depan head).
{
    registration->next = head;
    // Pertama, kita sambungkan pointer next dari node baru (registration) ke head yang lama, sehingga node baru ini siap menjadi yang paling depan.

    head = registration;
    // Kemudian, kita ubah head linked list agar langsung menunjuk ke node baru ini. Dengan cara ini, operasi insert selesai hanya dalam waktu konstan O(1), sangat efisien meskipun list sudah panjang sekalipun.
}

void deleteRegistration(Registration* &head, const string& id)
// Fungsi ini bertugas menghapus satu data pendaftaran dari linked list berdasarkan ID attendee yang diberikan.

{
    Registration *temp = head;
    // Kita pakai pointer temp untuk berjalan mencari node yang akan dihapus, mulai dari head.

    Registration *prev = nullptr;
    // Pointer prev untuk mengingat node sebelum temp, supaya nanti bisa menyambung ulang list setelah node dihapus.

    while (temp != nullptr && temp->attendee->data.id != id)
    // Selama belum sampai akhir list dan belum menemukan ID yang cocok, kita terus maju.
    {
        prev = temp;
        // Simpan node saat ini sebagai previous.

        temp = temp->next;
        // Pindah ke node berikutnya.
    }

    if (temp == nullptr)
        return;
    // Kalau sampai akhir list tapi tidak ketemu ID-nya, langsung keluar fungsi tanpa hapus apa-apa.

    if (prev == nullptr)
    // Kalau prev masih nullptr, berarti node yang dihapus adalah head (node pertama).
    {
        head = temp->next;
        // Kita ubah head langsung menunjuk ke node kedua, sehingga node pertama terlewati.
    }
    else
    // Kalau bukan head, node ada di tengah atau akhir list.
    {
        prev->next = temp->next;
        // Sambungkan node sebelumnya langsung ke node setelah temp, sehingga temp terlepas dari rantai.
    }

    delete temp;
    // Terakhir, kita bebaskan memori node yang sudah tidak terpakai lagi agar tidak terjadi memory leak.
}
// Dengan cara ini, penghapusan node pada singly linked list tetap aman dan efisien, baik node di awal, tengah, maupun akhir.

void getAllRegistration(Registration *head)
// Fungsi ini bertugas menampilkan semua data pendaftaran yang ada di sistem secara lengkap dan berurutan.

{
    Registration *curr = head;
    // Kita pakai pointer curr untuk berjalan dari node pertama sampai terakhir di linked list.

    while (curr != nullptr)
    // Selama curr belum nullptr (artinya masih ada node yang belum ditampilkan), kita terus loop.
    {
        printClassSessionDetails(curr->class_session);
        // Pertama, tampilkan detail lengkap sesi kelas yang didaftari, supaya jelas kelas apa yang dipesan.

        cout << getDate(curr->registration_date) << endl;
        // Kemudian cetak tanggal pendaftaran dalam format yang mudah dibaca, diakhiri enter.

        printAttendeeDetails(curr->attendee);
        // Lalu tampilkan detail peserta yang mendaftar, seperti nama, ID, dan informasi lainnya.

        curr = curr->next;
        // Setelah satu pendaftaran selesai ditampilkan, maju ke node pendaftaran berikutnya.
    }

    cout << endl;
    // Setelah semua pendaftaran ditampilkan, kita cetak satu baris kosong agar output terlihat lebih rapi dan terpisah dari tampilan menu atau output selanjutnya.
}
// Dengan fungsi ini, admin bisa dengan mudah melihat seluruh riwayat atau daftar pendaftaran yang ada di sistem tanpa mengubah data apa pun.