

# create folder ta3 dist (-p if not exist)
mkdir -p dist

echo "Compiling Random100.c..."
gcc TP0/Random100.c -o dist/Random100

echo "Compiling Random1000.c..."
gcc TP0/Random1000.c -o dist/Random1000

echo "Compiling Test-1.c..."
gcc TP0/Test-1.c -o dist/Test-1

echo "Compiling Test-2.c..."
gcc TP0/Test-2.c -o dist/Test-2

echo "Compiling Test-3.c..."
gcc TP0/Test-3.c -o dist/Test-3

echo "Done! All executables are in the dist/ folder"
