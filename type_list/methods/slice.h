#ifndef SLICE_H
#define SLICE_H

#include "type_list/base/data_type_list.h"
#include "type_list/base/support_types.h"

#include "type_list/methods/at.h"
#include "type_list/methods/push_back_front.h"

template<unsigned int start, unsigned int finish, class... T> struct slice : cur_type_t<empty_type_list>{};

template<unsigned int start, unsigned int finish, class H, class... T>
struct slice<start, finish, type_list<H, T...>>{
    static_assert(start < finish, "Invalid slice index");
    typedef typename push_front<typename slice<start + 1, finish, type_list<T...>>::type, H>::type type;
};

template<unsigned int finish, class H, class... T>
struct slice<finish, finish, type_list<H, T...>> : cur_type_t<type_list<H>>{};

template<unsigned int start, unsigned int finish, class... T>
struct slice<start, finish, type_list<T...>> : cur_type_t<type_list<T...>>{};

#endif // SLICE_H
