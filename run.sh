#! /bin/bash
CXX=/c/MinGW/bin/g++.exe


for day in ./*/
do
    for file in ${day}*.cpp
    do
        name=${file%.*}

        exe=${name}.exe

        echo ${name}

        $CXX $file -o ${exe}
        ${exe} < ${name}
    done
done