#ifndef CONCAT_H
#define CONCAT_H

#include "type_list/base/base_all.h"

template<class... Args>
struct concat : cur_type_t<empty_type_list>{};

template<class... T1, class... T2>
struct concat<type_list<T1...>, type_list<T2...>> : cur_type_t<type_list<T1..., T2...>>{};

#endif // CONCAT_H
