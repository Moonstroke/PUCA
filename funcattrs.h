#ifndef FUNC_ATTRS_H
#define FUNC_ATTRS_H



#ifdef __GNUC__
# define INLINE __attribute__((__always_inline__)) inline

# define NOTNULL(...) __attribute__((__nonnull__(__VA_ARGS__)))

# define PURE __attribute__((__pure__))
# define CONST __attribute__((__const__))

#else /* __GNUC__ */

#define INLINE inline

#define NOTNULL(...)

#define PURE
#define CONST

#endif

#endif /* FUNC_ATTRS_H */
