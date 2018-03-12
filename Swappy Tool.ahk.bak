#NoEnv
#SingleInstance force
SendMode Input

Grid := []
PositionsX := []
PositionsY := []
Colors := []
Colors[0xF2E1DA] := -1
Colors[0xEF9A9A] := 1
Colors[0xCE93D8] := 2
Colors[0x90CAF9] := 3
Colors[0xC5E1A5] := 4
Colors[0xFFDC73] := 5
Colors[0xBBACE8] := 6
Colors[0xDEA58A] := 7
Colors[0x8ADECA] := 8
Colors[0x8AB7DE] := 9
Colors[0xFFDD41] := 10
lastmin := 1
a := 0

while (A_Index<=4, y:=A_Index-1)
	while (A_Index<=4, x:=A_Index-1){
		Grid[y,x] := "0xFFFFFF"
		PositionsX[x] := 1000
		PositionsY[y] := 1000
	}


!a::
MouseGetPos X, Y
PositionsX[a] := X
PositionsY[a] := Y
a := a + 1
return

!s::
GetValues(Grid, PositionsX, PositionsY, Colors, lastmin)
MsgBox, % getText(Grid)
return

!x::
next := MakeNextMove(Grid, PositionsX, PositionsY, Colors, lastmin)
return

!z::
next := "callback"
while(1){
	next := MakeNextMove(Grid, PositionsX, PositionsY, Colors, lastmin)
	if (next != "clicked")
		break
	Sleep, 3000
}
return

; FUNCTIONS



MakeNextMove(Grid, PositionsX, PositionsY, Colors, ByRef lastmin){
biggest := 1
if(GetValues(Grid, PositionsX, PositionsY, Colors, lastmin)="stopped"){
	MsgBox, Coś się skisiło...
	return "error"
}

FileDelete, plansza.txt
FileAppend, % getText(Grid), plansza.txt
if(!FileExist("Swapper.exe")){
	MsgBox, Brakuje skompilowanego programu o nazwie "Swapper.exe".`nZatrzymano...
	;return "error"
}
RunWait, Swapper.exe, A_WorkingDir, Hide
if(!FileExist("ruch.txt")){
	MsgBox, Brakuje pliku tekstowego o nazwie "ruch.txt".`nZatrzymano...
	;return "error"
}
FileRead, nextMove, ruch.txt
;MsgBox, % nextMove

i := 1
m := 0
n := 0
x := 0
o := 0
while(i <= StrLen(nextMove)){
	c := SubStr(nextMove, i, 1)
	i := i + 1
	if(c != "o" && c != "x"){
		continue
	}
	if(c = "x"){
		x := x + 1
		if(x > 2){
			break
		}
		MouseMove, PositionsX[m], PositionsY[n]
		MouseClick, left
	}
	else{
		o := o + 1
		if(o > 14){
			break
		}
	}
	m := m + 1
	if(m >= 4){
		m := 0
		n := n + 1
	}
}
if(x != 2 || o != 14){
	MsgBox, Zawartość pliku "ruch.txt" jest w złym formacie.`n(To powiadomienie oznacza, że jest zła ilość "x" lub "o")`nZatrzymano...
	return "error"
}
return "clicked"
}

getText(Array){
text := % Array[0,0]	"`t"	Array[0,1]	"`t"	Array[0,2]	"`t"	Array[0,3]	"`n"
        . Array[1,0]	"`t"	Array[1,1]	"`t"	Array[1,2]	"`t"	Array[1,3]	"`n"
        . Array[2,0]	"`t"	Array[2,1]	"`t"	Array[2,2]	"`t"	Array[2,3]	"`n"
        . Array[3,0]	"`t"	Array[3,1]	"`t"	Array[3,2]	"`t"	Array[3,3]
return text
}

GetValues(ByRef Grid, PositionsX, PositionsY, Colors, ByRef lastmin){
thismin := 30
thismax := 1
while (A_Index<=4, y:=A_Index-1)
	while (A_Index<=4, x:=A_Index-1){
		PixelGetColor, color, PositionsX[x], PositionsY[y], RGB
		Grid[y,x] := Colors[color]
		if(!Grid[y,x]){
			Grid[y,x] := color
			return "stopped"
		}
		if (Grid[y,x] < lastmin && Grid[y,x] != -1){
			Grid[y,x] := Grid[y,x] + 10
		}
		if(Grid[y,x] > 0 && Grid[y,x] < thismin){
			thismin := Grid[y,x]
		}
		if(Grid[y,x] > thismax){
			thismax := Grid[y,x]
		}
	}

if(thismax < 4){
	thismax := 4
}
thresh := thismax - 3
if(thismax >= 10){
	thresh := thresh - 1
}
if(thismax >= 15){
	thresh := thresh - 1
}
if(thismin > thresh){
	thismin := thresh	
}
if(thismin > 10){
	thismin := 10
}
lastmin := thismin
return "ok"
}