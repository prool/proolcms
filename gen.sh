#/bin/sh
./cms gen
cat header > index.html
cat body >> index.html
echo Generated by ProolCMS `date +"%d-%b-%Y %H:%m %a"` "<hr>">> index.html
cat footer >> index.html
