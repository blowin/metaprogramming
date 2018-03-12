#ifndef POP_H
#define POP_H

#include "type_list/base/base_all.h"
#include "type_list/methods/push_back_front.h"

namespace {
    template<int curIdx, int idx, class... Args> struct pop_help;

    template<int curIdx, int idx, class H, class... Args>
    struct pop_help<curIdx, idx, type_list<H, Args...>>
    {
    private:
        typedef typename pop_help<curIdx + 1, idx, type_list<Args...>>::type pop_tail;
    public:
        typedef typename push_front<pop_tail, H>::type type;
    };

    template<int idx, class T, class... Args>
    struct pop_help<idx, idx, type_list<T, Args...>>
     : cur_type_t<type_list<Args...>>{};

    template<int curIdx, int idx, class... Args>
    struct pop_help<curIdx, idx, type_list<Args...>>
     : cur_type_t<type_list<Args...>>{};
}

template<int idx, class... T>
struct pop : cur_type_t<empty_type_list>{};

template<int idx, class... Args>
struct pop<idx, type_list<Args...>>
 : cur_type_t<typename pop_help<0, idx, type_list<Args...>>::type>
{};

#endif // POP_H
