#ifndef DATA_TYPE_LIST_H
#define DATA_TYPE_LIST_H

#include "support_types.h"

template<class... Args>
struct type_list{};

template<class... Args>
struct length : positive_idx<0>{};

template<class... Args>
struct length<type_list<Args...>> : positive_idx<sizeof...(Args)>{};

#endif // DATA_TYPE_LIST_H
