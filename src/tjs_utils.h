#include "tjs_defined.h"
#include "tjs_types.h"

int get_opt_with_int(str opt_name,int default_val);

long long get_opt_with_ll(str opt_name,int default_val);

str get_opt_with_str(str opt_name, uint *len,str default_val);

void print_useage();
