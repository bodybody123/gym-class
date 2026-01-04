#ifndef ATTENNDEELIST_HPP // Jika macro ATTENNDEELIST_HPP belum didefinisikan, maka kompiler akan melanjutkan membaca kode di bawahnya.
#define ATTENNDEELIST_HPP //Baris ini mendefinisikan macro ATTENNDEELIST_HPP. Setelah baris ini dieksekusi, macro tersebut menjadi "terdefinisi", sehingga jika file ini di-include lagi di tempat lain, bagian #ifndef akan bernilai false dan isi file tidak akan diproses ulang (mencegah error duplicate definition).

#include "../models/Attendee.hpp" // Meng-include file header Attendee.hpp yang berada di folder models satu level di atas folder saat ini.

void insertAttendee(Attendee* &head, Attendee *attendee); // Deklarasi fungsi insertAttendee yang bertugas menyisipkan objek Attendee baru ke dalam linked list dengan menerima referensi ke pointer head agar head dapat langsung diperbarui jika list masih kosong atau node baru menjadi head, serta pointer ke objek attendee yang akan ditambahkan, sehingga perubahan struktur linked list tetap permanen di luar fungsi.

void deleteAttendee(Attendee* &head, const string& id); // Deklarasi fungsi deleteAttendee yang bertugas menghapus node attendee dari linked list berdasarkan ID yang diberikan, dengan menerima referensi ke pointer head agar head dapat diperbarui jika node yang dihapus adalah node pertama, serta const string& id sebagai referensi konstan untuk efisiensi dan keamanan, sehingga struktur linked list tetap terjaga setelah penghapusan.

void printAttendeeDetails(Attendee *attendee); // Deklarasi fungsi printAttendeeDetails yang bertugas mencetak semua detail informasi dari satu objek Attendee tertentu dengan menerima pointer ke node tersebut sebagai parameter, sehingga kita bisa langsung menampilkan data seperti nama, ID, username, atau field lainnya tanpa perlu mencari ulang di dalam linked list.

void getAllAttendees(Attendee* head); // Deklarasi fungsi getAllAttendees yang bertugas menampilkan informasi semua attendee yang ada dalam linked list dengan menerima pointer ke head sebagai parameter (bukan referensi karena fungsi ini hanya membaca dan melakukan traversal tanpa mengubah struktur atau posisi head), sehingga cocok untuk operasi read-only seperti menampilkan daftar lengkap attendee.

Attendee* getAttendeeById(Attendee* head, string id); // Deklarasi fungsi getAttendeeById yang bertugas mencari attendee dalam linked list mulai dari head berdasarkan ID yang diberikan, lalu mengembalikan pointer ke node tersebut jika ditemukan atau nullptr jika tidak ada, sehingga memudahkan akses langsung untuk operasi selanjutnya seperti update, delete, atau menampilkan detail.

void updateAttendee(Attendee* head, Attendee* attendee); // Deklarasi fungsi updateAttendee yang bertugas mencari node attendee dalam linked list mulai dari head berdasarkan ID pada objek attendee baru yang diberikan, kemudian memperbarui semua field pada node yang ditemukan dengan data terbaru dari objek tersebut, sehingga informasi attendee yang sudah ada dapat diubah tanpa mengubah struktur linked list secara keseluruhan.

Attendee* getAttendeeByUsername(Attendee *attendee, string username); // Deklarasi fungsi getAttendeeByUsername yang bertugas mencari attendee dalam linked list mulai dari node yang diberikan sebagai parameter pertama berdasarkan username yang dicari, kemudian mengembalikan pointer ke node tersebut jika username-nya cocok atau nullptr jika tidak ditemukan, sehingga memungkinkan akses langsung ke data attendee berdasarkan username uniknya.

#endif // menutup blok include guard (ifndef)