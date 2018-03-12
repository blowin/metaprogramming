#ifndef AT_H
#define AT_H

#include "type_list/base/base_all.h"

template<int idx, class... Args>
struct at : cur_type_t<empty_type_list>{};

template<int idx, class Head, class... Args>
struct at<idx, type_list<Head, Args...>>
{
    typedef typename at<idx - 1, type_list<Args...>>::type type;
};

template<class T, class... Args>
struct at<0, type_list<T, Args...>> : cur_type_t<T>{};

#endif // AT_H
