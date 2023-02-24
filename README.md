# The FUR Compiler

---

## What is it?

The FUR Compiler is a compiler built in C and assembly to compile my own programming language called FUR. This is just a personal project that I want to be capable of doing some small cool stuff.

## What I want it to do (TODO)

### What the program can do

- [] compile and run
- [] print "hello world"
- [] able to take user input
- [] capable of doing arithmetic 
- [] capable of creating a window
- [] capable of accessing a device's ports 
- [] read and write files 
- [] be able to assemble assembly and web assembly 
- [] be able to render xml and html code

### What OS can run 

- [] capable of running natively on MacOS, Windows, and Linux
- [] can be install via brew    
- [] can be build via CMake or Makefile
- [] have a gui app for basic info and interaction
- [] have a website for the compiler  

---

## Syntax 

    // read as 'define a function that returns a data_type named main that takes parameters such that - code logic - '
    def_fn -> data_type main( ...parameters):
    {
        // code ...
        return data_type
    }

    // Arrays and Sets
    array/lists/sets = [...elements]

    // While Loop 
    While (condition)
    {
        // code
    }

    // For Loop 
    for ( x in S; i in [0 ... len(S)])
    {
        // code
    }
    // or
    for (i in [0 ... n])
    {
        // code
    }

    // Booleans
    AND: && 
    OR: ||
    NOT: !

    // 
