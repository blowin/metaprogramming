#ifndef SWAP_H
#define SWAP_H

#include "type_list/base/data_type_list.h"

#include "type_list/methods/at.h"
#include "type_list/methods/replace_by_index.h"

template<unsigned int f, unsigned int s, class...T>
struct swap;

template<unsigned int f, unsigned int s, class...T>
struct swap<f, s, type_list<T...>>{
private:
    typedef typename at<f, type_list<T...>>::type first;
    typedef typename at<s, type_list<T...>>::type second;
public:
    typedef typename replace_by_index<s, first,
                typename replace_by_index<f, second, type_list<T...>>::type
            >::type type;
};

#endif // SWAP_H
