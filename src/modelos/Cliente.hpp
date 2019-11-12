#ifndef CLIENTE_H
#define CLIENTE_H

#include "Editable.hpp"
#include <string>
using namespace std;

class Cliente : public Editable {
    public:
        Cliente();
    private:
        char id = 'C';
};


#endif