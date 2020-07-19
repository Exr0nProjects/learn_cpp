#!/bin/zsh

export ENVROOT=$(dirname "$(realpath -s "$0")")
tmux setenv ENVROOT $ENVROOT

#tmux setenv IDEMODE 0
#export IDEMODE=0
alias crt='cd $ENVROOT && source ./create.sh'
alias ans='g++ -std=c++11 answer*.cpp -o answer && ./answer && cat *.out'
#alias check='for (( i=1; ; i++ )); do py gen.py > test.in && ./auto < test.in > test.diff && ./answer < test.in > correct.diff && echo -en "\rtest case $i" && [[ -z "$(diff --brief *.diff)" ]] || break; done'
check () {
	setopt LOCAL_OPTIONS NO_NOTIFY NO_MONITOR

	GEN_CMD="python gen.py"
	if [[ -f "gen.cpp" ]]; then
		g++ --std=c++11 gen.cpp -o casegen
		GEN_CMD="./casegen"
	fi

	for (( i=1; ; i++)); do
		echo -en "\rtest case $i"
		$GEN_CMD > test.in							# TODO: generate in parallel with checking
		#echo "generated"
		#./auto < test.in > debug.diff && echo "    debug tested" &
		#./answer < test.in > correct.diff && echo "    correct tested" &
		./auto < test.in > debug.diff &
		./answer < test.in > correct.diff &
		wait
		#echo "tested"
		[[ -z "$(diff --brief *.diff)" ]] || break
		#echo "compared"
	done
}
alias clean='setopt +o nomatch && rm -f auto *.in *.out answer *.diff'

