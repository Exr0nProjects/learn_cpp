#!/bin/bash
ls xjoi.net | grep -E "^x[0-9]{4}$" | sed 's/x//' > completed.txt
ls xjoi.net | grep -E "^[0-9]{4}$" > working.txt