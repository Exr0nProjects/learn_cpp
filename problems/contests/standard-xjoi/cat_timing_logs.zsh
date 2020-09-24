cat $(ls -Atd -- */ | head -n 9 | awk '{print $0 "timing_log.md"}') > weekly_tests.md

