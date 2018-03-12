#ifndef IS_INTEGER_H
#define COND_H

#include "type_list/base/support_types.h"
#include "type_list/base/data_func_list.h"

template<class, class> struct tl_or   : false_value{};
template<class, class> struct tl_and  : true_value{};

template<class T, template<class> class HirstFunctions, template<class> class... Functions>
struct tl_or<T, func_list<HirstFunctions, Functions...>>
    : support_types::bool_value_t<HirstFunctions<T>::value || tl_or<T, func_list<Functions...>>::value>{};

template<class T, template<class>class HirstFunctions, template<class> class... Functions>
struct tl_and<T, func_list<HirstFunctions, Functions...>>
    : support_types::bool_value_t<HirstFunctions<T>::value && tl_and<T, func_list<Functions...>>::value>{};

#endif // IS_INTEGER_H
