#ifndef SORT_H
#define SORT_H

#include "type_list/base/data_type_list.h"
#include "type_list/base/support_types.h"

namespace {
    template<bool cond, template<class, class> class Comparator, class Pair, class TL1, class... TL2>
    struct sort_help : cur_type_t<empty_type_list>{};

    template<template<class, class> class Comparator,
             class V1, class V2, class... TL1, class NewHead, class... TL2>
    struct sort_help<true, Comparator, type_list<V1, V2>, type_list<TL1...>, type_list<NewHead, TL2...>>{
    private:
        static constexpr bool comp_res = Comparator<V1, NewHead>::value;
    public:
        typedef typename sort_help<comp_res, Comparator, type_list<V1, NewHead>,
                type_list<TL1..., V2>, type_list<TL2...>>::type type;
    };

    template<template<class, class> class Comparator,
             class V1, class V2, class... TL1, class NewHead, class... TL2>
    struct sort_help<false, Comparator, type_list<V1, V2>, type_list<TL1...>, type_list<NewHead, TL2...>>{
    private:
        static constexpr bool comp_res = Comparator<V2, NewHead>::value;
    public:
        typedef typename sort_help<comp_res, Comparator, type_list<V2, NewHead>,
                type_list<TL1..., V1>, type_list<TL2...>>::type type;
    };

    template<template<class, class> class Comparator,
             class V1, class V2, class... TL1, class... TL2>
    struct sort_help<true, Comparator, type_list<V1, V2>, type_list<TL1...>, type_list<TL2...>>
        : cur_type_t<type_list<TL1..., V2, V1, TL2...>>{};

    template<template<class, class> class Comparator,
             class V1, class V2, class... TL1, class... TL2>
    struct sort_help<false, Comparator, type_list<V1, V2>, type_list<TL1...>, type_list<TL2...>>
        : cur_type_t<type_list<TL1..., V1, V2, TL2...>>{};


    template<int sz, template<class, class> class Comparator, class...T>
    struct repeats;

    template<int sz, template<class, class> class Comparator, class H1, class H2, class...T>
    struct repeats<sz, Comparator, type_list<H1, H2, T...>>{
    private:
        typedef typename sort_help<Comparator<H1, H2>::value, Comparator, type_list<H1, H2>,
        type_list<>, type_list<T...>>::type sort_tl;
    public:
        typedef typename repeats<sz - 1, Comparator, sort_tl>::type type;
    };

    template<template<class, class> class Comparator, class H1, class H2, class...T>
    struct repeats<0, Comparator, type_list<H1, H2, T...>>
        : cur_type_t<typename sort_help<Comparator<H1, H2>::value, Comparator,
            type_list<H1, H2>, type_list<>, type_list<T...>>::type>{};
}

template<template<class, class> class Comparator, class... T> struct sort
        : type_list<empty_type_list>{};

template<template<class, class> class Comparator, class H1, class H2, class...T>
struct sort<Comparator, type_list<H1, H2, T...>>{
    typedef typename repeats<length<type_list<H1, H2, T...>>::value, Comparator, type_list<H1, H2, T...>>::type type;
};

template<template<class, class> class Comparator, class...T>
struct sort<Comparator, type_list<T...>>
    : cur_type_t<type_list<T...>>{};

#endif // SORT_H
