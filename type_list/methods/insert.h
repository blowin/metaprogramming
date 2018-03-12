#ifndef INSERT_H
#define INSERT_H

#include "type_list/base/base_all.h"
#include "type_list/methods/push_back_front.h"

namespace {
    template<int curIdx, int idx, class T, class... Args> struct insert_help;

    template<int idx, class T, class H, class... Args>
    struct insert_help<idx, idx, T, type_list<H, Args...>>
     : cur_type_t<type_list<T, H, Args...>>{};

    template<int curIdx, int idx, class T, class... Args>
    struct insert_help<curIdx, idx, T, type_list<Args...>>
     : cur_type_t<type_list<Args...>>{};

    template<int curIdx, int idx, class T, class H, class... Args>
    struct insert_help<curIdx, idx, T, type_list<H, Args...>>
    {
    private:
        typedef typename insert_help<curIdx + 1, idx, T, type_list<Args...>>::type insert_tail;
    public:
        typedef typename push_front<insert_tail, H>::type type;
    };

    template<bool is_end, int idx, class T, class... Args>
    struct way_insert : cur_type_t<type_list<empty_type_list>>{};

    template<int idx, class T, class... Args>
    struct way_insert<false, idx, T, type_list<Args...>>
        : cur_type_t<typename insert_help<0, idx, T, type_list<Args...>>::type>{};

    template<int idx, class T, class... Args>
    struct way_insert<true, idx, T, type_list<Args...>>
        : cur_type_t<typename push_back<type_list<Args...>, T>::type>{};
}

template<int idx, class... T>
struct insert : cur_type_t<empty_type_list>{};

template<int idx, class T, class... Args>
struct insert<idx, T, type_list<Args...>>
 : cur_type_t<typename way_insert<idx == length<type_list<Args...>>::value,
        idx, T, type_list<Args...>>::type>
{};

#endif // INSERT_H
