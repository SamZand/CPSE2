@echo off
set back=%cd%
for /d %%i in (*) do (
	cd "%%i"
	echo current directory:
	make clean
	cd
	
	cd %back%
)
pause