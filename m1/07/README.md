# m1.07. Preparing Our Lexer


-----

**Table of Contents**

<!-- MarkdownTOC autolink="true" bracket="round" autoanchor="false" lowercase="only_ascii" uri_encoding="true" levels="1,2,3,4" -->

- [Lesson Assets](#lesson-assets)
    - [Assets Origin](#assets-origin)
    - [My Changes](#my-changes)
- [Lesson Notes](#lesson-notes)
    - [Function Pointers](#function-pointers)

<!-- /MarkdownTOC -->

-----

# Lesson Assets

- [`/build/`][build/]
- [`/helpers/`][helpers/]
    + [`buffer.c`][buffer.c]
    + [`buffer.h`][buffer.h]
    + [`vector.c`][vector.c]
    + [`vector.h`][vector.h]
- [`compiler.c`][compiler.c] — changed.
- [`compiler.h`][compiler.h] — changed.
- [`cprocess.c`][cprocess.c] — changed.
- [`lex_process.c`][lex_process.c] — newly added.
- [`lexer.c`][lexer.c] — newly added.
- [`main.c`][main.c]
- [`Makefile`][Makefile] — changed.
- [`test.c`][test.c]

## Assets Origin

The files for this lesson were taken from the [PeachCompiler] repository [commit `cebcee6`][cebcee6], as per the lesson's assets-link:

- [Checkout `cebcee6`][cebcee6 tree]

## My Changes

- `compiler.c` LL:4-6 — added surrounding spaces to `=` in assignments, to improve source readability.

# Lesson Notes

## Function Pointers

In the video (`2:32`) Daniel point out the importance of function pointers to abstract away the lexer functionality in order to allow end users to add their custom lexer-processing functions — i.e. creating an open-ended lexer, instead of a lexer which only works in a fixed manner.

This is basically the C way to mimic how inheritance works in OOP.

<!-- MarkdownTOC:excluded -->
### Function Pointers How-To

Here's a brief reminder on how function pointers work in C ...

The declaration syntax of a function pointer is:

```c
function_return_type (*Pointer_name)(function argument list)
```

Here's a usage example:

```c
void (*fun_ptr)(int) = some_fun;  // <1> `&` removed
fun_ptr(10);  // <2> `*` removed
```

Note the following peculiarities compared to normal data pointers:

1. In the assignment, the function name doesn't need an `&` — `= some_fun` vs `= &some_fun`.
2. Invoking the function via its pointer doesn't require an `*` either — `fun_ptr(10)` vs `*fun_ptr(10)`.

<!-- MarkdownTOC:excluded -->
### Actual Code Usage

In [`compiler.h` L58 ](compiler.h#L58) we see function pointers being defined as types so they can be used within the `lex_process_functions` structure:

```c
typedef char (*LEX_PROCESS_NEXT_CHAR)(struct lex_process* process);
typedef char (*LEX_PROCESS_PEEK_CHAR)(struct lex_process* process);
typedef void (*LEX_PROCESS_PUSH_CHAR)(struct lex_process* process, char c);

struct lex_process_functions
{
    LEX_PROCESS_NEXT_CHAR next_char;
    LEX_PROCESS_PEEK_CHAR peek_char;
    LEX_PROCESS_PUSH_CHAR push_char;
};
```

This allows [`compiler.c` L3 ](compiler.c#L3) to instantiate a `lex_process_functions` structure whose `.next_char`, `.peek_char` and `.push_char` fields point to actual lexer functions:

```c
struct lex_process_functions compiler_lex_functions = {
    .next_char = compile_process_next_char,
    .peek_char = compile_process_peek_char,
    .push_char = compile_process_push_char
};
```

i.e. the functions `compile_process_next_char()`, `compile_process_peek_char()` and `compile_process_push_char()`, which are defined in [`cprocess.c` LL:29,43,51](cprocess.c#L29), respectively.

Note how all three functions above have different signatures, hence they can't share a common function pointer type definition.

<!-- MarkdownTOC:excluded -->
### External References

- [GeeksforGeeks » _Function Pointer in C_][funptr Geeks] — by Abhay Rathi.
- [TutorialsPoint » _Function Pointer in C_][funptr TutPt] — by Anvi Jain.

<!-- tutorials & articles -->

[funptr Geeks]: https://www.geeksforgeeks.org/function-pointer-in-c/ "Function Pointer in C — by Abhay Rathi (GeeksforGeeks)"
[funptr TutPt]: https://www.tutorialspoint.com/function-pointer-in-c "Function Pointer in C — by Anvi Jain (TutorialsPoint)"

<!-----------------------------------------------------------------------------
                               REFERENCE LINKS
------------------------------------------------------------------------------>

<!-- PeachCompiler -->

[PeachCompiler]: https://github.com/nibblebits/PeachCompiler

[cebcee6]: https://github.com/nibblebits/PeachCompiler/commit/cebcee6565cb0ed32db7e8c4fd7ff7dc38a28407 "PeachCompiler commit cebcee6: Preparing Our Lexer"
[cebcee6 tree]: https://github.com/nibblebits/PeachCompiler/tree/cebcee6565cb0ed32db7e8c4fd7ff7dc38a28407 "Navigate PeachCompiler repository checkout cebcee6"

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

[lex_process.c]: ./lex_process.c
[lexer.c]: ./lexer.c


<!-- EOF -->
