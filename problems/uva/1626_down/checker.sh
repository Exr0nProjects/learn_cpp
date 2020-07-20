check () {
        setopt LOCAL_OPTIONS NO_NOTIFY NO_MONITOR
        GEN_CMD="python gen.py"
        if [[ -f "gen.cpp" ]]
        then
                g++ --std=c++11 gen.cpp -o casegen
                GEN_CMD="./casegen"
        fi
        for ((i=1; ; i++)) do
                echo -en "\rtest case $i"
                $GEN_CMD > test.in
                ./auto < test.in | awk '{ print length }' > debug.diff &
                ./answer < test.in | awk '{ print length }' > correct.diff &
                wait
                [[ -z "$(diff --brief *.diff)" ]] || break
        done
}

