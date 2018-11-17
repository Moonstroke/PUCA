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
