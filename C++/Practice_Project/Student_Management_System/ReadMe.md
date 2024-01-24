This is a simple practice project, with which I can use my C++ konwledge get more familier with them.
Such a project can be easily found over the internet. I also use some basic ideas for this system but auch make some simplification in order to write code as I want.

### System Construct

#### GUI (actually a consoule)
1. Main page for login
    a. Admin login
    b. Student login
2. Login page
    Unix style, input Username and then password
3. Check page
    a. For student: 
    (1) only show his/her own record
    (2) change his or her password
    b. For Admin there are different options shown as text
    (1) search record with student ID
    (2) add new record 
    (3) change record
    (4) delet record with ID
    (5) show all rercords

#### What have been used
1. **fstream**
all record and user-password are saved in txt files and can be read and wrote with code.

2. **vector**
all records are read from file and saved in a vector

3. **map**
user-passwords are read from file and saved in map
