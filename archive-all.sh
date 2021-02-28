#! /bin/bash

for file in *
do
    [ -d $file ] && tar -czf $file.tar.gz $file
done