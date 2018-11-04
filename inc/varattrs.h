#ifndef PUCA_VARATTRS_H
#define PUCA_VARATTRS_H



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

#endif /* PUCA_VARATTRS_H */
