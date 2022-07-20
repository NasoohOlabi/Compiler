
Program ArrayExample; {bbrebere}
var arr1 : array [ 1 .. 9 ] of Integer;
Var var1, var2 : Integer;



procedure MYPROD (x,y : integer);

Begin
    var1 := x + y
End;



function addFunc (a, b : integer) : integer;

Begin
    return a + b
End;


procedure ArrProcedure ( localArr : array [ 1 .. 9 ] of Integer );

Begin
    var1 := localArr[4]
End;



Begin



 arr1[4] := 5;

 var1 := arr1[4];


 if (var1 < 1) then 
    var1 := 100 
 else 
    var1 := 99999; 
    var1 := 99998
 endif;



 var1 := 1;

 var2 := 10;

 while (var1 < 3) DO

    var2 := var2 * 10;
    var1 := var1 + 1

 endwhile;

 ArrProcedure(arr1);

 var1 := addFunc(3,6);
 

 MYPROD(addFunc(3,6) , 6)

    
End