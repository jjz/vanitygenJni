#!/usr/bin/env bash
cd vanitygen/
make clean
make
cd ..
make clean
make
javac VanitygenJni.java
java VanitygenJni
