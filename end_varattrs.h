/**
 * \file end_varattrs.h
 * \author joH1
 * \version 0.1
 *
 * \brief Include this file to remove variable attributes.
 *
 * This file contains \c #undef directives to remove the definitions of the
 * variable attributes declared in varattrs.h, to clean up the macros namespace.
 */

#ifndef VAR_ATTRS_H
# warning end_varattrs.h included without varattrs.h
#endif


#undef THREADLOCAL
#undef ALIGN

#if defined(HAVE_DTOR)
# undef DTOR
#endif
