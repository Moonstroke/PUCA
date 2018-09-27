/**
 * \file end_funcattrs.h
 * \author joH1
 * \version 0.1
 *
 * \brief Include this file to remove the attributes.
 *
 * This file is designed to be included at the end of a user's code, to remove
 * access to the attributes.
 * The need for such a file arose from the fact that using attributes with a
 * prefix would turn out to be more tedious to type: consider \c ATTRS_INLINE
 * vs. a mere \c INLINE.
 * Though there are drawbacks to this design, mainly that the inclusion of this
 * file must not be omitted, and the header defining the attributes should be
 * included last (to avoid name clashes), this mechanism ensures that, between
 * two files, the namespace is kept clean and identifier ambiguities are
 * minimized.
 **/

#ifndef FUNC_ATTRS_H
# warning end_funcattrs.h included without funcattrs.h
#endif


#undef INLINE
#undef NODISCARD
#undef NORETURN
#undef NOTNULL
#undef PURE
#undef CONSTEXPR
#undef MALLOC
#undef THISCALL
#undef FASTCALL
#undef HOTSPOT
#undef COLDSPOT
#undef VISIBLE
#undef INTERNAL
#undef DEFAULT

#ifdef HAS_ALIAS
# undef ALIAS
#endif

#ifdef OO_ATTRS
# undef CTOR
# undef MEMBER
#endif
