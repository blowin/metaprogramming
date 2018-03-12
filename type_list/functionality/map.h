#ifndef MAP_H
#define MAP_H

template<template <class>
         class Func,
         class... Args>
struct map;

template<template <class>
         class Func,
         class Head,
         class... Args>
struct map<Func, type_list<Head, Args...>>
{
    typedef typename push_front<
        typename map<Func, type_list<Args...>>::type, typename Func<Head>::type
    >::type type;
};

template<template <class>
         class Func,
         class... Args>
struct map<Func, type_list<Args...>>
 : cur_type_t<type_list<Args...>>{};

#endif // MAP_H
