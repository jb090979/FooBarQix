#!/bin/bash
SCRIPT=$(readlink -f "$0")
SCRIPTPATH=$(dirname "$SCRIPT")
echo $SCRIPTPATH

find $SCRIPTPATH/src  -iname *.[hc]pp | xargs clang-format -i --style=file
find $SCRIPTPATH/test -iname *.[hc]pp | xargs clang-format -i --style=file

