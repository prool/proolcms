#/bin/sh
echo "No title" > tmp
mcedit tmp
echo "]title "`head -n1 tmp` > tmp2
echo "]date" `date +"%d-%b-%Y %H:%m %a"` >> tmp2
tail -n+2 tmp >> tmp2
echo " " >> tmp2
echo "]end" >> tmp2
cat tmp2 text.txt > tmp3
mv tmp3 text.txt
rm tmp2
rm tmp

