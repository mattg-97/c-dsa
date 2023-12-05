REM Build script for dsa
@ECHO OFF
SetLocal EnableDelayedExpansion

REM Get a list of all the .c files.
SET cFilenames=
FOR /R %%f in (*.c) do (
    SET cFilenames=!cFilenames! %%f
)

REM echo "Files:" %cFilenames%

SET assembly=dsa
SET compilerFlags=-g 
REM -Wall -Werror
SET includeFlags=-Ilib/
SET linkerFlags=-Lbin/
SET defines=-D_DEBUG -DKIMPORT

ECHO "Building %assembly%%..."

clang %cFilenames% %compilerFlags% -o ./bin/%assembly%.exe %defines% %includeFlags% %linkerFlags%

ECHO "All assemblies built successfully!"