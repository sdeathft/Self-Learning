# Prefer consts, enums and inlines to #defines

- `#define` is a preprocessor directive. So, even before compilation, all the variables will be replaced by their values.
- So, the variable may not be entered in the `symbol table` that the compiler maintains.
- Issues?
  - If we get an error involving the constant, then error message will refer to the value, and not the variable name, which makes it confusing
  - For eg., `#define ASPECT_RATIO 1.653`, if there is an error involving 1.653, the compiler might not indicate it as ASPECT_RATIO
- Replacement?
  - Use `const`. Eg: `const double ASPECT_RATIO = 1.653;`
  - Gets into the symbol table
  - Make sure the pointers are constant while declaring in header files: `const T* [const] ptr`
- Other use cases:
  - Class specific constants:
    - If a constant needs to be a part of the class, we can make it a member variable.
    - But, this will lead to one copy per object. To avoid this, we can make it a static variable.
    ~~~C++
        class GamePlayer {
        private:
            static const int num_turns = 5; // const static variable, shared among objects
        }
        // To use in a source file, define it with no value - Why? const vars must be given values where they are declared.
        const int GamePlayer::num_turns; 
    ~~~
    - Unlike const variables, #define doesn't have any scope.
  - Enum hack:
    - If we need the constant to be available at compile time, then we can declare it as an enum
    ~~~C++
        class GamePlayer {
        private:
            enum {num_turns = 5};
            int scores[num_turns];
        }
    ~~~
    - Similar to #defines, enums doesn't allow to take a pointer (or) reference to it. But, const does.
  - Avoid using macro defined functions:
    - Consider the following:
    ~~~C++
        #define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))
        
        int a = 5, b = 0;
        CALL_WITH_MAX(++a, b); // this increases the value of a twice, because each occurrence of (a) is replaced with ++a, which is called twice.

        // At this point, a = 7, b = 0, which is not desirable.
    ~~~
    - Instead, use inline functions with templates:
    ~~~C++
        template <typename T> 
        inline void callWithMax(const T &a, const T &b) {
            f(a > b ? a : b);
        }
    ~~~
    - It gives the benefit of functions, obeying scope and access rules