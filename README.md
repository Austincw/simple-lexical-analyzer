# simple-lexical-analyzer
A simple lexical analyzer created for a COMP 360 project following a particular EBNF grammar

This program was created by Eli Lewis, Zachary Solomon, and myself for a Programming Languages class project

The EBNF grammar this program follows is:
<program>     ->    <keyword> <funcname>(){<declare> <stmts>}
<keyword>     ->    float
<declare>     ->    float <ident>;
              |     float <ident>, <declarident>
<declarident> ->    <ident>, <declarident>
              |     <ident>;
<stmts>       ->    <assign>; <stmts>
              |     <assign>;
<assign>      ->    <ident> = <expr>
<expr>        ->    <ident> {+|-} <expr>
              |     <ident>
<funcname>    ->    <ident>
<ident>       ->    a<ident> | b<ident> |...| z<ident> | ε



