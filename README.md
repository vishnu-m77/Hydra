# Hydra

Hydra is called so because a number of active card stacks are maintained, each called a ”head”, and whenever a head is removed from the game, two new heads are created. The goal of each player in Hydra is to lose all of their cards by placing them on the heads, but whenever a head is removed, it is reshuffled into the offending player’s deck.

To start a game of Hydra, one needs as many standard, 54-card decks (i.e., with jokers) as there are players. These decks are shuffled together, then distributed equally to each player, face down in a pile. This pile is each player’s draw pile, and each player additionally has a discard pile, which starts empty, and during a turn, a reserve. To start the game, the first player places a single card from the top of their draw pile face up in the center of the table, creating the first “head”. If the card happens to be a joker, then it is taken to have the value 2 (see the discussion of jokers below). From there, play proceeds clockwise.

In a turn of Hydra, one must draw and play as many cards as there are currently heads, unless an action ends the player’s turn early. For instance, if there are three heads, the player must play three cards. To play a card, the player draws it from the top of the player’s draw pile, and performs an action with it. If the player’s draw pile is empty, the player must first shuffle their discard pile to form a new draw pile, then draw from that. If the player’s draw and discard piles are both empty, and the player has no reserve, the player wins. There are several possible actions, and conditions under which the actions are allowed:

1. If the card’s face value is strictly less than the value of the top card of any head (an ace is considered to have the value 1, and so has the lowest value), the card may be placed, face up, on that head.
2. If the card’s face value is equal to the face value of the top card of any head, the card may be placed, face up, on that head, but this ends the player’s turn immediately, and they draw no further cards.
3. If the top card of any head is an ace, and the played card is not, then it may be placed, face up, on that head.
4. If the player has no reserve, and there is more than one head, they may place this card into reserve. To do so, the player simply places the card, face down, in front of them.
5. If the player has a reserve, then the player may swap the played card for the reserve card.

In the first three actions, if the played card is a joker, then the player determines and announces a value for the joker while playing it, and the value announced must satisfy the requirements for the action. For instance, the player may place a joker on a 3, by announcing that the joker is now an ace, 2, or 3. In the latter case, as this would fit action 2, this also ends the player’s turn. The joker retains its announced value as long as it remains on top of the head it was placed on, so in our above example, the next player must treat the joker as an ace, 2, or 3 (whichever it was announced to be), not a joker.

If the player had more cards to draw in the current turn, then after the first, third, or fourth action, they simply continue. If they are required to draw more cards, and they have more cards in their draw and/or discard pile, they draw another card; if they are required to draw more cards, but their only remaining card is the reserve, then their reserve card is added to their discard, and their turn ends; if they are out of cards entirely, they win; if they are not required to draw another card and still have cards, then their reserve, if any, is added to their discard pile, and their turn ends. After the third action, the player’s reserve, if any, is added, face down, to their discard pile, and play continues with the next player, unless the current player is out of cards, in which case they win. After the fifth action, the player must play the card retrieved from the reserve, and this does not count as drawing another card: That is, if the player must play five cards (because there are five heads), swapping four times does not free them of this requirement.

## A few subtleties to note:

- Aces are “universal”: They may be played on any head, and if they are the top card on any head, then any card may be played on them. The only caveat is that if a player plays an ace on an ace, that ends their turn, leaving the universal card free for the next player.
- Jokers are wildcards, but are not universal in the sense that aces are, since their value is restricted by announcing it. A joker can be played as an ace, of course, in which case it is universal.
- A player who’s drawn a card of equal value to an existing head may end their turn, removing any further risk that turn, but also keeping all of the cards they would otherwise have been able to play that turn. Deciding when it’s best to end one’s turn involves strategy.
- A player cannot win in a turn in which they’ve used the reserve, because the reserve card itself is not played.
- Otherwise, a player can win at any point during their turn.

If none of the first four actions apply, and the player does not wish to swap with their reserve, the player
must perform the following sequence of actions, called “cutting off” a head:
- Place the played card into their discard pile, face down.
- Place their reserve card, if any, into their discard pile, face down.
- Move every card in the oldest head, face down, into their discard pile.
- With the top two cards from the player’s draw pile (reshuffling the discard pile if necessary), create two new heads by placing the two cards, face up, as two new piles. Any jokers placed in this manner are given the value 2.

Generally speaking, this action will give them more cards, rendering them further away from victory.
After that, play continues with the next player. Note however that it is possible to “win by losing”: If the player’s last card does not match any action, they will be forced to cut off a head. But, if the oldest head consists of only a single card, and the player had no reserve at the time, then the two cards they play to create two new heads are their last two cards. They will thus be rendered without any cards, and win!

Play continues until a player wins.

Hydra isn’t an especially strategic game, but what strategy there is comes from a combination of careful use of the reserve and card counting. For instance, if a player has determined that a particular head is particularly rich in low cards, or universal aces, they may play quite boldly, confident that while they may end up cutting off a head and thus gaining more cards, the cards they end up with will be easier to play in the future than the cards they currently have. They may even use the reserve to hold a high-valued card, then swap with the reserve to intentionally “lose”, enriching their future draw pile with easily-played low cards. Alternatively, if they draw an ace, they would be wise to put it in their reserve, allowing them to play recklessly, since they can always swap for their ace and render their situation more playable.

## Computer Hydra

If you’ve carefully read the rules of Hydra, you’ve probably noticed that the suit is irrelevant. Nonetheless, you must remember the suit. Each card is represented by the concatenation of its value (A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K) with a character for its suit (S, H, C, D), e.g. 10D or KS. A joker in the hand is represented by the string “Joker”, but a joker that’s been played and assigned a value is represented by that value, with J as the “suit”, e.g. 3J.

When the game begins, Computer Hydra prompts “How many players?”, input a number greater than 1, then starts a game with that many players. Internally, it shuffles together the decks, distributes the cards evenly among the players, and even performs the first player’s move, removing their first card and starting a head.

After that, every time the program interacts with a player, it prints a blank line, the list of heads, the list of players, and then the interactive prompt.

The list of heads consists of the line “Heads:”, one line per head, then a blank line. Each head is printed in the following pattern: “a: b (c)” a is the number of the head. The first head in the game has number 1, but when a head is removed from the game, its number is out of the game forever, so the first head printed won’t usually be number 1. b is the value of the top card on the head. c is the total number of cards in the head, including the top card. For example:

```
Heads:
2: A (12)
3: 9 (3)
4: 10 (6)
```

The list of players consists of the line “Players:”, one line per player, then a blank line. There are two forms of the player line: One if the player is the current player, and one if they are not.
If they are not the current player, the line follows this pattern: “Player a: b (c draw, d discard)”. a is the player’s number, starting from 1. b is the sum of the number of cards in their draw and discard piles. c is the number of cards in their draw pile. d is the number of cards in their discard pile.
If they are the current player, the line follows this pattern: “Player a: b (c draw, d discard) + 1 in hand, e remaining, f in reserve”. a, b, c, and d are as above. e is the number of cards they still must play in their current turn, after the one in their hand. f is either 1 or 0, indicating whether they do or do not have a reserve. Note that if the player is playing, they have exactly one card in their hand by definition.

There are two interactive prompts for players:

1. “Player a, it is your turn.”. a is the player’s number, starting from 1. The player must enter any line (typically a blank line) to continue play. Note that when this prompt is displayed, it is no one’s turn, so all of the player lines should be in the form taken when it is not the player’s turn.
2. “Player a, you are holding a b. Your move?”. a is the player’s number, starting from 1. b is the value of the card in the player’s hand, or “Joker” if the card is a joker. The player is expected to enter their move, as a number.

The move is either the number of an active head, or 0. 0 refers to either placing the current card in reserve, or swapping the current card for the reserve card, depending on whether the player currently has a reserve card. If the player selects a head, but there is no valid move with that head, the game simply ignores the invalid move and prompts again. The same is true for a number greater than 0 but less than the first current head, or greater than the number of the last current head. If the card being placed is a joker, and a head has been selected, a further prompt requests “Joker value?”. The user must enter one of A, J, Q, K, or a number between 2 and 10, representing the value. If the entered value is not valid for the given play, then the play is ignored, and the player’s turn repeats. Note that cutting off a head is done by inputting the number of the first head, and this action is only valid when there is nowhere else the player can play their current card. In any case, the game updates the state of the cards according to the rules of Hydra, and either continues play or declares the player the winner.

The game is over when a player is out of cards, which can happen at several points during their turn, outlined in the rules above. When a player wins, the program prints “Player a wins!”, where a is the winning player’s number, and then quits.

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
