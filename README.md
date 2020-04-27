# Brawler arena shooter Game with implemented Reinfocement learning Artificial Intelligence

This projet implements and compares both Reinforcement learning AI and conventional Behavior Tree AI on top of a 3D multiplayer brawler arena shooter game.

# The Game:
## Weapons:
- The game implements a data-driven weapon system (with multiple projectiles, ammunition, particle systems, reloading animation). Everything is server-side and synchronized across multiple player instances.
![Bazooka-gif](https://github.com/mikirov/Elsys-Thesis-Work-2019-2020/blob/master/Documentation/Images/20200413_231529.gif)
![Default-gun-gif](https://github.com/mikirov/Elsys-Thesis-Work-2019-2020/blob/master/Documentation/Images/20200413_233054.gif)
## Co-op game mode:
- The game implements a lobby that waits for 4 people to join before entering the main arena. The game spawns BT AI and RL AI against the 4 players.
![lobby](https://github.com/mikirov/Elsys-Thesis-Work-2019-2020/blob/master/Documentation/Images/lobby.png)
![lobby2](https://github.com/mikirov/Elsys-Thesis-Work-2019-2020/blob/master/Documentation/Images/lobby2.png)
## Various animations:
- The players have animations for different actions (all animation logic is written in C++)
![walk-animation](https://github.com/mikirov/Elsys-Thesis-Work-2019-2020/blob/master/Documentation/Images/20200303_212213.gif)
![death-animation](https://github.com/mikirov/Elsys-Thesis-Work-2019-2020/blob/master/Documentation/Images/20200303_212418.gif)
![reload-animation](https://github.com/mikirov/Elsys-Thesis-Work-2019-2020/blob/master/Documentation/Images/20200303_213937.gif)
## Chat:
- A fully synchronized C++ chat is implemented into the game. It has animations and a sccroll button:
![chat-animation](https://github.com/mikirov/Elsys-Thesis-Work-2019-2020/blob/master/Documentation/Images/20200303_221724.gif)

# The artificial intelligence:
## Behavior tree AI:
- The game implements a Behavior Tree enemy AI. All nodes are implemented in C++.
![BT](https://github.com/mikirov/Elsys-Thesis-Work-2019-2020/blob/master/Documentation/Images/behaviortree.png)
## Reinforcement learning AI:
![training](https://github.com/mikirov/Elsys-Thesis-Work-2019-2020/blob/master/Documentation/Images/training.png)
- The reinforcement learning AI consists of two phases: training the agent and playing against the agent:
- - A fully costumizable training user interface was created. It allows the developer to tweek training data in real time to achieve the wanted behavior.
- - Progress is being made towards exporting the RL code to a plugin.
- - The agent stores it's progress when killed and when another one spawns in the next epoch the training continues where it left off.
- After an agent is trained it reads the model data from it's Q-table and does the best action

## Explanation of The Reinforcement learning algorithm:
![explanation](https://github.com/mikirov/Elsys-Thesis-Work-2019-2020/blob/master/Documentation/Images/explanation.png)
![explanation2](https://github.com/mikirov/Elsys-Thesis-Work-2019-2020/blob/master/Documentation/Images/explanation2.png)
- The algorithm implemented in this project is tabular Q-learning
- It takes and agent and an environment.
- The agent is given a finite set of possible actions it can perform
- The environment gives the agent the current state of the game
- The environment gives the agent the current reward for the previous action it has performed
- The agent tries to optimize the total predicted future reward by doing the action that will give it the highest reward in a given state.
# Read more:
- [Thesis](https://github.com/mikirov/Elsys-Thesis-Work-2019-2020/blob/master/Documentation/thesis.pdf) 
- [Short documentation](https://github.com/mikirov/Elsys-Thesis-Work-2019-2020/blob/master/Documentation/short-thesis.pdf)
- [Thesis presentation](https://github.com/mikirov/Elsys-Thesis-Work-2019-2020/blob/master/Documentation/thesis-presentation.pptx)
