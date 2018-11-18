/**
 * \file varattrs.h
 * \author joH1
 * \version 0.1
 *
 * \brief Variable attributes
 *
 * This header defines attributes for declarations of variables.
 */
#ifndef PUCA_VARATTRS_H
#define PUCA_VARATTRS_H

#include "puca.h" /* for common attributes */



#ifdef __GNUC__
# define THREADLOCAL __thread
# define ALIGN(n) __attribute__((__aligned__(n)))
#else /* non-GNU C */
# ifdef _MSC_VER /* MSVC */
#  define THREADLOCAL __declspec(thread)
# define ALIGN(n) __declspec(align(n))
# else /* non-GNU non-Windows C */
#  if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L /* ISO C11 */
#   define THREADLOCAL _Thread_local
#   define ALIGN(n) _Alignas(n)
#  else /* non-GNU, non-Windows, non-ISO-C11 C */
#   warning Vanilla C, THREADLOCAL defined empty
#   define THREADLOCAL
#   define ALIGN(n)
#  endif
# endif /* _MSC_VER */
#endif /* __GNUC__ */

#ifdef HAVE_DTOR
# ifndef __GNUC__
#  error Cannot have destructors without GNU C
# endif
# define DTOR(func) __attribute__((__cleanup__(func)))
#endif /* HAVE_DTOR */


/**
 * \def THREADLOCAL
 *
 * \brief The variable has a different storage place for each running execution
 *        thread.
 */
/**
 * \def ALIGN(n)
 *
 * \brief The variable is aligned with a given size (in bytes).
 *
 * \param[in] n The alignment size
 *
 * \note The alignment can only be widened (\a n must be greater or equal to the
 *       original size of the variable).
 */
/**
 * \def DTOR(func)
 *
 * \brief The provided function is called when the variable is destroyed.
 *
 * The function is passed the address of the variable just before it goes out of
 * scope. This allows to implicitly handle resources managed by the variable,
 * for example heap-allocated memory.
 *
 * \param[in] func The function to call
 *
 * \note This attribute only affects function-local variables of automatic
 * storage class. \c static variables, global variable, function parameters,
 *  etc. are not affected by this attribute.
 */


#endif /* PUCA_VARATTRS_H */
