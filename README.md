# C Compiler Course Exercises

[Tristano Ajmone]'s personal notes and exercises for the _[Creating a C Compiler From Scratch]_ video-course by [Daniel McCarthy], along with the lessons source code material.

-----

**Table of Contents**

<!-- MarkdownTOC autolink="true" bracket="round" autoanchor="false" lowercase="only_ascii" uri_encoding="true" levels="1,2,3" -->

- [Project Contents](#project-contents)
- [About](#about)
    - [Course Lessons Assets](#course-lessons-assets)
    - [Code Fixes](#code-fixes)
    - [Personal Notes](#personal-notes)
    - [Windows Tested](#windows-tested)
- [License](#license)

<!-- /MarkdownTOC -->

-----

# Project Contents

- [`/m1/`][m1/] — [Module 1]:
    + [`/04/`][04/] — Preparing Our Project.
    + [`/06/`][06/] — Creating Our Token Structures.
- [`LICENSE`][LICENSE] — GPLv2 License.

# About

_[Creating a C Compiler From Scratch]_ is a commercial video-course on how to hand-code a C compiler in C, without resorting to third party lexer/parser generator tools like Yacc, Bison, etc.

The course is available at the [Dragon Zap] and [Udemy] online stores, as a single product at the former, and as three separate modules at the latter.

> **NOTE** — at the time of this writing, only the first of the three modules has been released.
> Modules 2 and 3 are currently undergoing final editing, and should become available soon.

## Course Lessons Assets

At [Udemy][Module 1] store, course assets are provided as links to specific commits at the [PeachCompiler] repository, from which the reader can download the source files, with occasional in-video instructions to fetch specific files from the [DragonCompiler] repository — a rather cumbersome solution, compared to having access to Zip archives with lesson-specific ready files, or a dedicated repository for the course assets.

While studying the course, I decided to gather the required material in an orderly fashion, organized into subfolders according to lesson.
Since both the [PeachCompiler] and [DragonCompiler] repositories are [GPLv2 licensed][LICENSE], I thought I might just as well share the material for the benefit of other students.

## Code Fixes

Besides saving end users the time of manually fetching each lesson files from specific commit checkouts, the files in this project often contain bug fixes that were introduced in later commits, for which I've manually overwritten the original files with their fixed versions, or other fixes that surfaced during students' Q&A.

I also took the liberty to fix some obvious typos in source comments and strings.

## Personal Notes

This being first and foremost my personal study project, I'm including my own course notes and reference links within the project, for my own benefit, and often tweak the original comments in the source files, or even add new ones, as a means to annotate my learning process.

If these extra annotations turn out to be useful to others, that's an added value.
Just beware at all times that this repository is a _**personal project**_, and that the assets herein contained often contain various changes compared to the original course material.

## Windows Tested

Whereas the online course explicitly targets Ubuntu, all the code within this repository is tested under MS Windows 10 Home, using MinGW as the compiler suite.
So far the project didn't require any fixes to run under MS Windows, but if the need arises I'll adapt the assets to ensure they work under Windows, at the expenses of other platforms.

# License

All the C source assets in this project were taken from the [PeachCompiler] and [DragonCompiler] repositories, both created by [Daniel McCarthy] and released under GPLv2 license:

- [`LICENSE`][LICENSE] — GPLv2 License.

<!-----------------------------------------------------------------------------
                               REFERENCE LINKS
------------------------------------------------------------------------------>

[Creating a C Compiler From Scratch]: https://dragonzap.com/course/creating-a-c-compiler-from-scratch "course page at Dragon Zap"

[Module 1]: https://www.udemy.com/course/creating-a-c-compiler-from-scratch-module-1/ "Module 1 course at Udemy"

<!-- compilers -->

[PeachCompiler]: https://github.com/nibblebits/PeachCompiler
[nibblebits/PeachCompiler]: https://github.com/nibblebits/PeachCompiler

[DragonCompiler]: https://github.com/nibblebits/DragonCompiler
[nibblebits/DragonCompiler]: https://github.com/nibblebits/DragonCompiler

<!-- Misc. -->


[Dragon Zap]: https://dragonzap.com "Visit Dragon Zap"
[Udemy]: https://www.udemy.com "Visit Udemy"

<!-- files & folders -->

[m1/]: ./m1/ "Module 1"
[04/]: ./m1/04/ "Lesson 4: Preparing Our Project"
[06/]: ./m1/06/ "Lesson 6: Creating Our Token Structures"

[LICENSE]: ./LICENSE "GPLv2 License"

<!-- people -->

[Daniel McCarthy]: https://github.com/nibblebits "View Daniel McCarthy's GitHub profile"
[Tristano Ajmone]: https://github.com/tajmone "View Tristano Ajmone's GitHub profile"

<!-- EOF -->
