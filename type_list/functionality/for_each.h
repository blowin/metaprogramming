#ifndef FOR_EACH_H
#define FOR_EACH_H

#include "type_list/base/base_all.h"
#include "type_list/methods/push_back_front.h"

template<template <class>
         class Func,
         class... Args>
struct for_each;

template<template <class>
         class Func,
         class Head,
         class... Args>
struct for_each<Func, type_list<Head, Args...>>
{
    for_each(){
        (*this)();
    }

    void operator ()() const{
        Func<Head>();

        for_each<Func, type_list<Args...>>();
    }
};

template<template <class>
         class Func,
         class... Args>
struct for_each<Func, type_list<Args...>>
{
    void operator ()() const{}
};

#endif // FOR_EACH_H
