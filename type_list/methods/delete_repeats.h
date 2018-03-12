#ifndef DELETE_REPEATS_H
#define DELETE_REPEATS_H

#include "type_list/base/base_all.h"
#include "delete_all_type.h"
#include "push_back_front.h"

template<class... T>
struct delete_repeats : cur_type_t<empty_type_list>{};

template<class Head, class... Args>
struct delete_repeats<type_list<Head, Args...>>
{
private:
    typedef typename delete_all_type<Head, type_list<Args...>>::type del_rep_tail;
public:
    typedef typename push_front<typename delete_repeats<del_rep_tail>::type, Head>::type type;
};

template<class... Args>
struct delete_repeats<type_list<Args...>>
 : cur_type_t<type_list<Args...>>{};
#endif // DELETE_REPEATS_H
