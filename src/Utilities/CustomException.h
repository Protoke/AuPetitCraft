//
// Created by protoke on 17/06/17.
//

#ifndef AUPETITCRAFT_NOTIMPLEMENTEDEXCEPTION_H
#define AUPETITCRAFT_NOTIMPLEMENTEDEXCEPTION_H

#include <stdexcept>

class NotImplementedException : public std::logic_error
{
public:
    NotImplementedException() : std::logic_error("Function not yet implemented") { };
};

#endif //AUPETITCRAFT_NOTIMPLEMENTEDEXCEPTION_H
