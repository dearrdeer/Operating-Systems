#!/bin/bash

ln file.txt file.lock

var=$(cat file.txt)
echo $((var+1)) > file.txt	