#ifndef ATTENDEE_HPP // berarti "if not defined". Compiler akan memeriksa apakah macro / preprocessor ATTENDEE_HPP belum didefinisikan.
#define ATTENDEE_HPP // Jika macro ATTENDEE_HPP memang belum didefinisikan (dari baris sebelumnya), maka macro ini akan didefinisikan sekarang. Setelah baris ini, jika file header ini di-include lagi di tempat lain, kondisi #ifndef ATTENDEE_HPP akan bernilai false, sehingga seluruh isi header akan di-skip oleh preprocessor.

#include <string> // adalah standar C++ <string>. Diperlukan karena nanti kita akan menggunakan tipe std::string untuk menyimpan data ID dan nama.

using namespace std; // Baris ini membawa seluruh nama-nama yang ada di namespace std (seperti string, cout, dll.) ke dalam global namespace. Agar kita bisa menulis string langsung tanpa harus menulis std::string.

// ? Child
struct AttendeeData { // Mendeklarasikan sebuah struct bernama AttendeeData.
    string id; // variabel bertipe string bernama id. Digunakan untuk menyimpan identifier unik peserta (misalnya nomor registrasi, email, atau UUID).
    string name; // variabel bertipe string bernama name. Digunakan untuk menyimpan nama lengkap peserta.
};

// Struct ini merepresentasikan sebuah node dalam singly linked list.
struct Attendee { // Mendeklarasikan struct baru bernama Attendee.
    AttendeeData data; // sebuah objek bertipe AttendeeData bernama data. Node ini menyimpan data peserta (id dan name) di dalamnya.
    Attendee* next; // sebuah pointer bertipe Attendee* bernama next. Pointer ini menunjuk ke node Attendee berikutnya dalam linked list. Jika ini adalah node terakhir, biasanya next akan bernilai nullptr (atau NULL).
};

#endif // menutup blok include guard yang berarti "end of if" dari #ifndef di awal baris