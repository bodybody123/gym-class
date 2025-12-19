#include <iostream>
#include <string>
#include "../service/ClassSessionService.hpp"

void CClassDetailPage(ClassSession *classSessionHead, Registration *registrationHead) {
        string classId;

        cout << "Pilih ID kelas: ";
        cin >> classId;

    getClassSessionDetailById(classSessionHead, registrationHead, classId);
}