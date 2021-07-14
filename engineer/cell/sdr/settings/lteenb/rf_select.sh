#!/bin/bash

name="$1"
path=$(dirname "$0")
link="rf_driver"

function help
{
    cur=$(readlink "$path/$link")
    echo "Usage: $(basename $0)"
    echo -e "    <type>: " $(cd $path && find . -maxdepth 1 -type d | grep "./" | cut -d '/' -f2 | sort | sed -e "s/^${cur}$/\\\\033[32m${cur}\\\\033[0m/")
    exit 1
}

if [ "$name" = "" ] ; then
    help
fi

if [ ! -e "$path/$name" ] ; then
    echo "$name rf driver does not exist"
    help
    exit 1
fi

rm -f "$path/$link"
ln -s "$name" "$path/$link"

echo "RF frontend $name selected"

