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

# define HOTSPOT __attribute__((__hot__))
# define COLDSPOT __attribute__((__cold__))

# define VISIBLE __attribute__((__visibility__(default)))
# define INTERNAL __attribute__((__visibility__(internal))) static

# define DEFAULT __attribute__((__weak__))
# ifdef HAS_ALIAS
#  define ALIAS(func) extern __attribute__((__weakref__(#func)))
# endif

#else /* non-GNU C */

# ifdef _MSC_VER /* MSVC compiler */
#  define INLINE __forceinline

#  if _MSC_VER >= 1700 /* MSVC 2012 and higher */
#   define NODISCARD _Check_return_ /* Needed on both function decl and defn */
#  else
#   define NODISCARD
#  endif
#  define NORETURN __declspec(noreturn)

#  define PURE __declspec(noalias) /* NOTE: this value allows function to modify
                                      memory pointed to by its pointer args */

#  define MALLOC __declspec(restrict)

#  define VISIBLE __declspec(dllexport)

# else /* not MSVC */

#  define INLINE inline

#  define NODISCARD
#  if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L /* ISO C11 */
#   define NORETURN _Noreturn
#  else
#   define NORETURN
#  endif

#  define PURE

#  define MALLOC

#  define VISIBLE

# endif /* _MSC_VER */

# define NOTNULL(...)

# define CONSTEXPR

# define HOTSPOT
# define COLDSPOT

# define INTERNAL static

# define DEFAULT
# ifdef HAS_ALIAS
#  error Cannot have aliases without GNU C
# endif

#endif /* __GNUC__ */


#ifdef OO_ATTRS /* Object-oriented function attributes */

# define CTOR MALLOC
# define MEMBER NOTNULL(1)

#endif /* OO_ATTRS */

#endif /* FUNC_ATTRS_H */
