#ifndef REPLACE_BY_INDEX_H
#define REPLACE_BY_INDEX_H

#include "type_list/base/data_type_list.h"
#include "type_list/base/support_types.h"

#include "type_list/methods/pop.h"
#include "type_list/methods/insert.h"

template<unsigned int idx, class T, class... ListData> struct replace_by_index : cur_type_t<type_list<empty_type_list>>{};

template<unsigned int idx, class T, class... ListData>
struct replace_by_index<idx, T, type_list<ListData...>>{
    typedef typename insert<idx, T, typename pop<idx, type_list<ListData...>>::type>::type type;
};

#endif // REPLACE_BY_INDEX_H
