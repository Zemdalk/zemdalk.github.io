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

Also, all the Chinese version I've found are scanned version. Therefore I'll just use the English version. A chance to practice my English, not bad!

# Chpt 1. Getting Started with C++

C++ is a superset of C. C++ joins 3 separate programming categories: **the procedural language, the object-oriented language and generic programming**.

## **C Programming Philosophy**

In general, computer languages deal with two cocepts--data and algorithms. Like most mainstream languages when C was created, C is a *procedural* language. That means is emphasizes the algorithm side of programming.

C includes features to facilitate *structured programming* approach, making it relatively easy to read and modify a program.

*Top-down* design was another feature of C. The idea is to break a large program into smaller, more manageable tasks. C uses programming unit called *functions* to implemente this idea.

## **The C++ Shift: Object-Oriented Programming**

Unlike procedural programming, which emphasizes algorithms, OOP emphasizes the data. The idea is to design data forms that correspond to the essential features of a problem.

In C++, a *class* is a specification describing such a new data form, and an *object* is a particular data structure constructed according to that plan.

The OOP approach to program design is to first design classes, then proceed to design a program using objects of those classes. This process of going from a lower level of organization(such as classes) to a higher level(such as program design) is called *bottom-up* programming.

There are other features of OOP such as information hiding, polymorphism, inheritance and etc.

## **C++ and Generic Programming**

The term *generic* refres to code that is type independent. Generic programming involves extending the language so that you can write a function for a generic type once and use it for a variety of actual types.

# Chpt 2. Setting Out to C++

## Namespaces

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

## C++ Output with `cout`

```cpp
cout << "Come up and C++ me some time."
```

The `<<` notation indicates that the statement is sending the string to `cout`; the symbols point the way the information flows. `cout` is a predefined object that knows how to display a variety of things, intcluding strings, numbers and individual characters. Thus, you can say that it inserts a string into the output stream.

## Using `cin`

``` cpp
cin >> carrots;
```

Just as C++ considers output to be a stream of characters flowing out of the program, it considers input to be a stream of characters flowing into the program.

# Chpt 3. Dealing with Data

## Naming Rules

One rule is worth noticing:

Names beginning with two underscore(_) characters or with an underscore character followed by an uppercase letter are reserved for use by the implementation--that is, the compiler and the resources it uses. Names beginning with a single underscore character are reserved for use as global identifiers by the implementation.

Using a name such as `__time_stop` or `_Donut` doesn't produce a compiler error; instead, it leads to undefined behavior. In other words, there's no telling what the result will be.

## The `sizeof` Operator and the `climits` Header File

You can apply the `sizeof` operator to a **type name** or to a **variable name**.

When you use the `sizeof` operator with a type name, such as `int`, you enclose the name in parentheses. But when you use the operator with the name of the variable, such as `n_short`, parentheses are optional.

The `climits` header file defines symbolic constants to represent type limits.

## Integer Literals

An integer literal, or constant, is one you write out explicitly, such as 212 or 1776. C++, like C, lets you write integers in three different number bases: base 10, base 8, and base 16.

C++ uses the first digit or two to identify the base of a number constant:

- 1-9: decimal(base 10)
- 0: octal(base 8)
- 0x or 0X: hexadecimal(base 16)

If you want to display a value in headecimal or octal form, you can use `cout` manipulators `dec`, `hex`, and `oct` to display integers in decimal, hexadecimal, and octal formats, respectively.

## `wchar_t`, `char16_t` and `char32_t`

The `wchar_t` type is an integer type with sufficient space to represent the largest extended character set used on the system. This type has the same size and sign properties as one of the other integer types, which is called the *underlying* type. The underlying type depends on the implementation.

Because the sign and size of `wchar_t` can vary from one implementation to another, C++11 introduces the types `char16_t`, which is unsigned and 16 bits, and `char32_t`, which is unsigned and 32 bits. C++11 uses the `u` prefix for `char16_t` character and string constants, like `u'C'` and `u"be good"`. Similarly, it uses the `U` prefix for `char32_t` constants, like `U'R'` and `U"dirty rat"`.

## A member function: `cout.put()`

The `cout.put()` function is the first example of an important C++ OOP concept, the *member function*. A member function belongs to a class and describes a method for manipulating class data. The `cout` is an object of class `ostream`. The class has a member function named `put()`. We can use the function with a particular object of the class, such as `cout` object.

To use a class member function with an object of that class, simply use a period to combine the object name(`cout`) with the function name(`put()`).

> We'll learn "Objects and Classes" in Chapter 10. Now the only classes we have encountered are `istream` and `ostream` classes.

## The `const` qualifier

C++ uses `const` to handle symbolic constants. For example, `const int Months = 12` initialized a constant named `Months` with value of 12.

## Writing Floating-Point Numbers

C++ has two ways of writing floating-point numbers. The first is the custom way, like `3.14159`. The second method is called E notation, which is like `3.14E-6`(= `0.00000314`). The -6 is called an *exponent*, and the 3.14 is termed the *mantissa*.(You can use both E or e in E notation)

## Floating-Point Constants

By default, floating-point constants such as 8.24 and 2.4E8 are type `double`. If we want a constant to be type `float`, we can use an `f` or `F` suffix. For type `long double`, we can use an `l` or `L` suffix.

## Conversion

When you try to combine mixed types, C++ converts all the concerned types to the same type.

C++ empowers us to force type conversions explicitly vis the *type cast* mechanism.

You can use `(typename) value` or `typename (value)` to complete type cast. The former is traditional C form of type cast, whereas the second form is pure C++. The idea behind the new form is to make a type cast look ike a function call. This makes type casts for the built-in types look like the type conversions you can design for user-defined classes.

C++ also introduces 4 type case operators that are more restrictive in bow they can be used. Ot the four, the `static_cast<>` operator, can be used for converting values from one numeric type to another. Usage: `static_cast<typename> value`. The idea behind is to be more restrictive than the traditional type cast.

## `auto` Declarations in C++11

C++11 introduces a facility that allows the compiler to deduce a type from the type of an initialization value. For this purpose it redefines the meaning of `auto`, a keyword dating back to C, but one hardly ever used.

``` cpp
auto n = 100;   // n is int
```