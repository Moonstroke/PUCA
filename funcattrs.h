#ifndef FUNC_ATTRS_H
#define FUNC_ATTRS_H



#ifdef __GNUC__ /* compiled as GNU C (GCC or Clang) */
# define INLINE __attribute__((__always_inline__)) inline
# define NODISCARD __attribute__((__warn_unused_result__))
# define NORETURN __attribute__((__noreturn__))
# define NOTNULL(...) __attribute__((__nonnull__(__VA_ARGS__)))
# define PURE __attribute__((__pure__,__warn_unused_result__))
# define CONSTEXPR __attribute__((__const__,__warn_unused_result__))
# define MALLOC __attribute__((__malloc__,__warn_unused_result__))

#else /* non-GNU C */
# define INLINE inline
# define NODISCARD
# define NORETURN
# define NOTNULL(...)
# define PURE
# define CONSTEXPR
# define MALLOC

#endif


#ifdef OO_ATTRS /* Object-oriented function attributes */
# define CTOR MALLOC
# define MEMBER NOTNULL(1)

#endif

#endif /* FUNC_ATTRS_H */
