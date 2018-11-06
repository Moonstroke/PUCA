/**
 * \file funcattrs.h
 * \author joH1
 * \version 0.1
 *
 * \brief Function qualifiers for declarations and/or definitions.
 *
 * This file provides definitions of a number of function attributes, that are
 * qualifiers designed to provide details on the function's behavior, and serve
 * as hints for the compiler or informational fragments for the reader.
 */
#ifndef PUCA_FUNCATTRS_H
#define PUCA_FUNCATTRS_H

#include "puca.h" /* for common attributes */



#ifdef __GNUC__

# define INLINE __attribute__((__always_inline__,__artificial__)) inline

# define NODISCARD __attribute__((__warn_unused_result__))
# define NORETURN __attribute__((__noreturn__))

# define NOTNULL(...) __attribute__((__nonnull__(__VA_ARGS__)))

# define PURE __attribute__((__pure__,__warn_unused_result__))
# define CONSTEXPR __attribute__((__const__,__warn_unused_result__))

# define MALLOC __attribute__((__malloc__,__warn_unused_result__))

# define THISCALL __attribute__((__thiscall__))
# define FASTCALL __attribute__((__fastcall__))

# define HOTSPOT __attribute__((__hot__))
# define COLDSPOT __attribute__((__cold__))

# ifdef HAVE_ALIAS
#  define ALIAS(func) extern __attribute__((__weakref__(#func)))
# endif

#else /* __GNUC__ */

# ifdef _MSC_VER
#  define INLINE __forceinline

#  if _MSC_VER >= 1700 /* MSVC 2012 and higher */
#   define NODISCARD _Check_return_ /* Needed on both function decl and defn */
#  else
#   define NODISCARD
#  endif
#  define NORETURN __declspec(noreturn)

#  define PURE __declspec(noalias) /* NOTE: this value allows function to modify
                                      memory pointed to by its pointer args */

#  define MALLOC __declspec(restrict)

#  define THISCALL __thiscall /* Note: currently C++-only */
#  define FASTCALL __fastcall

# else /* _MSC_VER */

#  define INLINE inline

#  define NODISCARD
#  if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L /* ISO C11 */
#   define NORETURN _Noreturn
#  else
#   define NORETURN
#  endif

#  define PURE

#  define MALLOC

#  define THISCALL
#  define FASTCALL

# endif /* _MSC_VER */

# define NOTNULL(...)

# define CONSTEXPR

# define HOTSPOT
# define COLDSPOT

# ifdef HAVE_ALIAS
#  error Cannot have aliases without GNU C
# endif

#endif /* __GNUC__ */


#ifdef HAVE_OOATTRS
# define CTOR MALLOC
# define MEMBER NOTNULL(1) THISCALL
#endif

/**
 * \def INLINE
 *
 * \brief The function's code is expanded in place of a call.
 */

/**
 * \def NODISCARD
 *
 * \brief The value returned should be checked, a warning is emitted if
 *        discarded.
 */

/**
 * \def NORETURN
 *
 * \brief The function does not return to the caller.
 */

/**
 * \def NOTNULL(...)
 *
 * \brief The arguments to the functions whose indices are given must not be
 *        \c NULL pointers.
 *
 * \param[in] ... The indices (starting from 1) at which pointers must not be
 *                \c NULL.
 */

/**
 * \def PURE
 *
 * \brief The function only performs calculations on its arguments and has no
 *        side effects.
 *
 * \warning The definition is looser under MSVC, where it allows pointed memory
 *          to be modified.
 */

/**
 * \def CONSTEXPR
 *
 * \brief The function has no side effects and does not even access external
 *        data (memory through pointers, global variables).
 *
 * \note This attribute imposes a stricter meaning on the function than \c PURE,
 *       as a pure function may dereference its pointer arguments.
 */

/**
 * \def MALLOC
 *
 * \brief The function returns a pointer to a portion of memory just allocated
 *        and unaliased (never referenced anywhere else in the program).
 */

/**
 * \def THISCALL
 *
 * \brief On x86 architectures, pass the first argument in the register \c ECX.
 *
 * \note This attribute is C++-specific under Windows; however GCC allows it for
 *       C functions as well.
 */

/**
 * \def FASTCALL
 *
 * \brief On x86 architectures, pass the txo first arguments in the registers
 *        \c ECX and EDX, respectively.
 */

/**
 * \def HOTSPOT
 *
 * \brief The function is called frequently and should be therefore optimized
 *        more aggressively.
 */

/**
 * \def COLDSPOT
 *
 * \brief The function is seldom called and should be optimized for space rather
 *        than memory.
 *
 * A branch consisting of a call to a cold function will be considered the
 * unlikely path during branch prediction processing.
 */

/**
 * \def ALIAS(func)
 *
 * \brief The function aliases the other symbol given as parameter.
 *
 * \param[in] func The identifier to alias
 */

/** \defgroup oo_attrs Object-oriented like attributes
 * \{
 */
/**
 * \def CTOR
 *
 * \brief The function returns a new instance of the related type.
 */

/**
 * \def MEMBER
 *
 * \brief The function takes, as first argument, an instance of the related type
 *        on which to perform the designed action.
 */

/** \} */

#endif /* PUCA_FUNCATTRS_H */
