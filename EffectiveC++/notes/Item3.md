# Use const whenever possible
- Use const to enforce that a particular object is not to be modified
- Allows invaraiance of that object

## Pointers and const:

~~~C++
    char *q;
    char *p = q; // non-const pointer, non-const data
    const char *p = q; // non-const pointer, const data
    char* const p = q; // const pointer, non-const data
    const char* const p = q; // const pointer, const data

    char *r;
    // non-const pointer => we can do p = r; 
    // non-const data => we can do *p = *r;

    // the following two are the exact same.
    const char* s;
    char const *s; 
~~~

- Use case in STL:
~~~C++
    std::vector<int> vec;

    const std::vector<int>::iterator iter = vec.begin(); // this is like T* const iter
    iter++; // not allowed
    *iter = 10; //allowed

    std::vector<int>::const_iterator c_iter = vec.begin(); // this is == const T* iter
    c_iter++; // allowed
    *c_iter = 10; // not allowed
~~~

- const member functions might not be really "const" - no modification of the member variables
  ~~~C++    
    class cTextBlock {
    public:
        char& operator[] (std::size_t position) const {
            return pText[position];
        }
    private:
        char *pText;
    };

    const cTextBlock cctb("Hello");
    char *pc = &cctb[0];

    *pc = 'J'; // the member variable is modified here! since operator[] returned a reference
    // So, although the object is const, the function is const, the member variable has changed.

  ~~~