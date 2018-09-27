#ifndef VARATTRS_H
#define VARATTRS_H



#ifdef __GNUC__

# define THREADLOCAL __thread

#else /* non-GNU C */

# ifdef _MSC_VER /* MSVC */

#  define THREADLOCAL __declspec(thread)

# else /* non-GNU non-Windows C */

#  if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L /* ISO C11 */
#   define THREADLOCAL _Thread_local
#  else /* non-GNU, non-Windows, non-ISO-C11 C */
#   warning Vanilla C, THREADLOCAL defined empty
#   define THREADLOCAL
#  endif

# endif /* _MSC_VER */
#endif /* __GNUC__ */

#if defined(HAVE_DTOR)
# ifndef __GNUC__
#  error Cannot have destructors without GNU C
# endif
# define DTOR(func) __attribute__((__cleanup__(func)))
#endif

#endif /* VARATTRS_H */
