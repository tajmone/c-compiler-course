# m1.06. Creating Our Token Structures

In this lesson we add to [`compiler.h`][compiler.h] the definitions for handling different tokens types.

-----

**Table of Contents**

<!-- MarkdownTOC autolink="true" bracket="round" autoanchor="false" lowercase="only_ascii" uri_encoding="true" levels="1,2,3,4" -->

- [Lesson Assets](#lesson-assets)
    - [Assets Origin](#assets-origin)
    - [Typos Fixes](#typos-fixes)
    - [My Changes](#my-changes)

<!-- /MarkdownTOC -->

-----

# Lesson Assets

- [`/build/`][build/]
- [`/helpers/`][helpers/]
    + [`buffer.c`][buffer.c]
    + [`buffer.h`][buffer.h]
    + [`vector.c`][vector.c]
    + [`vector.h`][vector.h]
- [`compiler.c`][compiler.c]
- [`compiler.h`][compiler.h] — only file changed.
- [`cprocess.c`][cprocess.c]
- [`main.c`][main.c]
- [`Makefile`][Makefile]
- [`test.c`][test.c]

## Assets Origin

The files for this lesson were taken from the [PeachCompiler] repository [commit `c220dd2`][c220dd2], as per the lesson's assets-link:

- [Checkout `c220dd2`][c220dd2 tree]

## Typos Fixes

- `compiler.h` L41 — comment "if their is" &rarr; "if there is"

## My Changes

- `compiler.h` — tweaked comments and added extra info for my own learning benefit.

<!-----------------------------------------------------------------------------
                               REFERENCE LINKS
------------------------------------------------------------------------------>

<!-- PeachCompiler -->

[PeachCompiler]: https://github.com/nibblebits/PeachCompiler

[c220dd2]: https://github.com/nibblebits/PeachCompiler/commit/c220dd2cdc7d09543ac01c888ad4616db8390b34 "PeachCompiler commit c220dd2: Creating our token structures"
[c220dd2 tree]: https://github.com/nibblebits/PeachCompiler/tree/c220dd2cdc7d09543ac01c888ad4616db8390b34 "Navigate PeachCompiler repository checkout c220dd2"

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
