#ifndef CONTAIN_H
#define CONTAIN_H

#include "index_of.h"

template<class T, class... Args>
struct contain : false_value{};

template<class T, class... Args>
struct contain<T, type_list<Args...>>
        : support_types::bool_value_t
    <
        index_of<T, type_list<Args...>>::value != -1
    >{};

#endif // CONTAIN_H
