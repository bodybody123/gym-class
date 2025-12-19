#include <string>
#include "GenerateId.hpp"

using namespace std;

string generateId(const string& prefix)
{
    static int counter = 1;
    return prefix + to_string(counter++);
}
