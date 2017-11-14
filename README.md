# Cradick_Pa4

#CS 2750 System Programming and Tools Programming Assignment 4
_____________________________________________________________________________________
1
Due: 11/05 (11:59PM)
This assignment consists of 2 problems.
First thing to do: Log on to delmar.umsl.edu. Create your submission directory named ‘your
lastname_pa4’. For example, if your name is ‘John Doe, your submission directory (for this assignment)
will be named doe_pa4 (do not use capital letters, and don’t forget to put the underscore symbol ‘_’
between your name and ‘pa4’). You will have to do your programming assignment 4 under this submission
directory. Be careful: any files outside your submission directory will not be submitted. Do not put
any unnecessary files or directories in your submission directory.
1. [30pt] Simple File Statistics
Write a program that will process one or more files and print out various statistics for these files. The
file names should be provided via command-line arguments or the program will simply use stdio stream
to get input (if there are no command-line arguments).
If the user does not provide any command line arguments, the input should be read from the stdio
stream instead of a standard file. If the user provides one or more command-line arguments, the program
should process files with the names provided by command-line arguments one by one, and print
out statistics for each file separately. If more files are processed, summary statistics should also be
printed out.
The program should report the following statistics about each file (also summary statistics if multiple
files are processed):
i) Number of characters in the file.
ii) Number of lines in the file (i.e. number of newline characters).
iii) Number of words in the file. A word is a sequence of any characters except for the space,
newline or tabulator characters not separated by these characters. Therefore, in a string "This is
the first line\nThis \t\this the 2nd" we would have 9 words (\n and \t
are the special characters).
The program will be similar to the wc command provided in Linux (test it to get an idea). I’d suggest to
use the functions defined in ctype.h. For example, isspace is a good function to identify white space
and distinguish it from the rest (other characters form words).
2. [70pt] Account Management System
Write a menu-driven, interactive program for managing bank accounts. All account information should be
stored in a binary file accounts.dat. Your data file accounts.dat should contain at least 7 different
customers when you submit this assignment. You can limit the maximum number of accounts in the bank
by 50. You may store all accounts in memory (as an array), which should simplify most operations, but any
change on any account should be immediately reflected in the data file (accounts.dat) not only on
exit.
For each customer, the data file should store the following fields (you decide on reasonable data types):
• First name
• Middle initial
• Last name
• Account number (any 6-digit number)
• Account balance
CS 2750 System Programming and Tools Programming Assignment 4
_____________________________________________________________________________________
2
The menu should provide you with the following options:
 0. Exit
 1. Deposit
 2. Withdrawal
 3. Add account
 4. Remove account
 5. Balance inquiry
 6. View accounts
The program then proceeds based on the user’s selection as follows:
• If the user picks 0, the program terminates (for any other choices, the program does something and
then returns to the menu).
• If the user picks 1, the program asks about the account number and the amount to deposit, and
performs the requested update in the data file. After performing the file update, the program should
report the new balance on the affected account. If a wrong account number is provided, the program
reports this and doesn’t make any changes.
• If the user picks 2, the program first asks for the account number and the amount to withdraw. If
the current balance is insufficient to cover the withdrawal, the program reports this information and
doesn’t make any changes in the account. Otherwise, the program updates the file accordingly and
prints out the new balance on the affected account. If a wrong account number is provided, the
program reports this and doesn’t make any changes.
• If the user picks 3, the program asks for information about a new customer, and then creates an
account for this customer. The (new) account number should also be provided on input. If the user
provides an account number already used, then the program complains and doesn’t perform the
requested update (nothing is changed).
• If the user picks 4, the program asks for an account number and it then removes the requested
account from the data file. If a wrong account number is provided, the program reports this and
doesn’t make any changes.
• If the user picks 5, the program asks for an account number and it then prints out all information
about that account stored in the data file. If a wrong account number is provided, the program
reports this and doesn’t make any changes.
• If the user picks 6, the program prints out all information about all accounts in the system (one by
one).
Test program:
I provide executable for problem 2 to allow you to test how a solution may look like. For problem 2,
just run ~/accounts/facstaff/yousefis/bin/bank/bank or if you like to have a copy of
both accounts.dat file and bank executable, then
cd ~
cp -r /accounts/facstaff/yousefis/bin/bank
cd bank
./bank
What to submit:
• Make sure to put your source files in your submission directory.
• Makefile to create wc and bank as executable for problem 1 and 2 respectively.
• Your entire programming assignment 4 submission directory will be submitted.
CS 2750 System Programming and Tools Programming Assignment 4
_____________________________________________________________________________________
3
How to submit:
• Move to the parent directory of your submission directory.
• Execute the following Linux script using your submission directory name as an argument.
~yousefis/cs2750/pa4/pa4_submit doe_pa4
• In the above line, doe_pa4 is just an example. Use your own submission directory name there.
Before you submit (Important!):
• Make sure your submission directory is named exactly as instructed. If not, you may get an error
message from the script, meaning your submission was not successful (that is, your programming
assignment was not submitted).
• Also, make sure to execute the script from the parent directory of your submission directory.
Otherwise the script will not be able to find your submission directory, resulting in an error.
• If you get an error message, you have to fix the problem and try again, until you get the “submission
successful” message. Otherwise your programming assignment will not be submitted.
• The script does not check if you have all the required files under your submission directory. This
means that even if your submission was successful, your submission may be missing some required
files in it, which could lead to loss of points in grading (the script will submit your programming
assignment directory even if it is completely empty!). So be careful, because you cannot resubmit!
Once your submission is successful, the script does not allow you to do it again. Always double
check before you submit.
Policy
• Do all the assignments on delmar.umsl.edu.
• The contents of each source code file (Linux script or .c file) should begin with the following
comments
• (for .c file, use // or /* */ for commenting):
# your name (e.g., John Doe)
# cs2750 PA # (e.g., cs2750 PA 4)
# date dd/mm/yyyy (e.g., 11/05/2017)
• Non-compilable program will get almost no credit (e.g., executable code is not produced due to
compiler errors).
• Non-working program will get almost no credit (e.g., the executable is terminated immaturely due
to run time errors).
• Copying somebody else’s program is not allowed. If identical (or nearly identical) programs are
found among students, it will be considered cheating and every student involved will get automatic
0 for the assignment. Copying some source code downloaded from the internet will also result in
the grade of 0.
