make

# make 결과가 0이면(정상)
if [ ${?} = 0 ]; then
    echo "Compile Success"
    echo "Execution Result"
    echo "===================="
    ./runfile | c++filt -t
else
    echo "Compile Error, so not executed"
fi