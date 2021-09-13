cat /etc/passwd | grep -v '^#' | awk -F: 'NR>=2 {print $1}' | rev | sort -r | awk -v a=$FT_LINE1 -v b=$FT_LINE2 'NR>=a && NR<=b {print $0","}'| tr '\n' ' ' | sed 's/, $/./' | tr -d ' '
