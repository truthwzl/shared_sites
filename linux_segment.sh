ps -w | grep sshd | grep -v grep | awk '{print $1}' to get sshd id
