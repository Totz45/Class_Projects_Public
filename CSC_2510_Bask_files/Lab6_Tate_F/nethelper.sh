#!/bin/bash

#reads in first argument which is a file
read_hosts() {
	hosts=$( cat $1 )
	count=1
	while read -r line
	do
		hosts_array[$count]=$line
		count=$(($count + 1))
	done <$1
}

#out of hosts listed in the file, user selects which one to use
pick_host() {
	count=1
	which_host=0
	for host in ${hosts_array[*]}
	do
		echo "$count $host"
		count=$(($count + 1))
	done
	while [[ $which_host -lt 1 || $which_host -ge $count ]]
	do
		read -p "Enter a number to select a host: " which_host
	done
}

read_hosts $1

while [[ $cmd != 'Q' && $cmd != 'q' ]]
do
	read -p "
	(N) for nslookup
	(P) for ping
	(S) for ssh
	(H) for hostname
	(I) for ifconfig
	(Q) for quit
	Select one of the above: " cmd
	case $cmd in
		[Nn])
			#nslookup option
			pick_host $1
			echo "nslookup ${hosts_array[$which_host]}"
			nslookup ${hosts_array[$which_host]}
			;;
		[Pp])
			#ping option
			pick_host $1
			echo "ping -c 1 ${hosts_array[$which_host]}"
			ping -c 1 ${hosts_array[$which_host]}
			;;
		[Ss])
			#ssh option
			read -p "Enter the server you want to use: " server
			read -p "What username should be used to login: " user
			ssh $user@$server
			;;
		[Hh])
			#hostname option
			hostname
			;;
		[Ii])
			#ifconfig option
			ifconfig -a
			;;
		[Qq])
			#quit option, terminates while loop for program
			;;
		*)
			#inform user that they enter an invalid option
			echo "That is not a valid option"
			;;
	esac
done
