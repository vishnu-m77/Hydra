# Hydra
A card game

# Modules

## Card
Card stores a suit and value. It has a function that outputs the ‘name’ of the Card (Ex: ‘KD’ or ‘2S’). It also has a function that modifies the value of the Card (for Joker), and functions that output the suit and value separately.

## Deck
Deck contains a vector of shared pointers of Cards. One function returns a shared pointer to the last Card added, and another function pops the last Card added. Deck also contains the shuffle function which shuffles the elements of the vector. The shuffle function uses the time as a seed and the random engine to shuffle the contents of the Deck.

## Player
Player holds two shared pointers to different decks, DrawPile and DiscardPile. It consists of the following functions: nextCard() returns the Card at the back of the Deck DrawPile. RecreateDrawPile() shuffles the Cards in DiscardPile and adds them to the DrawPile. nextCard() calls on this function if the DrawPile is empty. There are functions that return the sizes of the DrawPile and DiscardPile. There are functions that are called addToDiscard, that have different input parameters. They are used to add either a single Card to the DiscardPile or an entire Deck to the DiscardPile.

## Players
Players has a vector of shared pointers of Player. It holds the number of players, and the current player. There is an addPlayer function that is ideally supposed to be called by the initializer of the Game. The functions nextCard(), and addToDiscard, call the same functions of the current Player. I made this in such a way that only the current player data can be accessed from outside the class. There is an output operator that prints the state of all Players. This function is made to be a friend of Players, so that it has access to the data.
There is another function written within the Players class which is used to print the intermediate part during each move (The part where the program prints the number of cards in hand, the remaining number of cards in the turn, and if a reserve card exists or not). The important part of the class is that it includes an incPlayer() function that increments the current player by 1. When it reaches the maximum number of players, it loops back and returns to the first player. This is done so that at the end of a turn, theGame can access the data of the next Player.

## Hydra
Hydra contains a vector of shared pointers to Deck. The addHydraHead function takes a shared pointer of a Deck as a parameter and adds it to the back of the Hydra. The removeHydra() function returns a shared pointer to the Deck of the oldest Hydra Head. The backOfDeck function takes an integer as input and returns a shared pointer to the back of the Deck with that index. As these functions are handled only by the programmer as helper functions during the run of theGame, I did not create checks or handle incorrect input. The addCardToDeck function adds a shared pointer to a Card to the back of the input index of the Deck. A size() function returns the number of HydraHeads. I also made an output operator as a friend of Hydra that prints all the details of the Hydra.

## theGame
theGame creates and stores all the data used in the program. It stores the Hydra and the Players. The constructor takes in two inputs: the number of players and the number of cards per player. It creates a SuperDeck which contains all the Cards of the Game (54 * number of players). This deck is then shuffled and then appropriate number of cards are assigned to each player. The constructor also initializes the Game by taking the first card from Player 1 and adding it to the Hydra. It then iterates to the next Player and calls the begin() function. The begin() function is the heart of the program. It contains a while loop that calls the next Turn repeatedly until the game ends (when a player wins). 

## Turn
Turn stores shared pointers of Cards – Hand and Reserve. They also store a Boolean value to keep track if the Reserve and the Hand have been swapped during a Move or not. Turn consists of a next() function that takes a reference to the Players and the Hydra. This function creates every Move, and acts on the output of the Move accordingly. If the Move calls for a swap of the Hand to the Reserve or place the Hand on the Reserve and take a new card as the Hand, Turn has a swap function that enables this. The next() function also calls another function outside Turn to cut the head of a Hydra and add two cards from the player as two new heads. After every move, the function also checks for the win condition.

## Move
Move has a shared pointer to a Card – Hand and Booleans for reserve and swapped that are passed by Turn. This also has a next() function that takes in a reference to a Hydra and the current player. The reserve Boolean, and the current player exists mainly for printing purposes (for calling the respective functions with these parameters). It gets a move from the user and passes it into the validHead function which checks if the input is a valid number between the beginning and end indices of the Hydra heads (or 0). Since input and output is controlled by io, it calls on a function to get the input of print stuff. The functions in io check for valid formatting of input ( if it is a valid integer, or a character, etc.). If the card in Hand is a Joker, it asks for the value of the Joker again by calling a function in io. Then the next() function passes Hydra as a reference, and the card in Hand, and the input move into a move() function outside the Move class. This function checks the conditions of the Game and enforces them. A helper function called possibleMoves() checks if there were any possible moves if the action was to cut the Head of a Hydra. If there were other possible moves, the move is repeated by returning a particular value to Turn and Turn repeats the move with the same Card in hand. Otherwise, the value returned will be the one which indicates Turn to call the cutHydraHead function.

# io
io is the module created to handle input and output of this program. It contains functions such as printHydra(), printPlayer(), getJoker(), getMove(), etc. that perform the equivalent actions and return the necessary values. The parameters are passed by reference, and the functions handle invalid input by using a loop that does not allow the program to end abruptly.
