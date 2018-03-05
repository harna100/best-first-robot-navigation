#!/bin/bash
# get how many iterations to do from command line
SUBDIR=./$1
COUNT=$2
mkdir ${SUBDIR}
CASES[0]=""
CASES[1]="Case1"
CASES[2]="Case2"
CASES[3]="Case3"
CASES[4]="Case4"
# iterate that many times
for (( i = 0; i < $COUNT; ++i )); do
	# make a directory for the current input
	mkdir ${SUBDIR}/${i}
	cd ${SUBDIR}/${i}
	# generate a grid
	CURR_FILE=sampleFile${i}.txt
	python ../../genGrid.py >> ${CURR_FILE}
	# run it for each case and redirect input into a file
	for (( j = 1; j < 5; ++j )); do
		../../main ${CURR_FILE} ${j} >> sampleFile${i}${CASES[$j]}.txt
	done
	# check the outputs? Find a map where 3&4 are different, need to hand check no paths found	

    cwd=$(pwd)
    python ../../checkCases.py ${cwd}
	cd ../..
done
