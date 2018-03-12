#ifndef SUPPORT_TYPES_H
#define SUPPORT_TYPES_H

namespace support_types {
    template<bool Val>  struct bool_value_t { static constexpr bool value = Val;    };
    template<int Idx>   struct int_idx_t    { static constexpr int value = Idx;     };
    template<class T>   struct cur_type_t   { typedef T type;                       };
}
using support_types::cur_type_t;

struct true_value   : support_types::bool_value_t<true> {};
struct false_value  : support_types::bool_value_t<false>{};

struct negative_idx : support_types::int_idx_t<-1> {};
template<int Idx>
struct positive_idx : support_types::int_idx_t<Idx>{};

struct empty_type_list{};

#endif // SUPPORT_TYPES_H
