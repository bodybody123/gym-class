#include "CPage.hpp"
#include "../service/ClassSessionService.hpp"

using namespace std;

void CDashboardPage(
    ClassSession *classSessionHead, 
    Registration *registrationHead, 
    Attendee *attendeeHead, 
    Attendee *currentUser) {
    getAllAttendingClass(registrationHead, currentUser);
}