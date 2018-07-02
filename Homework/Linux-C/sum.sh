# @Date     : 2018/07/02
# @Author   : IceCory (icecory520@gmail.com)
# @Copyright(C): GPL 3.0

sum=0
for val in $*
do
    sum=`expr $sum + $val`
done
echo $sum