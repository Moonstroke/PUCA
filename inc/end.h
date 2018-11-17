/**
 * \file end.h
 * \author joH1
 * \version 0.1
 *
 * \brief Undefinitions of all attributes
 *
 * This file is intended to be included after all decorated declarations (or
 * the very end of the file) as it undefines the attributes--all of them. This
 * allows to keep a namespace globally clean. The limited scope of the attribute
 * also permits to avoid potential name conflicts between files units.
 */
#ifndef PUCA_H
# warning PUCA/end.h included without any PUCA header previsouly included
#endif



#undef VISIBLE
#undef INTERNAL
#undef DEFAULT
#ifdef HAVE_OO_ATTRS
# undef PUBLIC
# undef PRIVATE
#endif

#ifdef PUCA_FUNCATTRS_H
# undef INLINE
# undef NODISCARD
# undef NORETURN
# undef NOTNULL
# undef PURE
# undef CONSTEXPR
# undef MALLOC
# undef THISCALL
# undef FASTCALL
# undef HOTSPOT
# undef COLDSPOT
# ifdef HAVE_ALIAS
#  undef ALIAS
# endif
# ifdef HAVE_IOATTRS
#  undef PRINTF
#  undef SCANF
#  undef STRFTIME
#  undef STRFMON
#  undef PARSE_FMT_STR
# endif
# ifdef HAVE_OO_ATTRS
#  undef CTOR
#  undef MEMBER
# endif
#endif

#ifdef PUCA_VARATTRS_H
# undef THREADLOCAL
# undef ALIGN
# ifdef HAVE_DTOR
#  undef DTOR
# endif
#endif
