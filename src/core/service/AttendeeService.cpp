#include <iostream>
#include "../models/Attendee.hpp"
#include "../models/Registration.hpp"
#include "../Lists/AttendeeList.hpp"
#include "AttendeeService.hpp"

using namespace std;

/**
 * Fungsi: registerAttendee
 * ------------------------
 * Mendaftarkan peserta (attendee) baru ke dalam sistem.
 * * @param attendeeHead: Pointer reference ke head dari linked list Attendee.
 * @param newAttendee:  Pointer ke node attendee baru yang ingin dimasukkan.
 */
void registerAttendee(
    Attendee *&attendeeHead, 
    Attendee *newAttendee
) {
    // 1. Cek apakah username sudah ada di dalam list (validasi unik)
    Attendee* attendee = getAttendeeByUsername(attendeeHead, newAttendee->data.name);

    // 2. Jika username ditemukan (tidak nullptr), tolak pendaftaran
    if (attendee != nullptr) {
        cout << "Username sudah diambil" << endl;
        return; 
    }

    // 3. Jika username belum ada, masukkan data ke linked list
    insertAttendee(attendeeHead, newAttendee);
}

/**
 * Fungsi: getAllAttendeesAndClassSessions
 * ---------------------------------------
 * Menampilkan semua data peserta beserta sesi kelas yang mereka ikuti.
 * * @param attendeeHead:     Pointer ke head list Attendee.
 * @param registrationHead: Pointer ke head list Registration (tabel penghubung).
 */
void getAllAttendeesAndClassSessions(
    Attendee *attendeeHead, 
    Registration *registrationHead
) {
    Attendee *currentAttendee = attendeeHead;

    // Cek jika list attendee kosong
    if (attendeeHead == nullptr) {
        cout << "No attendees available." << endl;
        return;
    }

    // Loop melalui setiap Attendee (Outer Loop)
    while (currentAttendee != nullptr)
    {   
        // Tampilkan data dasar Attendee
        cout << "Attendee: " << currentAttendee->data.name << " (ID: " << currentAttendee->data.id << ")" << endl;

        Registration *currentRegistration = registrationHead;

        cout << "Registered Class Sessions:" << endl;
        
        // Loop melalui list Registration untuk mencari kelas milik attendee saat ini (Inner Loop)
        while (currentRegistration != nullptr)
        {
            // Mencocokkan pointer attendee di registrasi dengan attendee yang sedang diproses
            if (currentRegistration->attendee == currentAttendee)
            {
                // Tampilkan detail sesi kelas (Nama, Jadwal, Pelatih, Tgl Registrasi)
                cout << "- " << currentRegistration->class_session->name << endl 
                     << "Schedule: " << getDate(currentRegistration->class_session->schedule) << endl
                     << "Coach: " << currentRegistration->class_session->coach << endl
                     << " (Registration date: "
                     << getDate(currentRegistration->registration_date) << ")" << endl;
            }
            currentRegistration = currentRegistration->next;
        }

        // Pindah ke attendee berikutnya
        currentAttendee = currentAttendee->next;
    }
}

/**
 * Fungsi: countAttendeesClassSessions
 * -----------------------------------
 * Menghitung dan menampilkan jumlah sesi kelas yang diikuti oleh setiap peserta.
 * * @param attendeeHead:     Pointer ke head list Attendee.
 * @param registrationHead: Pointer ke head list Registration.
 */
void countAttendeesClassSessions(
    Attendee *attendeeHead, 
    Registration *registrationHead
) {
    Attendee *currentAttendee = attendeeHead;

    if (attendeeHead == nullptr) {
        cout << "No attendees available." << endl;
        return;
    }

    // Loop setiap Attendee
    while (currentAttendee != nullptr)
    {   
        int count = 0; // Inisialisasi penghitung untuk attendee saat ini
        Registration *currentRegistration = registrationHead;

        // Loop list Registration
        while (currentRegistration != nullptr)
        {
            // Jika registrasi ini milik attendee saat ini, tambahkan hitungan
            if (currentRegistration->attendee == currentAttendee)
            {
                count++;
            }
            currentRegistration = currentRegistration->next;
        }

        // Tampilkan hasil hitungan per orang
        cout << "Attendee: " << currentAttendee->data.name << " is registered in " << count << " class session(s)." << endl;

        currentAttendee = currentAttendee->next;
    }
}

/**
 * Fungsi: countAttendeesWithNoClassSessions
 * -----------------------------------------
 * Menghitung jumlah total peserta yang belum mendaftar di kelas manapun.
 * * @param attendeeHead:     Pointer ke head list Attendee.
 * @param registrationHead: Pointer ke head list Registration.
 * @return int:             Jumlah peserta tanpa kelas.
 */
int countAttendeesWithNoClassSessions(Attendee *attendeeHead, Registration *registrationHead)
{
    Attendee* currentAttendee = attendeeHead;
    int noClassSessionCount = 0; // Variabel penampung total peserta pasif

    // Loop setiap Attendee
    while (currentAttendee != nullptr)
    {
        bool hasClassSessions = false; // Flag penanda status keaktifan
        Registration* currentRegistration = registrationHead;

        // Cek list registrasi
        while (currentRegistration != nullptr)
        {
            // Jika ditemukan satu saja data registrasi milik attendee ini
            if (currentRegistration->attendee == currentAttendee)
            {
                hasClassSessions = true;
                break; // Hentikan loop inner agar lebih efisien (sudah ketemu 1)
            }
            currentRegistration = currentRegistration->next;
        }

        // Jika flag masih false, berarti tidak ikut kelas manapun
        if (!hasClassSessions)
        {
            noClassSessionCount++;
        }

        currentAttendee = currentAttendee->next;
    }

    return noClassSessionCount;
}