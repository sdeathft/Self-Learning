# Inheritance

## Make sure public inheritance models "is-a"
* class D derived publicly from class B
  * Every object of type D is also of type B, but not vice versa
  * B represents a more general concept, and D, a more specialized concept
  * In place of using an object of type B, one can use type D (because it is also of type B), but not vice versa
* Public inheritance and is-a are not simply equivalent. Consider a `Bird` class and a `Penguin` class. 
  ```C++
    class Bird {
        virtual void fly();
    };

    class Penguin : public Bird {
        // ...
    };
  ```
  * This would be imprecise design, due to issues in English language.
  * A more correct design would be as follows:
  ```C++
    class Bird {};
    class FlyingBird : public Bird {
        virtual void fly();
    };
    class Penguin : public Bird {};
  ```
  * Another possible way is to generate a runtime error inside the fly function for penguin class(this would be recognized only at the runtime)

## Avoid hiding inherited names
* Hiding refers to the phenomenon where a variable in the local scope hides any variables with the same name in an outer scope.
* Consider the following classes:
```C++
    class Base {
        int x;
    public:
        virtual void mf1() = 0;
        virtual void mf2();
        void mf3();
    };

    class Derived: public Base {
    public:
        virtual void mf1();
        void mf4();
    };

    // suppose mf4 was defined as follows:
    void Derived::mf4() {
        mf2(); // this will call Base's mf2 after searching for it in the local scope, and derived class's scope.
    }
```
* Consider the following more complex case:
```C++
    class Base {
        int x;
    public:
        virtual void mf1() = 0;
        virtual void mf1(int);
        virtual void mf2();
        void mf3();
        void mf3(double);
    };

    class Derived : public Base {
    public:
        virtual void mf1(); // hides mf1 of Base class
        void mf3(); // hides mf3 class of Base
        void mf4();
    };
```
* See [here](../tests/inheritance.cpp) for more details.
  
## Differentiate b/w inheritance of Interface and inheritance of Implementation
* Possible ways of inhering a function:
  * [1] Only inherit the declaration
  * [2] Inherit the declaration and definition, without allowing to override
  * [3] Inherit the declaration and definition, with permission to override

Consider the following example:
~~~C++
    class Shape {
    public:
        virtual void draw() = 0; // just inherit the interface - [1]
        virtual void error(const std::string &msg); // inherit the definition as well, and allow to override - [3]
        int objectID() const; // inherit the definition as well, without permission to override - [2]
    };

    class Rectange : public Shape {};
    class Ellipse : public Shape {};
~~~

* Dangerous to allow simple virtual functions to specify both a declaration and a default implementation. Why? Consider the following example:
```C++
    class Airport {};

    class Airplane {
        virtual void fly(const Airport &destination);
    };

    void Airplane::fly(const Airport& destination) {
        // some default code implementing the function
    }

    class ModelA: public Airplane {};
    class ModelB: public Airplane {};

    // suppose another Model comes along, named Model C, which should be flown differently. So, the usual fly function won't work.
    // this could cause problems, if there is no "fly" function implemented in class ModelC.
    // The problem is that 'ModelC' is not forced to implement the fly function. Instead, it can fall back to the original base class' fly implementation if it wants.
```
* Solution to this problem:
```C++

    class Airplane {
    public:
        virtual void fly(const Airport& destination) = 0; // make it pure virtual
    protected:
        void defaultFly(const Airport& destination); // provide a default implementation as a protected method, moreover, this shouldn't be redefined in the derived classes. so, kept as a non-virtual function.
    };

    void Airplane::defaultFly(const Airport& destination) {
        // provide some default code here...
    }

    class ModelA: public Airplane {
        virtual void fly(const Airport& destination) {
            defaultFly(destination); // call the default implementation
        }
    };

    class ModelB: public Airplane {
        virtual void fly(const Airport& destination) {
            defaultFly(destination); // call the default implementation
        }
    };

    // model C is forced to implement the "fly" function, otherwise it won't compile. 
```

## Consider alternatives to virtual functions
Consider the following design:
```C++
    class GameCharacter {
    public:
        virtual int healthValue() const;
    };
```

* Alternative Designs:
### [1] Template method pattern(nothing to do with C++ templates) via the non-virtual interface idiom
```C++
    class GameCharacter {
    public:
        int healthValue() const { // non-virtual function, that the derived classes don't redefine
            // do "before" stuff here
            int retVal = doHealthValue();
            // do "after" stuff here
            return retVal;
        }
    private:
        virtual int doHealthValue() const; // virtual function, that the derived classes redefine
    };
```
See [here](../code-samples/nvi_idiom.cpp) for more details.

### Strategy Pattern via function pointers
* The idea is that since calculation of healthValue is the same for all characters, it shouldn't be a part of the character at all!
* We create a non-member function, and pass it as a pointer to the constructor to the character class.
```C++
    class GameCharacter {
    public:
        // define a function pointer type
        typedef int (*HealthCalcFunc)(const GameCharacter&);

        // pass this pointer to the constructor
        explicit GameCharacter(HealthCalcFunc hcf = defaultHealthCalc) : healthFunc(hcf) {}
        
        // use the pointer to calculate the value of health
        int healthValue() const { return healthFunc(*this); }
    private:
        HealthCalcFunc healthFunc;
    };
```
* Some interesting flexibilities:
  * Different instances of the same character type can have different health calculation functions.
  * Health calculation functions maybe changed at the run-time.
* Issues:
  * The calculation function cannot use the inner variables of the class.

### Strategy Pattern via functors
* Use functors instead of function pointers.
```C++
    #include <functional>

    class GameCharacter;
    int defaultHealthCalc(const GameCharacter &gc);

    class GameCharacter {
    public:
        // define a functor type
        typedef std::function<int (const GameCharacter&)> HealthCalcFunc;

        // pass this functor to the constructor
        explicit GameCharacter(HealthCalcFunc hcf = defaultHealthCalc) : healthFunc(hcf) {}
        
        // use the functor to calculate the value of health
        int healthValue() const { return healthFunc(*this); }
    private:
        HealthCalcFunc healthFunc;
    };
```

## Virtual functions in another hierarchy
Create a separate class for `HealthCalculation` and move all the virtual functions to that class. Then, inherit that class in the `GameCharacter` class.
```C++
    class HealthCalcFunc {
    public:
        virtual int calc(const GameCharacter& gc) const;
    };

    class GameCharacter {
    public:
        explicit GameCharacter(HealthCalcFunc hcf = defaultHealthCalc) : healthFunc(hcf) {}
        
        int healthValue() const { return healthFunc.calc(*this); }
    private:
        HealthCalcFunc healthFunc;
    };
```

# Never redefine an inherited non-virtual function
- If there is a need to do this in public inheritance, then the whole point of inheritance is lost. The "is-a" relationship becomes questionable.

# Never redefine a function's inherited default parameter value
- Let's look at only virtual functions, because as per the previous item, we wont be redefining non-virtual functions
- Consider the following example:
```C++

    class Shape {
    public:
        enum ShapeColor { Red, Green, Blue };
        virtual void draw(ShapeColor color = Red) const = 0;
    };

    class Rectangle {
    public:
        virtual void draw(ShapeColor color = Green) const;
    };

    Shape *pr = new Rectangle();
    pr -> draw(); // what color will be used? Red or Green?
```
- See [here](../code-samples/dont_redefine_inherited_default_values.cpp) for code.
- The problem is that the default parameter value is bound statically, at compile time, whereas the virtual function going to be used is bound dynamically. So, the default parameter value of the base class is used, not the derived class. This is because the compiler doesn't know which derived class is going to be used at run-time.
- Also, if the default value needs to be changed in the Shape class, it also needs to be changed in all the derived classes. This is a maintenance nightmare.

* How to avoid this? By using the alternative designs discussed earlier. 
* See [here](../code-samples/dont_redefine_inherited_default_values_alternative.cpp) for code.