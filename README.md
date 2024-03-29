# Table of Contents
* [Description](https://github.com/alecksandr26/trycatch-c#try-catch-c-tc-c)
* [How to install it?](https://github.com/alecksandr26/trycatch-c#how-to-install-it-)
    * [Using yay](https://github.com/alecksandr26/trycatch-c#using-yay)
    * [Using make](https://github.com/alecksandr26/trycatch-c#using-make)
* [Getting started](https://github.com/alecksandr26/trycatch-c#getting-started)
* [Video example](https://github.com/alecksandr26/trycatch-c?tab=readme-ov-file#video-example)
* [References](https://github.com/alecksandr26/trycatch-c#references)

# Try Catch C (trycatch-c)
This module offers a straightforward macro interface that facilitates seamless exception handling in the C programming language, drawing inspiration from the paradigm employed in C++.

# How to install it ?
## Using `yay`
1. Open a terminal window and ensure that you have yay installed on your system.
2. Run the command `yay -S trycatch-c` to search for and install the package from the [AUR (Arch User Repository)](https://aur.archlinux.org/packages/trycatch-c).

## Using `make`
1. Download the source code for the `trycatch-c` package from [releases](https://github.com/alecksandr26/trycatch-c/archive/refs/tags/v1.2.0.tar.gz)
2. Extract the contents of the downloaded archive to a directory of your choice.
3. Open a terminal window and navigate to the directory where you extracted the source code.
4. Run the command `make pkg` to build a `x86_64.pkg.tar.zst` package.
5. Then just install the pacakge.

# Getting started
1. Install the [trycatc-c](https://github.com/alecksandr26/tc-c#how-to-install-it-) library on your system.
2. Include the trycatch.h header file in your C source code file using the following statement:
```c
#include <trycatch.h>
```
3. Define your exceptions using the `Except` type, as demonstrated in the following example:
```c
Except someError = {"Some error"};
```
In this instance, `someError` represents an exception of the `Except` type, accompanied by the message "Some error."
Alternatively, you can leverage the ***general-purpose exceptions*** already defined in the [trycatch/exceptions.h](https://github.com/alecksandr26/trycatch-c/blob/main/include/trycatch/exceptions.h) header file, 
depending on your specific requirements.
```c
#define E Except

// User exceptions  
extern E ExceptLogicalError;
extern E ExceptInvalidArgument;
extern E ExceptDomainError;
extern E ExceptLengthError;
extern E ExceptOutOfRange;

// System error exceptions
extern E ExceptRuntimeError;
extern E ExceptRangeError;
extern E ExceptOverflowError;
extern E ExceptSystemError;
extern E ExceptFileSystemError;
extern E ExceptSocketSystemError;
extern E ExceptReadSystemError;
extern E ExceptWriteSystemError;

// Memory exceptions
extern E ExceptBadAlloc;
extern E ExceptBadArrayNewLength;
extern E ExceptBadPtr;

#undef E
```

4. Use the try, throw, and except macros to handle exceptions in your code. Here is an example code snippet:
```c
try {
    throw(someError); // <--- throw the exception of someError
} catch(someError) {
    puts("Exception caught!");
} endtry;
```
This code snippet attempts to raise the someError exception using the throw macro. If the exception is raised, the except macro will catch it and execute the code block following it. 
In this case, the code block simply prints a message to the console.
Additionally, you have the option to include a ***message*** when raising an exception to provide supplementary information about the error:
```c
try {
    throw(someError, "This is a message"); // <--- Adding an message
} catch(someError) {
    puts("Exception caught!");
} endtry;
```
This modification allows you to add a descriptive message when throwing the `someError` exception, enhancing the contextual 
information available during exception handling and debugging.

5. Compile your code with ***the -ltc flag*** to link against the ***trycatch-c library***. For example:
```
cc mycode.c -ltc
```
## Video example


https://github.com/alecksandr26/trycatch-c/assets/66882463/ee33dac7-a704-4754-bc77-ba561a93a301




# References
1. Mark. (2023). How setjmp and longjmp work. Offlinemark. https://offlinemark.com/2016/02/09/lets-understand-setjmp-longjmp/
2. Hanson, D. (1996). C Interfaces and Implementations: Techniques for Creating Reusable Software.
