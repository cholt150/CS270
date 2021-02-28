#! /bin/bash

subdirname=$1
subdirname=${subdirname%.*}

if [ ! -d "${subdirname}.tmp" ] #check if the subdirectory does not exist
then
    mkdir "${subdirname}.tmp" #If it doesnt exist we are good
else
    mv "${subdirname}.tmp" "${subdirname}.tmp.RENAMED" #else we rename the original
    mkdir "${subdirname}.tmp"
fi

for arg in $@
do
    if [ -f "${subdirname}.tmp/$arg" ] #Check if the file already exists
    then
        echo "You are trying to copy a file ($arg) that already exists. What would you like to do?"
        echo "1) Overwrite"
        echo "2) Ignore"
        echo "3) Rename new file"
        echo "Choose 1, 2, or 3 and press return."

        read choice
        case choice in
            1) rm "${subdirname}.tmp/$arg";
                cp $arg "${subdirname}.tmp/$arg" || echo "Error copying $arg, check permissions." ;;
            2) ;;
            3) echo "Enter the new filename";
                read newname ;
                cp $arg "${subdirname}.tmp/$newname" || echo "Error copying $arg, check permissions." ;;
        esac
    else
        cp $arg "${subdirname}.tmp/$arg" || echo "Error copying $arg, check permissions."
    fi
done

tar -czf ${subdirname}.tar ${subdirname}.tmp
echo "Created archive as ${subdirname}.tar"
rm -r "${subdirname}.tmp" #Clean up temp dir
[ -d "${subdirname}.tmp.RENAMED" ] && mv "${subdirname}.tmp.RENAMED" "${subdirname}.tmp" #Clean up file renames