---
title: C++自学笔记（2）
tags: A-技术笔记 C++
mathjax: true
mathjax_autoNumber: true
key: C++自学笔记（2）
sharing: true
typora-root-url: ..
---

> 因为平时经常遇到C++，以后的课程应该也免不了要用，学一下C++。
> 
> 参考用书：C++ Primer Plus(Sixth Edition)，作者：Stephen Prata

<!--more-->

This passage includes notes of Chapter 5,6 and 7. I'll try to be make it simple and easy to read. Most content of these chapters are familiar to people who has learnt C. Also, I'll only take down notes that are new or not familiar to me.

# Chpt 5. Loops and Relational Expressions

### `cout.setf()` function

Note that in `express.cpp`, we use `cout.setf(ios_base::boolalpha);`. This function call sets a flag that instructs `cout` to display the words `true` and `false` instead of `1` and `0`.

### For loop

C++ allows you to declare a variable in the initialization area of a `for` loop, which is not permitted in C:

``` cpp
for (int i = 0; i < 5; i++)
    ...
```

### Building a Time-Delay loop

In the `ctime` header file(or the `time.h` in traditional C), a function called `clock()` returns the system time elapsed **since a program started execution**. Note that `clock()` does not return the time in seconds, however, and the type of its return value might be `long`, `unsigned long` or others based on your system.

`ctime` header file provides solutions to these problems. First, It defines a symbolic constant, `CLOCKS_PER_SEC`, that equals the number of system time units per second. So dividing the system time by this value yields seconds. Or you can multiply seconds by `CLOCKS_PER_SEC` to get time in the system units.

Second, `ctime` establishes `clock_t` as an alias for the `clock()` return type. This means you can declare a variable as type `clock_t`, and the compiler cnverts it to `long` or `unsigned int` or whatever is the proper type for your system.

### Special Note on `cin` 

When reading type `char` values, just as when reading other basic types, `cin` skips over spaces and new line characters. You can refer to Listing 5.16 `textin1.cpp` to see this.

### The End-of-File(EOF) condition

When `cin` detects the EOF, it sets two bits(the *eofbit* and the *failbit*) to 1. You can use a member function named `eof()` to see whether the eofbit has been set; the call `cin.eof()` returns the `bool` value `true` or `false` based on whether EOF has been detected or not.

Similarly, the `fail()` member function returns `true` if either the eofbit or the failbit has been set to `1` and `false` otherwise.

Note that the `eof()` and `fail()` methods report the result of the most recent attempt to read; that is, they report on the past rather than look ahead. So a `cin.eof()` or `cin.fail()` test should always follow an attempt to read. You can refer to Listing 5.18 `textin3.cpp` for this.

### `bool` value of `cin`

The `istream` class provides a function that can convert an `istream` object such as `cin` to a `bool` value. This conversion function is called when `cin` occurs in a location where a `bool` is expected, such as in the test condition of a `while` loop.

# Chpt 6. Branching Statements and Logical Operators

### The `cctype` Library of Character Functions

The `cctype` header file(`ctype.h` in the older style) holds several functions that simplify such tasks as determining whether a character is an uppercase letter or a digit or punctuation. For example, the `isalpha(ch)` function returns a nonzero if `ch` is a letter and zero value otherwise. Similarly, the `ispunct(ch)` function returns a `true` value only if `ch` is a punctuation character, such as a comma or a period.

### Reading Mismatch Type into a Variable

Suppose you have the beneath lines in a program:

``` cpp
int n;
cin >> n;
```

If you enter, say, a word instead a number? Four things occur in such a mismatch:

- The value of `n` is left unchanged.
- The mismatched input is left in the input queue.
- An error flag is set in the `cin` object.
- The call to the `cin` method, if converted to type `bool`, returns `false`.

The fact that the method returns `false` means that you can use non-numeric input to terminate a number-reading loop. The fact that non-numeric input sats an error flag means that you have to reset the flag before the program can read more input. You can use the `clear()` method to reset the error flag, just use `cin.clear()`.

### Simple File I/O

File output is silimar to console output using `cout`. In file output:

- You must include the `fstream` header file.
- The `fstream` header file defines an `ofstream` class for handling output.
- You need to declare one or more `ofstream` variables, or objects, which you can name as you please, as long as you respect the usual naming conventions.
- You must account for the `std` namespace; for example, you can use the `using` directive or the `std::` prefix for elements such as `ofstream`.
- You need to associate a specific `ofstream` object with a specific file; one way to do so is to use the `open()` method.
- When you're finished with a file, you should use the `close()` method to close the file.
- You can use an `ofstream` object with the `<<` operator to output a variety of data types.

Note that although the `iostream` header file provides a predefined `ostream` object called `cout`, you have to declare your own `ofstream` object, choosing a name for it and associating it with a file. Here's how you declare such objects:

``` cpp
ofstream outFile;           // outFile an ofstream object
ofstream fout;           // fout an ofstream object
```

You may refer to Listing 6.15 `outfile.cpp` for usage of `ofstream` class.

Note that when you open an existing file for output, by default it is truncated to a length of zero bytes, so **the contents are lost**.

`ifstream` class is similarly designed. Note that `is_open()` method returns `true` if the file was successfully opened. You can use `is_open()` method to check whether a file was opened successfully:

``` cpp
ifstream inFile;
inFile.open("bowling.txt");
if (!inFile.is_open())
    exit(EXIT_FAILURE);
```

The `exit()` function is prototyped in the `cstdlib` header file, which also defines `EXIT_FAILURE` as an argument value used to communicate with the operating system. The `exit()` function terminates the program.

