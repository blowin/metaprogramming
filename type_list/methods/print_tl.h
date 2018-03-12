#ifndef PRINT_H
#define PRINT_H

#include "type_list/base/base_all.h"

#include <iostream>
#include <typeinfo>

namespace tl {
    template<class T>
    struct print_func
    {
        print_func(){
            (*this)();
        }

        void operator()() const{
            std::cout << typeid(T).name() << " ";
        }
    };

    template<class... Args>
    void print_tl(type_list<Args...>){}

    template<class Header, class... Args>
    void print_tl(type_list<Header, Args...>){
        print_func<Header>();
        print_tl(type_list<Args...>());
    }
}

#endif // PRINT_H
