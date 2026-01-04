/**
 * Preprocessor directive ini memeriksa apakah macro REGISTRATION_HPP 
 * sudah didefinisikan. Jika belum, maka isi file akan diproses; 
 * jika sudah, maka diabaikan untuk mencegah double inclusion dan error kompilasi.
 */
#ifndef REGISTRATION_HPP
/**
 * Mendefinisikan macro REGISTRATION_HPP agar pada include berikutnya, kondisi 
 * #ifndef akan gagal dan isi file tidak diproses ulang. 
 * Ini adalah teknik include guard standar pada header file C++.
 */
#define REGISTRATION_HPP
/**
 * Meng-include header standar C++ untuk kelas std::string. 
 * Meskipun tidak digunakan langsung di struct ini, 
 * mungkin diperlukan oleh header lain atau untuk ekspansi kode di masa depan.
 */
#include <string>
/**
 * Meng-include header kustom Date.hpp yang mendefinisikan kelas/struct Date, 
 * yang akan digunakan sebagai tipe untuk menyimpan tanggal pendaftaran. 
 */
#include "Date.hpp"
/**
 * Meng-include header kustom Attendee.hpp yang mendefinisikan kelas/struct Attendee, 
 * yang merepresentasikan data peserta/klien dalam sistem pendaftaran.
 */
#include "Attendee.hpp"
/**
 * Meng-include header kustom ClassSession.hpp yang mendefinisikan kelas/struct 
 * ClassSession, yang merepresentasikan sesi atau jadwal kelas yang dapat didaftarkan.
 */
#include "ClassSession.hpp"
/**
 * Membawa seluruh isi namespace std ke scope global. Ini mempermudah penggunaan 
 * tipe seperti string tanpa prefix std::, tetapi sebaiknya dihindari di header 
 * file karena dapat menyebabkan konflik nama di file lain yang meng-include header ini.
 */
using namespace std;
/** 
 * Catatan informal (mungkin reminder developer) yang menandakan bahwa struct 
 * ini merepresentasikan sebuah "relasi" (relationship) dalam desain sistem, 
 * kemungkinan relasi many-to-many antara Attendee dan ClassSession melalui 
 * tabel/entitas pendaftaran.
 */ 
// ? Relation
/**
 * Deklarasi struct Registration yang berfungsi sebagai node untuk menyimpan 
 * data satu pendaftaran, sekaligus menghubungkan attendee dengan class session.
 */
struct Registration {
    // Anggota data bertipe Date yang menyimpan tanggal ketika pendaftaran dilakukan. Ini berguna untuk tracking waktu pendaftaran.
    Date registration_date;
    // Pointer ke objek Registration lain dengan tipe yang sama. Digunakan untuk membentuk singly linked list, sehingga daftar pendaftaran dapat disusun secara dinamis tanpa array tetap.
    Registration* next;
    // Pointer ke objek Attendee yang menunjukkan peserta yang melakukan pendaftaran ini. Memungkinkan akses ke detail attendee tanpa duplikasi data.
    Attendee* attendee;
    // Pointer ke objek ClassSession yang menunjukkan sesi kelas yang didaftarkan. Ini menghubungkan pendaftaran dengan jadwal kelas tertentu.
    ClassSession* class_session;
};

// Akhiri blok include guard. Jika macro REGISTRATION_HPP sudah didefinisikan, kompilator akan melewatkan seluruh isi di atas.
#endif