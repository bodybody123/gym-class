#ifndef CPAGE_HPP
#define CPAGE_HPP

#include "../models/ClassSession.hpp"
#include "../models/Registration.hpp"
#include "../models/Attendee.hpp"

enum PAGE
{
    INITIAL,
    REGISTER,
    LOGIN,
    DASHBOARD,
    DETAIL
};

void CViewRegisterPage(Attendee *&head);
void CViewLoginPage(Attendee *head, Attendee *&currentUser);
void CDashboardPage(ClassSession *classSessionHead, Registration *registrationHead, Attendee *attendeeHead, Attendee *currentUser);
void CClassDetailPage(ClassSession *classSessionHead, Registration *registrationHead);
void CGetAllClassPage(ClassSession *classSession);
void CRegisterClassSessionPage(ClassSession *classSessionHead, Registration* &registrationHead, Attendee *currentUser);
void CDeregisterClassSessionPage(ClassSession *classSessionHead, Registration *registrationHead, Attendee *currentUser);

#endif