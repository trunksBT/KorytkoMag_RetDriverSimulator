# This is simulator for AISG 2.0 RetDriver

# Checkout command  
- SSH: git clone git@github.com:trunksBT/KorytkoMag_RetDriverSimulator.git --recursive  
- HTTPS: git clone https://github.com/trunksBT/KorytkoMag_RetDriverSimulator.git --recursive  

# KorytkoMag_RetDriver
UNBLOCKED_SCENARIOS > QUALITY  
SOME SMELLS > OVER-ENGINEERING  
PLANNED REFACTOR AFTER FINISH  

# UML_ActivityDiagram:  
1. Install the https://code.visualstudio.com/download  
2. Install the https://marketplace.visualstudio.com/items?itemName=jebbs.plantuml  
3. Open the docs/UML_DiagramOfSequence.wsd via Visual Studio Code  
4. Click "Alt + D"  

# UML_ClassDiagram:  
1. Install the https://www.microsoft.com/pl-PL/download/details.aspx?id=51188  
2. Open the docs/UML_DiagramOfClasses.vsdx via Visio Viewer  

# Dependencies:
- cmake 3.12.4
- g++ 8.2.1 
- gcc 8.2.1
- libboost-all-dev 1.71.0

# How to run:  
1.  
- cmake .  
OR
- cmake -DCMAKE_CXX_COMPILER="/usr/bin/g++-8" .
OR
- cmake -DCMAKE_CXX_COMPILER="/usr/bin/g++" .
OR
- cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo // for using gdb  
2.  
- bash runBinary.sh  
  
# How to run tests:  
- bash runUT.sh
- bash runMT.sh  

# Logger:  
<Hour:Minute:Second.Milisec> severity [FileName::FunctionName:Line]  

FileName != ClassName

