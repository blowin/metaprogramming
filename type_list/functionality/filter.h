#ifndef FILTER_H
#define FILTER_H

#include "type_list/base/base_all.h"
#include "type_list/methods/push_back_front.h"
#include "type_list/functionality/type_traits/condit.h"

#define FILTERS_HOLDER(name, cond, ...)                                             \
    template<class T>                                                               \
    struct name{                                                                    \
        static constexpr bool value = cond<T, tl::func_list<__VA_ARGS__>>::value;   \
    }

namespace helper {
    template<bool pred, template <class>class Func, class T, class... Args> struct filter;

    template<template <class> class Func, class T, class H, class... Args>
    struct filter<true, Func, T, type_list<H, Args...>>
        : cur_type_t<
            typename push_front<typename filter<Func<H>::value, Func, H, type_list<Args...>>::type, T>::type
            >{};

    template<template <class>class Func, class T, class H, class... Args>
    struct filter<false, Func, T, type_list<H, Args...>>
        : cur_type_t<typename filter<Func<H>::value, Func, H, type_list<Args...>>::type>{};

    template<bool pred, template <class> class Func, class T, class... Args>
    struct filter<pred, Func, T, type_list<Args...>>
        : cur_type_t<type_list<Args...>>{};
}

template<template <class> class Func, class... Args> struct filter;

template<template <class> class Func, class Head, class... Args>
struct filter<Func, type_list<Head, Args...>>
 : cur_type_t<typename helper::filter<Func<Head>::value, Func, Head, type_list<Args...>>::type>{};

template<template <class>class Func, class... Args>
struct filter<Func, type_list<Args...>>
 : cur_type_t<type_list<Args...>>{};

#endif // FILTER_H
