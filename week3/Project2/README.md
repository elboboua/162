# Project 3 - 162
Zoo Typoon Project

# To-do
1. Create animal class 
2. Create turtle, tiger, penguin class.
3. Create the zoo class
    1. must save the animals as dynamic arrays 
        10 at first
    2. Check money function
    3. Number of each animal variable
    4. SIZE of array variable for each animal. 
    5. Buy animal function
    
    


# Problems
1. Where to put Random Events?
2. How to handle growing a dynamic array. 
3. Input validation
4. Animal amount variable in the zoo class to keep. 
    1. Every time a new animal is created, it checks the size of the array and if it needs to grow its grows
5. How will user buy animals?   
    print animal. Do you want? How many?
    Make sure to check wallet. 

# Extra credit
1. Status message - put a message into a text file for each random event.
2. Different feed types.
3. New animal  Try to do this.

# Design

At the beginning of the game, the user buys animals.
At the beginning of each day, the user will receive the status of the zoo along with the random event.
Afterwards, the player will be able to make choice. 

# Inherited Animal Classes
Animals bought are 1 day old

Methods
	1. growAnimal() - increases the animals age by 1. 
	2. isAdult() - returns true if animal is 3 days or older

# Zoo Class
Attributes
	1. numberOf for each animal.
	2. budget
Methods
	1. beginGame method
	2. initial buying animals method
	3. gameLoop - no user input is required 
	4. randomEvent
	5. feedFunction (also subtracts money)
	6. addAnimal - needs to be able to dynamically grow the pointer array
