#ifndef INDEX_OF_H
#define INDEX_OF_H

#include "type_list/base/base_all.h"

template<class T, class... Args>
struct index_of : negative_idx{};

template<class T, class Head, class... Args>
struct index_of<T, type_list<Head, Args...>>
{
private:
    static constexpr int cur_idx = index_of<T, type_list<Args...>>::value;
public:
    static constexpr int value = (cur_idx == -1) ? -1 : (1 + cur_idx);
};

template<class T, class... Args>
struct index_of<T, type_list<Args...>>
    : negative_idx{};

template<class T, class... Args>
struct index_of<T, type_list<T, Args...>>
    : positive_idx<0>{};
#endif // INDEX_OF_H
