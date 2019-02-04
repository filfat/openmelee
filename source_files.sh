#!/bin/sh
find source -regex '.*\.\(c\|cpp\|h\)$' -print
find libs -regex '.*/.*\.\(c\|cpp\|h\)$' -print