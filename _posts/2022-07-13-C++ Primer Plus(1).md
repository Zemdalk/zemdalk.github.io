---
title: C++自学笔记（1）
tags: A-技术笔记 C++
mathjax: true
mathjax_autoNumber: true
key: C++自学笔记（1）
sharing: true
typora-root-url: ..
---

> 因为平时经常遇到C++，以后的课程应该也免不了要用，学一下C++。
> 
> 参考用书：C++ Primer Plus(Sixth Edition)，作者：Stephen Prata

<!--more-->

I have learned the programming language C already, thus I'll only take down new grammars and features in C++ in my notes.

Also, all the Chinese versions I've found are scanned version, but I find an English version which is not scanned. Therefore I'll just use the English version. A chance to practice my English, not bad!

# Chpt 1. Getting Started with C++

C++ is a superset of C. C++ joins 3 separate programming categories: **the procedural language, the object-oriented language and generic programming**.

### **C Programming Philosophy**

In general, computer languages deal with two cocepts--data and algorithms. Like most mainstream languages when C was created, C is a *procedural* language. That means is emphasizes the algorithm side of programming.

C includes features to facilitate *structured programming* approach, making it relatively easy to read and modify a program.

*Top-down* design was another feature of C. The idea is to break a large program into smaller, more manageable tasks. C uses programming unit called *functions* to implemente this idea.

### **The C++ Shift: Object-Oriented Programming**

Unlike procedural programming, which emphasizes algorithms, OOP emphasizes the data. The idea is to design data forms that correspond to the essential features of a problem.

In C++, a *class* is a specification describing such a new data form, and an *object* is a particular data structure constructed according to that plan.

The OOP approach to program design is to first design classes, then proceed to design a program using objects of those classes. This process of going from a lower level of organization(such as classes) to a higher level(such as program design) is called *bottom-up* programming.

There are other features of OOP such as information hiding, polymorphism, inheritance and etc.

### **C++ and Generic Programming**

The term *generic* refres to code that is type independent. Generic programming involves extending the language so that you can write a function for a generic type once and use it for a variety of actual types.

# Chpt 2. Setting Out to C++

### Namespaces

If you use `iostream` instead of `iostream.h`, you should use the following namespace directive to make the definitions in `iostream` available to your program:

```cpp
using namespace std;
```

This is called a *`using` directive*. Namespace support is a C++ feature that combines pre-existing code from several vendors and to help organize programs. One potential problem is that you might use two prepackaged products that both have a function called `wanda()`. The namespace facility lets a vendor pakcage its wares in a unit called a *namespace* so that you can use the name of a namespace to indecate which vendor's product you want. So Microflop Industries could place its definitions in a namespace called `Microflop`. Then `Microflop::wanda()` could denote Microflop's version of `wanda()`. Similarly, `Piscine::wanda()` could denote Piscine Corporation's version of `wanda()`.

Thus, you can omit the `using` directive and, instead, code in the following style:

```cpp
std::cout << "Come up and C++ me some time.";
std::cout << std::endl;
```

The following line means you can use names defined in the `std` namespace without using the `std::` prefix:

```cpp
using namespace std;
```

### C++ Output with `cout`

```cpp
cout << "Come up and C++ me some time."
```

The `<<` notation indicates that the statement is sending the string to `cout`; the symbols point the way the information flows. `cout` is a predefined object that knows how to display a variety of things, intcluding strings, numbers and individual characters. Thus, you can say that it inserts a string into the output stream.

### Using `cin`

``` cpp
cin >> carrots;
```

Just as C++ considers output to be a stream of characters flowing out of the program, it considers input to be a stream of characters flowing into the program.

# Chpt 3. Dealing with Data

### Naming Rules

One rule is worth noticing:

Names beginning with two underscore(_) characters or with an underscore character followed by an uppercase letter are reserved for use by the implementation--that is, the compiler and the resources it uses. Names beginning with a single underscore character are reserved for use as global identifiers by the implementation.

Using a name such as `__time_stop` or `_Donut` doesn't produce a compiler error; instead, it leads to undefined behavior. In other words, there's no telling what the result will be.

### The `sizeof` Operator and the `climits` Header File

You can apply the `sizeof` operator to a **type name** or to a **variable name**.

When you use the `sizeof` operator with a type name, such as `int`, you enclose the name in parentheses. But when you use the operator with the name of the variable, such as `n_short`, parentheses are optional.

The `climits` header file defines symbolic constants to represent type limits.

### Integer Literals

An integer literal, or constant, is one you write out explicitly, such as 212 or 1776. C++, like C, lets you write integers in three different number bases: base 10, base 8, and base 16.

C++ uses the first digit or two to identify the base of a number constant:

- 1-9: decimal(base 10)
- 0: octal(base 8)
- 0x or 0X: hexadecimal(base 16)

If you want to display a value in headecimal or octal form, you can use `cout` manipulators `dec`, `hex`, and `oct` to display integers in decimal, hexadecimal, and octal formats, respectively.

### `wchar_t`, `char16_t` and `char32_t`

The `wchar_t` type is an integer type with sufficient space to represent the largest extended character set used on the system. This type has the same size and sign properties as one of the other integer types, which is called the *underlying* type. The underlying type depends on the implementation.

Because the sign and size of `wchar_t` can vary from one implementation to another, C++11 introduces the types `char16_t`, which is unsigned and 16 bits, and `char32_t`, which is unsigned and 32 bits. C++11 uses the `u` prefix for `char16_t` character and string constants, like `u'C'` and `u"be good"`. Similarly, it uses the `U` prefix for `char32_t` constants, like `U'R'` and `U"dirty rat"`.

### A member function: `cout.put()`

The `cout.put()` function is the first example of an important C++ OOP concept, the *member function*. A member function belongs to a class and describes a method for manipulating class data. The `cout` is an object of class `ostream`. The class has a member function named `put()`. We can use the function with a particular object of the class, such as `cout` object.

To use a class member function with an object of that class, simply use a period to combine the object name(`cout`) with the function name(`put()`).

> We'll learn "Objects and Classes" in Chapter 10. Now the only classes we have encountered are `istream` and `ostream` classes.

### The `const` qualifier

C++ uses `const` to handle symbolic constants. For example, `const int Months = 12` initialized a constant named `Months` with value of 12.

### Writing Floating-Point Numbers

C++ has two ways of writing floating-point numbers. The first is the custom way, like `3.14159`. The second method is called E notation, which is like `3.14E-6`(= `0.00000314`). The -6 is called an *exponent*, and the 3.14 is termed the *mantissa*.(You can use both E or e in E notation)

### Floating-Point Constants

By default, floating-point constants such as 8.24 and 2.4E8 are type `double`. If we want a constant to be type `float`, we can use an `f` or `F` suffix. For type `long double`, we can use an `l` or `L` suffix.

### Conversion

When you try to combine mixed types, C++ converts all the concerned types to the same type.

C++ empowers us to force type conversions explicitly vis the *type cast* mechanism.

You can use `(typename) value` or `typename (value)` to complete type cast. The former is traditional C form of type cast, whereas the second form is pure C++. The idea behind the new form is to make a type cast look ike a function call. This makes type casts for the built-in types look like the type conversions you can design for user-defined classes.

C++ also introduces 4 type case operators that are more restrictive in bow they can be used. Ot the four, the `static_cast<>` operator, can be used for converting values from one numeric type to another. Usage: `static_cast<typename> value`. The idea behind is to be more restrictive than the traditional type cast.

### `auto` Declarations in C++11

C++11 introduces a facility that allows the compiler to deduce a type from the type of an initialization value. For this purpose it redefines the meaning of `auto`, a keyword dating back to C, but one hardly ever used.

``` cpp
auto n = 100;   // n is int
```

# Chpt 4. Compound Types

### Arrays

You can use a comma-separated list of values (the *initialization list*) enclosed in braces to initialize an array, like `int yamcosts[3] = {20, 30, 5};`. However, you can **only** use the initialization form when defining the array. You cannot use it later(~~`int hands[4]; hands[4] = {5, 6, 7, 9};`~~) and you cannot assign one array wholesale to another(~~`int cards[4] = {1, 2, 3, 4}; hands = cards;`~~).

You can let the compiler counter number of elements in an array while initializing:

```cpp
short things[] = {1, 5, 3, 8};
int num_elements = sizeof things / sizeof (short);
```

### C-style Strings 

C++ has two ways of dealing with strings. The first is *C-style string*, like `char name[4] = {'S', 'a', 'm', '\0'};`; the second is using C++ `string` class.

For C-style strings, you can just initialize it without denoting the number of characters:

```cpp
char fish[] = "Bubbles";    // let the compiler count
```

A tricky point about `cin` is that `cin` uses whitespace(spaces, tabs, and newlines) to delineate a string. This means that `cin` only reads one word when it gets input from a character array. The program [instr1.cpp](instr1.cpp) shows this.

To read input strings a line at a time instead of a word, you should use `istream`(`cin` is its object) class member functions `getline()` and `get()`. The difference is, after reading a line, `getline()` discards the newline character, whereas `get()` leaves it in the input queue.

`get(name, ArSize)` reads input characters from keyboard and stops when input reaches its end or input is longer than `ArSize`. Note that the character `'\n'` will be left in the inpiut queue.

A single `get()` reads one character a time. We can use it to absort the `'\n'` character left by the above function:

``` cpp
cin.get(name, ArSize);      // read first line
cin.get();                  // read newline
cin.get(dessert, ArSize);   // read second line
```

Another way to use `get()` is to *concatenate*, or join, two class member functions, as follows:

``` cpp
cin.get(name, ArSize).get();    // concatenate member functions
```

This is possible because `cin.get(name, ArSize)` returns the `cin` object.

### Use `string` Class

Just use 

```cpp
string str1;
```

to declare a string. We can also use `cin` and `cout` to assign or print the value of a string.

The `string` class makes it simpler for some operations to be done. For example, you can assign a string object directly to another. Also you can combine strings using the operator `+`. An advantage of using `string` class is that you don't have to worry about oversizing. `string` objects will automatically resize its size to fit in your input or your operation.

We can use member functions `size()` of `string` class to get the length of a string, which is equivalent to the `strlen()` function from the `<cstring>` header file(the older `<string.h>`).

We can use `getline(cin, stringname)` to get a string from the keyboard. Note that `cin` is an argument of the function, which indicates that this `getline()` function is not the member function method from `istream` class. It takes `cin` as an argument that tells it where to find the input. Also, there isn't an argument for the size of the string because the `string` object automatically resizes to fit the objects, as we've discussed above.

### Structure and Union

You've defined a strcture `inflatable`:

``` cpp
struct inflatable{
    char name[20];
    float volume;
    double price;
};
```

Then you can create variables of type `inflatable`:

```cpp
inflatable hat;
```

Notice that you don't have to write `struct` before structure name `inflatable`, which is required in C.

You can use `string` class members within structure definition. Just move the `using` directive before structure definition.

The usage and function of *union* in C++ is the same as is in C.

### Enumerations

*Enumeration* is defined as follows:

```cpp
enum spectrum {red, orange, yellow, green, blue, violet, indigo, ultraviolet};
```

It establishes `red`, `orange`, `yellow`, and so on, as symbolic constants for the integer values 0-7. These constants are called *enumerators*.

Notice that only assignment operator is defined for enumerations. In particular, arithmetic operations are not defined. However, enumerators can be automatically converted to `int` type, but `int` types are not converted automatically to the enumeration type:

```cpp
int color = blue;           // valid, spectrum type promoted to int
spectrum band;
band = 3;                   // invalid, int not converted to spectrum
color = 3 + red;            // valid, red converted to int
```

### Allocating Memory with `new`

In C, you can allocate memory with the library function `malloc()`. You can still so so in C++, but C++ provides a better way: the `new` operator.

```cpp
int *pn = new int;
```

The `new int` part tells the program you want some new storage suitable for holding an `int`. The `new` operator uses the type to figure out how many bytes are needed. Then it finds the memory and returns teh address.he

### Freeing memory with `delete`

You can free memory with `delete`:

```cpp
int *ps = new int;
...
delete ps;
```

### Use `new` to Create Dynamic Arrays

```cpp
int *psome = new int[10];
```

### Use `delete` to Free Dynamic Arrays

```cpp
delete [] psome;
```

### Pointer and Array

Array name denotes the address of the starting element of the array. We have that `pointername[i] == *(pointername + i)`. Thus, in many cases we can use pointer names and array names in the same way.

However, there are two major differences between pointer names and array names. The first one is that array name is a constant, so you cannot change it. But pointername is changeable:

```cpp
pointername = pointername + 1;      // valid
arrayname = arrayname + 1;          // not allowed
```

A second difference is that applying the `sizeof` operator to an array name yields the size of the array, even if the pointer points to an array. But applying the `sizeof` operator to array names produce the size of the array. For example:

```cpp
double wages[3] = {10000.0, 20000.0, 30000.0};
double *pw = wages;                 

cout << sizeof(wages) << " = size of wages array\n";
cout << sizeof(pw) << " = size of pw pointer\n";
```

Running result:

```
24 = size of wages array
4 = size of pw pointer
```

### Pointer and String

``` cpp
char animal[20] = "bear";           // animal holds bear
char *ps = animal;
cout << animal << " at " << (int *) animal << endl;
cout << ps << " at " << (int *) ps << endl;
```

Output:

``` 
bear at 0x61fdf0
bear at 0x61fdf0
```

Normally, if you give `cout` a pointer, it prints an address. But if the pointer is type `char *`, `cout` displays the pointer-to string. If you want to see the address of the string, you have to type cast the pointer to another pointer type, such as `int *`, as the example above shows.

### The `vector` Template Class

The `vector` template class is similiar to the `string` class in that it is a dynamic array. Basically, it's an alternative to using `new` to create a dynamic array.

We'll pay attention to 5 aspects of the `vector` class: 

1. To use a `vector` class, you need to include the `vector` header file.
2. The `vector` identifier is part of the `std` namespace, so you can use a `using` directive, a `using` declaration, or `std::vector`.
3. Templates use a different syntax to indicate the type of data stored.
4. The `vector` class uses a different syntax to indicate the number of elements.

```cpp
using namespace std;
vector<int> vi;         // create a zero-size array of int
int n;
cin >> n;
vector<double> vd(n);   // create an array of n doubles
```

### The `array` Template Class (C++11)

Compared to `vector`, the built-in array type is a bit more efficient, but it comes at a cost of leesened convenience and safety. To solve this problem, C++11 adds the `array` template class. To create an `array` object, you need to include the `array` header file. Also it is in namespace `std`.

``` cpp
#include <array>
...
using namespace std;
array<int, 5> ai;           // create array object of 5 ints
array<double, 4> ad = {1.2, 2.1, 3.43, 4.3};
```

