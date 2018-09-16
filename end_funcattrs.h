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
#undef HOTSPOT
#undef COLDSPOT
#undef VISIBLE
#undef INTERNAL
#undef DEFAULT

#ifdef OO_ATTRS
# undef CTOR
# undef MEMBER
#endif
