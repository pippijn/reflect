#!/bin/sh

export MUDFLAP_OPTIONS=
export MUDFLAP_OPTIONS="$MUDFLAP_OPTIONS -heur-proc-map"
export MUDFLAP_OPTIONS="$MUDFLAP_OPTIONS -viol-segv"
#export MUDFLAP_OPTIONS="$MUDFLAP_OPTIONS -check-initialization"
#export MUDFLAP_OPTIONS="$MUDFLAP_OPTIONS -print-leaks"
export MUDFLAP_OPTIONS="$MUDFLAP_OPTIONS -wipe-stack"
export MUDFLAP_OPTIONS="$MUDFLAP_OPTIONS -wipe-heap"
