#ifndef REGISTRATIONLIST_HPP // cek apakah REGISTRATIONLIST_HPP sudah di definisikan atau belum

#define REGISTRATIONLIST_HPP // Kalau belum ada, langsung definisikan macro ini sekarang.

#include "../models/Registration.hpp" // agar bisa mengambil isi dari file Registration.hpp

void insertRegistration(Registration* &head, Registration *registration);
// Fungsi ini digunakan untuk menambahkan data pendaftaran baru ke dalam linked list registrasi; karena parameter head menggunakan referensi (&head), fungsi ini bisa langsung mengubah head jika list masih kosong, sementara registration adalah pointer ke objek pendaftaran baru yang sudah dibuat dan siap disisipkan ke dalam list.

void deleteRegistration(Registration* &head, const string& id);
// Fungsi ini berfungsi untuk menghapus satu data pendaftaran dari linked list berdasarkan ID yang diberikan; dia akan mencari node dengan ID tersebut, melepaskannya dari rantai list, membebaskan memorinya, dan karena head menggunakan referensi (&head), fungsi ini juga bisa langsung mengubah head jika node yang dihapus adalah elemen pertama sehingga list menjadi lebih pendek atau bahkan kosong.

void getAllRegistration(Registration *head);
// Fungsi ini digunakan untuk menampilkan semua data pendaftaran yang ada di sistem; dia akan mulai dari head linked list, lalu berjalan satu per satu melalui setiap node sambil mencetak detail pendaftaran tersebut, sehingga admin atau pengguna bisa melihat daftar lengkap semua registrasi secara jelas dan terorganisir.

#endif