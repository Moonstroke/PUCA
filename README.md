# PUCA
## Portable Unified C Attributes

The purpose of this project is to provide a single comprehensive set of
declarations and definitions decorators for the most common dialects of the C
language: GNU C, ISO C 11, Windows C, etc.

The decorators are declared as macros in the header files in the directory
`inc`, grouped by the type of declaration they are applied to: functions,
variables, etc.

This project is mainly based on the GNU attributes, a GCC --and now Clang-- C
extension; using series of `#if/#else` directives, equivalent decorators from
other dialects of C are used instead of GNU's.

The design convention is to define the attributes for one kind of declarations
in the corresponding header, and to undefine them in the adequate `end_*`
header, which is to be included at the end of the user's header. The purpose of
this pattern is to keep a clean namespace and, as the decorators are not defined
with any sort of macro prefix (no `PUCA_DECORATOR`, only `DECORATOR`),
occurences of identifier conflicts is minimized. There are of course drawbacks
to this practice (for example, the inclusion of the `end_` header is easily
omitted), however the advantages are substantial and it was deemed a valuable
compromise.


### 1. Function attributes

- `INLINE` (GNU, Windows, ISO C11 and others in a certain measure)

  The function's body is expanded inside the calling function, in lieu of a
  usual function call. This can increase the size of the caller, but removes the
  function call overhead.

<!-- TODO -->


### 2. Variable attributes

- `THREADLOCAL` (GNU, Windows, ISO C11)

  The variable has a thread-local storage class, i.e. each thread of execution
  has its own version of the variable.

- `ALIGN(n)` (GNU, Windows, ISO C11)

  The variable is stored using `n` bytes of memory rather than the automatic
  size of the declared type (padding bytes are added).

  *Note*: this attribute can only increase the storage size of the identifier,
  not decrease it.

<!-- TODO -->
