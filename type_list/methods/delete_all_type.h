#ifndef DELETE_ALL_TYPE_H
#define DELETE_ALL_TYPE_H

#include "type_list/base/base_all.h"
#include "push_back_front.h"

template<class... T>
struct delete_all_type : cur_type_t<empty_type_list>{};

template<class T, class Head, class... Args>
struct delete_all_type<T, type_list<Head, Args...>>
 : cur_type_t<typename push_front<typename delete_all_type<T, type_list<Args...>>::type, Head>::type>
{};

template<class T, class... Args>
struct delete_all_type<T, type_list<T, Args...>>
 : cur_type_t<typename delete_all_type<T, type_list<Args...>>::type>
{};

template<class T, class... Args>
struct delete_all_type<T, type_list<Args...>>
 : cur_type_t<type_list<Args...>>
{};


#endif // DELETE_ALL_TYPE_H
