#!/usr/bin/perl

my @lines=<>;

$_ = join('',@lines);

s/return\s+(\w+)/printf\("$1 "\);return $1/gi;

    print;
