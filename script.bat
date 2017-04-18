g++ -o p ASD_Z2\ASD_Z2.cpp

for /l %%n in (0,1,9) do (
	echo ****************** Test numer %%n ****************** 
	p.exe <./tests/stud%%n.txt >out.txt
	fc out.txt ./tests/stud%%n_out.txt
)
del p.exe
del out.txt
pause