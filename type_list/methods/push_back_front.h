#ifndef PUSH_BACK_FRONT_H
#define PUSH_BACK_FRONT_H

#include "type_list/base/base_all.h"

template<class T, class... Args>
struct push_back : cur_type_t<type_list<Args..., T>>{};

template<class... Args, class T>
struct push_back<type_list<Args...>, T> : cur_type_t<type_list<Args..., T>>{};

template<class T, class... Args>
struct push_front : cur_type_t<type_list<T, Args...>>{};

template<class... Args, class T>
struct push_front<type_list<Args...>, T> : cur_type_t<type_list<T, Args...>>{};

#endif // PUSH_BACK_FRONT_H
