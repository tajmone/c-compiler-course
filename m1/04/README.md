# m1.04. Preparing Our Project

-----

**Table of Contents**

<!-- MarkdownTOC autolink="true" bracket="round" autoanchor="false" lowercase="only_ascii" uri_encoding="true" levels="1,2,3,4" -->

- [Lesson Assets](#lesson-assets)
    - [Assets Origin](#assets-origin)
    - [Bug Fixes](#bug-fixes)
    - [Typos Fixes](#typos-fixes)
- [Lesson Notes](#lesson-notes)
    - [Vector Helper Usage](#vector-helper-usage)

<!-- /MarkdownTOC -->

-----

# Lesson Assets

- [`/build/`][build/] — object files output folder.
- [`/helpers/`][helpers/] — custom helpers for the project:
    + [`buffer.c`][buffer.c]
    + [`buffer.h`][buffer.h]
    + [`vector.c`][vector.c]
    + [`vector.h`][vector.h]
- [`compiler.c`][compiler.c] — compiler code template.
- [`compiler.h`][compiler.h] — shared header file.
- [`cprocess.c`][cprocess.c] — compile process template.
- [`main.c`][main.c]
- [`Makefile`][Makefile]
- [`test.c`][test.c] — sample C source to compile.

## Assets Origin

The files for this lesson were taken from the [PeachCompiler] repository [commit `0980a32`][0980a32], as per the lesson's assets-link:

- [Checkout `0980a32`][0980a32 tree]

## Bug Fixes

- `helpers/vector.c` L32 — the file was replaced with the latest from [DragonCompiler], which contains a bug-fix for a missing `return vector` statement ([see `082d6bed`][082d6bed]):

    ```c
    struct vector *vector_create_no_saves(size_t esize)
    {
        struct vector *vector = calloc(sizeof(struct vector), 1);
        vector->data = malloc(esize * VECTOR_ELEMENT_INCREMENT);
        vector->mindex = VECTOR_ELEMENT_INCREMENT;
        vector->rindex = 0;
        vector->pindex = 0;
        vector->esize = esize;
        vector->count = 0;
        return vector;     <--- missing in original!
    }
    ```

## Typos Fixes

- `compiler.c` LL:8,10,12 — fixed comments typo: "Preform" &rarr; "Perform"
- `main.c` L9 — fixed typo in output string: "file" &rarr; "fine", according to course audio:

    ```c
    printf("everything compiled fine\n");
    ```

- `/helpers/` — fixed various typos within comments in `vector.c` and `vector.h`.

# Lesson Notes

## Vector Helper Usage

- [`/helpers/vector.c`][vector.c]
- [`/helpers/vector.h`][vector.h]

The following code illustrates how to create a new vector, push three values unto it, pop the last added value, and then iterate through the vector and print its stored values to STDOUT:

```c
#include <stdio.h>
#include "helpers/vector.h"
int main()
{
    struct vector* vec = vector_create(sizeof(int));

    int x = 50;
    vector_push(vec, &x); // push 50 into vector
    x = 20;
    vector_push(vec, &x); // push 20 into vector
    x = 10;
    vector_push(vec, &x); // push 10 into vector

    vector_pop(vec);      // pop last value (i.e. 10)

    vector_peek_ptr_at(vec, 0);
    int* ptr = vector_peek(vec);
    while(ptr)
    {
        printf("%i\n", *ptr);
        ptr = vector_peek(vec);
    }
    return 0;
}

```

Running the above will yield:

    50
    20

This vector implementation offers a wide variety of functions to operate on it in a flexible manner.

<!-----------------------------------------------------------------------------
                               REFERENCE LINKS
------------------------------------------------------------------------------>

<!-- PeachCompiler -->

[PeachCompiler]: https://github.com/nibblebits/PeachCompiler

[0980a32]: https://github.com/nibblebits/PeachCompiler/commit/0980a32bf2618d54e629b5e560fc44385a130d8c "PeachCompiler commit 0980a32: Preparing Our Project"
[0980a32 tree]: https://github.com/nibblebits/PeachCompiler/tree/0980a32bf2618d54e629b5e560fc44385a130d8c "Navigate PeachCompiler repository checkout 0980a32"

<!-- DragonCompiler -->

[DragonCompiler]: https://github.com/nibblebits/DragonCompiler

[082d6bed]: https://github.com/nibblebits/DragonCompiler/commit/082d6bed9bbb59af989d7a707060eceee1567809 "DragonCompiler commit 082d6bed: Update vector.c"

<!-- files -->

[build/]: ./build/
[helpers/]: ./helpers/

[buffer.c]: ./helpers/buffer.c
[buffer.h]: ./helpers/buffer.h
[vector.c]: ./helpers/vector.c
[vector.h]: ./helpers/vector.h

[compiler.c]: ./compiler.c
[compiler.h]: ./compiler.h
[cprocess.c]: ./cprocess.c
[main.c]: ./main.c
[Makefile]: ./Makefile
[test.c]: ./test.c

<!-- EOF -->
