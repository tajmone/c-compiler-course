#include "compiler.h"
int compile_file(const char* filename, const char* out_filename, int flags)
{
    struct compile_process* process = compile_process_create(filename, out_filename, flags);
    if (!process)
        return COMPILER_FAILED_WITH_ERRORS;

    // (1/3) Perform lexical analysis

    // (2/3) Perform parsing

    // (3/3) Perform code generation

    return COMPILER_FILE_COMPILED_OK;
}
