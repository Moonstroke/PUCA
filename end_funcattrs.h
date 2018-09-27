/**
 * \file end_funcattrs.h
 * \author joH1
 * \version 0.1
 *
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
