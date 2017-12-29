$DIR = "build\"
$TARGET = "indie_studio.exe"

if ( (Test-Path $DIR) -eq $false )
{
  echo "Creating build\ directory"
  mkdir $DIR
}

echo "Moving into build directory"
cd $DIR
echo "CMake is generating makefiles"
cmake -G "Visual Studio 15 2017 Win64" ../ 
echo "Executing makefiles"
& 'C:\Program Files (x86)\Microsoft Visual Studio\2017\BuildTools\MSBuild\15.0\Bin\MSBuild.exe' .\indie_studio.vcxproj /p:PreferredToolArchitecture=x64
cd ../
if ( (Test-Path $TARGET) -eq $true )
{
  rm $TARGET
}
mv ($DIR + "\Debug\" + $TARGET) ./
