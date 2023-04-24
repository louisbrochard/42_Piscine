#!/bin/sh
cat /etc/passwd | sed 's/:.*//' | grep -v "#" | sed 1~2d | rev | sort -r | tail -n $FT_LINE1 | head -n $((FT_LINE2-FT_LINE1)) | sed -z "s/\n/, /g" | sed "s/..$/./"
