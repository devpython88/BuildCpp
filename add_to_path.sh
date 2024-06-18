FILE="/path/to/your/file.txt"

if [ -e "$FILE" ]; then
    sudo rm /usr/bin/BuildCpp
    sudo cp BuildCpp /usr/bin
else
    sudo cp BuildCpp /usr/bin

fi