#!/usr/bin/env bash

msg=`git status --short | sed -nr 's/ M "([0-9]{3}).*$/#\1/p' | paste -s -d','`
[ -n $msg ] && (
    git add .
    git commit -m "$msg"
    git push
)

