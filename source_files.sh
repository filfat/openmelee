#!/bin/sh
find source -regex '.*\.\(c\|cpp\)$' -print
find libs -regex '.*/.*\.\(c\|cpp\)$' -print

find source -regex '.*\.\(h\)$' -print
find libs -regex '.*/.*\.\(h\)$' -print