// Baris ini adalah preprocessor directive yang disebut "include guard".
// Tujuannya untuk mencegah file header ini di-include lebih dari satu kali dalam satu unit kompilasi.
// Jika macro CLASSSESSION_HPP sudah didefinisikan, maka seluruh isi file sampai #endif akan diabaikan.
#ifndef CLASSSESSION_HPP
// Baris ini mendefinisikan macro CLASSSESSION_HPP.
// Setelah baris ini, compiler akan menganggap CLASSSESSION_HPP sudah ada, sehingga jika file ini di-include lagi, isi di dalamnya tidak akan diproses ulang.
#define CLASSSESSION_HPP

// Meng-include header standar C++ untuk kelas std::string.
// Kelas string akan digunakan untuk menyimpan data teks seperti id, name, description, dan coach.
#include <string>
// Meng-include file header kustom bernama Date.hpp.
// Diasumsikan file ini berisi definisi kelas atau struct Date yang digunakan untuk menyimpan jadwal sesi kelas.
#include "Date.hpp"
// Meng-include file header kustom bernama Attendee.hpp.
// Diasumsikan file ini berisi definisi struct atau kelas Attendee yang merepresentasikan peserta kelas.
#include "Attendee.hpp"

// Mengizinkan penggunaan nama-nama dari namespace std tanpa harus menuliskan std:: di depannya.
// Contoh: kita bisa langsung menulis string daripada std::string.
// Catatan: dalam proyek besar, penggunaan ini di header kadang dihindari untuk mencegah namespace pollution.
using namespace std;

// Mendefinisikan sebuah struct bernama ClassSession.
// Struct ini merepresentasikan satu sesi kelas (misalnya yoga, fitness, workshop, dll) dalam sistem manajemen kelas.
// ? Parent
// Ini adalah struktur data untuk menyimpan informasi satu sesi kelas olahraga atau fitness.
struct ClassSession {
     // ID unik buat sesi ini, misalnya "YOGA-001" atau "HIIT-2026-01", biar gampang dibedain sama yang lain.
    string id;
    // Nama kelas yang ditampilkan ke user, contohnya "Yoga Pemula Pagi" atau "HIIT Intensitas Tinggi".
    string name;
    // Penjelasan lengkap tentang kelas ini, apa yang bakal diajarkan, siapa yang cocok ikut, durasi, dll.
    string description;
     // Jadwal kapan kelas ini diadakan (tanggal dan mungkin jamnya). Tipe Date diambil dari file Date.hpp yang sudah di-include.
    Date schedule;
    // Batas maksimal berapa orang yang boleh daftar ke kelas ini, misalnya 20 orang supaya nggak terlalu penuh.
    int capacity;
    // Biaya yang harus dibayar peserta untuk ikut kelas ini, dalam satuan rupiah atau mata uang lain.
    int fee;
     // Nama pelatih atau instruktur yang bakal ngajar di sesi ini, biar peserta tahu siapa yang ngajarin.
    string coach;
     // Pointer yang nunjuk ke sesi kelas berikutnya. Ini buat nyambungin semua sesi jadi satu rantai (singly linked list).
    ClassSession* next;
};

// Mendefinisikan struct baru bernama ClassSessionAttendees.
// Struct ini dipakai buat nyimpan info peserta yang sudah daftar di satu sesi kelas tertentu.
struct ClassSessionAttendees {
    // Pointer yang nunjuk langsung ke objek ClassSession yang punya daftar peserta ini. Jadi kita tahu ini daftarnya milik kelas mana.
    ClassSession* class_session;
    // Hitungan jumlah peserta yang sudah terdaftar sekarang. Praktis banget buat cek sekilas: "Masih ada slot kosong nggak ya?"
    int attendee_count;
    // Pointer ke node ClassSessionAttendees berikutnya. Artinya semua daftar peserta per sesi disusun jadi satu rantai linked list.
    ClassSessionAttendees* next;
    // Pointer ke head (awal) dari linked list peserta yang ikut sesi ini. Tiap Attendee pasti punya pointer next biar bisa nyambung jadi list.
    Attendee* attendees;
};

#endif