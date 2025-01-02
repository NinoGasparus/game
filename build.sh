#!/usr/bin/bash

optLvl='O2'

files=(
	"./main.cpp"

  "./DataStruct/DataStruct/DataStruct.cpp"

  "./DataStruct/Vector/Vec2D.cpp"
  "./DataStruct/Vector/Vec3D.cpp"
  "./DataStruct/Vector/Vec4D.cpp"
  "./DataStruct/Vector/VecND.cpp"

  "./Drawable/Drawable.cpp"
  "./Drawable/Point.cpp"
  "./Drawable/Line.cpp"
  "./Drawable/Tri.cpp"

  "./Renderer/Renderer.cpp"
  "./Renderer/Window.cpp"

  "./Intervalometer/IntMeter.cpp"
)

flags=(
	"SDL2"

	""  

  ""
  ""
  ""
  ""
  
  ""
  ""
  ""
  ""

  ""
  ""

  ""
)


if [[ "$1" == "all" ]]; then
    rm -rf Build/
fi
mkdir -p ./Build

linkFlags=()

for ((i=0; i<${#files[@]}; i++)); do
    
	objectFile="./Build/$(basename ${files[$i]} .cpp).o"
    	
	if [[ ! -f $objectFile || ${files[$i]} -nt $objectFile ]]; then
        	
		if [[ "${flags[$i]}" != "" ]]; then
            		g++ -$optLvl -c ${files[$i]} -l${flags[$i]} -o $objectFile
        	else
			g++ -$optLvl -c ${files[$i]} -o $objectFile
	    	fi
		echo "Compiling ${files[$i]}"
    	else
        	echo "Skipping ${files[$i]}, unchanged."
	fi
	
	if [[ "${flags[$i]}" != "" ]]; then
		linkFlags+=("-l${flags[$i]}")
    	fi
done

g++ ./Build/*.o -o main "${linkFlags[@]}" 
echo "Compilation and linking complete."


