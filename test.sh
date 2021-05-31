g++ Cl4_TP_ListaDeFechas.cpp -o Cl4_TP_ListaDeFechas.out
cat input | ./Cl4_TP_ListaDeFechas.out > output

DIFF=$(diff output expected)
if [ "$DIFF" != "" ]
then
    echo "Teste falló."

else
     echo "Teste pasó."
fi
