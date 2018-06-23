sum=0
for val in $*
do
    sum=`expr $sum + $val`
done
echo $sum