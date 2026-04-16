@echo off
chcp 65001 > nul
echo ========================================
echo    EasyCPP - Compilazione e Test
echo ========================================
echo.

echo [0/2] Rimozione vecchio eseguibile...
if exist test_easycpp.exe del test_easycpp.exe

echo [1/2] Compilazione in corso...
g++ -std=c++17 test_easycpp.cpp -o test_easycpp.exe -I..
if %errorlevel% neq 0 (
    echo.
    echo [ERRORE] Compilazione fallita! Controlla i messaggi sopra.
    pause
    exit /b %errorlevel%
)
echo [OK] Compilazione completata con successo.

echo.
echo [2/2] Esecuzione del test...
echo.
test_easycpp.exe

echo.
echo ========================================
echo    Test terminato.
echo ========================================
pause