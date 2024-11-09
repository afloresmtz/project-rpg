# Project Delivery - Turn-Based RPG 

### Context 
RPGs, also known as Role-Playing Games, are a genre of videogames that originated from table-top RPGs such as Dungeons and Dragons, and quickly became a success when videogames were created. In an RPG, you take the role of a character (normally an adventurer or traveller) immersed in a rich and vibrant world, normally with secrets to find and a backstory to uncover. While the genre contains a massive amount of subgenres (such as MMORPGs (massive multiplayer online RPGs), for example), the focus of this project will be a turn-based RPG, specifically. A turn-based RPG omits the quick action of fights and battles for a more strategic approach, having the characters and enemies take turns to attack each other or help their teammates. This way, players need to plan their actions and choose the moves and playstyle they prefer, without the pressure of time or reflexes. Some notable examples of popular turn-based RPGs are: Baldur's Gate 3, Slay the Spire, the Persona series of games, or Undertale / Deltarune. 

### Importance
While it's true that RPGs (and videogames in general) may not serve some higher purpose or help society in anything productive, I still believe that videogames, if nothing else, are a way of having fun with friends, relaxing after a long day of work, and in general a good source of entretainment. Similarly, while some might disagree with the idea, I believe videogames can be a form of art, and the creation of art will always be a net positive for humanity. Therefore, while this project will not be a game that I publish and gain revenue from, I still believe that the creation of videogames can be beneficial, as long as people spend a healthy amount of time in them and not dedicate their whole lives to them. Overall, I decided to do this project because videogames are one of my main source of entretainment and comfort, and I believe I can do something simple but challenging with this project. 

### How I will approach the project (with OOP)
This type of game is, in my opinion, very appropiate to the subject of Object-Oriented Programming. I plan to have 4 characters in a party that the player will be able to control. This party of characters will ascend floors of a tower, encountering different things in each floor. Some floors may contain a treasure, some may contain a fight, and some may contain a shop to spend gold and buy upgrades. Characters will be able to upgrade some stats or learn new moves after fights, which will help them face a final boss at the end of the tower. Right there, I can already formulate three main classes of objects that my program will possess: Character, Enemy, and Event. These classes will have characteristics that all Characters, Enemies and Events will share, and different objects (such as the four main characters) will be created accordingly. Similarly, these classes will have subclasses, as to expand the types of objects that can be created. For example, the Enemy Class will have different subclasses for each type of enemy. Some of the methods of the class "Enemy" will be shared among all enemies, such as changing its health or dealing damage, while some methods will be exclusive to some subclasses (such as the specific abilities of an enemy type).

The game will be run completely in the terminal, with no other visuals involved. The player will be able to input actions (such as "Attack", "Defend", or "Use Spell") to control the character in the current turn. There will be no movement from the characters, nor a visual indicator of the characters on the screen; the game will run completely on text, with one event after the other. 

## UML Class Diagram
![UMLClassDiagram(1)](https://github.com/user-attachments/assets/523c884d-efbe-44f6-9aa1-d2b2cb24c872)

