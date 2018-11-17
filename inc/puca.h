/**
 * \file puca.h
 * \author joH1
 * \version 0.1
 *
 * \brief Project's main header and common attributes
 *
 * This header can be used to include all the specific headers (\c funcattrs.h,
 * \c varattrs.h) at once. It also defines the attributes common to all kinds of
 * decoratable symbols.
 */
#ifndef PUCA_H
#define PUCA_H



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

#ifdef HAVE_OOATTRS /* Object-oriented-like attributes */
# define PUBLIC VISIBLE
# define PRIVATE INTERNAL
#endif


/**
 * \def VISIBLE
 *
 * \brief The symbol is visible from other modules (external linkage).
 */
/**
 * \def INTERNAL
 *
 * \brief The symbol is not visible from other modules; it has internal linkage.
 */
/**
 * \def DEFAULT
 *
 * \brief The symbol is declared as weak, designed to be overriden from outside
 *        the declaring module.
 */

/** \defgroup oo_attrs Object-oriented like attributes
 * \{
 */
/**
 * \def PUBLIC
 *
 * \brief The declared symbol is accessible from outside the module.
 */
/**
 * \def PRIVATE
 *
 * \brief The symbol is only accessible in the current module.
 */
/** \} */


#if !defined(PUCA_FUNCATTRS_H) && !defined(PUCA_VARATTRS_H)
# include "funcattrs.h"
# include "varattrs.h"
#endif

#endif /* PUCA_H */
