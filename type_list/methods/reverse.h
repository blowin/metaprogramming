#ifndef REVERSE_H
#define REVERSE_H

#include "type_list/base/base_all.h"
#include "type_list/methods/push_back_front.h"

template<class... Args>
struct reverse : cur_type_t<empty_type_list>{};

template<class Head, class... Args>
struct reverse<type_list<Head, Args...>>
{
private:
    typedef typename reverse<type_list<Args...>>::type new_head;
public:
    typedef typename push_back<new_head, Head>::type type;
};

template<class... Args>
struct reverse<type_list<Args...>> : cur_type_t<type_list<Args...>>{};


#endif // REVERSE_H
