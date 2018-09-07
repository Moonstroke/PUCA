#ifndef FUNC_ATTRS_H
#define FUNC_ATTRS_H



#ifdef __GNUC__
# define INLINE __attribute__((__always_inline__)) inline

# define NODISCARD __attribute__((__warn_unused_result__))

# define NOTNULL(...) __attribute__((__nonnull__(__VA_ARGS__)))

# define PURE __attribute__((__pure__,__warn_unused_result__))
# define CONST __attribute__((__const__,__warn_unused_result__))

# define MALLOC __attribute__((__malloc__,__warn_unused_result__))

#else /* __GNUC__ */

#define INLINE inline

#define NODISCARD

#define NOTNULL(...)

#define PURE
#define CONST

#define MALLOC

#endif

#endif /* FUNC_ATTRS_H */
