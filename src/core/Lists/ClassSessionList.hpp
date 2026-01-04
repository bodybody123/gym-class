#ifndef CLASSSESSIONLIST_HPP
// Cek apakah macro CLASSSESSIONLIST_HPP belum pernah didefinisikan sebelumnya.
// Ini bagian dari "include guard" biar header file nggak ke-include dua kali.

#define CLASSSESSIONLIST_HPP
// Kalau belum ada, langsung definisikan macro ini sekarang.

#include "../models/ClassSession.hpp" // untuk mengambil isi yang ada di dalem file ClassSession.hpp

void insertClassSessionData(ClassSession* &head, ClassSession *classSession);
// Fungsi buat nambahin data sesi kelas baru ke linked list: head bisa berubah langsung lewat referensi (&head) kalau list masih kosong, sementara classSession adalah pointer ke objek baru yang mau disisipkan (biasanya di awal atau akhir list tergantung implementasi di .cpp).

void deleteClassData(ClassSession* head, const string& id);
// Fungsi ini berguna untuk menghapus satu sesi kelas dari linked list berdasarkan ID yang kita berikan; dia akan mencari node dengan ID tersebut, melepaskannya dari linked list, lalu membebaskan memori yang dipakainya supaya tidak ada memory leak.

void printClassSessionDetails(ClassSession *classSession);
// Fungsi ini berfungsi untuk menampilkan detail lengkap satu sesi kelas ke layar, mulai dari nama kelas, deskripsi, jadwal, kapasitas, biaya, hingga nama coach-nya, sehingga pengguna atau admin bisa melihat informasi sesi tersebut secara jelas dan rapi.

void getAllClassSessions(ClassSession* head);
// Fungsi ini digunakan untuk menampilkan semua sesi kelas yang tersedia di sistem; dia akan mulai dari head linked list, lalu berjalan satu per satu ke setiap node sambil mencetak detail masing-masing sesi kelas, sehingga pengguna bisa melihat daftar lengkap kelas yang ada secara rapi.

ClassSession* getClassSessionById(ClassSession* head, string id);
// Fungsi ini bertugas mencari sesi kelas di dalam linked list berdasarkan ID yang diberikan; dia akan berjalan dari head sambil membandingkan ID setiap node, lalu mengembalikan pointer ke node yang cocok jika ketemu, atau nullptr jika sesi dengan ID tersebut tidak ada di sistem.

#endif