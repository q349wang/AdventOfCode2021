#! /bin/bash
CXX=/c/MinGW/bin/g++.exe

if [ -n "$1" ]
    then

        for file in ./day${1}/*.cpp
        do
            name=${file%.*}

            exe=${name}.exe

            echo ${name}

            time $CXX $file -o ${exe} -O2
            time ${exe} < ${name}
        done
    exit 0
fi


for day in ./*/
do
    for file in ${day}*.cpp
    do
        name=${file%.*}

        exe=${name}.exe

        echo ${name}

        time $CXX $file -o ${exe} -O2
        time ${exe} < ${name}
    done
done