REM Build script for dsa
@ECHO OFF
SetLocal EnableDelayedExpansion

REM Get a list of all the .c files.
SET cFilenames=
FOR /R %%f in (*.c) do (
    SET cFilenames=!cFilenames! %%f
)

ECHO %cFilenames%

REM echo "Files:" %cFilenames%

SET assembly=dsa
SET compilerFlags=-g 
REM -Wall -Werror
SET includeFlags=-Isrc -I../library/src/
SET linkerFlags=-L../bin/ -llibrary.lib
SET defines=-D_DEBUG -DIMPORT

ECHO "Building %assembly%%..."

clang %cFilenames% %compilerFlags% -o ./../bin/%assembly%.exe %defines% %includeFlags% %linkerFlags%