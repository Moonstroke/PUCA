
/* Function attributes */

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
# undef VISIBLE
# undef INTERNAL
# undef DEFAULT

# ifdef HAVE_ALIAS
#  undef ALIAS
# endif

# ifdef HAVE_OO_ATTRS
#  undef CTOR
#  undef MEMBER
#  undef PUBLIC
#  undef PRIVATE
# endif

#endif


/* Variable attributes */

#ifdef PUCA_VARATTRS_H

# undef THREADLOCAL
# undef ALIGN

# ifdef HAVE_DTOR
#  undef DTOR
# endif

#endif
