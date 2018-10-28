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

- NODISCARD (GNU, Windows in a measure)

  A warning is emitted by the compiler if the value returned by the function is
  not used -- be it stored in a variable or part of an expression.

  *Note*: under Windows, the attribute must be provided on both the function's
  declaration and definition (if both exist), so for complete portability this
  attribute should always be given to both statements.

- NORETURN (GNU, Windows, C11)

  The function does not return to its caller. A good example is a function
  called `die`, that calls internally `exit` or `abort`. Ths function's return
  type must be declared as `void`.

- NOTNULL(...) (GNU)

  The parameter to this attribute correspond to the indices (starting from 1) of
  pointer arguments to the function that must not be passed a value of `NULL`.

  *Note*: this attribute only detects static `NULL`s, pointers whose value is
  determined at runtime are not diagnosed.

- PURE (GNU, Windows in a certain measure)

  The function does not modify memory outside its own locals: data referenced by
  pointer arguments, global variables can be accessed, but are not modified.

  *Note*: under Windows, the meaning carried by this attribute allows it to
  modify data through its pointer arguments. However, for maximal portability,
  this attribute should not be used for functions that do not modify global
  memory.

- CONSTEXPR (GNU)

  The function does not access global memory. This attribute is stricter than
  `PURE` in that pointer arguments must not even be dereferenced or global
  variables, read. Examples of such functions are mathematical functions, whose
  result only depend on the given values (`pow`, `cos`, etc.)

- MALLOC (GNU, Windows)

  The function returns a pointer to a chunk of memory just allocated (`malloc`
  or other), and that is never referenced anywhere else in the program.

- THISCALL (GNU, Windows)

  On x86 platforms, the first parameter of the functions, if of integral type,
  is passed using the register `ECX`.

- FASTCALL (GNU, Windows)

  On x86 platforms, the first two parameters of the functions, if of integral
  type, are passed using the registers `EDX` and `ECX`.

- HOTSPOT (GNU)

  The function is called often, and is an good target for more aggressive
  optimization.

- COLDSPOT (GNU)

  The function is seldom called, and is to be optimized for space usage rather
  than memory.

  During the branch prediction processing, if a path is a call to a
  `COLDSPOT` function, it is considered the unlikely path.

- VISIBLE (all)

  The function is accessible from outer scope (outside the declaring unit).
  This is the default behavior on most platforms, however this attribute makes
  it explicit that the function is purposely accessible.

- INTERNAL (all)

  The function is only accessible from inside the declaring file. On non-GNU
  dialects, this attribute is only defined as the keyword `static`.

- DEFAULT (GNU, Windows in a measure)

  The definition provides a default implementation for the declared symbol, and
  is intended to be overriden with a user-provided redefinition.
  On Windows dialect this behavior is enabled by default: a function library may
  be overshadowed by a user's definition of the symbol, and the user's will be
  used preferentially to the library's.

- ALIAS(func) (GNU if `HAVE_ALIAS` is defined)

  The declared function provides a name alias for the target given as parameter.

  This attribute carries strong meaning and can alter code's portability if
  used; it is only defined if the guard macro `HAVE_ALIAS` is defined, so that
  only knowing users make use of it. An error is raised if the guard is defined
  and the compilation is not carried out with a GNU-compatible compiler.


#### Object-oriented atributes

The following attributes can be considered somehow as meta-attributes: they are
only aliases of the previous attributes, but they add a layer of abstraction by
carrying a meaning close to concepts of object-oriented programming. They are
defined if, and only if, the guard macro `HAVE_OOATTRS` is itself defined.

- CTOR

  The function returns a pointer to a new instance of the related type.

- MEMBER

  The function takes, as its first parameter, a pointer to an instance of the
  related type.

- PUBLIC

  The function is accessible from external scope.

- PRIVATE

  The function can only be referenced from inside the declaring module.


### 2. Variable attributes

- `THREADLOCAL` (GNU, Windows, ISO C11)

  The variable has a thread-local storage class, i.e. each thread of execution
  has its own version of the variable.

- `ALIGN(n)` (GNU, Windows, ISO C11)

  The variable is stored using `n` bytes of memory rather than the automatic
  size of the declared type (padding bytes are added).

  *Note*: this attribute can only increase the storage size of the identifier,
  not decrease it.

- DTOR(func) (GNU if `HAVE_DTOR` is defined)

  The target function is automatically called with the varaible's address as
  parameter when the variable falls out of scope. This allows to implicitly call
  `free` on a `malloc`-ed variable implicitly. The prototype of the function is,
  with
  *type* the type of the variable:

      void my_cleanup_func(type*);
  so, for e.g. a `void*` variable, the prototype is:

      void my_cleanup_voidp(void**);
  Due to its huge impact on a program's behavior, this attribute is only defined
  if the guard macro `HAVE_DTOR` is defined. If this macro is defined and the
  compilation is not performed with a GNU-compatible compiler, an error is
  raised.
