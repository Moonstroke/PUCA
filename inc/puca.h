#ifndef PUCA_H
# define PUCA_H


#ifdef __GNUC__ /* compiled as GNU C (GCC or Clang) */

# define VISIBLE __attribute__((__visibility__(default)))
# define INTERNAL __attribute__((__visibility__(internal))) static

# define DEFAULT __attribute__((__weak__))

#else /* non-GNU C */
# ifdef _MSC_VER /* MS Visual Compiler */

#  define VISIBLE __declspec(dllexport)

# else /* non-MS C */

#  define VISIBLE

# endif /* _MSC_VER */

# define INTERNAL static

# define DEFAULT

#endif /* __GNUC__ */


#ifdef HAVE_OOATTRS /* Object-oriented function attributes */

# define PUBLIC VISIBLE
# define PRIVATE INTERNAL
#endif


/**
 * \def VISIBLE
 *
 * \brief The function is visible from other modules.
 */

/**
 * \def INTERNAL
 *
 * \brief The function is nt visible from other modules.
 */

/**
 * \def DEFAULT
 *
 * \brief The functions is declared as a weak symbol, designed to be overriden
 *        from outside the module.
 */


/** \defgroup oo_attrs Object-oriented like attributes
 * \{
 */
/**
 * \def PUBLIC
 *
 * \brief The function is accessible from outside the module.
 */

/**
 * \def PRIVATE
 *
 * \brief The function is only accessible in the current module.
 */
/** \} */


#if !defined(PUCA_FUNCATTRS_H) && !defined(PUCA_VARATTRS_H)
# include "funcattrs.h"
# include "varattrs.h"
#endif

#endif /* PUCA_H */
