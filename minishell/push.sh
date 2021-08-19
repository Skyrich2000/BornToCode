C="\e[1;31m"
E="\e[0m"

function conform {
	while true
	do
		read -p "$1 [y/n] : " yn
		case $yn in
			[Yy] ) echo "1"; break;;
			[Nn] ) echo "0"; break;;
		esac
	done
}

printf "$C[SYNC] :: git pull$E\n"
cd ../../EuiminnCode
git remote -v
git pull

cd ../BornToCode/minishell
printf "$C[SYNC] :: copy Here to Euiminnn$E\n"
if [ $(conform "COPY?") -eq "1" ]; then
	ls | grep -v sh | xargs -I % cp -rf % ../../EuiminnCode/WIP/minishell/
	printf "$C[SYNC] :: copy done$E\n"
else
	printf "$C[SYNC] :: canceled $E\n"
fi
