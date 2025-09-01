#!/bin/sh

pipenv --rm
git submodule update --remote --recursive || exit 1
#git submodule update --remote --merge --recursive || exit 1
pipenv install || exit 1

