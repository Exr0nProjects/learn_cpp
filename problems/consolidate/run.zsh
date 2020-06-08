#!/bin/zsh

CONTEXT=0
DIR='..'
OUTDIR=$(pwd)

echo "Exporting to... $OUTDIR"

cd $DIR
pwd

awk '{$1=$1}1' =(ack --nogroup -C $CONTEXT --ignore-file=match:'/x/' --ignore-file=ext:html,md,js,css '\bFIX') > $OUTDIR/out.txt

cat $OUTDIR/out.txt

#ack -f --type=cpp --ignore-file=match:/x.+/ $DIR > searchfiles.txt

