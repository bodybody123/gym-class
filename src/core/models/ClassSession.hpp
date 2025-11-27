#ifndef CLASSSESSION_HPP
#define CLASSSESSION_HPP

#include <string>

using namespace std;

struct ClassSession {
    string id;
    string name;
    string schedule;
    int capacity;
    int fee;
    string coach;
    ClassSession* next;
};

#endif