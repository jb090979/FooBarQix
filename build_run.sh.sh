#!/bin/bash
SCRIPT=$(readlink -f "$0")
SCRIPTPATH=$(dirname "$SCRIPT")
echo $SCRIPTPATH

pushd $SCRIPTPATH/build
cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"
make all
printf "\n\nexecute FooBarQix\n"
./src/FooBarQix_run


printf "\n\nexecute unit tests\n"
./test/FooBarQix_test

popd

