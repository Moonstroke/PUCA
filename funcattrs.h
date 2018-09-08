#ifndef FUNC_ATTRS_H
#define FUNC_ATTRS_H



#ifdef __GNUC__ /* compiled as GNU C (GCC or Clang) */
# define INLINE __attribute__((__always_inline__,__artificial__)) inline
# define NODISCARD __attribute__((__warn_unused_result__))
# define NORETURN __attribute__((__noreturn__))
# define NOTNULL(...) __attribute__((__nonnull__(__VA_ARGS__)))
# define PURE __attribute__((__pure__,__warn_unused_result__))
# define CONSTEXPR __attribute__((__const__,__warn_unused_result__))
# define MALLOC __attribute__((__malloc__,__warn_unused_result__))

#else /* non-GNU C */
# ifdef _MSC_VER /* MSVC compiler */
#  define INLINE __forceinline
#  define NORETURN __declspec(noreturn)
#  if _MSC_VER >= 1700 /* MSVC 2012 and higher */
#   define NODISCARD _Check_return_ /* Needed on both function decl and defn */
#  else
#   define NODISCARD
#  endif
#  define PURE __declspec(noalias) /* NOTE: this value allows function to modify
                                      memory pointed to by its pointer args */
#  define MALLOC __declspec(restrict)

# else /* not MSVC */
#  define INLINE inline
#  define NORETURN
#  define PURE
#  define MALLOC
#  define NODISCARD
# endif /* _MSC_VER */

# define NOTNULL(...)
# define CONSTEXPR

#endif /* __GNUC__ */


#ifdef OO_ATTRS /* Object-oriented function attributes */
# define CTOR MALLOC
# define MEMBER NOTNULL(1)

#endif /* OO_ATTRS */

#endif /* FUNC_ATTRS_H */
