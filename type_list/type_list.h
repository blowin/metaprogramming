#ifndef TYPE_LIST_H
#define TYPE_LIST_H

#define NAMED_LIST(name, ...) typedef type_list<__VA_ARGS__> name

#include "type_list/base/data_type_list.h"

namespace tl {
    #include "methods/all_methods.h"

    #include "functionality/all_functionality.h"
}
#include "methods/print_tl.h"

#endif // TYPE_LIST_H
