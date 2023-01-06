# The Birthday Wish Generator

My program stores information on 10 different people, all of which one person (the user) has a relation with. 
The program is used to 

Both programs input the number of people the user wants to wish in the year, and the names of the people the user wants to wish.

Each person's birthday is stored as an integer. (mmdd OR mdd)
To convert to a readable date:
- divide the integer by 100
- output will be a value from 1 to 12, print the corresponding month value (EX: 1 = January, 3 = March, etc).
- find the reminder of previous operation, this will be the day value

## Linked List 

The linked list program is the project2022.c file.

There are two linked lists.
- One linked list has nodes that store values of a particular person
- The other linked list stores values of the ideas to celebrate.

Thic function inputs the number of people a person wants to wish in a year, then the names of every person that the user wants to wish. 

Each node contains:
    - birthdate
    - name
    - whether the wished or not (binary val)
    - next node
    - depth of friendship
        have choice of relations:
            - family/close friend: 3
            - friend: 2
            - acquaintance/other: 1 

There are 10 people, with their infomation stored:

Name   relation level  date (mdd/mmdd)    wishedYou

Diya        3               114             1
PJ          3               222             1
Jack        3               223             1
Aly         1               430             0
Yukta       2               929             1
Wei         1               930             0
Krish       2               1006            1
Jay         2               1111            1
Gia         1               1122            0
Zoya        1               1212            1

We find the corresponding node by comparing the name value of the node to the inputted name.
If they match, we use the corresponding relation level to find out what idea we should use for them.

Idea List:

Hold the values of different ideas a person can do to celebrate someone's birthday.

This is another linked list, that stores the following information, for each idea.

Idea                                              For What Relation Value      Done Before?

hold a surprise party                                       3                       0
make a collage with your memories                           3                       0
send them a birthday card                                   1                       0
gift them simple jewerly                                    2                       0
commission a painting of the two of you                     3                       0
text them happy birthday                                    1                       0
plan a movie together                                       3                       0
write a poem                                                3                       0
gift them a gag gift                                        2                       0
give them a gift card to their favorite store               1                       0
gift them cheap chocolate                                   1                       0
gift them nice chocolate                                    2                       0
gift them their favorite chocolates & treats                3                       0
gift tickets to a new movie                                 2                       0

All ideas' DoneBefore value are intialized at zero.

The Space Complexity for this version is O(1).

## Arrays

All of the values are stored in a different array:
- Name
- relation level
- date (mdd/mmdd)
- wishedYou

The index of each array corresponds to the same person. After finding the index of the value where the inputted name matched the name in the Name array, we use this index to find the values of the relation level, the date of their birthday, and whether they wished you or not.

Finding the name has a time complexity of O(n), and finding the values of the relation level, date, and wishedYou has a time complexity of O(1)

Then, we use the value of the relation level to find a corresponding idea for them, if wishYou != 0.

The Relation value for the ideas and Done before values are stored in a matrix (2 x 14). Essentially, we find an idea by comparing the relation value from the person and the idea value are the same, and then see if the idea has been done before or not (this is the 2nd column in the matrix).
By using the same index of the row of the matrix, we can output the idea, and update the done before value to one.

Finding a corresponding idea has a time complexity of O(n), and printing the idea has a time complexity of O(1).

The Space Complexity for this version is O(1)

## Testing

When the user inputted name does not exist:
- Run the program
- input: 1
- input: AJ
- output: No information on this person is found. Make sure the name is spelt correctly and has proper capitalization.
- (the program then stops)
Since the name AJ does not exist within the values of people that the program has information on, it outputs the above print statment.

When the user inputs a person that did not wish them a happy birthday:
- input: 1
- input: Aly
- Output: Aly's birthday is April 30th. Aly did not wish you on your birthday, so there is no need to wish them.
Since Aly did not wish the user, the user is not given an idea to use to wish them

When the user asks for three unique ideas for the same person:
- input: 3
- input: Diya
- output: Diya's birthday is January 14. You can hold a surprise party for them.
- input: Diya
- output: Diya's birthday is January 14. You can make a collage with your memories for them.
- input: Diya
- output: Diya's birthday is January 14. You can commission a painting of the two of you for them.

The user wants to find 7 unique ideas for a person that has the relationship value of 3.
- input: 7
- Now, input Diya seven different times 
- After the 7th input, the output is: No unused ideas are avaliable. Reuse a previous idea.

This happens because all the values in the idea used or not have been changed to 1, meaning that there are no longer any unique ideas left for the year.

In both of the programs, the outputs are the same for the same inputs.

I tested this program by comparing the time and space complexities of the different programs

## Overall

Between the two programs, the time complexity and the space complexity are the same. 
