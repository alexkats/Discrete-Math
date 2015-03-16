for ((i = 0; i < 3; i++))
do
    echo
done

declare -a array
((size = 0))

while read line
do
    array[size]=$line
    ((size++))
done < testing

declare -i tests
tests=${array[1]}
language=${array[3]}
name=${array[5]}
((lang = 1))

if ((lang < 1))
then
    if [ -f $name ]
    then
        rm $name
    fi
else
    if [ -f $name"*.class" ]
    then
        rm *.class
    fi
fi

if [ $language == "C++" ]
then
    ((lang = 0))
fi

if ((lang < 1))
then
    if ! g++ -o2 -Wall $name".cpp" -o $name
    then
        echo "Your program hasn't compiled!"
        exit
    fi
else
    if ! javac $name".java"
    then
        echo "Your program hasn't compiled!"
        exit
    fi
fi

if ! javac StartCheck.java
then
    echo "Checker hasn't compiled!"
    
    if ((lang < 1))
    then
        rm $name
    fi

    rm *.class
    exit
fi

((q = 0))
echo "Compilation is OK! Testing now!"
echo

for ((i = 1; i <= tests; i++))
do
    str="$i"

    if ((i < 10))
    then
        str=0$str
    fi

    cp Tests/$str ./
    mv $str $name".in"

    if ((lang < 1))
    then
        ./$name
    else
        java $name
    fi

    rm $name".in"
    cp Tests/$str".a" ./
    mv $str".a" $name".a"
    java StartCheck
    rm $name".a"
    echo -n "Test $i:"

    if ! [ -f WA ]
    then
        if ! [ -f TL ]
        then
            echo -n " OK"

            if [ -f time ]
            then
                while read line
                do
                    echo "; Time: $line s"
                done < time
            else
                echo
            fi

            ((q++))
            continue
        else
            echo -n " Time limit exceeded"

            if [ -f time ]
            then
                while read line
                do
                    echo "; Time: $line s"
                done < time
            else
                echo
            fi

            rm TL

            if [ ${array[9]} == "Yes" ]
            then
                continue
            else
                rm StartCheck*.class
                cp Tests/$str ./
                mv $str $name".in"

                if [ -f time ]
                then
                    rm time
                fi

                for ((j = 0; j < 3; j++))
                do
                    echo
                done

                exit
            fi
        fi
    else
        echo -n " Wrong answer"

        if [ -f time ]
        then
            while read line
            do
                echo "; Time $line s"
            done < time
        else
            echo
        fi

        rm WA

        if [ -f TL ]
        then
            rm TL
        fi

        if [ ${array[9]} == "Yes" ]
        then
            continue
        else
            rm StartCheck*.class
            cp Tests/$str ./
            mv $str $name".in"

            if [ -f time ]
            then
                rm time
            fi

            for ((j = 0; j < 3; j++))
            do
                echo
            done

            exit
        fi
    fi
done

rm *.class

if ((lang < 1))
then
    rm $name
fi

rm $name".out"

if [ -f time ]
then
    rm time
fi

echo
word="test"

if ((q != 1))
then
    word=$word"s"
fi

echo "$q $word out of $tests passed!"

for ((i = 0; i < 3; i++))
do
    echo
done
