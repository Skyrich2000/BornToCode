SET=$(seq 58 84)
for i in $SET
 do
    result=`expr $i + 7`
    mv "$i".xpm "$result".xpm
 done  
