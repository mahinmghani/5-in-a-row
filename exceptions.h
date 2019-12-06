#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <iostream>
#include <exception>
#include <vector>
#include <cstdlib>

/* =================

CUSTOM EXCEPTION CLASS

================= */

class Invalid_Input: public std::exception{                                                         //NOTE: This is how to INHERIT. This class inherits everything public from exception. 
public: 
    virtual const char* what() const throw() {
        return "Exception caught. Invalid input entered.\n";                                        //NOTE: Here, we override the method which is returned in the exception class, which is the what() method in this case.
    }
};

void clear_buffer();
void exceptionHandling(int &variable);
void exceptionHandling (int &variable, std::string t);


#endif