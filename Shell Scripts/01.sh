#!/bin/bash

ret=$(ls -Rl /dev | grep ^b | wc -l)
echo The total no. of block device files is: $ret
