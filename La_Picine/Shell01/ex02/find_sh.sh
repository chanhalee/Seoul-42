#!/bin/sh

find ./ -regex ".*\.sh$" -exec basename -s ".sh" "{}" \;
