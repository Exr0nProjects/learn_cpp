check () {
        setopt LOCAL_OPTIONS NO_NOTIFY NO_MONITOR
        GEN_CMD="python3 gen.py"
        if [[ -f "gen.cpp" ]]
        then
                g++ --std=c++11 gen.cpp -o casegen
                GEN_CMD="./casegen"
        fi
        for ((i=1; ; i++)) do
                echo -en "\rtest case $i"
                eval ${GEN_CMD} > test.in
                ./auto < test.in > debug.diff &
                py answer.py < test.in > correct.diff &
                wait
                [[ -z "$(diff --brief *.diff)" ]] || break
        done
}

