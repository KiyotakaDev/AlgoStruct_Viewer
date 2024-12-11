# AlgoStruct Viewer

This project is a command-line program for visualizing algorithms and data structures written in C.

### Things Learned 

Here is what I learned while building this project:

1. **Makefile Variables**
    - I gained insights into how Makefile variables help organize and simplify build processes. 
    For instance, defining CC for the compiler and CFLAGS for compiler flags allowed me to 
    easily adjust configurations without editing every rule.
2. **Input Buffer Handling**
    - Handling input buffers is critical, it avoids unexpected behavior such as reading leftover data or buffer overflow
    and ensures consistent input handling in command-line programs.
3. **int \*foo[] != int \*\*foo**
    - Understanding the difference between these two notations was eye-opening:
        - **int \*foo[]:** An array of pointers to integers. (not dynamic unless you use dynamic memory for the array)
        - **int \*\*foo:** A pointer to a pointer to an integer. (It is fully dynamic)
4. **Funcion in a Struct**
    - Embedding function pointers within structs allowed for dynamic behavior in data structures.
    For example, I created a struct that could hold different action implementations and call them interchangeably.
    This approach is a precursor to object-oriented programming principles in C, enabling modular and reusable code.
