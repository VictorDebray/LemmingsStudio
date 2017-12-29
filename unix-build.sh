TARGET=indie_studio
DIR=build/
CYAN='\033[0;36m'
DEF='\033[0m'

echo -e "$CYAN  Building $TARGET $DEF"
if [ ! -d $DIR ]; then
	echo -e "$CYAN  Creating build directory $DEF"
	mkdir $DIR
fi

echo -e "$CYAN  Moving into build directory $DEF"
cd $DIR
echo -e "$CYAN  Executing CMake $DEF"
cmake -GNinja ../
echo -e "$CYAN  Executing Make $DEF"
ninja
