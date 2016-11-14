CXXFLAGS = -std=c++11

# Add debug flags
CXXFLAGS += -g3 -ggdb3 -O0

# Enable UndefinedBehaviorSanitizer (undefined behavior detection)
# Not available with GCC 4.8.4
# CXXFLAGS += -fsanitize=undefined

# Enable -Wall warnings
#  (includes the following for C++ :
#       -Waddress                     (warn if a pointer/fonction is used in a comparaison,
#                                      example "void func(void); if (func) ..." ou "if (x == "abc") ...")
#       -Warray-bounds=1              (only with -O2 and above
#                                      warn if an array is always accessed out of bounds)
#       -Wbool-compare                (warn about boolean expression compared with an integer value different from true/false)
#       -Wc++11-compat                (warn about C++ constructs whose meaning differs between ISO C++ 1998 and ISO C++ 2011)
#       -Wc++14-compat                (warn about C++ constructs whose meaning differs between ISO C++ 2011 and ISO C++ 2014)
#       -Wchar-subscripts             (warn if an array index if of char type (signed on some hardware))
#       -Wcomment                     (warn if comments are oppend within a comment)
#       -Wenum-compare                (warn about a comparison between values of different enumerated types)
#       -Wformat                      (warn if calls to printf and scanf, etc., supplied arguments haven't appropriate types compaired
#                                      to the format string specified, and that the conversions specified in the format string make sense)
#       -Wlogical-not-parentheses     (warn about logical not used on the left hand side operand of a comparison)
#       -Wmaybe-uninitialized         (warn if a variable in not initialized in every possible scope it is used in)
#       -Wnonnull                     (warn about passing a null pointer for arguments marked as requiring a non-null value by the
#                                      nonnull function attribute)
#       -Wopenmp-simd                 (warn if the vectorizer cost model overrides the OpenMP or the Cilk Plus simd directive set by user)
#       -Wparentheses                 (warn if parentheses are omitted in certain contexts
#                                      example "x<=y<=z" is equivalent to "(x<=y ? 1 : 0) <= z")
#                                              which is a different interpretation from that of ordinary mathematical notation)
#       -Wpointer-sign                (warn for pointer argument passing or assignment with different signedness)
#       -Wreorder                     (warn if the compiler reorder variables initialisation. It occures when variables are
#                                      initialized in a different order than they are declared.
#                                      example : "struct A {
#                                                    int i;
#                                                    int j;
#                                                    A() : j(0), i(j) { }
#                                                 };"
#                                      i and j initialisation will be modified to "i(j), j(0)" and i will probably not initialized to 0.)
#       -Wreturn-type                 (warn whenever a function is defined with a return type that defaults to int)
#       -Wsequence-point              (warn about code that may have undefined semantics because of violations of sequence point rules
#                                      in the C and C++ standards
#                                      exemple : "a = a++;", "a[n] = b[n++]" or "a[i++] = i;")
#       -Wsign-compare                (warn when a comparison between signed and unsigned values could produce an incorrect result when
#                                      the signed value is converted to unsigned)
#       -Wstrict-aliasing             (this option is only active when -fstrict-aliasing is active)
#       -Wstrict-overflow=1           (this option is only active when -fstrict-aliasing is active)
#       -Wswitch                      (warn whenever a switch statement has an index of enumerated type and lacks a case for one or more of
#                                      the named codes of that enumeration (The presence of a default label prevents this warning))
#       -Wtrigraphs                   (warn if any trigraphs are encountered that might change the meaning of the program)
#       -Wuninitialized               (warn if an automatic variable is used without first being initialized)
#       -Wunknown-pragmas             (warn when a "#pragma" directive is encountered that is not understood by GCC)
#       -Wunused-but-set-variable     (warn whenever a local variable is assigned to, but otherwise unused (aside from its declaration))
#       -Wunused-function             (warn whenever a static function is declared but not defined or a non-inline static function is unused)
#       -Wunused-label                (warn whenever a label is declared but not used)
#       -Wunused-local-typedefs       (warn when a typedef locally defined in a function is not used)
#       -Wunused-value                (warn whenever a statement computes a result that is explicitly not used)
#       -Wunused-variable             (warn whenever a local variable or non-constant static variable is unused aside from its declaration)
#       -Wvolatile-register-var       (warn if a register variable is declared volatile)
#  )
CXXFLAGS += -Wall

# Set associated Werror separately to avoid errors on new warnings added in Wall in further gcc version
CXXFLAGS += -Werror=address
CXXFLAGS += -Werror=array-bounds
#CXXFLAGS += -Werror=bool-compare  # Not available with GCC 4.8.4
CXXFLAGS += -Werror=c++11-compat
CXXFLAGS += -Werror=char-subscripts
CXXFLAGS += -Werror=comment
CXXFLAGS += -Werror=enum-compare
CXXFLAGS += -Werror=format
#CXXFLAGS += -Werror=logical-not-parentheses  # Not available with GCC 4.8.4
CXXFLAGS += -Werror=maybe-uninitialized
CXXFLAGS += -Werror=nonnull
CXXFLAGS += -Werror=parentheses
CXXFLAGS += -Werror=pointer-sign
CXXFLAGS += -Werror=reorder
CXXFLAGS += -Werror=return-type
CXXFLAGS += -Werror=sequence-point
CXXFLAGS += -Werror=sign-compare
CXXFLAGS += -Werror=strict-aliasing
CXXFLAGS += -Werror=switch
CXXFLAGS += -Werror=trigraphs
CXXFLAGS += -Werror=uninitialized
CXXFLAGS += -Werror=unknown-pragmas
CXXFLAGS += -Werror=unused-but-set-variable
CXXFLAGS += -Werror=unused-function
CXXFLAGS += -Werror=unused-label
CXXFLAGS += -Werror=unused-local-typedefs
CXXFLAGS += -Werror=unused-value
CXXFLAGS += -Werror=unused-variable
CXXFLAGS += -Werror=volatile-register-var

# Enable -Wextra warnings
#  (includes the following for C++ :
#       -Wclobbered                   (warn for variables that might be changed by longjmp or vfork)
#       -Wempty-body                  (warn if an empty body occurs in an 'if', 'else' or 'do while' statement)
#       -Wignored-qualifiers          (warn if the return type of a function is a scalar types or void and has a type qualifier such as 'const')
#       -Wmissing-field-initializers  (warn if a structure's initializer has some fields missing)
#       -Wtype-limits                 (warn if a comparison is always true or always false due to the limited range of the data type)
#       -Wuninitialized               (warn if an automatic variable is used without first being initialized or if a variable may be clobbered by a setjmp call)
#       -Wunused-parameter            (warn whenever a function parameter is unused aside from its declaration)
#       -Wunused-but-set-parameter    (warn whenever a function parameter is assigned to, but otherwise unused)
#  )
CXXFLAGS += -Wextra

# Set associated Werror
CXXFLAGS += -Werror=clobbered
CXXFLAGS += -Werror=empty-body
CXXFLAGS += -Werror=ignored-qualifiers
CXXFLAGS += -Werror=missing-field-initializers
CXXFLAGS += -Werror=type-limits
CXXFLAGS += -Werror=uninitialized
CXXFLAGS += -Werror=unused-parameter
CXXFLAGS += -Werror=unused-but-set-parameter

# The option -Wextra also prints warning messages for the following cases:
# - A pointer is compared against integer zero with <, <=, >, or >=.
# - (C++ only) An enumerator and a non-enumerator both appear in a conditional expression.
# - (C++ only) Ambiguous virtual bases.
# - (C++ only) Subscripting an array that has been declared register.
# - (C++ only) Taking the address of a variable that has been declared register.
# - (C++ only) A base class is not initialized in a derived class's copy constructor.
CXXFLAGS += -Werror=extra

### Add even more warnings

# Warn whenever a pointer is cast such that the required alignment of the target is increased
# Example: char * => int * on machines where integers can only be accessed at two- or four-byte boundaries
CXXFLAGS += -Werror=cast-align

# Warn whenever a pointer is cast so as to remove a type qualifier from the target type, example : const char* => char*
CXXFLAGS += -Werror=cast-qual

# Warn for conditionally-supported (C++11 [intro.defs]) constructs.
#CXXFLAGS += -Werror=conditionally-supported  # Not available with GCC 4.8.4

# Warn for implicit conversions that may alter a value, example : int => uint
CXXFLAGS += -Werror=conversion

# Warn when a class seems unusable because all the constructors or destructors in that class are private, and it has neither friends nor public static member functions.
CXXFLAGS += -Werror=ctor-dtor-privacy

# Warn when a value of type float is implicitly promoted to double
CXXFLAGS += -Werror=double-promotion

# Check printf-like format so variable type matched the specified format
CXXFLAGS += -Wformat=2 -Werror=format-security

# Warn about uninitialized variables that are initialized with themselves, example : "int i = i;"
CXXFLAGS += -Werror=init-self

# Warn about suspicious uses of logical operators in expressions (&&, || instead of &, |)
CXXFLAGS += -Werror=logical-op

# Warn if a user-supplied include directory via "-I<include_dir>" does not exist
CXXFLAGS += -Werror=missing-include-dirs

# Warn if an old-style (C-style) cast to a non-void type is used within a C++ program.
CXXFLAGS += -Werror=old-style-cast

# Warn when a function declaration hides virtual functions from a base class.
CXXFLAGS += -Werror=overloaded-virtual

# Warn about anything that depends on the “size of” a function type or of void.
# In C++, warn also when an arithmetic operation involves NULL.
CXXFLAGS += -Werror=pointer-arith

# Warn if anything is declared more than once in the same scope, even in cases where multiple declaration is valid and changes nothing.
CXXFLAGS += -Werror=redundant-decls

# Warn whenever a local variable or type declaration shadows another variable, parameter, type, or class member (in C++), or
# whenever a built-in function is shadowed, example : "int class =1;"
CXXFLAGS += -Werror=shadow

# Warn for implicit conversions that may change the sign of an integer value, like assigning a signed integer
# expression to an unsigned integer variable. An explicit cast silences the warning
CXXFLAGS += -Werror=sign-conversion

# This option is only active when -fstack-protector is active.
# Warns about functions that are not protected against stack smashing.
CXXFLAGS += -Werror=stack-protector

# Warn about functions that might be candidates for attributes pure, const or noreturn
CXXFLAGS += -Werror=suggest-attribute=noreturn

# Warn about overriding virtual functions that are not marked with the override keyword.
# Note: suggest-final-types and suggest-final-methods are pointless with libraries
#CXXFLAGS += -Werror=suggest-override  # Not available with GCC 4.8.4

# Warn whenever a switch statement does not have a 'default' case
CXXFLAGS += -Werror=switch-default

# Warn whenever a switch statement has an index of enumerated type and lacks a case for one or more of the named codes of
# that enumeration
CXXFLAGS += -Werror=switch-enum

# Warn when an expression is casted to its own type.
CXXFLAGS += -Werror=useless-cast

# Warn when a literal '0' is used as null pointer constant. This can be useful to facilitate the conversion to nullptr in C++11.
CXXFLAGS += -Werror=zero-as-null-pointer-constant

# Gcc compiler enables many warning by default, convert them all to errors
CXXFLAGS += -Werror=attributes
CXXFLAGS += -Werror=conversion-null
CXXFLAGS += -Werror=coverage-mismatch
CXXFLAGS += -Werror=cpp
#CXXFLAGS += -Werror=delete-incomplete  # Not available with GCC 4.8.4
CXXFLAGS += -Werror=deprecated
CXXFLAGS += -Werror=deprecated-declarations
CXXFLAGS += -Werror=div-by-zero
CXXFLAGS += -Werror=free-nonheap-object
CXXFLAGS += -Werror=implicit-function-declaration
CXXFLAGS += -Werror=inherited-variadic-ctor
CXXFLAGS += -Werror=int-to-pointer-cast
CXXFLAGS += -Werror=invalid-memory-model
CXXFLAGS += -Werror=invalid-offsetof
CXXFLAGS += -Werror=main
CXXFLAGS += -Werror=mudflap
CXXFLAGS += -Werror=narrowing
CXXFLAGS += -Werror=non-template-friend
#CXXFLAGS += -Werror=normalized  # Not available with GCC 4.8.4
CXXFLAGS += -Werror=overflow
#CXXFLAGS += -Werror=poison-system-directories  # Not available with GCC 4.8.4
CXXFLAGS += -Werror=packed-bitfield-compat
CXXFLAGS += -Werror=pragmas
CXXFLAGS += -Werror=property-assign-default
CXXFLAGS += -Werror=protocol
CXXFLAGS += -Werror=pmf-conversions
CXXFLAGS += -Werror=pointer-to-int-cast
CXXFLAGS += -Werror=return-local-addr
#CXXFLAGS += -Werror=shift-count-negative  # Not available with GCC 4.8.4
#CXXFLAGS += -Werror=shift-count-overflow  # Not available with GCC 4.8.4
#CXXFLAGS += -Werror=sizeof-array-argument  # Not available with GCC 4.8.4
CXXFLAGS += -Werror=sync-nand
#CXXFLAGS += -Werror=switch-bool  # Not available with GCC 4.8.4
CXXFLAGS += -Werror=unused-result
CXXFLAGS += -Werror=varargs
CXXFLAGS += -Werror=virtual-move-assign
CXXFLAGS += -Werror=volatile-register-var
CXXFLAGS += -Werror=vla
CXXFLAGS += -Werror=write-strings
