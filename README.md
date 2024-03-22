
# Work Report

## Features:
Two Apps, labs, and plane
The lab app takes in a list of labs and how many stations they have
  - user can choose to reserve a specific lab with their ID and choose to log out by giving their ID

The plane app creates 7 rows and 4 columns of seats
  - user can choose to reserve specific seats and cancel their reservation

<br><br>

- Implemented:
  - Implemented the menu for both plane and lab app
  - With their respective reservation and cancelling

<br><br> 


<br><br>

- Bugs
  - If input a char or string character when it is asking for row/seat or station/labs, it will cause an infinite loop

<br><br>

# Reflections:

- Any thoughts you may have and would like to share.

# Lab App output:
<pre>
<br/><br/>Lab App Output
//-------------------------//
Log[i]n, Log[o]ut, or [E]xit
Please enter what you would like to do: i

What lab station would you like to login?
Enter the lab number, station number, and id number: 3 5 12
lab: 3, station: 5, id: 12
labs are:
     0     |     0     |     0     |     0     |     0     |     0
     0     |     0
     0
     0     |     0     |     0     |     0     |     0     |    12     |     0
     0     |     0
     0     |     0     |     0     |     0
Successfully login into lab 3, station 5
Bringing user back into main program

//-------------------------//
Log[i]n, Log[o]ut, or [E]xit
Please enter what you would like to do: i

What lab station would you like to login?
Enter the lab number, station number, and id number: 0 4 12
lab: 0, station: 4, id: 12
labs are:
     0     |     0     |     0     |     0     |    12     |     0
     0     |     0
     0
     0     |     0     |     0     |     0     |     0     |    12     |     0
     0     |     0
     0     |     0     |     0     |     0
Successfully login into lab 0, station 4
Bringing user back into main program

//-------------------------//
Log[i]n, Log[o]ut, or [E]xit
Please enter what you would like to do: i

What lab station would you like to login?
Enter the lab number, station number, and id number: 5 2 13
lab: 5, station: 2, id: 13
labs are:
     0     |     0     |     0     |     0     |    12     |     0
     0     |     0
     0
     0     |     0     |     0     |     0     |     0     |    12     |     0
     0     |     0
     0     |     0     |    13     |     0
Successfully login into lab 5, station 2
Bringing user back into main program
What lab station would you like to login?
Enter the lab number, station number, and id number: 4 1 3
lab: 4, station: 1, id: 3
labs are:
     0     |     0     |     0     |     0     |    12     |     0
     0     |     0
     0
     0     |     0     |     0     |     0     |     0     |    12     |     0
     0     |     3
     0     |     0     |    13     |     0
Successfully login into lab 4, station 1
Bringing user back into main program

//-------------------------//
  Log[i]n, Log[o]ut, or [E]xit
Please enter what you would like to do: o

What lab station would you like to logout?
Enter the id number you would like to log out of: 12 
labs are:
     0     |     0     |     0     |     0     |     0     |     0
     0     |     0
     0
     0     |     0     |     0     |     0     |     0     |     0     |     0
     0     |     3
     0     |     0     |    13     |     0
Successfully logout of all lab and station
Bringing user back into main program

//-------------------------//
Log[i]n, Log[o]ut, or [E]xit
Please enter what you would like to do: o

What lab station would you like to logout?
Enter the id number you would like to log out of: 3
labs are:
     0     |     0     |     0     |     0     |     0     |     0
     0     |     0
     0
     0     |     0     |     0     |     0     |     0     |     0     |     0
     0     |     0
     0     |     0     |    13     |     0
Successfully logout of all lab and station
Bringing user back into main program

//-------------------------//
Log[i]n, Log[o]ut, or [E]xit
Please enter what you would like to do: E
Thank you for using the program, exiting
<br/><br/>
</pre>
# Plane App output:
<pre>
<br/><br/>
Welcome to PLANE program

//-------------------------//
[R]eserve a spot, [C]anceled a reservation, or [E]xit
Please enter what you would like to do: R 

What row & seat would you like to reserve?
Enter the row & seat number: 3 1 
row: 3, seat: 1
plane are:
        A     B     C     D
[1]     A     B     C     D
[2]     A     B     C     D
[3]     A     B     C     D
[4]     A     X     C     D
[5]     A     B     C     D
[6]     A     B     C     D
[7]     A     B     C     D
Successfully reserve row 3, seat 1
Bringing user back into main program

//-------------------------//
[R]eserve a spot, [C]anceled a reservation, or [E]xit
Please enter what you would like to do: R

What row & seat would you like to reserve?
Enter the row & seat number: 5 2
row: 5, seat: 2
plane are:
        A     B     C     D
[1]     A     B     C     D
[2]     A     B     C     D
[3]     A     B     C     D
[4]     A     X     C     D
[5]     A     B     C     D
[6]     A     B     X     D
[7]     A     B     C     D
Successfully reserve row 5, seat 2
Bringing user back into main program

//-------------------------//
[R]eserve a spot, [C]anceled a reservation, or [E]xit
Please enter what you would like to do: R

What row & seat would you like to reserve?
Enter the row & seat number: 0 3
row: 0, seat: 3
plane are:
        A     B     C     D
[1]     A     B     C     X
[2]     A     B     C     D
[3]     A     B     C     D
[4]     A     X     C     D
[5]     A     B     C     D
[6]     A     B     X     D
[7]     A     B     C     D
Successfully reserve row 0, seat 3
Bringing user back into main program

//-------------------------//
[R]eserve a spot, [C]anceled a reservation, or [E]xit
Please enter what you would like to do: R

What row & seat would you like to reserve?
Enter the row & seat number: 0 3
row: 0, seat: 3
plane are:
        A     B     C     D
[1]     A     B     C     X
[2]     A     B     C     D
[3]     A     B     C     D
[4]     A     X     C     D
[5]     A     B     C     D
[6]     A     B     X     D
[7]     A     B     C     D
The row and/or seat is occupied. Please choose a different one
Enter the row & seat number: 1 2
row: 1, seat: 2
plane are:
        A     B     C     D
[1]     A     B     C     X
[2]     A     B     X     D
[3]     A     B     C     D
[4]     A     X     C     D
[5]     A     B     C     D
[6]     A     B     X     D
[7]     A     B     C     D
Successfully reserve row 1, seat 2
Bringing user back into main program

//-------------------------//
[R]eserve a spot, [C]anceled a reservation, or [E]xit
Please enter what you would like to do: C

What row & seat would you like to cancel the reservation of?
Enter the row & seat you would like to cancel: 3 1
seats are:
        A     B     C     D
[1]     A     B     C     X
[2]     A     B     X     D
[3]     A     B     C     D
[4]     A     B     C     D
[5]     A     B     C     D
[6]     A     B     X     D
[7]     A     B     C     D
Successfully canceled row 3 & seat 1
Bringing user back into main program
What row & seat would you like to cancel the reservation of?
Enter the row & seat you would like to cancel: 0 0
seats are:
        A     B     C     D
[1]     A     B     C     X
[2]     A     B     X     D
[3]     A     B     C     D
[4]     A     B     C     D
[5]     A     B     C     D
[6]     A     B     X     D
[7]     A     B     C     D
The row & seat is not reserve
Please input the correct row & seat you wishes to [c]ancel or [e]xit to main program: C
Enter the row & seat you would like to cancel: 0 3 
seats are:
        A     B     C     D
[1]     A     B     C     D
[2]     A     B     X     D
[3]     A     B     C     D
[4]     A     B     C     D
[5]     A     B     C     D
[6]     A     B     X     D
[7]     A     B     C     D
Successfully canceled row 0 & seat 3
Bringing user back into main program

//-------------------------//
[R]eserve a spot, [C]anceled a reservation, or [E]xit
Please enter what you would like to do: E
Thank you for using the program, exiting
<br/><br/>
</pre>


