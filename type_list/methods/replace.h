#ifndef REPLACE_H
#define REPLACE_H

#include "type_list/base/base_all.h"
#include "push_back_front.h"

template<class... T>
struct replace : cur_type_t<empty_type_list>{};

template<class From, class To, class Head, class... Args>
struct replace<From, To, type_list<Head, Args...>>
{
private:
    typedef typename replace<From, To, type_list<Args...>>::type tail_repl;
public:
    typedef typename push_front<tail_repl, Head>::type type;
};

template<class From, class To, class... Args>
struct replace<From, To, type_list<Args...>> : cur_type_t<type_list<Args...>>{};

template<class From, class To, class... Args>
struct replace<From, To, type_list<From, Args...>>
    : cur_type_t<type_list<To, Args...>>{};

#endif // REPLACE_H
