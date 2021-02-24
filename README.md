# Lexical-Analyzer-in-C++
A simple implementation of a lexical analyzer in C++ for a UNI homework.
The lexical analyzer reads the characters from source code and convert it into tokens.

Different tokens or lexemes are:

Keywords
Identifiers
Operators
Constants
Take below example.

c = a + b;

After lexical analysis a symbol table is generated as given below.

Token	Type
c	identifier
=	operator
a	identifier
+	operator
b	identifier
;	separator
