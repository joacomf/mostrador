#ifndef Mesa_H
#define Mesa_H

#include "Editable.hpp"
#include <string>
using namespace std;

class Mesa : public Editable {
    public:
        Mesa();
    private:
        char id = 'M';
};


#endif