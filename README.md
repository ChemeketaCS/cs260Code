# cs260Code

Examples and Starter Code for CS260 at Chemeketa Community College

To compile by hand in any of the project folders you will need to add
this to your g++ call:  
`-I  ../../`   
*(That is a capital i - may be hard to see depending on your font)*

That says to add ../../ (the folder that is two levels above this one)
to the list of locations to look for included files. All of the projects
live two folders down from the root folder where doctest.h is located.

For most projects, this basic recipe is sufficient:  
`g++ *.cpp -g -I  ../../ -o program.exe`

Assuming you do this in the Chemeketa Development Environment virtual machine,
you should then be able to do:  
`drmemory -- program.exe`
