#ifndef PARSEOPT_H
#define PARSEOPT_H

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include <stdbool.h>

//////////////////////////////////////////////////////////////////////////////
// CONSTANTS AND DATA TYPES
//////////////////////////////////////////////////////////////////////////////
typedef bool (parse_flags_fn)(char* flags);
typedef bool (parse_opt_fn)(char *name, char* val);

//////////////////////////////////////////////////////////////////////////////
// GLOBAL FUNCTION PROTOTYPES
//////////////////////////////////////////////////////////////////////////////
bool optparse(int argc, char **argv, parse_flags_fn *flagsfunc, parse_opt_fn *optfunc);

#endif //PARSEOPT_H

