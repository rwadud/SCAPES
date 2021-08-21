#   SCAPES
#
#     
###      UNZIP SCAPES:
####        unzip SCAPES.zip
####        cd SCAPES/
#     
###      BUILD/RUN
####         qmake
####         make
####         ./bin/SCAPES
###         OR
###         Turnkey (single command)
####        ./run
#     
###      CLEAN UP
####        make distclean
#
#        
###      SAMPLE PROGRAMS FOR D2
####        AreaOfRect.scp
####        Sigma.scp
#
###               HOW TO
## -----------------------------------------
####    Create New program:       File  > New
####     
####    Open a saved program:     File  > Open
####     
####    Save current program:     File  > Save
####     
####    Save new program:         File  > Save As
####     
####    Close SCAPES:             File  > Exit
####     
####    Compile current program:  Build > Compile
####    
####    Run the program:          Build > Run
#
#
#### NOTE: The Compilation output is in the Resources Folder

## FACTORY METHOD
#### Factory Method is being used so we are able to create the objects on the fly without our program having to prepare anything that will not be needed. This prevents the need for the class to anticipate the type of objects that is needed.
### Benefits of Factory Method:
##### Factory method eliminates the need to bind application-specific classes into your code. The program only deals with product interfaces; therefore it can work with any user-defined ConcreteProduct classes.
##### According to the Gang of Four; The Factory method allows us to “Define an interface for creating an object, but let the subclasses decide which class to instantiate. Factory Method lets a class defer instantiation to subclasses.”
##### By virtualizing the functions inside creator.h and statementcreator.h, we are able to achieve all the benefits of the factory method
##### Allows us to abstract the creation of our objects away from its actual implementation.
##### The StatementCreator is used in CompileControll::compile() method and RunControl::regenerate() method.
##### A new statement is created by doing Statement *stmt = stmtCreator.Create(instr) where instr is a string of the instruction (dci, prt, ..etc)
