#include <string>
#include "../service/ClassSessionService.hpp"

void CClassDetailPage(ClassSession *classSessionHead, Registration *registrationHead, string classId) {
    getClassSessionDetailById(classSessionHead, registrationHead, classId);
}