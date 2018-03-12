#ifndef ALL_TYPE_TRAITS_H
#define ALL_TYPE_TRAITS_H

#include "type_list/base/support_types.h"

template<class T> struct del_ref                    : cur_type_t<T>{};
template<class T> struct del_ref<T&>                : cur_type_t<T>{};

template<class T> struct del_all_ref                : cur_type_t<T>{};
template<class T> struct del_all_ref<T&&>           : cur_type_t<T>{};

template<class T> struct del_volatile               : cur_type_t<T>{};
template<class T> struct del_volatile<volatile T>   : cur_type_t<T>{};

template<class T> struct del_pointer                : cur_type_t<T>{};
template<class T> struct del_pointer<T*>            : cur_type_t<T>{};

template<class T> struct del_all_pointers           : cur_type_t<T>{};
template<class T> struct del_all_pointers<T**>      : cur_type_t<T>{};

template<class T> struct del_const                  : cur_type_t<T>{};
template<class T> struct del_const<const T>         : cur_type_t<T>{};

template<class T> struct add_volatile               : cur_type_t<volatile T>{};

template<class T> struct add_ref                    : cur_type_t<T&>{};

template<class T> struct to_movable                 : cur_type_t<T&&> {};

template<class T> struct add_pointer                : cur_type_t<T*>{};

template<class T> struct add_const                  : cur_type_t<const T>{};

#endif // ALL_TYPE_TRAITS_H
